#pragma once

#include "routing_table_entry.h"
#include <string>
#include <queue>

class RoutingTableRepository {
private:
    const std::string ROUTE_FILE_PATH = "route.txt";
public:
    static std::queue<RoutingTableEntry> GetEntries();
};