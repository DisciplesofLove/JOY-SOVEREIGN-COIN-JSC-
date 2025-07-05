# Transaction Fees

JOY Sovereign Coin inherits Monero's dynamic fee algorithm. Transaction fees are calculated per byte and scale with the current block reward and median block weight.

The daemon computes the minimum required fee as:

```
fee_per_byte = get_dynamic_base_fee(block_reward, median_block_weight)
needed_fee = tx_weight * fee_per_byte
```

`get_dynamic_base_fee` implements the scaling formula defined in `src/cryptonote_core/blockchain.cpp`. By default `CRYPTONOTE_FEES_ENABLED` is set to `0`, allowing transactions to be submitted without fees. Set it to `1` to require the calculated minimum fee.

## Feeless inference routing

When proof-of-inference is enabled, JOY integrates with IOTA, Solana and Polygon Supernet. Inference results can be routed through these networks, allowing the JOY chain to subsidize transaction costs from partner networks and operate without native fees.
The routing logic is defined in `src/cryptonote_basic/inference_router.cpp` and currently acts as a placeholder for future integrations.
