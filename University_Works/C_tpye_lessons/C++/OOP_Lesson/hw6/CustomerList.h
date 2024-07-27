#ifndef CUSTOMER_LIST_H
#define CUSTOMER_LIST_H

#include "Customer.h"

class CustArray {
private:
	Customer** ar;
	int arsize;
	void init(int);

protected:
	void do_resize(int);
	int do_size(void) { return arsize; }
	Customer* do_at(int);
	void do_remove(int);
	void do_to(int, Customer*);

public:
	CustArray(int);
	CustArray(void);
	~CustArray(void);
};

class CustomerList : public CustArray {
public:
	// Creates an empty customer list
	CustomerList(void) {}

	// Does nothing
	~CustomerList(void) {}

	// Returns a copy of the Customer at position pos
	Customer* at(int pos) { return do_at(pos); }

	// Removes the Customer from position pos
	void remove(int pos) { do_remove(pos); }

	// Enters a Customer to position pos
	void to(int pos, Customer* val) { do_to(pos, val); }

	// Returns the current size
	int size(void) { return do_size(); }

	// Resizes the list to sz discarding existing entries
	void resize(int sz) { do_resize(sz); }
};
#endif // CUSTOMER_LIST_H