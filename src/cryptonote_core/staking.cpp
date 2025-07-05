#include "staking.h"

#include <vector>

namespace cryptonote
{
  static std::vector<staking_entry> staked_entries;

  bool add_stake(const std::string &address, uint64_t amount, uint64_t height)
  {
    (void)address;
    (void)amount;
    (void)height;
    // TODO: implement staking logic
    return true;
  }

  bool remove_stake(const std::string &address, uint64_t amount)
  {
    (void)address;
    (void)amount;
    return true;
  }

  uint64_t get_stake(const std::string &address)
  {
    (void)address;
    return 0;
  }
}
