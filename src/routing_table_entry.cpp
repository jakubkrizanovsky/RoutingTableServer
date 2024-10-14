#include "routing_table_entry.h"

RoutingTableEntry::RoutingTableEntry(std::string line) {
    interface = ReadNext(line);
    destination = IPv4Address(ReadNext(line));
    gateway = IPv4Address(ReadNext(line));
    flags = (unsigned short) stoul(ReadNext(line));
    refCount = ReadNext(line);
    use = ReadNext(line);
    metric = ReadNext(line);
    mask = IPv4Address(ReadNext(line));
    mtu = ReadNext(line);
    window = ReadNext(line);
    irtt = ReadNext(line);
}

bool RoutingTableEntry::IsUsable()
{
    return flags & 1;
}

std::string RoutingTableEntry::ReadNext(std::string& line) {
    int pos = line.find("\t");
    std::string value = line.substr(0, pos);
    line.erase(0, pos + 1);
    return value;
}
