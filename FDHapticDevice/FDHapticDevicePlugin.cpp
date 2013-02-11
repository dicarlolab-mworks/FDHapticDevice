//
//  FDHapticDevicePlugin.cpp
//  FDHapticDevice
//
//  Created by Christopher Stawarz on 1/17/13.
//  Copyright (c) 2013 German Primate Center. All rights reserved.
//

#include "FDHapticDevice.h"

#include "FixedForce.h"


class FDHapticDevicePlugin : public Plugin {
    void registerComponents(shared_ptr<ComponentRegistry> registry) MW_OVERRIDE {
        registry->registerFactory<StandardComponentFactory, FDHapticDevice>();
        registry->registerFactory<StandardComponentFactory, FixedForce>();
    }
};


MW_SYMBOL_PUBLIC
extern "C" Plugin* getPlugin() {
    return new FDHapticDevicePlugin();
}
