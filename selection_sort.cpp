#include<iostream>
using namespace std;
void selectionsort(int k[],int n)
{
    int pass,min_index,i,j,temp;
    for(pass=1;pass<n-1;pass++)
    {
       min_index=pass;

    for(i=pass+1;i<n;i++)
    {
        if(k[i]<k[min_index])
        {
            min_index=i;
        }
    }
    }
    if(min_index=!pass)
    {
        temp=k[i];
                k[i]=k[min_index];
                k[min_index]=temp;
    }

    for(int i=0;i<n;i++)
    {
      cout<<k[i];
    }
}
int main()
{
     int i,j,k[10],n,temp,pass;
    cin>>n;
   for(i=0;i<n;i++)
    {
      cin>>k[i];
    }

    selectionsort(k,n);

}
