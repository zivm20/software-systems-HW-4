#ifndef GRAPH_
#define GRAPH_

#include "List.h"
#include "Node.c"
#include "Edge.c"

typedef struct GRAPH_{
  pList nodes;
}Graph,*pGraph;



pGraph createGraph();
pNode getNode(pGraph graph, int id);
pEdge getEdge(pGraph graph, int src, int dest);
Bool addEdge(pGraph graph, int src,int dest,int weight);
Bool addNode(pGraph graph,int id);

void delGraph(pGraph graph);
void printGraph(pGraph graph);





#endif
