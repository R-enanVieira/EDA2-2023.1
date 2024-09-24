#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 500010
int* colors;

// Structure to represent a node in adjacency list
struct Node {
  int key;
  struct Node* next;
};

// Function to create a new node
struct Node* createNode(int key) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->key = key;
  newNode->next = NULL;
  return newNode;
}

// Function to add an edge to the graph
void addEdge(struct Node* adjList[], int u, int v) {
  struct Node* newNode = createNode(v);
  newNode->next = adjList[u];
  adjList[u] = newNode;
}

// Function to perform Breadth First Search on a graph
// represented using adjacency list
void bfs(struct Node* adjList[], int startNode, int visited[]) {
  // Create a queue for BFS
  int queue[MAX_VERTICES];
  int front = 0, rear = 0;
  int greenApple = 0, apple = 0;
  bool first = true;

  // Mark the current node as visited and enqueue it
  visited[startNode] = 1;
  queue[rear++] = startNode;
  queue[rear++] = -1;
  // Iterate over the queue
  while (front != rear) {
    // Dequeue a vertex from queue and verify it
    int currentNode = queue[front++];

    if (currentNode == -1) {
      if (front != rear) queue[rear++] = -1;
      if (!first) printf("%d %d\n", greenApple, apple);
      greenApple = 0;
      apple = 0;
      first = false;

    } else {
      greenApple += (colors[currentNode] == 1 ? 1 : 0);
      apple += (colors[currentNode] == 2 ? 1 : 0);
      // Get all adjacent vertices of the dequeued vertex
      // currentNode If an adjacent has not been visited,
      // then mark it visited and enqueue it
      struct Node* temp = adjList[currentNode];
      while (temp != NULL) {
        int neighbor = temp->key;
        if (!visited[neighbor]) {
          visited[neighbor] = 1;
          queue[rear++] = neighbor;
        }
        temp = temp->next;
      }
    }
  }
}

int main() {
  int n;
  scanf("%d", &n);

  struct Node* adjList[n + 10];
  int visited[n + 10];
  for (int i = 0; i < n + 10; i++) {
    adjList[i] = NULL;
    visited[i] = 0;
  }

  colors = malloc((n + 10) * sizeof(int));

  for (int i = 0; i < n; i++) {
    int m, l, r;
    scanf("%d %d %d", &m, &l, &r);
    colors[i + 1] = m;
    if (l) addEdge(adjList, i + 1, l);
    if (r) addEdge(adjList, i + 1, r);
  }

  bfs(adjList, 1, visited);

  return 0;
}
