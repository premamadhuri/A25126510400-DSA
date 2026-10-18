#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char page[50];
    struct node *prev, *next;
};

struct node *head = NULL, *current = NULL;

void insert()
{
    struct node *newnode, *temp;

    newnode = (struct node *)malloc(sizeof(struct node));

    if(newnode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter web page name: ");
    scanf("%49s", newnode->page);

    newnode->prev = NULL;
    newnode->next = NULL;

    if(head == NULL)
    {
        head = current = newnode;
    }
    else
    {
        temp = head;

        while(temp->next != NULL)
            temp = temp->next;

        temp->next = newnode;
        newnode->prev = temp;
    }

    printf("Page inserted successfully\n");
}

void forward()
{
    if(current == NULL)
        printf("No web pages available\n");
    else if(current->next == NULL)
        printf("Already at the last page\n");
    else
    {
        current = current->next;
        printf("Current page: %s\n", current->page);
    }
}

void backward()
{
    if(current == NULL)
        printf("No web pages available\n");
    else if(current->prev == NULL)
        printf("Already at the first page\n");
    else
    {
        current = current->prev;
        printf("Current page: %s\n", current->page);
    }
}

void deletePage()
{
    struct node *temp = head;
    char key[50];

    printf("Enter page name to delete: ");
    scanf("%49s", key);

    while(temp != NULL && strcmp(temp->page, key) != 0)
        temp = temp->next;

    if(temp == NULL)
    {
        printf("Page not found\n");
        return;
    }

    if(temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if(temp->next != NULL)
        temp->next->prev = temp->prev;

    if(current == temp)
    {
        if(temp->next != NULL)
            current = temp->next;
        else
            current = temp->prev;
    }

    free(temp);

    printf("Page deleted successfully\n");

    if(current != NULL)
        printf("Current page: %s\n", current->page);
    else
        printf("No web pages available\n");
}

void displayForward()
{
    struct node *temp = head;

    if(head == NULL)
    {
        printf("No web pages available\n");
        return;
    }

    printf("Pages from first to last:\n");

    while(temp != NULL)
    {
        printf("%s -> ", temp->page);
        temp = temp->next;
    }

    printf("NULL\n");
}

void displayBackward()
{
    struct node *temp = head;

    if(head == NULL)
    {
        printf("No web pages available\n");
        return;
    }

    while(temp->next != NULL)
        temp = temp->next;

    printf("Pages from last to first:\n");

    while(temp != NULL)
    {
        printf("%s -> ", temp->page);
        temp = temp->prev;
    }

    printf("NULL\n");
}

int main()
{
    int ch;

    while(1)
    {
        printf("\n1. Insert Page\n");
        printf("2. Move Forward\n");
        printf("3. Move Backward\n");
        printf("4. Delete Page\n");
        printf("5. Display First to Last\n");
        printf("6. Display Last to First\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                insert();
                break;

            case 2:
                forward();
                break;

            case 3:
                backward();
                break;

            case 4:
                deletePage();
                break;

            case 5:
                displayForward();
                break;

            case 6:
                displayBackward();
                break;

            case 7:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}