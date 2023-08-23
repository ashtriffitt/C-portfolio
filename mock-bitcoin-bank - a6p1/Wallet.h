//
// Created by datsu on 11/27/2022.
//

#ifndef ASSIGNMENT6_WALLET_H
#define ASSIGNMENT6_WALLET_H


class Wallet {

private :
    int balance_usd;
    int balance_btc_amount;
    int balance_btc_value;

public :
    // Makes an empty wallet upon registration (creation of the user class)
    Wallet()

    int get_balance_usd(){return balance_usd;};
    int get_balance_btc_amount(){return balance_btc_amount;};
    int get_balance_btc_value(){return balance_btc_value;};

    void change_balance_usd(int i){balance_usd += i};
    void change_balance_btc_amount(int i){balance_btc_amount += i};
    void change_balance_btc_value(int i){balance_btc_value += i};

};


#endif //ASSIGNMENT6_WALLET_H
