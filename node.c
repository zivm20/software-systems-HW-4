#include <stdio.h>
#include <stdlib.h>
#include "List.h"


typedef struct _NODE{
  int id;
  pList edges_out;
  pList edges_in;
}Node, *pNode;

pKey nodeKey(pElement pElem){
  pNode node = (pNode) pElem;
  int* out = &(node->id)
  return out;
}

Bool compare(pKey e1,pkey e2){
  return ((*int)e1 == (*int)e2)? true:false;
}

void delNode(pElement pElem){
  pNode node = (pNode) pElem;
  deleteList(node->edges_out);
  node->edges_out = NULL;
  deleteList(node->edges_in);
  node->edges_in = NULL;
  free(node);

}
Bool insertNode(){

}

void printNode(pElement pElem){
  pNode node = (pNode) pElem;
  printf("%d: ",node->id);
  printList(node->edges_out);
}

pNode createNode(int id){
  pNode node;
  if(node = (pNode)malloc(sizeof(Node))){
    if(!(node->edges_out)=(pList)malloc(sizeof(List))){
      free(node);
      return NULL;
    }
    if(!(node->edges_in)=(pList)malloc(sizeof(List))){
      free(node);
      deleteList(node->edges_in);
      node->edges_in = NULL;
      return NULL;
    }
    node->id = id;

  }
  return node;
}
