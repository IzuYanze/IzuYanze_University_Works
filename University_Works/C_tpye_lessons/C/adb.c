#include <stdio.h>

int gcd(int x, int y){
    if(x >=y )
        return !y ? x : gcd(y,x%y);
    else
        return !x ? y : gcd(x,y%x);

}

int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    printf("%d",gcd(a,b));
    return 0;
}