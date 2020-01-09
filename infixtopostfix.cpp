#include<iostream>
using namespace std;
int top=0;
char s[50];
void push(char x)
{
    top++;
    s[top]=x;
}
char pop()
{
    char t=s[top];
    top--;
    return t;
}
int f(char c)
{
    if(c=='+' || c=='-')
    {
        return 1;
    }
    else if(c=='#')
    {
        return 0;
    }
    else if(c=='*' || c=='/')
    {
        return 2;
    }
    else if(c=='^')
    {
        return 3;
    }
    else
    {
        return 4;
    }
}
int r(char c)
{
    if(c=='+' || c=='-' || c=='*' || c=='/')
    {
        return -1;
    }
    else
    {
        return 1;
    }
}
int main()
{
    string infix;
    int i=0,j=0,rank1=0;
    char next[50];
    char output[50];
    s[top]='#';
    char temp;
    cout<<"enter infix expression:";
    cin>>infix;
    infix.append("#");
    next[0]=infix[0];
    while(next[i]!='#')
    {
        while(f(next[i])<=f(s[top]))
        {
            temp=pop();
            output[j]=temp;
            j++;
            rank1=rank1+r(temp);
        }
        push(next[i]);
        i++;
        next[i]=infix[i];
    }
    while(s[top]!='#')
    {
        temp=pop();
        output[j]=temp;
        j++;
        rank1=rank1+r(temp);
    }
    if(rank1==1)
    {
        cout<<"expression is valid";
    }
    else
    {
        cout<<"not valid expression";
    }
    cout<<endl;
    for(int p=0;p<infix.length()-1;p++)
    {
        cout<<output[p];
    }

}
