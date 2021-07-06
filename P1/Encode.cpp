#include<iostream>
#include <vector>
#include <bits/stdc++.h> 
using namespace std;
int main(){
    string str;
    getline(cin, str);
    vector<char> vect;
    //cout << str << endl;
    // stringstream s(str);
    int len = str.size();
    cout << len << endl;
    for (int i = 0; i < len; i++){
        if (((int)str[i] <= 122 && (int)str[i] >=97) || ((int)str[i] >=65 &&(int)str[i]  <= 90) || (int)str[i] ==32){
            vect.push_back(str[i]);
        }     
    }
    if(vect.size() == len){
        cout << str;
    }
    else{
        for(int i = vect.size() - 1; i >=0 ; i--){
            cout << vect[i];
        }
    }
    return 0;
}