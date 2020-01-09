#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
    int data;
    struct node* link;
};

struct node* create(int x)
{
        struct node* ptr;
        ptr=(struct node*)malloc(sizeof(struct node));
        ptr->data=x;
        ptr->link=NULL;
        return ptr;
}
struct node* insertatfirst(int x,struct node* head)
{
    struct node *New;
    New=create(x);
    if(head==NULL)
    {
        head=New;
    }
    else
    {
        New->link=head;
        head=New;
    }
}
void display(struct node *head)
{
    if(head==NULL)
    {
        cout<<"no node is available";
    }
    else
    {
        struct node *trav;
        struct node *temp;
        trav=head;
        while(trav->link!=NULL)
        {
            temp=trav;
            cout<<trav->data<<endl;
            trav=trav->link;
        }
        cout<<temp->data;
    }
}

int main()
{
    struct node *head;
    head=NULL;
    head=insertatfirst(56,head);
    head=insertatfirst(33,head);
    head=insertatfirst(55,head);
    display(head);
}
