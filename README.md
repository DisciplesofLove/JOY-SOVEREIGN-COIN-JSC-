# JOY Sovereign Coin

JOY Sovereign Coin (JOY) is a private cryptocurrency based on Monero. It extends the protocol with a proof-of-inference consensus model and cross-chain transaction routing.

## Key features

- **Proof of inference:** nodes submit verifiable machine-learning inference results instead of performing traditional mining.
- **Feeless by default:** transaction fees can be disabled via the `CRYPTONOTE_FEES_ENABLED` flag.
- **Cross-chain routing:** inference submissions and transfers can be relayed through IOTA, Solana and Polygon Supernet to subsidize costs. The placeholder implementation lives in `src/cryptonote_basic/inference_router.cpp`.
- **Proof of Stake and Use:** validators can stake JOY and earn additional voting weight through active participation.
- **Privacy:** ring signatures and stealth addresses inherited from Monero.

## Building

Clone the repository with its submodules and run `make`:

```bash
git clone --recursive <this-repo-url>
cd JOY-Sovereign-Coin
make
```

Executables will be in `build/release/bin`.

## Running

Start the daemon with:

```bash
./build/release/bin/joyd --detach
```

The command-line wallet is `joy-wallet-cli`.

## Documentation

- [Transaction fees](docs/FEES.md)
- [Staking and participation](docs/POS_POU.md)

JOY is released under the BSD 3-Clause license.

Contributions are welcome via pull requests.
