//
//  FDHapticDevice.cpp
//  FDHapticDevice
//
//  Created by Christopher Stawarz on 1/17/13.
//  Copyright (c) 2013 German Primate Center. All rights reserved.
//

#include "FDHapticDevice.h"

#include <boost/bind.hpp>
#include <boost/foreach.hpp>

#include "dhdc.h"


const std::string FDHapticDevice::POS_X("pos_x");
const std::string FDHapticDevice::POS_Y("pos_y");
const std::string FDHapticDevice::POS_Z("pos_z");


void FDHapticDevice::describeComponent(ComponentInfo &info) {
    IODevice::describeComponent(info);
    
    info.setSignature("iodevice/fd_haptic_device");
    
    info.addParameter(POS_X);
    info.addParameter(POS_Y);
    info.addParameter(POS_Z);
}


FDHapticDevice::FDHapticDevice(const ParameterValueMap &parameters) :
    IODevice(parameters),
    pos_x(parameters[POS_X]),
    pos_y(parameters[POS_Y]),
    pos_z(parameters[POS_Z]),
    deviceID(NO_DEVICE)
{
}


FDHapticDevice::~FDHapticDevice() {
    if (deviceID != NO_DEVICE) {
        if (dhdClose(deviceID) < 0) {
            logDHDError("Unable to close haptic device");
        }
    }
}


bool FDHapticDevice::initialize() {
    int result = dhdOpen();
    
    if (result < 0) {
        logDHDError("Unable to open haptic device");
        return false;
    }
    
    deviceID = char(result);
    
    return true;
}


bool FDHapticDevice::startDeviceIO() {
    if (!isRunning()) {
        try {
            runLoopThread = boost::thread(boost::bind(&FDHapticDevice::runLoop,
                                                      component_shared_from_this<FDHapticDevice>()));
        } catch (const boost::thread_resource_error &e) {
            logError("Unable to start haptic device", e.what());
            return false;
        }
    }
    
    return true;
}


bool FDHapticDevice::stopDeviceIO() {
    if (isRunning()) {
        runLoopThread.interrupt();
        try {
            runLoopThread.join();
        } catch (const boost::system::system_error &e) {
            logError("Unable to stop haptic device", e.what());
            return false;
        }
    }
    
    return true;
}


void FDHapticDevice::logError(const std::string &error, const std::string &reason) {
    merror(M_IODEVICE_MESSAGE_DOMAIN, "%s: %s", error.c_str(), reason.c_str());
}


void FDHapticDevice::logDHDError(const std::string &error) {
    logError(error, dhdErrorGetLastStr());
}


bool FDHapticDevice::isRunning() const {
    return (runLoopThread.get_id() != boost::thread::id());
}


void FDHapticDevice::runLoop() {
    while (true) {
        Eigen::Vector3d position;
        if (dhdGetPosition(&(position.x()), &(position.y()), &(position.z()), deviceID) < 0) {
            logDHDError("Unable to get haptic device position");
            return;
        }
        
        // Update position variables to reflect current position
        pos_x->setValue(position.x());
        pos_y->setValue(position.y());
        pos_z->setValue(position.z());
        
        Eigen::Vector3d velocity;
        if (dhdGetLinearVelocity(&(velocity.x()), &(velocity.y()), &(velocity.z()), deviceID) < 0) {
            logDHDError("Unable to get haptic device velocity");
            return;
        }
        
        Eigen::Vector3d force(0.0, 0.0, 0.0);
        
        BOOST_FOREACH(const boost::shared_ptr<Force> &fc, forceComponents) {
            if (fc->isActive()) {
                force += fc->getForce(position, velocity);
            }
        }
        
        if (dhdSetForce(force.x(), force.y(), force.z(), deviceID) < 0) {
            logDHDError("Unable to set haptic device force");
            return;
        }
        
        // Give another thread a chance to terminate this one
        boost::this_thread::interruption_point();
    }
}


























