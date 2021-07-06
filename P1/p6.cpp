#include<stdio.h>
#include<bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    vector<int> A;
    int n;
    cin >> n;
    for(int i = 0 ; i < n; i++){
        int temp;
        cin >> temp;
        A.push_back(temp);
    }
        
    int len = A.size();
        int flag = 0;
        vector<int> vec(len);
        iota(vec.begin(), vec.end(), 0);
        reverse(vec.begin(), vec.end());
        if (len == 1)
            return true;
        int local, global;
        local = global = 0;
        for(int i = 0; i < len - 1; i++){
            if (A[i+1] < A[i])
                local++;
            for(int j = i+1; j < len; j++){
                if (A[j] < A[i]){
                    global++;
                }
            }
            
        }
        cout << local << " " << global << endl;
        for (int i = 0; i < len; i++){
        cout << vec[i] << " ";
    }
    cout << endl;
}