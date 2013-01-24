//
//  FixedForce.cpp
//  FDHapticDevice
//
//  Created by Christopher Stawarz on 1/22/13.
//  Copyright (c) 2013 German Primate Center. All rights reserved.
//

#include "FixedForce.h"


const std::string FixedForce::F_X("f_x");
const std::string FixedForce::F_Y("f_y");
const std::string FixedForce::F_Z("f_z");


void FixedForce::describeComponent(ComponentInfo &info) {
    Force::describeComponent(info);
    
    info.setSignature("iochannel/fd_haptic_device_fixed_force");
    
    info.addParameter(F_X);
    info.addParameter(F_Y);
    info.addParameter(F_Z);
}


FixedForce::FixedForce(const ParameterValueMap &parameters) :
    Force(parameters),
    f_x(parameters[F_X]),
    f_y(parameters[F_Y]),
    f_z(parameters[F_Z])
{
}


Eigen::Vector3d FixedForce::getForce(const Eigen::Vector3d &position, const Eigen::Vector3d &velocity) {
    return Eigen::Vector3d(f_x->getValue().getFloat(),
                           f_y->getValue().getFloat(),
                           f_z->getValue().getFloat());
}


























