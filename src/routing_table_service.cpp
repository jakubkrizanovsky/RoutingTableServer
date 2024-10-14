#include "routing_table_service.h"

std::list<RoutingTableEntry> RoutingTableService::GetUsableEntries()
{
    std::list<RoutingTableEntry> entries = m_RoutingTableRepository.GetEntries();

    //Filter unusable entries
    entries.remove_if([](RoutingTableEntry entry)
    {
        return !entry.IsUsable();
    });

    return entries;
}
