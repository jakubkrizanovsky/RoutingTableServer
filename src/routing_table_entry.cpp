#include "routing_table_entry.h"

RoutingTableEntry::RoutingTableEntry(std::string line) {
    interface = line.substr(0, line.find("\t"));
}
