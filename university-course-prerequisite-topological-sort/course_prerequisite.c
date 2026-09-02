#include <stdio.h>

#define MAX 100

int graph[MAX][MAX];
int indegree[MAX];
int n;

/* Add a directed edge u -> v */
void addEdge(int u, int v)
{
    if (graph[u][v] == 0)
    {
        graph[u][v] = 1;
        indegree[v]++;
    }
}

/* BFS Topological Sort using Kahn's Algorithm */
void kahnBFS()
{
    int queue[MAX];
    int front = 0, rear = 0;
    int order[MAX];
    int count = 0;

    /* Add all courses with indegree 0 */
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
            queue[rear++] = i;
    }

    /* Process the queue */
    while (front < rear)
    {
        int u = queue[front++];
        order[count++] = u;

        for (int v = 0; v < n; v++)
        {
            if (graph[u][v] == 1)
            {
                indegree[v]--;

                if (indegree[v] == 0)
                    queue[rear++] = v;
            }
        }
    }

    printf("\nBFS (Kahn's Algorithm) Topological Order:\n");

    if (count != n)
    {
        printf("Cycle detected. No valid course order exists.\n");
        return;
    }

    for (int i = 0; i < count; i++)
        printf("%d ", order[i]);

    printf("\n");
}

/* DFS variables */
int color[MAX];
int stack[MAX];
int top = -1;
int dfsCycle = 0;

/*
   color:
   0 = unvisited
   1 = visiting
   2 = completed
*/

void dfs(int u)
{
    color[u] = 1;

    for (int v = 0; v < n; v++)
    {
        if (graph[u][v] == 0)
            continue;

        /* Back edge -> cycle */
        if (color[v] == 1)
        {
            dfsCycle = 1;
            return;
        }

        /* Visit unvisited vertex */
        if (color[v] == 0)
        {
            dfs(v);

            if (dfsCycle)
                return;
        }
    }

    color[u] = 2;
    stack[++top] = u;
}

/* DFS Topological Sort */
void dfsTopologicalSort()
{
    for (int i = 0; i < n; i++)
        color[i] = 0;

    top = -1;
    dfsCycle = 0;

    for (int i = 0; i < n; i++)
    {
        if (color[i] == 0)
        {
            dfs(i);

            if (dfsCycle)
                break;
        }
    }

    printf("\nDFS Topological Order:\n");

    if (dfsCycle)
    {
        printf("Cycle detected. No valid course order exists.\n");
        return;
    }

    while (top >= 0)
        printf("%d ", stack[top--]);

    printf("\n");
}

int main()
{
    int e;
    int u, v;

    printf("Enter number of courses: ");
    scanf("%d", &n);

    /* Initialize graph */
    for (int i = 0; i < n; i++)
    {
        indegree[i] = 0;

        for (int j = 0; j < n; j++)
            graph[i][j] = 0;
    }

    printf("Enter number of prerequisite relationships: ");
    scanf("%d", &e);

    printf("Enter prerequisite pairs (A B means A -> B):\n");

    for (int i = 0; i < e; i++)
    {
        scanf("%d %d", &u, &v);

        if (u >= 0 && u < n && v >= 0 && v < n)
            addEdge(u, v);
        else
            printf("Invalid course number. Enter values between 0 and %d.\n", n - 1);
    }

    /* BFS */
    kahnBFS();

    /*
       Recalculate indegree because Kahn's Algorithm modifies it.
       This is not needed for DFS, but restores the graph data.
    */
    for (int i = 0; i < n; i++)
        indegree[i] = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] == 1)
                indegree[j]++;
        }
    }

    /* DFS */
    dfsTopologicalSort();

    return 0;
}
