#ifndef LIST_H_
#define LIST_H_

typedef struct List_ *pList

typedef enum Bool_{false = 0,true} Bool;
typedef void *pElement;
typedef void *pKey;


typedef pKey (*GET_KEY)(pElement);
typedef Bool (*INSERT_ELEMENT)(pElement);
typedef void (*DELETE_ELEMENT)(pElement);
typedef Bool (*COMPARE)(pElement,pElement);
typedef void (*PRINT_ELEMENT)(pElement);


pList createList(GET_KEY,DELETE_ELEMENT,COMPARE,PRINT_ELEMENT,INSERT_ELEMENT);
Bool addElem(pList,pElement);
pElement getListElem(pList, pKey);
Bool removeElem(pList,pKey);
void printList(pList);
void deleteList(pList);

pElement get(pList,int);



#endif LIST_H_
