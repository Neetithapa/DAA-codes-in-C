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
 int color[max_nodes];
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

bool isbipartite(struct graph* graph, int start) {
    
 for (int i = 0; i < max_nodes; i++) {
 graph->color[i] = -1;
 }
 graph->color[start] = 0;
 int queue[max_nodes];
 int front = 0, rear = 0;
 queue[rear++] = start;
 
 while (front != rear) {
 int currnode = queue[front++];
 struct node* adjnode = graph->adjlist[currnode];
 while (adjnode != NULL) {
 int adjdest = adjnode->dest;
 if (graph->color[adjdest] == -1) {
     
 graph->color[adjdest] = 1–graph->color[currnode];
 
 queue[rear++] = adjdest;
 } 
 else if (graph->color[adjdest] == graph->color[currnode]) 
 {
 return false;
 }
 
 adjnode = adjnode->next;
 }
}
 return true;
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
 addedge(graph, dest, src); // adding edge for undirected graph
 }
 if (isbipartite(graph, 0)) {
 printf("the graph is bipartite.\n");
 } else
 {
 printf("the graph is not bipartite.\n");
 }
 return 0;
}
