#include <iostream>
#include <stdlib.h>
#include "matrix.h"
using namespace std;

//constructors and destructor
Matrix::Matrix(void): data{{1,0},{0,1}}{};

Matrix::Matrix(const int Array[2][2]): data{{Array[0][0],Array[0][1]},{Array[1][0],Array[1][1]}} {};
Matrix::~Matrix(){};
//public function
const int Matrix::determinant(void) const{
    return (this->data[0][0] * this->data[1][1] - this->data[1][0] * this->data[0][1]);
};
const Matrix Matrix::transpose(void) const{
    int temp[2][2];
    temp[0][0] = this->data[0][0];
    temp[0][1] = this->data[1][0];
    temp[1][0] = this->data[0][1];
    temp[1][1] = this->data[1][1];
    Matrix Ans(temp);
    return Ans;
}
//overloadings
const Matrix Matrix::operator+(const Matrix &Right) const{
    int a=this->data[0][0] + Right.data[0][0];
    int b=this->data[0][1] + Right.data[0][1];
    int c=this->data[1][0] + Right.data[1][0];
    int d=this->data[1][1] + Right.data[1][1];
    int temp[2][2] = {{a,b},{c,d}};
    Matrix Ans(temp);
    return Ans;
};
const Matrix Matrix::operator*(const int &num) const{
    int temp[2][2];
    temp[0][0] = this->data[0][0] * num;
    temp[0][1] = this->data[0][1] * num;
    temp[1][0] = this->data[1][0] * num;
    temp[1][1] = this->data[1][1] * num;
    Matrix Ans(temp);
    return Ans;
};
const Matrix Matrix::operator*(const Matrix &Right) const{
    int temp[2][2];
    temp[0][0] = this->data[0][0] * Right.data[0][0] + this->data[0][1] * Right.data[1][0] ;
    temp[0][1] = this->data[0][0] * Right.data[0][1] + this->data[0][1] * Right.data[1][1] ;
    temp[1][0] = this->data[1][0] * Right.data[0][0] + this->data[1][1] * Right.data[1][0] ;
    temp[1][1] = this->data[1][0] * Right.data[0][1] + this->data[1][1] * Right.data[1][1] ;
    Matrix Ans(temp);
    return Ans;
};
const bool Matrix::operator==(const Matrix &Right) const{
    if(this->data[0][0] == Right.data[0][0] && this->data[0][1] == Right.data[0][1] && 
        this->data[1][0] == Right.data[1][0] && this->data[1][1] == Right.data[1][1])
        return true;
    else
        return false;
};
const bool Matrix::operator!=(const Matrix &Right) const{
    return !(*this == Right);
};
//also overloadings
std::ostream & operator<<(ostream &output, const Matrix &Ma){
    output << "[[" << Ma.data[0][0] << ", " << Ma.data[0][1] << "], [" << Ma.data[1][0] << ", " << Ma.data[1][1] << "]]" << flush;
    return output;
};
Matrix operator*(const int &num , const Matrix &Ma){
    int temp[2][2];
    temp[0][0] = Ma.data[0][0] * num;
    temp[0][1] = Ma.data[0][1] * num;
    temp[1][0] = Ma.data[1][0] * num;
    temp[1][1] = Ma.data[1][1] * num;
    Matrix Ans(temp);
    return Ans;
};
//Bonus overloading
Matrix& Matrix::operator=(const Matrix &Right){
    this->data[0][0] = Right.data[0][0];
    this->data[0][1] = Right.data[0][1];
    this->data[1][0] = Right.data[1][0];
    this->data[1][1] = Right.data[1][1];
    return *this;
}
Matrix& Matrix::operator++(){
    this->data[0][0] += 1;
    this->data[0][1] += 1;
    this->data[1][0] += 1;
    this->data[1][1] += 1;
    return *this;
}
Matrix Matrix::operator++(int){
    Matrix temp = *this;
    this->data[0][0] += 1;
    this->data[0][1] += 1;
    this->data[1][0] += 1;
    this->data[1][1] += 1;
    return temp;
}
Matrix& Matrix::operator--(){
    this->data[0][0] -= 1;
    this->data[0][1] -= 1;
    this->data[1][0] -= 1;
    this->data[1][1] -= 1;
    return *this;
}
Matrix Matrix::operator--(int){
    Matrix temp = *this;
    this->data[0][0] -= 1;
    this->data[0][1] -= 1;
    this->data[1][0] -= 1;
    this->data[1][1] -= 1;
    return temp;
}