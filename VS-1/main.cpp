#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT 
    WE always have to give size while creation of vectors  otherwise segmentation fault will occur*/   
    long n, q;
    cin >> n;
    cin >> q;
    vector<vector<long>> a( n , vector<long> (10000000,0)); 
    vector<long> b(q);
    //cout << b.max_size() << endl;
    for (long i = 0;i < n; i++){
        long count;
        cin >> count;
        for (long j = 0; j < count; j++){
            scanf("%ld", &a[i][j]);
        }
    }
    
    for(long i = 0; i < q; i++){
        long x,y;
        cin >> x;
        cin >> y;
        b[i] = a[x][y];
    }
    for(long i = 0; i < q; i++){
        cout << b[i] << endl;
    }
    return 0;
}