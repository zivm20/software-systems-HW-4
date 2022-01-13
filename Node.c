#include <stdio.h>
#include <stdlib.h>
#include "List.h"
#include "Edge.c"


#ifndef NODE_STRUCT_
#define NODE_STRUCT_
typedef struct _NODE{
  int id;
  int distance;
  pList edges_out;
}Node, *pNode;




int nodeGetId(pElement pElem){
  pNode node = (pNode) pElem;
  int out = node->id;
  return out;
}

Bool compareNode(pElement e1,pElement e2){
  pNode n1 = (pNode) e1;
  pNode n2 = (pNode) e2;
  return (n1->id) == (n2->id)? true:false;
}

void delNode(pElement pElem){
  pNode node = (pNode) pElem;
  deleteList(node->edges_out);
  node->edges_out = NULL;
  free(node);

}
void printNode(pElement pElem){
  pNode node = (pNode) pElem;
  printf("%d: ",node->id);
  printList(node->edges_out);
}


pNode createNode(int id){
  pNode node;
  if((node = (pNode)malloc(sizeof(Node)))){
    if(!(node->edges_out = createList(getEdgeDest,delEdge,compareEdge,printEdge))){
      free(node);
      return NULL;
    }
    node->id = id;
    node->distance = 0;
  }
  return node;
}

#endif
