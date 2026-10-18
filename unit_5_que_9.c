#include <stdio.h>

int main()
{
    int a[20][20], visited[20] = {0};
    int queue[20], n, start;
    int front = 0, rear = -1;
    int i, j, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    if(start < 0 || start >= n)
    {
        printf("Invalid starting vertex\n");
        return 0;
    }

    visited[start] = 1;
    queue[++rear] = start;

    printf("BFS traversal: ");

    while(front <= rear)
    {
        v = queue[front++];
        printf("%d ", v);

        for(i = 0; i < n; i++)
        {
            if(a[v][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }

    printf("\n");

    return 0;
}