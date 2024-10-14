#pragma once

#include <string>

class Resource {
public:
    virtual std::string GetResponse() = 0;
};