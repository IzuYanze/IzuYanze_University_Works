#ifndef BK
#define BK

#include "account.h"

class Bank{
    private:
        char bank_name[31];
        Account bank_account[20];
        int accounts;
        int order[20];
        void sort_accounts(void);
        int bsearch_account(const char*);
    public:
        //construct the bank
        Bank(void);
        //This member function takes one parameter,
        //a string that contains the name of a file.
        //This string parameter can be a C/C++ string. 
        //The function returns nothing.
        void read_accounts(const char*);
        void process_transactions(const char*);
        void print(void)const;
};


#endif