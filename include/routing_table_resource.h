#pragma once

#include "resource.h"
#include "routing_table_service.h"
#include <string>

class RoutingTableResource : public Resource {
private:
    RoutingTableService m_RoutingTableService;
public:
    std::string GetResponse() override;
};