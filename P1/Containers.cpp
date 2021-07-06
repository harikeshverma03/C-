#include<iostream>
#include <vector>
#include <bits/stdc++.h> 
using namespace std;

int main(){
    string in; map<int,int>m;
    int max = 0, min = 27;
    vector <int> vect;
    int count = 1;
    //getline(cin, in);
    in = "CBACBACBACBACBACBACBACBA";
    int n = in.length();
    int arr[1000];
    for(int i =0; i < n; i++){
        arr[i] = (int)in[i] - 64;
       // cout << arr[i] << endl;
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i]; 
    }
    vect.push_back(arr[0]);
    for(int i = 1; i<n;i++){
        if(arr[i] == arr[i-1])
            continue;
        else
            vect.push_back(arr[i]);
    }
    int len = vect.size();
    vector<vector<int> > vec;
    vector<int> sm;
    sm.push_back(vect[0]);
    vec.push_back(sm);
    sm.clear();
    for(int i = 1; i < len; i++){
        bool got = false;
        //cout << vec.size() << endl;
        for (int j = 0; j<vec.size(); j++){
              if(vec[j][vec[j].size()-1]>=vect[i]){
                vec[j].push_back(vect[i]);
                got=true;
                break;
            }
        }
        if(!got){
            sm.push_back(vect[i]);
            vec.push_back(sm);
            sm.clear();
        }
        }
        for(vector<int> i : vec){
        for(int j: i){
            cout << j << " ";
        }
        cout << "|||" << endl;
    }
        cout<< vec.size();
    return 0;
}