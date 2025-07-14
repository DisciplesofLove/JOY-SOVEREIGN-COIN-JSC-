#include "inference_router.h"

namespace cryptonote {
  // TODO: send results asynchronously once networking code is ready
  void route_inference(const std::string &serialized_result)
  {
    // In a real deployment, this would forward inference results
    // to IOTA, Solana and Polygon Supernet so their reward pools
    // can subsidize JOY transaction costs.
    (void)serialized_result;
  }
}
