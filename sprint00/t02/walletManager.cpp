#include "walletManager.h"

Wallet *createWallet(int septims) {
    Wallet *wal = new Wallet;

    wal->septims = septims;
    return wal;
}

Wallet *createWallets(int amount) {
    return new Wallet [amount];
}

void destroyWallet(Wallet *wal) {
    delete wal;
}

void destroyWallets(Wallet *wals) {
    delete[] wals;
}
