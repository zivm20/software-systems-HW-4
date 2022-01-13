#include <stdio.h>
#include <stdlib.h>
#include "List.h"

#ifndef EDGE_STRUCT_
#define EDGE_STRUCT_

typedef struct _Edge{
  int weight;
  int dest;
  int src;
}Edge, *pEdge;


int getEdgeDest(pElement pElem){
  pEdge edge = (pEdge) pElem;
  return edge->dest;
}

Bool compareEdge(pElement e1,pElement e2){
  pEdge edge1 = (pEdge) e1;
  pEdge edge2 = (pEdge) e2;

  if(edge1->dest == edge2->dest && edge1->src == edge2->src){
    return true;
  }
  return false;
}

void delEdge(pElement pElem){
  pEdge edge = (pEdge) pElem;
  free(edge);

}
void printEdge(pElement pElem){
  pEdge edge = (pEdge) pElem;
  printf("%d:%d",edge->dest,edge->weight);
}

pEdge createEdge(int src, int dest,int weight){
  pEdge edge;
  if((edge = (pEdge)malloc(sizeof(Edge)))){
    edge->src = src;
    edge->weight = weight;
    edge->dest = dest;
  }
  return edge;
}

#endif
