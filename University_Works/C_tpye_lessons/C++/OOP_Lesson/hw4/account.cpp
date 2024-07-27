#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include "account.h"
using namespace std;

Account::Account(void): account_number("None"), customer_name("None"), current_balace(0) {};


const char* Account::get_account_number(void) const{
    return this->account_number;
};

const double Account::get_balance(void) const{
    return this->current_balace;
};

void Account::change_name(const char* newname){
    for(int i=0;i<21;i+=1)
        this->customer_name[i] = newname[i];
};

void Account::change_number(const char* newnumber){
    for(int i=0;i<11;i+=1)
        this->account_number[i] = newnumber[i];
};

void Account::process_deposit(const double &deposit_value){
    this->current_balace += deposit_value;
};

const bool Account::process_withdrawal(const double &withdraw_value){
    if(this->current_balace < withdraw_value)
        return false;
    this->current_balace -= withdraw_value;
    return true;
};

void Account::print(void) const{
    cout << "Account Number: " << this->account_number << endl;
    cout << "Name: " << this->customer_name << endl;
    cout << "Balance: " << setprecision(2) << fixed << this->current_balace << endl;
    cout << endl;
};

const int Account::cmp(const Account &another) const{
    for(int i=0;i<10;i++){
        if(this->account_number[i] == another.account_number[i])
            continue;

        if(this->account_number[i] > another.account_number[i])
            return 1;
        else
            return -1;
    }
    return 0;
};

const int Account::cmp(const char* Array) const{
    for(int i=0;i<10;i++){
        if(this->account_number[i] == Array[i])
            continue;

        if(this->account_number[i] > Array[i])
            return 1;
        else
            return -1;
    }
    return 0;
};