#include <stdio.h>
#include <stdlib.h>
#include "List.h"
#include "Node.c"

typedef struct _Node *pNode;
typedef struct _Edge{
  int weight;
  pNode dest;
}Edge, *pEdge;

pKey edgeKey(pElement pElem){
  pEdge edge = (pEdge) pElem;
  int* out = &(dest->id);
  return out;
}

Bool compareEdge(pKey e1,pkey e2){
  return ((*int)e1 == (*int)e2)? true:false;
}

void delEdge(pElement pElem){
  pEdge edge = (pEdge) pElem;
  edge->dest = NULL;
  free(edge);

}
void printEdge(pElement pElem){
  pEdge edge = (pEdge) pElem;
  printf("%d:%d",edge->dest->id,edge->weight);
}

pEdge createEdge(pNode dest,int weight){
  pEdge edge;
  if(edge = (pEdge)malloc(sizeof(Edge))){
    edge->weight=weight;
    edge->dest = dest;
  }
  return edge;
}
