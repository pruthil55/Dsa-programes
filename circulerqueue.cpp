#include<iostream>
using namespace std;
int f=-1;
int r=-1;
int Size=20;
int arr[20];
void enqueue(int x)
{
    if((f==0 && r==Size-1) || (r==f-1))
    {
        cout<<"overflow";
    }
    else if(f==-1)
    {
        f=0;
        r++;
        arr[r]=x;
    }
    else if(r==Size-1 && f!=0)
    {
        r=0;
        r++;
        arr[r]=x;
    }
    else
    {
        r++;
        arr[r]=x;
    }
}
void dequeue()
{
    int y;
    if(f==-1)
    {
        cout<<"no element available";
    }
    else if(f==r)
    {
        f=-1;
        r=-1;
        cout<<"no element available";
    }
    else if(f==Size-1)
    {
        f=0;
    }
    else
    {
        y=arr[f];
        cout<<y<<endl;
        f++;
    }
}
int main()
{
    enqueue(45);
    enqueue(32);
    enqueue(56);
    dequeue();
    dequeue();

}
