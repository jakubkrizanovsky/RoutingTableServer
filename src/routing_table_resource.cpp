#include "routing_table_resource.h"
#include "routing_table_repository.h"
#include <list>
#include <string>
#include <iostream>

std::string RoutingTableResource::GetResponse()
{
    std::string response = "<html><table>\n";

    std::list<RoutingTableEntry*> entries = RoutingTableRepository::GetEntries();

    std::list<RoutingTableEntry*>::iterator it;
    for (it = entries.begin(); it != entries.end(); it++) {
        response += "\t<tr>";
        response += "<td>" + (*it)->interface + "</td>";
        response += "</tr>\n";
    }

    RoutingTableRepository::DeleteEntries(entries);

    response += "</table></html>\n";

    return response;
}