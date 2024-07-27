#include "triangle.h"
#include <iostream>
#include <iomanip>
using namespace std;

#define ROOT3 1.73205080757

Triangle::Triangle(int s) : side(s), border('#'), fill('*') {
    if(s < 1)
        side = 1;
    else if (s > 39)
        side = 39;
};

Triangle::Triangle(int s, char b) : side(s), border(b), fill('*') {
    if(s < 1)
        side = 1;
    else if (s > 39)
        side = 39;
};

Triangle::Triangle(int s, char b, char f) : side(s), border(b), fill(f) {
    if(s < 1)
        side = 1;
    else if (s > 39)
        side = 39;
};

Triangle::~Triangle(){};

int Triangle::GetSize(void){
    return this->side;
};

int Triangle::Perimeter(void){
    return (this->side) * 3;
};

double Triangle::Area(void){
    return (double)((this->side) * (this->side)) * ROOT3 / 4;
};

void Triangle::Grow(void){
    this->side ++;
    if(this->side > 39)
        this->side = 39;
};

void Triangle::Shrink(void){
    this->side --;
    if(this->side < 1)
        this->side = 1;
};

void Triangle::SetBorder(char c){
    if(c > 126 || c < 33)
        c = '#';
    this->border = c;
};

void Triangle::SetFill(char c){
    if(c > 126 || c < 33)
        c = '*';
    this->fill = c;
};

void Triangle::Draw(void){
    for(int i=0; i<this->side; i++){
        for(int j=0; j < this->side-i; j++)
            cout << ' ';
        cout << this->border ;
        for(int j=1; j <= i; j++){
            if( j == i || i == this->side-1 )
                cout << ' ' << this->border ;
            else
                cout << ' ' << this->fill ; 
        }
        cout << endl;
    }
};

void Triangle::Summary(void){
    cout << "Size of triangle's side = " << this->side << " units." << endl;
    cout << "Perimeter of triangle = " << this->Perimeter() << " units." << endl;
    cout << "Area of triangle = " << fixed << setprecision(2) << this->Area() << " units." << endl;
    cout << "Triangle looks like:" << endl;
    this->Draw();
};



void Triangle::SetName(const char* newname){
    int i;
    for(i = 0; newname[i]!='\0'; i++)
        this->name[i] = newname[i];
    this->name[i] = '\0';
};
void Triangle::GetName(char* myname){
    int i;
    for(i = 0; this->name[i]!='\0'; i++)
        myname[i] = this->name[i];
    myname[i] = '\0';
}