//
//  FDHapticDevice.h
//  FDHapticDevice
//
//  Created by Christopher Stawarz on 1/17/13.
//  Copyright (c) 2013 German Primate Center. All rights reserved.
//

#ifndef __FDHapticDevice__FDHapticDevice__
#define __FDHapticDevice__FDHapticDevice__

#include <string>

#include <boost/static_assert.hpp>
#include <boost/thread/thread.hpp>
#include <boost/type_traits/is_signed.hpp>

using namespace mw;


class FDHapticDevice : public IODevice {
    
public:
    static void describeComponent(ComponentInfo &info);
    
    explicit FDHapticDevice(const ParameterValueMap &parameters);
    ~FDHapticDevice();
    
    bool initialize() MW_OVERRIDE;
    bool startDeviceIO() MW_OVERRIDE;
    bool stopDeviceIO() MW_OVERRIDE;
    
private:
    BOOST_STATIC_ASSERT(boost::is_signed<char>::value);
    static const char NO_DEVICE = -1;
    
    static void logDHDError(const std::string &msg);
    
    bool isRunning() const;
    void runLoop();
    
    char deviceID;
    boost::thread runLoopThread;
    
};


#endif // !defined(__FDHapticDevice__FDHapticDevice__)


























