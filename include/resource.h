#pragma once

#include <string>

class Resource {
public:
    virtual std::string GetContext() = 0;
};