#pragma once

#include <string>

class RoutingTableEntry {
public:
    std::string interface;
    RoutingTableEntry(std::string line);
};