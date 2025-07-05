#pragma once

#include <cstdint>
#include <string>

namespace cryptonote
{
  void record_inference(const std::string &address);
  void record_domain_usage(const std::string &address);
  uint64_t get_participation_score(const std::string &address);
}
