// Array using C++ modified
#include <iostream>
using namespace std;
template <class T>
class Array
{
    private:
    T *A;
    int size;
    int length;
    void swap(int *x,int *y);
    public:
Array()
{
    size=10;
    length=0;
    A=new T[size];
}
Array(int sz)
{
size=sz;
length=0;
A=new T[size];
}
~Array()
{
delete []A;
}
void Display();
void Append(T x);
void Insert(int index,T x);
T Delete(int index);

};
template <class T>
void Array<T>::Display()
{
int i;
cout<<"\nElements are\n";
for(i=0;i<length;i++)
cout<<A[i]<<" ";
}
template <class T>
void Array<T>::Append(T x)
{
if(length<size)
A[length++]=x;
}

template <class T>
void Array<T>::Insert(int index,T x)
{
int i;
if(index>=0 && index <=length)
{
for(i=length;i>index;i--)
A[i]=A[i-1];
A[index]=x;
length++;
}
}
template <class T>
T Array<T>::Delete(int index)
{
T x=0;
int i;
if(index>=0 && index<length)
{
x=A[index];
for(i=index;i<length-1;i++)
A[i]=A[i+1];
length--;
return x;
}
return 0;
}

int main()
{
Array<int> *arr1;
int ch,sz;
int x,index;
cout<<"Enter Size of Array";
scanf("%d",&sz);
arr1=new Array<int>(sz);
do
{
cout<<"\n\nMenu\n";
cout<<"1. Insert\n";
cout<<"2. Delete\n";
cout<<"3. Search\n";
cout<<"4. Sum\n";
cout<<"5. Display\n";
cout<<"6.Exit\n";
cout<<"enter you choice ";
cin>>ch;
switch(ch)
{
case 1: cout<<"Enter an element and index ";
cin>>x>>index;
arr1->Insert(index,x);
break;
case 2: cout<<"Enter index ";
cin>>index;
x=arr1->Delete(index);
cout<<"Deleted Element is"<<x;
break;
case 5:arr1->Display();
}
}while(ch<6);
return 0;
}