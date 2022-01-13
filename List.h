#ifndef LIST_H_
#define LIST_H_

typedef struct List_ *pList,List;

typedef enum Bool_{false = 0,true} Bool;
typedef void *pElement;


typedef int (*GET_KEY)(pElement);
typedef void (*DELETE_ELEMENT)(pElement);
typedef Bool (*COMPARE)(pElement,pElement);
typedef void (*PRINT_ELEMENT)(pElement);


pList createList(GET_KEY,DELETE_ELEMENT,COMPARE,PRINT_ELEMENT);
Bool addElem(pList,pElement);
Bool removeElem(pList,pElement);
void printList(pList);
void deleteList(pList);

pElement get(pList,int);
int indexOf(pList, pElement);
int findIndexOf(pList,int);



#endif
