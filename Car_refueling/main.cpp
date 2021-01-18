#include <iostream>

using namespace std;
int car_refueling(int x[], int L , int n)
{
    int numrefill = 0;int curefill = 0; int lastrefill = 0;
    while (curefill <= n){
        lastrefill = curefill;
        while(curefill <= n && (x[curefill + 1] - x[lastrefill] <= L))
            curefill++;
        if (curefill == lastrefill)
            return -1;
        if (curefill <= n)
            numrefill++;

        }
        return numrefill;
}
int main()
{
    cout << "Hello world!" << endl;
    int n,L;
    int x[] = {0,25,50,60,75,100};
    n = 4;
    L = 25;
    cout << car_refueling(x,L,n) << endl;
    return 0;
}
