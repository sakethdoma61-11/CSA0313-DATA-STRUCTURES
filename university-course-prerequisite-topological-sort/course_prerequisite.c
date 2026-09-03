#include <stdio.h>

#define MAX 20

const char *courses[MAX] = {
    "Programming Fundamentals",
    "Data Structures",
    "DBMS",
    "Computer Networks",
    "Algorithms",
    "Operating Systems",
    "Artificial Intelligence",
    "Machine Learning"
};

int graph[MAX][MAX];
int n = 8;

void addEdge(int from, int to) {
    graph[from][to] = 1;
}

void createGraph(void) {
    addEdge(0, 1);  /* Programming Fundamentals -> Data Structures */
    addEdge(0, 2);  /* Programming Fundamentals -> DBMS */
    addEdge(1, 4);  /* Data Structures -> Algorithms */
    addEdge(1, 5);  /* Data Structures -> Operating Systems */
    addEdge(3, 5);  /* Computer Networks -> Operating Systems */
    addEdge(2, 6);  /* DBMS -> Artificial Intelligence */
    addEdge(4, 6);  /* Algorithms -> Artificial Intelligence */
    addEdge(5, 7);  /* Operating Systems -> Machine Learning */
    addEdge(6, 7);  /* Artificial Intelligence -> Machine Learning */
}

void displayGraph(void) {
    int i, j;
    printf("\nCourse Prerequisite Graph:\n");
    for (i = 0; i < n; i++) {
        printf("%s -> ", courses[i]);
        for (j = 0; j < n; j++)
            if (graph[i][j]) printf("%s, ", courses[j]);
        printf("\n");
    }
}

/* BFS / Kahn's Algorithm */
void kahnTopologicalSort(void) {
    int indegree[MAX] = {0};
    int queue[MAX], result[MAX];
    int front = 0, rear = 0, count = 0;
    int i, j;

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (graph[i][j]) indegree[j]++;

    for (i = 0; i < n; i++)
        if (indegree[i] == 0) queue[rear++] = i;

    while (front < rear) {
        int u = queue[front++];
        result[count++] = u;

        for (j = 0; j < n; j++) {
            if (graph[u][j]) {
                indegree[j]--;
                if (indegree[j] == 0)
                    queue[rear++] = j;
            }
        }
    }

    printf("\nBFS - Kahn's Topological Sort:\n");
    if (count != n) {
        printf("Cycle detected! No valid course order exists.\n");
        return;
    }

    for (i = 0; i < count; i++) {
        printf("%s", courses[result[i]]);
        if (i != count - 1) printf(" -> ");
    }
    printf("\n");
}

/* DFS state: 0=unvisited, 1=visiting, 2=visited */
int state[MAX];
int stack[MAX];
int top = -1;
int cycleDetected = 0;

void DFS(int u) {
    int v;
    state[u] = 1;

    for (v = 0; v < n; v++) {
        if (!graph[u][v]) continue;

        if (state[v] == 1) {
            cycleDetected = 1;
            return;
        }

        if (state[v] == 0) {
            DFS(v);
            if (cycleDetected) return;
        }
    }

    state[u] = 2;
    stack[++top] = u;
}

void dfsTopologicalSort(void) {
    int i;
    for (i = 0; i < n; i++) state[i] = 0;
    top = -1;
    cycleDetected = 0;

    for (i = 0; i < n; i++) {
        if (state[i] == 0) {
            DFS(i);
            if (cycleDetected) break;
        }
    }

    printf("\nDFS Topological Sort:\n");
    if (cycleDetected) {
        printf("Cycle detected! No valid course order exists.\n");
        return;
    }

    for (i = top; i >= 0; i--) {
        printf("%s", courses[stack[i]]);
        if (i != 0) printf(" -> ");
    }
    printf("\n");
}

void addCycle(void) {
    /* Machine Learning -> Data Structures creates:
       Data Structures -> Algorithms -> AI -> ML -> Data Structures */
    addEdge(7, 1);
}

int main(void) {
    printf("============================================\n");
    printf(" UNIVERSITY COURSE PREREQUISITE SYSTEM\n");
    printf("============================================\n");

    createGraph();
    displayGraph();

    kahnTopologicalSort();
    dfsTopologicalSort();

    printf("\nAdding a prerequisite cycle for testing...\n");
    addCycle();

    kahnTopologicalSort();
    dfsTopologicalSort();

    return 0;
}
