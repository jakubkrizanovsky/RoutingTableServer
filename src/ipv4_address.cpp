#include "ipv4_address.h"

IPv4Address::IPv4Address()
{
    m_Value = 0;
}

IPv4Address::IPv4Address(std::string hexString)
{
    m_Value = std::stoul(hexString, 0, 16);
}

std::string IPv4Address::ToString()
{
    std::string value = std::to_string((m_Value & 255));
    value += ".";
    value += std::to_string((m_Value & (255 << 8)) >> 8);
    value += ".";
    value += std::to_string((m_Value & (255 << 16)) >> 16);
    value += ".";
    value += std::to_string((m_Value & (255 << 24)) >> 24);
    return value;
}
