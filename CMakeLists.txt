cmake_minimum_required(VERSION 3.9)
project(LeapTest)

set(LEAP_INCLUDE_PATH "/usr/local/lib64/LeapSDK/include/")
set(OSC_INCLUDE_PATH "/usr/local/lib/oscpack")
set(LEAP_LIBRARY_PATH "/usr/local/lib64/LeapSDK/lib/x64")
set(CMAKE_CXX_STANDARD 11)

include_directories(${LEAP_INCLUDE_PATH} ${OSC_INCLUDE_PATH})

set(IpSystemTypePath ip/posix)
add_library(LeapLib STATIC IMPORTED)
add_library(oscpack

        ${OSC_INCLUDE_PATH}/ip/IpEndpointName.h
        ${OSC_INCLUDE_PATH}/ip/IpEndpointName.cpp

        ${OSC_INCLUDE_PATH}/ip/NetworkingUtils.h
        ${OSC_INCLUDE_PATH}/${IpSystemTypePath}/NetworkingUtils.cpp

        ${OSC_INCLUDE_PATH}/ip/UdpSocket.h
        ${OSC_INCLUDE_PATH}/${IpSystemTypePath}/UdpSocket.cpp

        ${OSC_INCLUDE_PATH}/ip/PacketListener.h
        ${OSC_INCLUDE_PATH}/ip/TimerListener.h

        ${OSC_INCLUDE_PATH}/osc/OscTypes.h
        ${OSC_INCLUDE_PATH}/osc/OscTypes.cpp
        ${OSC_INCLUDE_PATH}/osc/OscHostEndianness.h
        ${OSC_INCLUDE_PATH}/osc/OscException.h
        ${OSC_INCLUDE_PATH}/osc/OscPacketListener.h
        ${OSC_INCLUDE_PATH}/osc/MessageMappingOscPacketListener.h
        ${OSC_INCLUDE_PATH}/osc/OscReceivedElements.h
        ${OSC_INCLUDE_PATH}/osc/OscReceivedElements.cpp
        ${OSC_INCLUDE_PATH}/osc/OscPrintReceivedElements.h
        ${OSC_INCLUDE_PATH}/osc/OscPrintReceivedElements.cpp
        ${OSC_INCLUDE_PATH}/osc/OscOutboundPacketStream.h
        ${OSC_INCLUDE_PATH}/osc/OscOutboundPacketStream.cpp

        )

set_property(TARGET LeapLib PROPERTY IMPORTED_LOCATION ${LEAP_LIBRARY_PATH}/libLeap.so)

add_executable(LeapTest
        main.cpp SampleListener.h SampleListener.cpp
        ${LEAP_INCLUDE_PATH}/Leap.h
        ${OSC_INCLUDE_PATH}/osc/OscOutboundPacketStream.h ${OSC_INCLUDE_PATH}/ip/UdpSocket.h)
target_link_libraries(LeapTest LeapLib oscpack)
