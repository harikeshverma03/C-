#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
   
    int t;
    cin>>t;
    while(t){
         vector<int> dp;
        long long n;
        long long answer = 0;
        cin>>n;
        while(n){
            int temp =  n % 8;
            dp.push_back(temp);
            n = n / 8;
        }
        for(int i = dp.size() - 1; i >= 0; i--){
            answer = answer  * 10 + dp[i];
        }
        t--;
        cout<<answer<<endl;
    }
    
    return 0;
}