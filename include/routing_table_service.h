#pragma once

#include "routing_table_entry.h"
#include "routing_table_repository.h"
#include <list>

class RoutingTableService {
private:
    RoutingTableRepository m_RoutingTableRepository;
public:
    std::list<RoutingTableEntry> GetUsableEntries();
};
