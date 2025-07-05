#pragma once

#include <cstdint>
#include <string>

namespace cryptonote
{
  struct staking_entry
  {
    std::string address;
    uint64_t amount;
    uint64_t unlock_height;
  };

  bool add_stake(const std::string &address, uint64_t amount, uint64_t height);
  bool remove_stake(const std::string &address, uint64_t amount);
  uint64_t get_stake(const std::string &address);
}
