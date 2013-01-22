//
//  FDHapticDevice.h
//  FDHapticDevice
//
//  Created by Christopher Stawarz on 1/17/13.
//  Copyright (c) 2013 German Primate Center. All rights reserved.
//

#ifndef __FDHapticDevice__FDHapticDevice__
#define __FDHapticDevice__FDHapticDevice__

#include <vector>

#include <boost/static_assert.hpp>
#include <boost/thread/thread.hpp>
#include <boost/type_traits/is_signed.hpp>

#include "Force.h"


class FDHapticDevice : public IODevice {
    
public:
    static const std::string POS_X;
    static const std::string POS_Y;
    static const std::string POS_Z;
    
    static void describeComponent(ComponentInfo &info);
    
    explicit FDHapticDevice(const ParameterValueMap &parameters);
    ~FDHapticDevice();
    
    bool initialize() MW_OVERRIDE;
    bool startDeviceIO() MW_OVERRIDE;
    bool stopDeviceIO() MW_OVERRIDE;
    
private:
    BOOST_STATIC_ASSERT(boost::is_signed<char>::value);
    static const char NO_DEVICE = -1;
    
    static void logError(const std::string &error, const std::string &reason);
    static void logDHDError(const std::string &error);
    
    bool isRunning() const;
    void runLoop();
    
    VariablePtr pos_x;
    VariablePtr pos_y;
    VariablePtr pos_z;
    
    std::vector< boost::shared_ptr<Force> > forceComponents;
    char deviceID;
    boost::thread runLoopThread;
    
};


#endif // !defined(__FDHapticDevice__FDHapticDevice__)


























