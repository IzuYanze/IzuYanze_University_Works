#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <iostream>

// An abstract class for a Customer.
// Add to this class what is necessary
class Customer{
    //how many customer accounted
    static int customer_count;
    //the number of account order when accounted
    const int customer_order;
protected:
    //how many customer now
    static int customer_live;
    //just return order (since it is private, it should call by derived)
    const int Cus_order(void) const{return customer_order;};
    //just to return 1st, 2nd, 3rd, 4th, etc.
    const char* OrdinaryNumber(const int&)const;
    std::string first_name;
    std::string surname;
    std::string town;
public:
    // Create a customer with:
    // f: first name
    // s: surname
    // t: town
    Customer(const std::string f, const std::string s, const std::string t);
    // Create a customer copying the properties from another object
    // c: a reference to the other Customer object
    Customer(const Customer &c);
    // Release previously allocated memory
    virtual ~Customer();
    // Write a message for the secretary, common part
    virtual void christmasPresent(void);
    //this is only for testing
    //static void printnum() {std::cout << customer_live << std::endl;}; 
};
class OrdinaryCustomer : public Customer{
    static int Ocustomer_count;
    static int Ocustomer_live;
    const int Ocustomer_order;
protected:
    std::string favorite_beer_brand;
public:
    // Create an ordinary customer with:
    // f: first name
    // s: surname
    // t: town
    // b: favorite beer brand
    OrdinaryCustomer(const std::string f, const std::string s, const std::string t,const std::string b);
    // Create an ordinary customer copying the properties from another object
    // c: a reference to the other OrdinaryCustomer object
    OrdinaryCustomer(const OrdinaryCustomer &c);
    // Release previously allocated memory
    ~OrdinaryCustomer();
    // Write a message for the secretary, particular part
    void christmasPresent(void);
};
class PremiumCustomer : public Customer{
    static int Pcustomer_count;
    static int Pcustomer_live;
    const int Pcustomer_order;
protected:
    std::string favorite_wine_brand;
public:
    // Create a premium customer with:
    // f: first name
    // s: surname
    // t: town
    // w: favorite wine brand
    PremiumCustomer(const std::string f, const std::string s, const std::string t,const std::string w);
    // Create a premium customer copying the properties
    // from another object
    // c: a reference to the other PremiumCustomer object
    PremiumCustomer(const PremiumCustomer &c);
    // Release previously allocated memory
    ~PremiumCustomer();
    // Write a message for the secretary, particular part
    void christmasPresent(void);
    //this is only for testing
    //static void printnumP() {std::cout << Pcustomer_live << std::endl;}; 
};

#endif // CUSTOMER_H