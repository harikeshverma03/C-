#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define SIZE 10

int hash1(int key){
    return key%10;
}
int probe(int h[], int key){
    int index = key%10;
    int i = 0;
    while(h[(index + i) % SIZE] != 0 && i < SIZE)
        i++;
    if (i == SIZE) return -1;
    return (index + i) % SIZE;
}
void Insert(int h[], int t){
    int index = hash1(t);
    if(h[index] == 0){
        h[index] = t;
        return;
    }
    else{
        index = probe(h, t);
        if (index == -1){
            cout << "Hash table is full !" << endl;
            return;
        }
        h[index] = t;
    }
}
int Search(int h[], int t){
    int index = hash1(t);
    if(h[index] == t){
        return index;
    }
    else{
        int hashnew = index; 
        int i = 0;
        while(h[hashnew] != 0 && i < SIZE){
            i++;
            hashnew = (index + i)%SIZE;
            if(h[hashnew] == t)
                return hashnew;
        }
        return -1;
    }
}
void Display(int h[]){
    for(int i = 0; i < SIZE; i++)
        cout << h[i] << " ";
    cout << endl;
}
int main(){
    int ht[10] = {0};
    Insert(ht, 12);
    Insert(ht, 15);
    Insert(ht, 25);
    Insert(ht, 36);
    Insert(ht, 46);
    Insert(ht, 56);
    Insert(ht, 66);
    Insert(ht, 76);
    Insert(ht, 86);
    Insert(ht, 96);
    Insert(ht, 65);
    Insert(ht, 90);
    int s = Search(ht, 86);
    if (s == -1)
        cout << "Value Not Found!" << endl;
    else     
        cout << "Value Found at :" << s  << endl;


    Display(ht);
    
    return 0;
}