#include <stdio.h>
#include <stdlib.h>
#include "List.h"




typedef List_{
    pElement *elements;
    int size;
    int used;

    GET_KEY getKeyFunc;
    DELETE_ELEMENT delElementFunc;
    INSERT_ELEMENT InsertElementFunc;
    COMPARE CompareFunc;
    PRINT_ELEMENT printElementFunc;
}List;


static int internalFind(pList pLst, pKey key){
  pKey pElemKey;
  int i;
  for(i=0; i<pLst->used; i++){
    pElemKey = pLst->getKeyFunc(pLst->elements[i]);
    if(pLst->getKeyFunc(key,pElemKey)){
      return i;
    }
  }
  return -1;
}

pList CreateList(GET_KEY getKeyFunc,
  DELETE_ELEMENT delElementFunc,
  COMPARE CompareFunc,
  PRINT_ELEMENT printElementFunc,
  INSERT_ELEMENT InsertElementFunc)
{

  pList pLst;
  if(pLst = (pList)malloc(sizeof(pList))){
    pLst->elements = NULL;
    pLst->size = 0;
    pLst->used = 0;
    pLst->getKeyFunc = getKeyFunc;
    pLst->delElementFunc = delElementFunc;
    pLst->CompareFunc = CompareFunc;
    pLst->InsertElementFunc = InsertElementFunc;
    pLst->printElementFunc = printElementFunc;
  }
  return pLst;
}

Bool AddElem(pList pLst,pElement pElem){

  if(pLst == NULL || pElem == NULL){
    return false;
  }
  if(pLst->used == plst->size){
    pLst->size = pLst->size+1;
    pElement *temp = (pElement*)realloc(pLst->elements,plst->size * sizeof(pElement));
    if(temp==NULL){
      printf("re-allocation error");
      deleteList(pLst);
      exist(0);
    }
    else{
      pLst->elements = temp;
    }
  }
  if(pLst->InsertElementFunc(pElem)){
    pLst->used++;
    return true;
  }
  return false;
}

pElement GetListElem(pList pLst, pKey key){
  int idx = internalFind(pLst,key);
  return (idx>=0)? pLst->elements[idx]:NULL;
}

pElement get(pList pLst, int key){
  if(pLst->used > key){
    return pLst->elements[key];
  }
  return NULL;
}

Bool removeElem(pList pLst, pKey key){
  int idx = internalFind(pLst,key);
  if(idx >= 0){
    pLst->delElementFunc(pLst->elements[idx]);
    //make sure pointer isn't initialized
    pLst->elements[idx] = NULL;
    //push the removed element to the end of the list
    while(idx < pLst->used -1){
      pLst->elements[idx] = pLst->elements[idx+1];
      idx++;
    }
    pLst->elements[pLst->used - 1] = NULL;
    plst->used--;
    return true;
  }
  return false;
}

void printList(pList pLst){
  int i;
  printf("[");
  for(i=0; i<pLst->used; i++){
    if(pLst->elements[i]){
      pLst->printElementFunc(pLst->elements[i]);

    }
    else{
      printf("null");
    }
    if(i < pLst->used-1){
      printf(", ");
    }
  }
  printf("]");
}


void deleteList(pList pLst){
  int i;

  for(i=0; i<pLst->used; i++){
    if(pLst->elements[i]){
      pLst->delElementFunc(pLst->elements[i]);
    }
  }
  free(pLst->elements);
  free(pLst);
}
