//
// Created by datsu on 11/27/2022.
//

#ifndef ASSIGNMENT6_BANK_H
#define ASSIGNMENT6_BANK_H

#include "Wallet.h"

class Bank {

private :
    Wallet wallet;

    string routing_number
    string account_number;
    string account_holder;

public :
    // This would ask the user for all the input, hence why its not taking anything in.
    Bank();

    // These would work with the wallet class to deposit and withdraw to and from bank into the wallet.
    void withdraw(int amount);
    void deposit(int amount);

};


#endif //ASSIGNMENT6_BANK_H
