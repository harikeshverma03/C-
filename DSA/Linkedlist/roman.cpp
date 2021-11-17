#include<iostream>
#include<string>
using namespace std;
int main()
{   int n,i,sum=0;
    cout<<"enter the num of characters"<<endl;
    cin>>n;
    char a[n];
    cout<<"enter the characters"<<endl;
    for(i=0;i<n;i++)
        cin>>a[i];
    if(a[0] == 'I')
        sum = sum + 1;
    else if(a[0] == 'V')
        sum = sum + 5;
    else if(a[0] == 'X')
        sum = sum + 10;
    else if(a[0] == 'L')
        sum = sum + 50;
    else if(a[0] == 'C')
        sum = sum + 100;
    else if(a[0] == 'D')
        sum = sum + 500;
    else if(a[0] == 'M')
        sum = sum + 1000;
    for(i=1;i<n;i++)
    {
        if(a[i]=='I')
            sum=sum+1;
        else if(a[i]=='V')
            if(a[i-1]=='I')
                sum=sum+3;
            else
                sum=sum+5;
        else if(a[i]=='X')
            if(a[i-1]=='I')
                sum=sum+8;
            else
                sum=sum+10;
        else if(a[i]=='L')
            if(a[i-1]=='X')
                sum=sum+30;
            else
                sum=sum+50;
        else if(a[i]=='C')
             if(a[i-1]=='X')
                sum=sum+80;
             else
                sum=sum+100;
        if(a[i]=='D')
            if(a[i-1]=='C')
                sum=sum+300;
            else
                sum=sum+500; 
        else if(a[i]=='M')
             if(a[i-1]=='C')
                sum=sum+800;
            else
                sum=sum+1000;
    }
    cout<<sum;
    return(0);
}