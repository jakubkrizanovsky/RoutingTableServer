#include "routing_table_resource.h"
#include "routing_table_repository.h"
#include <list>
#include <string>
#include <iostream>

std::string RoutingTableResource::GetResponse()
{
    std::string response = "<html><table>\n";

    std::list<RoutingTableEntry> entries = m_RoutingTableService.GetUsableEntries();

    std::list<RoutingTableEntry>::iterator it;
    response += "\t<tr><th>Interface</th><th>Destination</th><th>Mask</th><th>Metric</th><th>Gateway</th><th>Flags</th></tr>\n";;
    for (it = entries.begin(); it != entries.end(); it++) {
        response += "\t<tr>";
        response += "<td>" + it->interface + "</td>";
        response += "<td>" + it->destination.ToString() + "</td>";
        response += "<td>" + it->mask.ToString() + "</td>";
        response += "<td>" + it->metric + "</td>";
        response += "<td><strong>" + it->gateway.ToString() + "</strong></td>";
        response += "<td>" + std::to_string(it->flags) + "</td>";
        response += "</tr>\n";
    }

    response += "</table></html>\n";

    return response;
}