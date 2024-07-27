#include <iostream>
#include "bank.h"
#include "account.h"
using namespace std;

int main() {
    // initialization test
    Account acc;
    acc.print();

    //acc.change_name("Josh");
    //acc.change_number("48763");
    //acc.process_deposit(105.23);
    //acc.print();
    //acc.process_withdrawal(25.87);
    //acc.print();
    //if(acc.process_withdrawal(500) == false)
    //    cout << "withdraw error" << endl;
    //acc.print();
    //Account a1, a2;
    //a1.change_number("1234567890");
    //a2.change_number("1234567899");
    ////cout << a1.cmp(a1) << endl;
    //cout << "cmp a1 and 1234567800" << a1.cmp("1234567890") << endl;

    Bank bank;
    bank.print();

    //return 0;

    //bank.read_accounts("X.txt"); // print an error message and exit the program

    bank.read_accounts("accounts.txt");

    bank.print();

    //bank.process_transactions("X.txt"); // print an error message and exit the program
    
    //cout << bank.bsearch_account("0") << '\n' << bank.bsearch_account("7307830409") << endl;

    bank.process_transactions("transactions.txt");

    bank.print();

    return 0;
}

