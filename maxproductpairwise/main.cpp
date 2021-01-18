#include <iostream>
#include<vector>
#include <bits/stdc++.h>
#include<deque>
#include<cstdlib>

using namespace std;
int maxpairvectorsort(vector<int> &vect){
    sort(vect.begin(), vect.end());
    int n = vect.size();
    return (vect[n-1]*vect[n-2]);
}
void arraysort(){
    int array[] = { 23, 5, -10, 0, 0, 321, 1, 2, 99, 30 };
    int size = sizeof(array) / sizeof(array[0]);
    sort(array, array +size);
    cout << size << endl;
    for (size_t i = 0; i < size; ++i) {
     cout << array[i] << ' ';
    }
    cout << endl;

}
int maxpairtwo(vector<int> &vect){
int n = vect.size();
int max1 = -1, max2 = -1;
for(int i = 0; i < n ;i++){
    if ((max1 == -1)|| (vect[i] > vect[max1])){
        max1 = i;
    }
}
for(int i = 0; i < n ;i++){
    if(i == max1){
        continue;
    }
    if ((max2 == -1) || (vect[i] > vect[max2]) ){
        max2 = i;
    }
}
// cout << max1 << " " << max2 << endl;
return (vect[max1] * vect[max2]);
}
int maxpairdeque(vector<int> &vect){
deque<int> deq;
int n = vect.size();
if(vect[0] > vect[1]){
    deq.push_back(0);
    deq.push_back(1);
}
else if (vect[1] >= vect[0]){
    deq.push_back(1);
    deq.push_back(0);
}
for( int i = 2; i < n; i++){
    if(vect[i] > vect[deq.front()]){
       deq.push_front(i);
       deq.pop_back();
    }
    else if(vect[i] > vect[deq.back()]){
        deq.pop_back();
        deq.push_back(i);
    }
}
return (vect[deq.front()]*vect[deq.back()]);
}
void stresstest(){
    srand(time(0));
    while(true){
        int n = rand()%10000 + 2;
        cout << n << endl;
        vector<int> a;
        for(int i = 0; i < n; i++){
            a.push_back(rand()%1000);
        }
        for (int i = 0; i < n; i++){
            cout << a[i] << " ";
        }
        cout << "\n" << endl ;
        int res1 = maxpairdeque(a);
        int res2 = maxpairtwo(a);
        if (res1 != res2){
            cout << "Wrong Answer" << endl;
            break;
        }
        else{
            cout << "Right Answer = " << res1 << " & " << res2 << endl;
            break;
        }

    }
}
int main()
{
    stresstest();
    int n;
    cin >> n;
    vector<int> vect;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        vect.push_back(temp);
    }

    // vector<int> vect(100000,2);
    int temp = maxpairdeque(vect);
    cout << temp << endl;
    return 0;
}
