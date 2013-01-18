//
//  FDHapticDevice.cpp
//  FDHapticDevice
//
//  Created by Christopher Stawarz on 1/17/13.
//  Copyright (c) 2013 German Primate Center. All rights reserved.
//

#include "FDHapticDevice.h"

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
    return true;
}


bool FDHapticDevice::stopDeviceIO() {
    return true;
}


void FDHapticDevice::logDHDError(const std::string &msg) {
    merror(M_IODEVICE_MESSAGE_DOMAIN, "%s: %s", msg.c_str(), dhdErrorGetLastStr());
}


























