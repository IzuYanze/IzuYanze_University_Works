#include "CustomerList.h"

#include <iostream>

using namespace std;

void CustArray::do_resize(int sz) {
	Customer** tmp = new Customer * [sz];
	int i;
	int copynum = (arsize < sz ? arsize : sz);
	// Copy existing fields
	for (i = 0; i < copynum; i++) tmp[i] = ar[i];
	// Initialize additional fields (if growing)
	for (i = copynum; i < sz; i++) tmp[i] = NULL;
	delete[] ar;
	ar = tmp;
	arsize = sz;
}

void CustArray::init(int sz) {
	// assert (sz > 0);
	arsize = sz;
	ar = new  Customer* [arsize];
	int i;
	for (i = 0; i < arsize; i++) ar[i] = NULL;
}

Customer* CustArray::do_at(int pos) {
	if (pos >= arsize || pos < 0); // Index out of bounds
	return ar[pos];
}

void CustArray::do_remove(int pos) {
	if (pos >= arsize || pos < 0); // Index out of bounds
	if (ar[pos] != NULL) ar[pos] = NULL;
}

void CustArray::do_to(int pos, Customer* val) {
	if (pos >= arsize || pos < 0); // Index out of bounds
	ar[pos] = val;
}

CustArray::CustArray(int sz) { init(sz); }
CustArray::CustArray(void) { init(100); }
CustArray::~CustArray(void) { delete[] ar; }