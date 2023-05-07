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

bool ispathexists(struct graph* graph, int start, int end) {
 for (int i = 0; i < max_nodes; i++) {
 graph->visited[i] = false;
 }
 int stack[max_nodes];
 int top = 0;
 stack[top++] = start;
 while (top > 0) {
 int currnode = stack[--top];
 if (currnode == end) {
 return true;
 }
 if (!graph->visited[currnode]) {
 graph->visited[currnode] = true;
 struct node* adjnode = graph->adjlist[currnode];
 while (adjnode != NULL) {
 stack[top++] = adjnode->dest;
 adjnode = adjnode->next;
 }
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
 int start, end;
 printf("enter the start and end vertices for the path: ");
 scanf("%d %d", &start, &end);
 if (ispathexists(graph, start, end)) {
 printf("a path exists between %d and %d.\n", start, end);
 } else {
 printf("no path exists between %d and %d.\n", start, end);
 }
 return 0;
}
