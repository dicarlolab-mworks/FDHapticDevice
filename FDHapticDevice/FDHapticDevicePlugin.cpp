//
//  FDHapticDevicePlugin.cpp
//  FDHapticDevice
//
//  Created by Christopher Stawarz on 1/17/13.
//  Copyright (c) 2013 German Primate Center. All rights reserved.
//


class FDHapticDevicePlugin : public mw::Plugin {
    void registerComponents(shared_ptr<mw::ComponentRegistry> registry) MW_OVERRIDE {
    }
};


extern "C" mw::Plugin* getPlugin() {
    return new FDHapticDevicePlugin();
}
