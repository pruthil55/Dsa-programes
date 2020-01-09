#include<iostream>
using namespace std;
void bubble_sort(int a[],int n)
{
    int temp;
     for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
 for(int i=0;i<n;i++)
    {
      cout<<a[i];
    }
}
int main()
{
    int i,j,k,n,temp,l,a[100];
    cin>>n;
   for(i=0;i<n;i++)
    {
      cin>>a[i];
    }

    bubble_sort(a,n);


}

