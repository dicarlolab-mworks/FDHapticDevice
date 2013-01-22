//
//  FixedForce.h
//  FDHapticDevice
//
//  Created by Christopher Stawarz on 1/22/13.
//  Copyright (c) 2013 German Primate Center. All rights reserved.
//

#ifndef __FDHapticDevice__FixedForce__
#define __FDHapticDevice__FixedForce__

#include "Force.h"


class FixedForce : public Force {
    
public:
    static const std::string F_X;
    static const std::string F_Y;
    static const std::string F_Z;
    
    static void describeComponent(ComponentInfo &info);
    
    explicit FixedForce(const ParameterValueMap &parameters);
    
    Eigen::Vector3d getForce(const Eigen::Vector3d &position, const Eigen::Vector3d &velocity) MW_OVERRIDE;
    
private:
    VariablePtr f_x;
    VariablePtr f_y;
    VariablePtr f_z;
    
};


#endif // !defined(__FDHapticDevice__FixedForce__)
