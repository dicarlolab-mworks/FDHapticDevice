//
//  FDHapticDevice.h
//  FDHapticDevice
//
//  Created by Christopher Stawarz on 1/17/13.
//  Copyright (c) 2013 German Primate Center. All rights reserved.
//

#ifndef __FDHapticDevice__FDHapticDevice__
#define __FDHapticDevice__FDHapticDevice__

using namespace mw;


class FDHapticDevice : public IODevice {
    
public:
    static void describeComponent(ComponentInfo &info);
    
    explicit FDHapticDevice(const ParameterValueMap &parameters);
    ~FDHapticDevice();
    
};


#endif // !defined(__FDHapticDevice__FDHapticDevice__)
