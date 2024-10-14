#pragma once

#include <string>

class IPv4Address
{
private:
    unsigned long m_Value;
public:
    IPv4Address();
    IPv4Address(std::string hexString);
    std::string ToString();
};