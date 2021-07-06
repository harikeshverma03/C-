#include<stdio.h>
int main()
{
    int n,j,m,k=0,l=0,i,arr[50][50];
    scanf("%d %d",&m,&n);
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }

    if(n>=1 && n<=20 && m>=1 && m<=20)
    {
               while(k<n && l<m)
               {
                   for(i=m-1;i>=l;i--)
                   {
                       printf("%d ",arr[i][n-1]);
                   }
                   n--;
                   for(i=n-1;i>=k;i--)
                   {
                       printf("%d ",arr[l][i]);
                   }
                   l++;
                   for(i=l;i<m;i++)
                   {
                       if(n==0)
                       {
                           return 0;
                       }
                       else
                       {
                           printf("%d ",arr[i][k]);
                       }

                   }
                   k++;
                   for(i=k;i<n;i++)
                   {
                       if(m==1)
                       {
                           return 0;
                       }
                       else
                       {
                           printf("%d ",arr[m-1][i]);
                       }
                   }
                   m--;
               } 
    }
    else;
    return 0;
}