#pragma once

#include "ipv4_address.h"
#include <string>

class RoutingTableEntry {
private:
    std::string ReadNext(std::string& line);
public:
    std::string interface;
    IPv4Address destination;
    IPv4Address gateway;
    unsigned short flags;
    std::string refCount;
    std::string use;
    std::string metric;
    IPv4Address mask;
    std::string mtu;
    std::string window;
    std::string irtt;
    RoutingTableEntry(std::string line);
    bool IsUsable();
};