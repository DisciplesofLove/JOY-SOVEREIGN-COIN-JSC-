#pragma once

#include <cstdint>
#include <string>

namespace cryptonote
{
  uint64_t get_voting_weight(const std::string &address);
}
