# Transaction Fees

JOY Sovereign Coin inherits Monero's dynamic fee algorithm. Transaction fees are calculated per byte and scale with the current block reward and median block weight.

The daemon computes the minimum required fee as:

```
fee_per_byte = get_dynamic_base_fee(block_reward, median_block_weight)
needed_fee = tx_weight * fee_per_byte
```

`get_dynamic_base_fee` implements the scaling formula defined in `src/cryptonote_core/blockchain.cpp`. If `CRYPTONOTE_FEES_ENABLED` is set to `0` in `src/cryptonote_config.h`, all transactions are accepted without fees.
