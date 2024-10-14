#pragma once

#include "routing_table_entry.h"
#include <string>
#include <list>

class RoutingTableRepository {
private:
    static const std::string ROUTE_FILE_PATH;
public:
    std::list<RoutingTableEntry> GetEntries();
};
