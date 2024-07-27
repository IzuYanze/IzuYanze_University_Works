#include <iostream>
#include "CustomerList.h"
using namespace std;

int main(void) {
	int i = 0;
	CustomerList* list = new CustomerList();
	list->to(i, new OrdinaryCustomer("Vivian", "Wang", "Taichung", "Holsten"));
	++i;
	list->to(i, new PremiumCustomer("Sam", "Lee", "Kaohsiung", "Bordeaux"));
	++i;
	list->to(i, new OrdinaryCustomer("John", "Chen", "Taipei", "Ginger Ale"));
	
	// Produce outputs (Write messages for the secretary) - fill in the code here
	//========================================================//
	cout << endl;
	list->at(0)->christmasPresent();
	cout << endl;
	list->at(1)->christmasPresent();
	cout << endl;
	list->at(2)->christmasPresent();
	cout << endl;
	//========================================================//

	// Release previously allocated memory - fill in the code here
	//========================================================//
	list->at(i)->~Customer();
	list->remove(i);
	--i;
	list->at(i)->~Customer();
	list->remove(i);
	--i;
	list->at(i)->~Customer();
	list->remove(i);
	--i;
	//========================================================//
	
	delete list;
	return 0;
}