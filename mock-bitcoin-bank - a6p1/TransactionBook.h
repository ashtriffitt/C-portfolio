//
// Created by datsu on 11/27/2022.
//

#ifndef ASSIGNMENT6_TRANSACTIONBOOK_H
#define ASSIGNMENT6_TRANSACTIONBOOK_H

#include "BitcoinTransaction.h"
#include <vector>

class TransactionBook {
private :
    vector<BitcoinTransaction> book;
public :
    // Adds the transaction to the book
    void add_transaction(BitcoinTransaction bt);

    // Returns a transaction from the book to access specific information.
    BitcoinTransaction get_transaction(int index);

    // Constructor will intialize empty vector.
    TransactionBook();

};


#endif //ASSIGNMENT6_TRANSACTIONBOOK_H
