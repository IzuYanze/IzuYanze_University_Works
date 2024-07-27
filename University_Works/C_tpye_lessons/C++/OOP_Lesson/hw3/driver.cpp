// driver.cpp -- driver program to demonstrate the behavior of
// the Triangle class
#include <iostream>
#include <iomanip>
#include "triangle.h"
using namespace std;

int main()
{
    cout << "-----------------Test Start-----------------\n";

    cout << "1. different triangles test\n";
    Triangle t_size_only(-5); // with negative size(set to 1)
    Triangle t_size_border(4,'x'); // with normal size
    Triangle t_all(40,'-','+'); // with size to big(set to 39)
    Triangle t_invalid_border(4,'\a','!'); // with unallowed border(set to '#')
    Triangle t_invalid_fill(4,'~','\0'); // with unallowed fill(set to '*')
    Triangle t_invalid_both(4,'\a','\0'); // with unallowed border(set to '#') and fill(set to '*')
    Triangle t_num2char(4,33,16); // num_to_char as border and fill is ok 
    Triangle t_char2num('!','+'); // char_to_num as size is ok
    t_size_only.Summary();
    t_size_border.Summary();
    t_all.Summary();
    t_invalid_border.Summary();
    t_invalid_fill.Summary();
    t_invalid_both.Summary();
    t_num2char.Summary();
    t_char2num.Summary();
    cout << "1. finish\n\n";

    cout << "2. function stress test\n";
    Triangle t_func(0,'/','\\');
    register int i;
    // Area() should return double value with default precision (6)
    for(i = 0; i < 39; i++){ // 39 times to check overgrow(shrink) 
        cout << "Size : " << t_func.GetSize() << ", Parameter = " << t_func.Perimeter() << ", Area = " << t_func.Area() << '\n';
        t_func.Grow();
    }
    for(i = 0; i < 39; i++){
        cout << "Size : " << t_func.GetSize() << ", Parameter = " << t_func.Perimeter() << ", Area = " << t_func.Area() << '\n';
        t_func.Shrink();
    }
    // Set all Area with Precision 2 decimal places(i.e 12.301 should be set to 12.30, not 12.3)
    for(i = 0; i < 39; i++){
        cout << "Here is a summary for t_func with size : " << t_func.GetSize() << '\n';
        t_func.Summary();
        t_func.Grow();
    }
    cout << "2. finish\n\n";

    return 0;
    }