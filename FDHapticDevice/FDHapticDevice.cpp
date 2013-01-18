//
//  FDHapticDevice.cpp
//  FDHapticDevice
//
//  Created by Christopher Stawarz on 1/17/13.
//  Copyright (c) 2013 German Primate Center. All rights reserved.
//

#include "FDHapticDevice.h"

#include <boost/bind.hpp>

#include "dhdc.h"


void FDHapticDevice::describeComponent(ComponentInfo &info) {
    IODevice::describeComponent(info);
    info.setSignature("iodevice/fd_haptic_device");
}


FDHapticDevice::FDHapticDevice(const ParameterValueMap &parameters) :
    IODevice(parameters),
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
            merror(M_IODEVICE_MESSAGE_DOMAIN, "Unable to start haptic device: %s", e.what());
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
            merror(M_IODEVICE_MESSAGE_DOMAIN, "Unable to stop haptic device: %s", e.what());
            return false;
        }
    }
    
    return true;
}


void FDHapticDevice::logDHDError(const std::string &msg) {
    merror(M_IODEVICE_MESSAGE_DOMAIN, "%s: %s", msg.c_str(), dhdErrorGetLastStr());
}


bool FDHapticDevice::isRunning() const {
    return (runLoopThread.get_id() != boost::thread::id());
}


void FDHapticDevice::runLoop() {
    while (true) {
        // Do something
        boost::this_thread::interruption_point();
    }
}


























