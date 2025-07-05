#pragma once

#include <string>

namespace cryptonote {
  /**
   * \brief Route inference results across partner networks
   *
   * Placeholder that integrates with IOTA, Solana and Polygon
   * to subsidize transaction processing for feeless JOY operation.
   */
  void route_inference(const std::string &serialized_result);
}
