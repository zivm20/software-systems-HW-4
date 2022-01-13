#include <stdio.h>
#include <stdlib.h>
#include "List.h"




typedef struct List_{
    pElement *elements;
    int size;
    int used;

    GET_KEY getKeyFunc;
    DELETE_ELEMENT delElementFunc;
    COMPARE CompareFunc;
    PRINT_ELEMENT printElementFunc;
}List;



pList createList(GET_KEY getKeyFunc,
  DELETE_ELEMENT delElementFunc,
  COMPARE CompareFunc,
  PRINT_ELEMENT printElementFunc)
{

  pList pLst = (pList)malloc(sizeof(List)) ;
  if( pLst != NULL){
    pLst->elements = NULL;
    pLst->size = 0;
    pLst->used = 0;
    pLst->getKeyFunc = getKeyFunc;
    pLst->delElementFunc = delElementFunc;
    pLst->CompareFunc = CompareFunc;
    pLst->printElementFunc = printElementFunc;
  }

  return pLst;
}

Bool addElem(pList pLst,pElement pElem){

  if(pLst == NULL || pElem == NULL){
    return false;
  }
  if(pLst->used == pLst->size){
    pLst->size = pLst->size+1;
    pElement *temp = (pElement*)realloc(pLst->elements,pLst->size * sizeof(pElement));
    if(temp==NULL){
      printf("list re-allocation error");

      return false;
    }
    else{
      pLst->elements = temp;
    }
  }
  pLst->elements[pLst->used]=pElem;
  pLst->used++;

  return true;
}

int indexOf(pList pLst, pElement target){
  return findIndexOf(pLst,pLst->getKeyFunc(target));
}

int findIndexOf(pList pLst, int target_key){
  int i;
  for(i=0; i<pLst->used; i++){
    if(target_key == pLst->getKeyFunc(pLst->elements[i])){
      return i;
    }
  }
  return -1;
}

pElement get(pList pLst, int idx){
  if(pLst->used > idx){
    return pLst->elements[idx];
  }
  return NULL;
}

Bool removeElem(pList pLst, pElement target){
  int idx = indexOf(pLst,target);
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
    pLst->used--;
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

Bool isin(pList pLst, pElement pElem){

  if(indexOf(pLst,pElem) != -1){
    return true;
  }
  return false;

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
