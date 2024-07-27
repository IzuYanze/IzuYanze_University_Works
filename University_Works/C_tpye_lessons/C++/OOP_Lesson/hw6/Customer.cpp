#include <iostream>
#include <stdlib.h>
#include <cstring>
#include "Customer.h"

using namespace std;

//==========================static initailize============================
int Customer::customer_count = 0;
int Customer::customer_live = 0;
int OrdinaryCustomer::Ocustomer_count = 0;
int OrdinaryCustomer::Ocustomer_live = 0;
int PremiumCustomer::Pcustomer_count = 0;
int PremiumCustomer::Pcustomer_live = 0;
//==========================Origin============================
const char* Customer::OrdinaryNumber(const int &number) const{
    if( (number)%10 == 1 && number != 11)
        return "st";
    else if( (number)%10 == 2 && number != 12)
        return "nd";
    else if( (number)%10 == 3 && number != 13)
        return "rd";
    else 
        return "th";
}

Customer::Customer(const string f, const string s, const string t): 
        first_name(f), surname(s), town(t), customer_order(customer_count+1) {
    
    Customer::customer_count++;
    Customer::customer_live++;
};

Customer::Customer(const Customer &c): 
        first_name(c.first_name), surname(c.surname), town(c.town), 
        customer_order(customer_count+1) {
    cout << "Calling the copy constructor to copy data from: "
         << this->first_name << ' ' << this->surname << ", at " << this->town << '.' <<endl;
    Customer::customer_count++;
    Customer::customer_live++;
};

Customer::~Customer(void){};

void Customer::christmasPresent(void){
    cout << this->first_name << ' ' << this->surname << ", at " << this->town  << "." << endl;
};
//==========================Ordinary============================
OrdinaryCustomer::OrdinaryCustomer(const string f, const string s, const string t,const string b):
        Customer(f,s,t), favorite_beer_brand(b), Ocustomer_order(Ocustomer_count+1) {
    OrdinaryCustomer::Ocustomer_count++;
    OrdinaryCustomer::Ocustomer_live++;
    cout << "This is the "<< OrdinaryCustomer::Ocustomer_order 
        << this->OrdinaryNumber(OrdinaryCustomer::Ocustomer_order)
        <<" OrdinaryCustomer, and " << this->Cus_order() 
        << this->OrdinaryNumber(this->Cus_order())
        << " Customer." << endl;
};

OrdinaryCustomer::OrdinaryCustomer(const OrdinaryCustomer &c): 
        Customer(c), favorite_beer_brand(c.favorite_beer_brand), 
        Ocustomer_order(Ocustomer_count+1) {
    OrdinaryCustomer::Ocustomer_count++;
    OrdinaryCustomer::Ocustomer_live++;
    cout << "This is the "<< OrdinaryCustomer::Ocustomer_order 
        << this->OrdinaryNumber(OrdinaryCustomer::Ocustomer_order)
        <<" OrdinaryCustomer, and " << this->Cus_order() 
        << this->OrdinaryNumber(this->Cus_order())
        << " Customer." << endl;
};

OrdinaryCustomer::~OrdinaryCustomer(void){
    OrdinaryCustomer::Ocustomer_live--;
    Customer::customer_live--;
    cout << "Survived " << OrdinaryCustomer::Ocustomer_live << " OrdinaryCustomer, and "
         << Customer::customer_live << " Customer." << endl;
    
}


void OrdinaryCustomer::christmasPresent(void){
    cout << this->first_name << ' ' << this->surname << ", at " << this->town  << "." << endl;
    cout << "This is the "<< OrdinaryCustomer::Ocustomer_order 
        << this->OrdinaryNumber(OrdinaryCustomer::Ocustomer_order)
        <<" OrdinaryCustomer, and " << this->Cus_order() 
        << this->OrdinaryNumber(this->Cus_order())
        << " Customer." << endl;
    cout << "Please send one bottle " << this->favorite_beer_brand
         << " using ordinary present wrapper." << endl;
};
//==========================Premium============================
PremiumCustomer::PremiumCustomer(const string f, const string s, const string t,const string w):
        Customer(f,s,t), favorite_wine_brand(w), Pcustomer_order(Pcustomer_count+1) {
    PremiumCustomer::Pcustomer_count++;
    PremiumCustomer::Pcustomer_live++;
    cout << "This is the "<< PremiumCustomer::Pcustomer_order 
        << this->OrdinaryNumber(PremiumCustomer::Pcustomer_order)
        <<" PremiumCustomer, and " << this->Cus_order() 
        << this->OrdinaryNumber(this->Cus_order())
        << " Customer." << endl;
};

PremiumCustomer::PremiumCustomer(const PremiumCustomer &c):
        Customer(c), favorite_wine_brand(c.favorite_wine_brand),
        Pcustomer_order(Pcustomer_count+1){
    PremiumCustomer::Pcustomer_count++;
    PremiumCustomer::Pcustomer_live++;
    cout << "This is the "<< PremiumCustomer::Pcustomer_order 
        << this->OrdinaryNumber(PremiumCustomer::Pcustomer_order)
        <<" PremiumCustomer, and " << this->Cus_order() 
        << this->OrdinaryNumber(this->Cus_order())
        << " Customer." << endl;
};

PremiumCustomer::~PremiumCustomer(void){
    PremiumCustomer::Pcustomer_live--;
    Customer::customer_live--;
    cout << "Survived " << PremiumCustomer::Pcustomer_live << " PremiumCustomer, and "
         << Customer::customer_live << " Customer." << endl;
}

void PremiumCustomer::christmasPresent(void){
    cout << this->first_name << ' ' << this->surname << ", at " << this->town  << "." << endl;
    cout << "This is the "<< PremiumCustomer::Pcustomer_order 
        << this->OrdinaryNumber(PremiumCustomer::Pcustomer_order)
        <<" PremiumCustomer, and " << this->Cus_order() 
        << this->OrdinaryNumber(this->Cus_order())
        << " Customer." << endl;
    cout << "Please send one bottle " << this->favorite_wine_brand
         << " using premium present wrapper." << endl;
};
