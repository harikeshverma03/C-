#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define I INT_MAX

int main(){


    class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int rs = 0, re = n-1;
        int rs = 0, re = n-1;
        while(rs < re){
            for(int i = 0; i <= re-rs-1;i++){
                int temp = matrix[rs+i][re];
                matrix[rs+i][re] = matrix[rs][rs+i];
                matrix[rs][rs+i] = matrix[re - i][rs];
                matrix[re - i][rs] = matrix[re][re-i];
                matrix[re][re-i] = temp;
            }
            rs++; re--;
            rs++; re--;
        }
    }
};
    return 0;
}