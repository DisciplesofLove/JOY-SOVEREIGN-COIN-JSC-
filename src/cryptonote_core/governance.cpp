#include "governance.h"
#include "staking.h"
#include "participation.h"

namespace cryptonote
{
  uint64_t get_voting_weight(const std::string &address)
  {
    const uint64_t stake = get_stake(address);
    const uint64_t score = get_participation_score(address);
    return stake + stake * score / 10;
  }
}
