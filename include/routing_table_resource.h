#pragma once

#include "resource.h"
#include <string>

class RoutingTableResource : public Resource {
public:
    std::string GetResponse() override;
};