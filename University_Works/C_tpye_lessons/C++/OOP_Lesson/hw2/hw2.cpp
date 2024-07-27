#include <iostream>
#include <fstream>
#include <sys/time.h>
using namespace std;

#define MAX_AREA 8 //this is the max length of y seq
#define h 200 //as the hint

class lake{
    int Area[MAX_AREA+1];
    int licenses;
public:
    lake(int array[]);
    ~lake(void);
    void cal_licenses(void);
    int get_licenses(void);
};

int main(int argc, char *argvs[]){
    //time cal start
    struct timeval start , end;
    gettimeofday(&start,NULL);

    int Input[9];//input buffer

    cout << "Hello, this is a program to help you calculate the following website's[https://www.cs.ccu.edu.tw/~damon/secure/course-wk.html] HW2."
         << '\n' << "We assume that you will give me 9 space-delimited integers of y and the h is 200ft" << endl;
    
    if(argc == 1){//if no command line file, read from stdin
        cout << "Please enter the 9 integers :";
        cin >> Input[0] >> Input[1] >> Input[2] >> Input[3] >> Input[4] >> Input[5] >> Input[6] >> Input[7] >> Input[8] ;
    }
    else{//reading from file
        cout << "Argument dectected, " ;
        if(argc > 2){//if argument have more
            cout << "but emerge arguments error. sad :( " << endl;
            exit(1);
        }
        ifstream txt;
        txt.open(argvs[1]);
        if(txt.fail()){//if fail to open
            cout << "but fail to open the file. sad :( " << endl;
            exit(1);
        }
        //if open success
        txt >> Input[0] >> Input[1] >> Input[2] >> Input[3] >> Input[4] >> Input[5] >> Input[6] >> Input[7] >> Input[8] ;
        txt.close();
        cout << "and succesfully read the file! cheers! :D" << endl;
    }
    //cout << Input[0] << Input[1] << Input[2] << Input[3] << Input[4] << Input[5] << Input[6] << Input[7] << Input[8] << endl;
    
    //main function
    lake warden(Input);
    warden.cal_licenses();

    //output
    cout << "The maximum number of fishing licenses that can be sold is : " << warden.get_licenses() << endl;

    //show time
    gettimeofday(&end,NULL);
    unsigned long time = 1000000 * (end.tv_sec-start.tv_sec)+ end.tv_usec-start.tv_usec;
    cout << "This program execute in " << time << " miliseconds." << endl;
    return 0;
}

lake::lake(int array[9]){
    for(int i=0;i<9;i++)
        this->Area[i] = array[i];
}

void lake::cal_licenses(void){
    //calculate the fish count with 20 per unit
    int fish_20 = (this->Area[0] + 4*(this->Area[1]) + 2*(this->Area[2]) + 4*(this->Area[3]) + 2*(this->Area[4]) + 4*(this->Area[5]) + 2*(this->Area[6]) + 4*(this->Area[7]) + this->Area[8]) *200 / 3000 ;
    //cal the licenses
    this->licenses = fish_20 * 3 / 4;
}

int lake::get_licenses(void){
    return licenses;
}

lake::~lake(){}