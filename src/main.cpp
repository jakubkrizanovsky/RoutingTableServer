#include "routing_table_resource.h"
#include <iostream>
#include <string>

int main() {
    RoutingTableResource resource;

    // std::queue<RoutingTableEntry*> entries = RoutingTableRepository::GetEntries();
    std::string response = resource.GetResponse();
    std::cout << response << std::endl;
    return 0;
}
