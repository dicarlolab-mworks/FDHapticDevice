//
//  Force.cpp
//  FDHapticDevice
//
//  Created by Christopher Stawarz on 1/18/13.
//  Copyright (c) 2013 German Primate Center. All rights reserved.
//

#include "Force.h"


const std::string Force::ACTIVE("active");


void Force::describeComponent(ComponentInfo &info) {
    Component::describeComponent(info);
    info.addParameter(ACTIVE, "1");
}


Force::Force(const ParameterValueMap &parameters) :
    Component(parameters),
    active(parameters[ACTIVE])
{
}


bool Force::isActive() const {
    return active->getValue().getBool();
}
