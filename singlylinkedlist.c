#include<stdio.h>
struct node
{
    int data;
    struct node * link;
};

struct node * head;

struct node * create(int value)
{
    struct node * ptr;
    ptr = (struct node *)malloc(sizeof(struct node *));

    ptr->data = value;
    ptr->link = NULL;
    return ptr;
}

void display()
{
    struct node * temp;
    temp = head;
    printf("\n\n");
    while(temp != NULL)
    {
        printf("%d  ",temp->data);
        temp = temp->link;
    }
}

void insertFirst()
{
    struct node * new_node;
    int n;
    printf("\nEnter value you want to insert : ");
    scanf("%d",&n);
    new_node = create(n);

    if(head == NULL)
    {
        printf("This is first node...\n");
        head = new_node;
        printf("Node Inserted...\n");
    }
    else
    {
        new_node->link = head;
        head = new_node;
        printf("Node Inserted...\n");
    }
}

void insertLast()
{
    struct node * new_node;
    struct node * temp;
    int n;
    printf("\nEnter value you want to insert : ");
    scanf("%d",&n);
    new_node = create(n);

    if(head == NULL)
    {
        printf("This is first node...\n");
        head = new_node;
        printf("Node Inserted...\n");
    }
    else
    {
        temp = head;
        while(temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = new_node;
        printf("Node Inserted...\n");
    }
}

void insertAfterSpecific()
{
    struct node * new_node;
    struct node * temp;
    int n;
    printf("\nEnter value you want to insert : ");
    scanf("%d",&n);
    new_node = create(n);

    if(head == NULL)
    {
        printf("This is first node...\n");
        head = new_node;
        printf("Node Inserted...\n");
    }
    else
    {
        int t;
        printf("Enter value after which you want to insert a node : ");
        scanf("%d",&t);

        temp = head;
        while((temp->data != t) && (temp->link != NULL))
        {
            temp = temp->link;
        }
        if((temp->link == NULL) && (temp->data != t))
        {
            printf("\nNo any value found in the list, which you have entered... Node not Inserted...");
        }
        else
        {
            new_node->link = temp->link;
            temp->link = new_node;
            printf("Node Inserted...\n");
        }
    }
}

void deleteFirst()
{
    struct node * temp;
    if(head == NULL)
    {
        printf("List is empty...");
    }
    else
    {
        temp = head;
        head = head->link;
        free(temp);
        printf("\nNode deleted from the begining...\n");
    }
}

void deleteLast()
{
    struct node *temp1 , *temp2;

    if(head == NULL)
    {
        printf("List is empty...");
    }
    else if(head->link == NULL)
    {
        head = NULL;
        free(head);
        printf("\nOnly one node deleted from the list...\n");
    }
    else
    {
        temp1 = head;
        while(temp1->link != NULL)
        {
            temp2 = temp1;
            temp1 = temp1->link;
        }

        temp2->link = NULL;
        free(temp1);
        printf("\nNode deleted from the list...\n");
    }
}

void deleteAfterSpecific()
{
    struct node *temp;
    if(head == NULL)
    {
        printf("List is empty...");
    }
    else if(head->link == NULL)
    {
        printf("\nOnly one node in the list... No any node is deleted...\n");
    }
    else
    {
        int t;
        printf("\nEnter value after which you want to delete a node : ");
        scanf("%d",&t);

        temp = head;
        while((temp->data != t) && (temp->link != NULL))
        {
            temp = temp->link;
        }

        if(temp->link == NULL)
        {
            printf("No any value found in the list, which you have entered... Node not deleted...");
        }
        else
        {
            temp->link = (temp->link)->link;
            printf("Node deleted...\n");
        }
    }
}

void search()
{
    int t,i=0,flag=0;
    printf("\nEnter value you want to search in the list : ");
    scanf("%d",&t);

    struct node *temp;
    temp = head;
    while(temp != NULL)
    {
        if(temp->data == t)
        {
            printf("%d data found at %d location...",t,i+1);
            flag = 1;
        }
        temp = temp->link;
        i++;
    }

    if(flag == 0)
    {
        printf("Data not found in the list...");
    }
}

void main()
{
    int choice = 0;
    while(choice != 9)
    {
        printf("\n===============================================\n");
        printf("Choose one option from the following list ...\n");
        printf("===============================================\n");
        printf("\n1.Insert at begining\n2.Insert at last\n3.Insert after specific location\n4.Delete from Beginning\n5.Delete from last\n6.Delete after specified location\n7.Search for an element\n8.Show\n9.Exit\n");
        printf("\nEnter your choice? : ");
        scanf("\n%d",&choice);

        switch(choice)
        {
            case 1:
                insertFirst();
                break;
            case 2:
                insertLast();
                break;
            case 3:
                insertAfterSpecific();
                break;
            case 4:
                deleteFirst();
                break;
            case 5:
                deleteLast();
                break;
            case 6:
                deleteAfterSpecific();
                break;
            case 7:
                search();
                break;
            case 8:
                display();
                break;
            case 9:
                exit(0);
                break;
            default:
                printf("Please enter valid choice..");
        }
    }
}
