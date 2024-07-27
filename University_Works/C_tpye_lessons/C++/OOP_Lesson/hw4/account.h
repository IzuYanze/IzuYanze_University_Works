#ifndef acccc
#define acccc
class Account{
    private:
        char account_number[11];
        char customer_name[21];
        double current_balace;
    
    public:
        Account(void);
        //This member function has no parameters. It should return the account number
        const char* get_account_number(void) const;
        // This member function has no parameters. It should return the current account balance.
        const double get_balance(void) const;
        //This member function should take a double deposit amount and add it to the balance for the bank account. It returns nothing.
        void change_name(const char*);
        void change_number(const char*);
        void process_deposit(const double &);
        //This member function should take a double withdrawal amount. 
        //If the bank account's balance is less than the withdrawal amount, 
        //the member function should just return false. 
        //Otherwise, subtract the withdrawal amount from 
        //the balance of the bank account and return true.
        const bool process_withdrawal(const double &);
        //This member function has no parameters and returns nothing
        void print(void) const;
        
        const int cmp(const Account &) const;
        const int cmp(const char*) const;
};
#endif
