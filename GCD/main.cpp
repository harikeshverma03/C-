#include <iostream>
#include<cstdlib>
#include <bits/stdc++.h>
using namespace std;
int gcdnaive(int a, int b){
    int i = max(a,b);
    if (a==b){
        return a;
    }
    i--;
    while(true){
        if (a%i == 0 && b%i == 0)
            return i;
        else
            i--;
    }
}
int gcdone(int a, int b){
    int best;
    for( int i = 1; i < a+b; i++){
        if (a%i == 0 && b%i == 0)
            best = i;
    }
    return best;
}
int gcdeucledian(int a, int b){
    if (b==0 )
        return a;
    int ap = a%b;
    return (gcdeucledian(b,ap));
}
int main()
{

    cout << "Enter Two Number:" << endl;
    int a,b,i =0, j =0;
    a = 3918848;
    b = 1653264;
    //cin >> a >> b;
    /*
    srand(time(0));
    a = rand()%100+1;
    b = rand()%100+1;
    */
    //j = gcdnaive(a,b);
    j = gcdone(a,b);
     //j = gcdeucledian(a,b);
    printf("GCD of %d and %d is %d & %d", a, b,i, j);
    return 0;
}
