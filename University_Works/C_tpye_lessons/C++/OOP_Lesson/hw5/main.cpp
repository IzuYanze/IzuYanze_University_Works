#include<iostream>
#include"matrix.h"

using namespace std;

int main() {
	// 1. Testing identity matrix constructor
	cout << "1. Testing identity matrix constructor" << endl;

	Matrix m1;
	cout << "m1 = " << m1 << endl;
	cout << endl;

	// 2. Testing array initialization constructor
	cout << "2. Testing array initialization constructor" << endl;

	int arr2[2][2] = { {5,7} ,{3,2} };
	Matrix m2(arr2);
	cout << "m2 = " << m2 << endl;

	int arr3[2][2] = { {2,3} ,{1,4} };
	Matrix m3(arr3);
	cout << "m3 = " << m3 << endl;
	cout << endl;

	// 3. Testing determinant
	cout << "3. Testing determinant" << endl;
	cout << "det" << m2 << " = " << m2.determinant() << endl;
	cout << "det" << m3 << " = " << m3.determinant() << endl;
	cout << endl;
	
	// 3-1. Testing transpose
	cout << "3. Testing transpose" << endl;
	cout << "transpose of " << m2 << " is " << m2.transpose() << endl;
	cout << "transpose of " << m3 << " is " << m3.transpose() << endl;
	cout << endl;

	// 4. Testing matrix addition
	cout << "4. Testing matrix addition" << endl;
	cout << m2 << " + " << m3 << " = " << m2 + m3 << endl;
	cout << m3 << " + " << m2 << " = " << m3 + m2 << endl;
	cout << endl;

	// 5. Testing scalar multiplication
	cout << "5. Testing scalar multiplication" << endl;
	cout << m2 << " * 2 = " << m2 * 2 << endl;
	cout << "4 * " << m2 << " = " << 4 * m2 << endl;
	cout << m3 << " * 2 = " << m3 * 2 << endl;
	cout << "4 * " << m3 << " = " << 4 * m3 << endl;
	cout << endl;

	// 6. Testing matrix multiplication
	cout << "6. Testing matrix multiplication" << endl;
	cout << m2 << " * " << m3 << " = " << m2 * m3 << endl;
	cout << m3 << " * " << m2 << " = " << m3 * m2 << endl;
	cout << m3 << " * " << m1 << " = " << m3 * m1 << endl;
	cout << m1 << " * " << m3 << " = " << m1 * m3 << endl;

	if ((m2 * m3).determinant() == m2.determinant() * m3.determinant())
		cout << "det(m2 * m3) and det(m2) * det(m3) are equal" << endl;
	else
		cout << "det(m2 * m3) and det(m2) * det(m3) are  not equal" << endl;
	cout << endl;

	// 7. Testing relational operators
	cout << "7. Testing relational operators" << endl;

	if (m2 == m2)
		cout << m2 << " and " << m2 << " are equal" << endl;
	else
		cout << m2 << " and " << m2 << " are not equal" << endl;

	if (m2 != m3)
		cout << m2 << " and " << m3 << " are not equal" << endl;
	else
		cout << m2 << " and " << m3 << " are equal" << endl;

	if (m3 == m2)
		cout << m3 << " and " << m2 << " are equal" << endl;
	else
		cout << m3 << " and " << m2 << " are not equal" << endl;

	if (m1 != m3)
		cout << m1 << " and " << m3 << " are not equal" << endl;
	else
		cout << m1 << " and " << m3 << " are equal" << endl;
	cout << endl;

	// 8. Bonus
	cout << "8. Bonus" << endl;
	cout << endl;
	cout << "8-1. Testing matrix assign" << endl;
	Matrix m4;
	cout << "m4 = " << m4 << endl;
	m4 = m3;
	cout << "After assign m3 value to m4, it become : " << m4 << endl;
	cout << endl;

	cout << "8-2. Testing matrix increment and decrement" << endl;
	cout << "m4++ = " << m4++ << endl;
	cout << "and now m4 become : " << m4 << endl;
	cout << "m4-- = " << m4-- << endl;
	cout << "and now m4 become : " << m4 << endl;
	cout << "++m4 = " << ++m4 << endl;
	cout << "and now m4 become : " << m4 << endl;
	cout << endl;

	return 0;
}