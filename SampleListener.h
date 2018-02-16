//
// Created by Derek Prince on 2/14/18.
//

#ifndef LEAPTEST_SAMPLELISTENER_H
#define LEAPTEST_SAMPLELISTENER_H


#include <iostream>
#include <cstring>
#include "/usr/local/lib64/LeapSDK/include/Leap.h"

using namespace Leap;

class SampleListener : public Listener {
public:
    virtual void onInit(const Controller&);
    virtual void onConnect(const Controller&);
    virtual void onDisconnect(const Controller&);
    virtual void onExit(const Controller&);
    virtual void onFrame(const Controller&);
    virtual void onFocusGained(const Controller&);
    virtual void onFocusLost(const Controller&);
    virtual void onDeviceChange(const Controller&);
    virtual void onServiceConnect(const Controller&);
    virtual void onServiceDisconnect(const Controller&);

private:
};

#endif //LEAPTEST_SAMPLELISTENER_H
