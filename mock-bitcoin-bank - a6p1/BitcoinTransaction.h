//
// Created by datsu on 11/27/2022.
//

#ifndef ASSIGNMENT6_BITCOINTRANSACTION_H
#define ASSIGNMENT6_BITCOINTRANSACTION_H
#include "Date.h"

class BitcoinTransaction {

private :
    char buy_sell;
    float amount_btc;
    float amount_usd;

    Date date;

    String blockchain_info;

public :
    // Ask the user for all the above information, create a BitcoinTransaction object,
    // go through with the transaction if valid, and add to the Transaction hisory.
    void transact();

};


#endif //ASSIGNMENT6_BITCOINTRANSACTION_H
