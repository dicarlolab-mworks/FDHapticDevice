//
//  FDHapticDevice.cpp
//  FDHapticDevice
//
//  Created by Christopher Stawarz on 1/17/13.
//  Copyright (c) 2013 German Primate Center. All rights reserved.
//

#include "FDHapticDevice.h"


void FDHapticDevice::describeComponent(ComponentInfo &info) {
    IODevice::describeComponent(info);
    info.setSignature("iodevice/fd_haptic_device");
}


FDHapticDevice::FDHapticDevice(const ParameterValueMap &parameters) :
    IODevice(parameters)
{
}


FDHapticDevice::~FDHapticDevice() {
}
