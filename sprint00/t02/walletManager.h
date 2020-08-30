#include <iostream>

struct Wallet {
    int septims;
};

Wallet *createWallet(int septims);
Wallet *createWallets(int amount);
void destroyWallet(Wallet *wal);
void destroyWallets(Wallet *wals);
