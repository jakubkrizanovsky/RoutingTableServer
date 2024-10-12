#pragma once

#include <string>

class RoutingTableEntry {
private:
    std::string m_interface;
public:
    RoutingTableEntry(std::string line);
};