#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
#include "account.h"
#include "bank.h"
#include <cstring>
using namespace std;

Bank::Bank(void): bank_name("None"), accounts(0){
    for(int i=0; i<20;i++)
        order[i] = i;
};

int Bank::bsearch_account(const char* acc_id){
    for(int left = 0, right = accounts; left!=right && left != accounts ; ){
        int mid_number = order[(left+right)/2];
        int result = this->bank_account[mid_number].cmp(acc_id);
        if(!result)
            return mid_number;
        if(result == 1)
            right = (left+right)/2;
        else
            left = (left+right)/2;
    }
    return -1;
};

void Bank::sort_accounts(void){
    for(int i=0; i< accounts; i++){
        int min = i;
        for(int j=i; j< accounts; j++){
            if(this->bank_account[order[min]].cmp(this->bank_account[order[j]]) == 1 )
                min = j;
        }
        int tmp = order[i];
        order[i] = order[min];
        order[min] = tmp;
    }
};

void Bank::read_accounts(const char* readfile){
    ifstream Input(readfile);
    if(Input.fail()){
        cerr << "fail to read [" << readfile << "]" << endl;
        exit(0);
    }
    string buf;
    getline(Input, buf);
    strcpy(this->bank_name ,buf.c_str());
    char buf2[21];
    for(int i=0; Input >> buf2; i+=1 ){
        this->bank_account[i].change_number(buf2);
        char last_name[20];
        double init_current;
        Input >> buf2 >> last_name >> init_current ;
        strcat(buf2," ");
        strcat(buf2,last_name);
        this->bank_account[i].change_name(buf2);
        this->bank_account[i].process_deposit(init_current);
        this->accounts += 1;
    }
    sort_accounts();
    Input.close();
};

void Bank::process_transactions(const char* readfile){
    ifstream Input(readfile);
    if(Input.fail()){
        cerr << "fail to read [" << readfile << "]" << endl;
        exit(0);
    }
    cout << "Transaction Report\n" << endl; 
    cout << "Date   Account     Type  Amount    New Banlance" << endl;

    char date[10], user_account[11], type;
    double amount;
    while (Input >> date){
        Input >> user_account >> type >> amount;
        //char status[30] = "Success";
        int target = this->bsearch_account(user_account);
        char status[40];
        if(target == -1)
            strcpy(status,"*** Invalid account number ***");
        else if(type == 'D'){
            this->bank_account[target].process_deposit(amount);
            itoa(this->bank_account[target].get_balance(),status,10);
        }
        else{
            if(this->bank_account[target].process_withdrawal(amount))
                itoa(this->bank_account[target].get_balance(),status,10);
            else
                strcpy(status,"*** Insufficient funds ***");
        }
        cout << std::right << setw(5) << date << setw(12) << user_account << setw(3) << type << "     " << setw(10) << std::left << amount << status << endl;
    }
    cout << endl;
    Input.close();
};

void Bank::print(void)const{
    cout << "Account Listing for " << bank_name << '\n' << endl;
    for(int i = 0; i < this->accounts; i+=1){
        this->bank_account[order[i]].print();
    }
};