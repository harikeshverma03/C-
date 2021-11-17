#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define I INT_MAX
int cost[8][8] = {  {I,I,I,I,I,I,I,I},
                    {I,I, 25, I,I,I,5,I},
                    {I,25,I,12,I,I,I, 10},
                    {I,I,12,I,8,I,I,I},
                    {I,I,I, 8,I,16,I,14},
                    {I,I,I,I,16 ,I,20,18},
                    {I,5,I,I,I,20,I,I},
                    {I,I,10,I,14 ,18 ,I,I}};
int near[8] = {I,I,I,I,I,I,I,I};

int t[2][6];
int main (){
    int k, u, v, n = 7, mini = I;
    for(int i = 1; i <=n; i++)
        for(int j = i; j <= n; j++)
            if(cost[i][j] < mini){
                mini = cost[i][j];
                u = i; v = j;
            }
    t[0][0] = u;
    t[1][0] = v;
    cout << u << " " << v << endl;
    near[u] = near[v] = 0;
    for(int i = 1; i <= n; i++){
        if(cost[i][u] < cost[i][v] && near[i] != 0)
            near[i] = u;
        else if (near[i] != 0) 
            near[i] = v;
    }
    for(int i = 1; i <= n; i++)
        cout << near[i] << endl;
    for(int i = 1; i < n-1; i++){
        mini = I;
        for(int j = 1; j <= n; j++){
            if(near[j]!= 0 && cost[j][near[j]] < mini){
                mini = cost[j][near[j]];
                k = j;
            }
        }
        cout << k << " " << near[k] << endl;   
        t[0][i] = k; t[1][i] = near[k];
        near[k] = 0;
        for(int j = 1; j <= n; j++){
            if(cost[j][near[j] ] > cost[j][k] && near[j] != 0)
                near[j] = k;
        }
    }     
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < n-1; j++)
            cout << t[i][j] << " ";
        cout << endl;
    }
    
    cout << mini << endl;
}

/*
 int n, m, k;
    cin >> n >> m >> k;
    vector<int> chapters(n,0);
    vector<int> time(n,0);
    for(int i = 0; i < n; i++) cin >> chapters[i];
    for(int i = 0; i < n; i++) cin >> time[i];
    map<int, vector<int>> mp;
    for(int i = 0; i < n; i++){
        mp[chapters[i]].push_back(time[i]);
    }
    for(auto it: mp)
        sort(it.second.begin(), it.second.end());
    vector<int> subjects(m+1,0);
    int prevtime = *min_element(time.begin(), time.end());
    int prevsub;
    for(int i = 0; i < n; i++){
        if(time[i] == prevtime){
            prevsub = chapters[i];
            if(mp[prevsub].size() > 1) mp[prevsub].erase(mp[prevsub].begin());
            else mp.erase(prevsub);
            break;
        }
    }
    k = k - prevtime;
    subjects[prevsub]++;
    while(k > 0){
        int mini = INT_MAX, sub;
        for(int i = 1; i <= m; i++){
            if(i == prevsub) continue;
            if(mp.find(i) != mp.end()){
                int temp = *min_element(mp[i].begin(), mp[i].end());
                if(temp < mini){
                    mini = temp;
                    sub = i;
                }
            }
        }
        if(mp.find(prevsub) == mp.end()){
            k = k - mini;
            subjects[sub]++;
            prevtime = mini;
            prevsub = sub;
        }
        else{
            if(mp[prevsub].front() == mini){
                k = k - mini;
                subjects[sub]++;
                prevsub = sub;
                if(mp[prevsub].size() > 1) mp[prevsub].erase(mp[prevsub].begin());
                else mp.erase(prevsub);
            }
            else if(mp[prevsub].front() < mini){
                k = k - mp[prevsub].front();
                subjects[prevsub]++;
                prevtime = mp[prevsub].front();
                if(mp[prevsub].size() > 1) mp[prevsub].erase(mp[prevsub].begin());
                else mp.erase(prevsub);
            }
            else if(mp[prevsub].front() > mini){
                k = k - mini;
                subjects[sub]++;
                prevsub = sub;
                if(mp[prevsub].size() > 1) mp[prevsub].erase(mp[prevsub].begin());
                else mp.erase(prevsub);
                prevtime = mini;
            }
        }
        
    }
    if(k < 0){
        k = k + prevtime;
        subjects[prevsub]--;
    }
    int marks = 0;
    for(int i = 1; i <= m; i++){
        cout << subjects[i] << " ";
        marks = marks + ceil(subjects[i]/2.0);
    }
    cout << endl;
    cout << marks << endl;
*/