#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct node *createNode(int value)
{
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}

struct node *insert(struct node *root, int value)
{
    if(root == NULL)
        return createNode(value);

    if(value < root->data)
        root->left = insert(root->left, value);
    else if(value > root->data)
        root->right = insert(root->right, value);

    return root;
}

struct node *findMin(struct node *root)
{
    while(root->left != NULL)
        root = root->left;

    return root;
}

struct node *deleteNode(struct node *root, int key)
{
    struct node *temp;

    if(root == NULL)
        return root;

    if(key < root->data)
        root->left = deleteNode(root->left, key);
    else if(key > root->data)
        root->right = deleteNode(root->right, key);
    else
    {
        /* Case 1 and Case 2 */
        if(root->left == NULL)
        {
            temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            temp = root->left;
            free(root);
            return temp;
        }

        /* Case 3: Two children */
        temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

void inorder(struct node *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main()
{
    struct node *root = NULL;
    int n, i, value, key;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter node values:\n");

    for(i = 0; i < n; i++)
    {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("In-order before deletion: ");
    inorder(root);

    printf("\nEnter value to delete: ");
    scanf("%d", &key);

    {
        struct node *temp = root;

        while(temp != NULL && temp->data != key)
        {
            if(key < temp->data)
                temp = temp->left;
            else
                temp = temp->right;
        }

        if(temp == NULL)
            printf("Node not found\n");
        else
        {
            root = deleteNode(root, key);
            printf("Node deleted successfully\n");
        }
    }

    printf("In-order after deletion: ");
    inorder(root);

    printf("\n");

    return 0;
}