#pragma once

#include "routing_table_entry.h"
#include <string>
#include <list>

class RoutingTableRepository {
private:
    static const std::string ROUTE_FILE_PATH;
public:
    static std::list<RoutingTableEntry*> GetEntries();
    static void DeleteEntries(std::list<RoutingTableEntry*> entries);
};
