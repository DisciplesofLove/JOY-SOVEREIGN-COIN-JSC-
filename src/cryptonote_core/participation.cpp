#include "participation.h"

#include <unordered_map>

namespace cryptonote
{
  static std::unordered_map<std::string, uint64_t> scores;

  void record_inference(const std::string &address)
  {
    ++scores[address];
  }

  void record_domain_usage(const std::string &address)
  {
    ++scores[address];
  }

  uint64_t get_participation_score(const std::string &address)
  {
    auto it = scores.find(address);
    return it == scores.end() ? 0 : it->second;
  }
}
