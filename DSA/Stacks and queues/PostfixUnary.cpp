#include<iostream>
#include<bits/stdc++.h>
using namespace std;
string postfix(string s){
    stack<char> st;
    string post = "";
    map<char, int> mpin;
    map<char, int> mpout;
    mpin['+'] = 2;      mpout['+'] = 1;
    mpin['-'] = 2;      mpout['-'] = 1;
    mpin['*'] = 4;      mpout['*'] = 3;
    mpin['/'] = 4;      mpout['/'] = 3;   
    mpin['^'] = 5;      mpout['^'] = 6;
    mpin['('] = 0;      mpout['('] = 7;
                        mpout[')'] = 0;

    
    for(int i = 0; i < s.length(); i++){
        if(s[i] == ' ')
            continue;
        if ((s[i] >= 97 && s[i] <= 122) ||(s[i] >= 48 && s[i] <= 57))
            post = post + s[i];
        else if (st.empty())
            st.push(s[i]);
        else{
            
            if(mpout[s[i]] > mpin[st.top()])
                st.push(s[i]);
            else{
                while(!st.empty() && mpout[s[i]] < mpin[st.top()]){
                    post = post + st.top();
                    st.pop();
                }
                if(!st.empty() && mpout[s[i]] == mpin[st.top()])
                    st.pop();
                else
                    if(s[i] != ')')st.push(s[i]);
            }
        }   
    }
    while(!st.empty()){
        post = post + st.top();
        st.pop();
    }
    return post;
}
int Evaluate(string s){
    stack<int> st;
    int a, b, temp;
    for(int i = 0; i < s.length(); i++){
        if ((s[i] >= 48 && s[i] <= 57))
            st.push((int)s[i] - 48);
        else if(s[i] == '+'){
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            temp = b + a;
            st.push(temp);
        }
        else if(s[i] == '-'){
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            temp = b - a;
            st.push(temp);
        }
        else if(s[i] == '*'){
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            temp = b * a;
            st.push(temp);
        }
        else if(s[i] == '/'){
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            temp = b / a;
            st.push(temp);
        }
    }
    return st.top();
}
int main(){
    string s;
    cout << "Enter the equation to convert to postfix : " ;
    getline(cin , s);
    string res = postfix(s);
    cout << res << endl;
    cout << Evaluate(res) << endl;
    return 0;
}