#include<iostream>
#include<bits/stdc++.h>
using namespace std;
string postfix(string s){
    stack<char> st;
    string post = "";
    map<char, int> mp;
    mp['+'] = 1;
    mp['-'] = 1;
    mp['*'] = 2;
    mp['/'] = 2;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == ' ')
            continue;
        if (s[i] >= 97 && s[i] <= 122)
            post = post + s[i];
        else if (st.empty())
            st.push(s[i]);
        else{
            if(mp[s[i]] > mp[st.top()])
                st.push(s[i]);
            else{
                while(!st.empty() && mp[s[i]] <= mp[st.top()]){
                    post = post + st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }
    }
    while(!st.empty()){
        post = post + st.top();
        st.pop();
    }
    return post;
}
string postfix2(string s){
    stack<char> st;
    string post = "";
    map<char, int> mp;
    mp['+'] = 1;
    mp['-'] = 1;
    mp['*'] = 2;
    mp['/'] = 2;
    for(int i = 97; i < 123; i++) mp[i] = 3;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == ' ')
            continue;
        if (st.empty())
            st.push(s[i]);
        else{
            if(mp[s[i]] > mp[st.top()])
                st.push(s[i]);
            else{
                while(!st.empty() && mp[s[i]] <= mp[st.top()]){
                    post = post + st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }
    }
    while(!st.empty()){
        post = post + st.top();
        st.pop();
    }
    return post;
}

int main(){
    string s;
    cout << "Enter the equation to convert to postfix : " ;
    getline(cin , s);
    string res = postfix2(s);
    cout << res;
    return 0;
}