#include "routing_table_repository.h"
#include <iostream>
#include <fstream>

const std::string RoutingTableRepository::ROUTE_FILE_PATH = "/proc/net/route";

std::list<RoutingTableEntry> RoutingTableRepository::GetEntries()
{
    std::list<RoutingTableEntry> entries;

    std::string line;
    std::ifstream routeFile(ROUTE_FILE_PATH);

    //Skip header line
    getline(routeFile, line);

    //Read the file line by line and create entries 
    while(getline(routeFile, line)) {
        entries.push_back(RoutingTableEntry(line));
    }
    routeFile.close();

    return entries;
}
