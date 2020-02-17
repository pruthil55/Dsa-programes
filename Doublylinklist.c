#include<stdio.h>

struct node
{
    int data;
    struct node *lptr;
    struct node *rptr;
};
struct node *L=NULL;
struct node *R=NULL;

struct node *create (int x)
{
    struct node *new1=(struct node*)malloc(sizeof(struct node));

    new1->data=x;
    new1->lptr=NULL;
    new1->rptr=NULL;
    return new1;
}

void insertatfront(int x)
{
    struct node *new2;
    new2 = create(x);
    if(L!=NULL){
    //new2->lptr=NULL;
    new2->rptr=L;
    L->lptr=new2;
    L=new2;
    }
    else{
        L=R=new2;
    }
}

void insertatlast(int x){
    struct node *new2;
    new2 = create(x);
    if(L !=NULL)
    {
        R->rptr = new2;
        new2->lptr =R;
        R=new2;
    }
    else
    {
        L=R=new2;
    }
}

void insertatspecific(int x, int m)
{
    struct node *new2;
    new2 = create(x);
     if(L->data == m)
    {
        new2->rptr = L;
        L->lptr=new2;
        L = new2;
    }
    else if(L != NULL)
    {
        struct node *temp = L;
        struct node *prev = NULL;
        while(temp->data != m)
        {
            prev = temp;
            temp = temp->rptr;
        }
        prev->rptr = new2;
        new2->lptr = prev;
        new2->rptr = temp;
        temp->lptr = new2;
    }
    else
    {
        L=R=new2;
    }
}
void deleteatspecific(int m)
{

     if(L->data == m)
    {
        printf("%d deleted sucessfully..." ,L->data);
        L = L->rptr;
    }
    else if(L != NULL)
    {
        struct node *temp = L;
        struct node *prev = NULL;
        while(temp->data != m)
        {
            prev = temp;
            temp = temp->rptr;
        }
        printf("%d deleted sucessfully..." ,temp->data);
        prev->rptr = temp->rptr;
        (temp->rptr)->lptr = prev;
    }
    else if(L==NULL)
    {
        printf("Underflow");
    }
}
void deleteatfront()
{
    if(L== NULL)
        printf("Underflow");
    else
    {
        printf("%d deleted sucessfully..." ,L->data);
        L = L->rptr;
        L->lptr = NULL;
    }
}

void deleteatlast()
{
    if(L== NULL)
        printf("Underflow");
    else
    {
         printf("%d deleted sucessfully..." ,R->data);
        R= R->lptr;
        R ->rptr= NULL;
    }
}

void display(){
    struct node* temp = L;
    if(L == NULL)
        printf("Underflow");
    else{
        while(temp != NULL){
            printf("%d %d %d\t",temp->lptr,temp->data,temp->rptr);
            temp = temp->rptr;
        }
    }
}

int main()
{
    int choice;
    int item,pos;
    while(1)
    {
        printf("\nEnter Choice \n 1: Display Doubly linked list \n 2: insert at front \n 3: insert at last \n 4: Delete at front \n 5: Delete at last\n 6: Insert at specific\n 7: Delete at specific\n 8: Exit............\n");
        scanf("%d",&choice);
        switch(choice)
        {
           case 1:
               display();
                break;
            case 2:
                printf("\nenter element..");
                scanf("%d",&item);
                insertatfront(item);
                break;
            case 3:
                printf("\nenter element..");
                scanf("%d",&item);
                insertatlast(item);
                break;
            case 4:
                deleteatfront();
                break;
            case 5:
                deleteatlast();
                break;
            case 6:
                printf("\nenter element you want to add..");
                scanf("%d",&item);
                printf("\nenter the element before you want to add..");
                scanf("%d",&pos);
                insertatspecific(item,pos);
                break;
            case 7:
                printf("\nenter element you want to delete..");
                scanf("%d",&item);
                deleteatspecific(item);
                break;
            case 8:
                exit(0);
                break;
            default:
            printf("\nInvalid choice.");
            break;
        }

    }
}
