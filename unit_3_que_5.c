#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char roll[20];
    struct node *next;
};

struct node *head = NULL;

void display();

void create()
{
    struct node *newnode, *temp;
    int n, i;

    printf("Enter number of students: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));

        if(newnode == NULL)
        {
            printf("Memory allocation failed\n");
            return;
        }

        printf("Enter roll number: ");
        scanf("%19s", newnode->roll);

        newnode->next = NULL;

        if(head == NULL)
            head = newnode;
        else
        {
            temp = head;

            while(temp->next != NULL)
                temp = temp->next;

            temp->next = newnode;
        }
    }

    display();
}

void insertBegin()
{
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));

    if(newnode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter roll number: ");
    scanf("%19s", newnode->roll);

    newnode->next = head;
    head = newnode;

    display();
}

void insertEnd()
{
    struct node *newnode, *temp;

    newnode = (struct node *)malloc(sizeof(struct node));

    if(newnode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter roll number: ");
    scanf("%19s", newnode->roll);

    newnode->next = NULL;

    if(head == NULL)
        head = newnode;
    else
    {
        temp = head;

        while(temp->next != NULL)
            temp = temp->next;

        temp->next = newnode;
    }

    display();
}

void search()
{
    struct node *temp = head;
    char key[20];

    printf("Enter roll number to search: ");
    scanf("%19s", key);

    while(temp != NULL)
    {
        if(strcmp(temp->roll, key) == 0)
        {
            printf("Roll number found\n");
            display();
            return;
        }

        temp = temp->next;
    }

    printf("Roll number not found\n");
    display();
}

void deleteNode()
{
    struct node *temp = head, *prev = NULL;
    char key[20];

    printf("Enter roll number to delete: ");
    scanf("%19s", key);

    while(temp != NULL && strcmp(temp->roll, key) != 0)
    {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL)
    {
        printf("Roll number not found\n");
    }
    else
    {
        if(prev == NULL)
            head = temp->next;
        else
            prev->next = temp->next;

        free(temp);

        printf("Roll number deleted successfully\n");
    }

    display();
}

void display()
{
    struct node *temp = head;

    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("Student roll numbers: ");

    while(temp != NULL)
    {
        printf("%s -> ", temp->roll);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main()
{
    int ch;

    while(1)
    {
        printf("\n1. Create List\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Search Roll Number\n");
        printf("5. Delete Roll Number\n");
        printf("6. Display List\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                create();
                break;

            case 2:
                insertBegin();
                break;

            case 3:
                insertEnd();
                break;

            case 4:
                search();
                break;

            case 5:
                deleteNode();
                break;

            case 6:
                display();
                break;

            case 7:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}