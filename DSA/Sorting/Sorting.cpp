#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
struct Node{
  int val;
  Node*next;
};
void Bubble(vector<int> &A){
    int n = A.size();
    for(int i = 0; i < n-1; i++)
        for(int j = 0; j < n-i-1; j++)
            if(A[j] > A[j+1])
                swap(A[j], A[j+1]);
}
void Insertion(vector<int> &A){
    int n = A.size();
    for(int i = 1; i < n; i++){
        int t = A[i];
        int j = i-1;
        while(j >= 0 && A[j] > t){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = t;
    }
}
void Selection(vector<int> &A){
    int n = A.size();
    for(int i = 0; i <n; i++){
        int j = i, k = i;
        for(j = i; j < n; j++)
            if(A[j] < A[k])
                k = j;
        swap(A[i], A[k]);
    }
}
int Partition(vector<int> &A, int l, int h){
  int pivot = A[l];
  int i = l, j = h;
  do{
    do{i++;}while(A[i] <= pivot);
    do{j--;}while(A[j] > pivot);

    if(i < j)
      swap(A[i], A[j]);
  }while(i < j);

  swap(A[j], A[l]);
  return j;
}

void Quicksort(vector<int> &A, int l, int h){
  int j;
  if(l < h){
    j = Partition(A, l, h);
    Quicksort(A,l,j);
    Quicksort(A,j+1, h);
  }
}

void Quicksort(vector<int> &A){
  A.push_back(INT_MAX);
  Quicksort(A,0, A.size() - 1);
  A.pop_back();
}

void Countsort(vector<int> &A){
  int n = A.size();
  int max = *max_element(A.begin(), A.end());
  vector<int> vec(max + 1, 0);
  for(auto it: A)
    vec[it]++;
  int i = 0, j = 0;
  while(i <= max){
    if(vec[i] == 0)
      i++;
    else{
      A[j++] = i;
      vec[i]--; 
    }
  }
}
void Merge(vector<int> &A, int l, int mid, int h){
  int i, j, k;
  vector<int> B(h-l+1);
  i = l; j = mid+1;
  k = 0;
  while(i <= mid && j <= h){
    if(A[i] < A[j])
      B[k++] = A[i++];
    else
      B[k++] = A[j++];
  }
  while(i <= mid) B[k++] = A[i++];
  while(j <= h) B[k++] = A[j++];
  for(int i = 0; i < k; i++)
    A[l+i] = B[i];
}
void Mergesort(vector<int> &A, int l, int h){
  if(l < h){
    int mid = (l+h)/2;
    Mergesort(A, l, mid);
    Mergesort(A, mid+1, h);
    Merge(A,l,mid,h);
  }
}

void Mergesort(vector<int> &A){
  int n = A.size();
  int l, mid, h, p;
  for(p = 2; p <= n; p*=2)
    for(int i = 0; i + p -1< n; i+=p){
      l = i;
      h = i+p-1;
      mid = (l + h)/2;
      Merge(A,l,mid,h);
    }
  if(p/2 < n)
    Merge(A, 0, p/2-1,n-1);
}
void Binsort(vector<int> &A){
  int n = A.size();
  int max = *max_element(A.begin(), A.end());
  vector<Node*> bins(max + 1, nullptr);
  for(int i = 0; i < n; i++){
    Node *head = bins[A[i]];
    if(!head){
      Node*t = new Node();
      t->val = A[i];
      t->next = nullptr;
      bins[A[i]] = t;
    }
    else{
      
      while(head->next != nullptr)
        head = head->next;
      Node*t = new Node();
      t->val = A[i];
      t->next = nullptr;
      head->next = t;
    }
  }
  int i = 0, j = 0;
  while(i <= max){
    while(bins[i] != nullptr){
      Node*p= bins[i];
      int temp = bins[i]->val;
      if(bins[i]->next == nullptr){
        bins[i] = nullptr;
        delete(p);
      }
      else{
        Node *q = nullptr;
        while(p->next){
          q = p;
          p = p->next;
        }
        q->next = nullptr;
        delete(p);
      }
      A[j++] = temp;
    }  
    i++;
  }
}
void Shellsort(vector<int> &A){
  int n = A.size();
  int gap, i, j;
  for(gap = n/2; gap >= 1; gap/=2){
    for(i = gap; i < n; i++){
      int temp = A[i];
      j = i - gap;
      while(j >= 0 && A[j] > temp){
        A[j+gap] = A[j];
        j = j - gap; 
      }
      A[j + gap] = temp;
    }
  }
}
int main() {
    vector<int> vec;
    int i = 0, temp;
    while(cin){
      cin >> temp;
      if(cin)vec.push_back(temp);
    }
      cin >> vec[i++];
    Shellsort(vec);
    for(auto it: vec) cout << it << " ";
    return 0;
}
/*
ll n, d; cin >> n >> d;
  ll dup = n;
  ll temp = 0, next = 0, ans = 0, tenpow = 1;
  while(n > 0){
    int t = n%10;
    temp = t*tenpow + temp;
    if(t == d){
      next = (d+1)*tenpow;
      ans = next - temp;
    }
    tenpow = tenpow*10;
    n = n/10;
  }
  if(d== 0){
    temp = 0, next = 0, ans = 0, tenpow = 1, n = dup;
    while(n > 0){
      int t = n%10;
      temp = t*tenpow + temp;
      if(t == 0){
        next = tenpow;
        ans = next + ans;
      }
      n = n/10;
      tenpow = tenpow *10;
    }
  }
  
  cout << ans << endl;




  ll n, k; cin >> n >> k;
  vector<int> vec(n,0);
  for(int i = 0; i < n; i++) cin >> vec[i];
  int arr[n+2] = {0};
  for(int i = 0; i < n; i++){
    if(vec[i] == 0)
      arr[1]++;
    else
      arr[0]++;
  }
  if(arr[0] == k){
    cout << 0 << endl;
    return;
  }
  int sieve[n+2] = {0};
  for(int i = 0; i < n; i++){
    sieve[vec[i]] = 1;
    int mex = 0;
    if(vec[i] == 0) mex =1;
    for(int j = i+1; j < n;j++){
      sieve[vec[j]] = 1;
      if(sieve[mex] == 0)
        arr[mex]++;
      else{
        int k;  
        for(k = mex; k <= n+1; k++)
          if(sieve[k] ==  0)
            break;
        mex = k;
        arr[mex]++;
      }
    }
    for(int p = 0; p <= n+1; p++)
      sieve[p] = 0;
  }
  int sum = 0;
  for(int i = 0; i <=n+1; i++){
    sum = sum + arr[i];
    if(sum >= k){
      cout << i << endl;
      return;
    }
  }



  ll n, q; cin >> n >> q;
  vector<vector<ll>> medals(n, vector<ll>(3,0));
  vector<int> que(q);
  for(int i = 0; i < n; i++){
    for(int j = 0; j < 3; j++) cin >> medals[i][j];
  }
  for(int i = 0; i<q; i++) cin >> que[i];




   ll m, n;
  cin >> m;
  ll c[m];
  for(int i = 0; i <m; i++){
    cin >> c[i];
    c[i] = c[i] - 998244353;
  }
  cin >> n;
  int a[n][n];
  for(int i = 0; i < n; i++){
    for(int j= 0; j < n; j++){
      cin >> a[i][j];
    }
  }

  for(int i = 0; i < m; i++){
    
  }
*/