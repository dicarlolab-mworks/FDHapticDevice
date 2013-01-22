//
//  Force.h
//  FDHapticDevice
//
//  Created by Christopher Stawarz on 1/18/13.
//  Copyright (c) 2013 German Primate Center. All rights reserved.
//

#ifndef __FDHapticDevice__Force__
#define __FDHapticDevice__Force__

#include "Eigen/Core"

using namespace mw;


class Force : public mw::Component {
    
public:
    static void describeComponent(ComponentInfo &info);
    
    explicit Force(const ParameterValueMap &parameters);
    
    virtual Eigen::Vector3d getForce(const Eigen::Vector3d &position, const Eigen::Vector3d &velocity) = 0;
    
};


#endif // !defined(__FDHapticDevice__Force__)
