//
// Created by Derek Prince on 2/14/18
//

#include <iostream>
#include <cstring>
#include "Leap.h"
#include "SampleListener.h"
#include "osc/OscOutboundPacketStream.h"
#include "ip/UdpSocket.h"


#define ADDRESS "127.0.0.1"
#define PORT 6448

#define OUTPUT_BUFFER_SIZE 256//1024

using namespace Leap;

int main(int argc, char** argv) {

    UdpTransmitSocket transmitSocket(IpEndpointName(ADDRESS, PORT));
    char buffer[OUTPUT_BUFFER_SIZE];
    osc::OutboundPacketStream packet( buffer, OUTPUT_BUFFER_SIZE );

    packet << osc::BeginBundleImmediate
           << osc::BeginMessage("wek/inputs")
           << (float)24 << (float)3.1415 << osc::EndMessage;
           //<< osc::BeginMessage("wek/inputs")
           //<< 24 << (float)10.8 << osc::EndMessage
           //<< osc::EndBundle;

    transmitSocket.Send( packet.Data(), packet.Size() );

    // Create a sample listener and controller
    SampleListener listener;
    Controller controller;

    // Have the sample listener receive events from the controller
    controller.addListener(listener);

    if (argc > 1 && strcmp(argv[1], "--bg") == 0)
        controller.setPolicy(Leap::Controller::POLICY_BACKGROUND_FRAMES);

    // Keep this process running until Enter is pressed
    std::cout << "Press Enter to quit..." << std::endl;
    std::cin.get();

    // Remove the sample listener when done
    controller.removeListener(listener);

    return 0;
}
