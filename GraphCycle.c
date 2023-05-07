#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define max_nodes 100

struct node {
 int dest;
 struct node* next;
};

struct graph {
 struct node* adjlist[max_nodes];
 bool visited[max_nodes];
};

struct node* createnode(int dest) {
 struct node* newnode = (struct node*) malloc(sizeof(struct node));
 newnode->dest = dest;
 newnode->next = NULL;
 return newnode;
}

void addedge(struct graph* graph, int src, int dest) {
 struct node* newnode = createnode(dest);
 newnode->next = graph->adjlist[src];
 graph->adjlist[src] = newnode;
}

bool dfs(struct graph* graph, int node, bool* stack) {
 if (!graph->visited[node]) 
 { 
 graph->visited[node] = true;
 stack[node] = true;
 struct node* adjnode = graph->adjlist[node];
 while (adjnode != NULL) 
 {
 if (!graph->visited[adjnode->dest] && dfs(graph, adjnode->dest, stack)) 
 return true;
 
 else if (stack[adjnode->dest]) 
 return true;
 
 adjnode = adjnode->next;
 }
 }
 stack[node] = false;
 return false;
}

bool containscycle(struct graph* graph, int numnodes) {
 bool stack[numnodes];
 for (int i = 0; i < numnodes; i++)
 {
 graph->visited[i] = false;
 stack[i] = false;
 }
 for (int i = 0; i < numnodes; i++) 
 {
 if (!graph->visited[i] && dfs(graph, i, stack)) {
 return true;
 }
 
 }
 return false;
}


int main() {
 int numnodes, numedges;
 printf("enter the number of nodes and edges in the graph: ");
 scanf("%d %d", &numnodes, &numedges);
 struct graph* graph = (struct graph*) malloc(sizeof(struct graph));
 for (int i = 0; i < numnodes; i++) {
 graph->adjlist[i] = NULL;
 }
 printf("enter the edges in the graph (source destination):\n");
 for (int i = 0; i < numedges; i++) {
 int src, dest;
 scanf("%d %d", &src, &dest);
 addedge(graph, src, dest);
 }
 if (containscycle(graph, numnodes)) {
 printf("the graph contains a cycle.\n");
 } else {
 printf("the graph does not contain a cycle.\n");
 }
 return 0;
}