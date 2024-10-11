#pragma once

#include "routing_table_entry.h"
#include <queue>

class RoutingTableRepository {
public:
    static std::queue<RoutingTableEntry> GetEntries();
};