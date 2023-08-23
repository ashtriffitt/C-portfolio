//
// Created by datsu on 11/27/2022.
//

#ifndef ASSIGNMENT6_USER_H
#define ASSIGNMENT6_USER_H

#include "TransactionBook.h"
#include "Bank.h"

class User {
private:
    string username;
    string password;

    string name;
    string address;

    Bank bank;

    TransactionBook transaction_book;

public :
    // This constructor would also call the bank, wallet and transaction book constructors.
    User(string username, string password, string name, string address);

    // There would be getters and setters for all of these. It would be pointless for me to write them all out.

};


#endif //ASSIGNMENT6_USER_H
