//
//  Force.cpp
//  FDHapticDevice
//
//  Created by Christopher Stawarz on 1/18/13.
//  Copyright (c) 2013 German Primate Center. All rights reserved.
//

#include "Force.h"


void Force::describeComponent(ComponentInfo &info) {
    Component::describeComponent(info);
}


Force::Force(const ParameterValueMap &parameters) :
    Component(parameters)
{
}
