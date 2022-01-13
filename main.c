#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"
#include "List.h"


int main(){
  //scanf("%c",&current_char);
  //printf("%c",current_char);
  char current_function;
  int node_num;
  int V_size=0;
  int iter = 0;
  int dest;
  int weight;
  char current_char;
  pGraph graph = NULL;



  do{
    current_char = getchar();
    ungetc(current_char,stdin);

    if(current_char == 'A'){
      scanf("%c %d ",&current_function,&V_size);
      if(graph != NULL){
        free(graph);
      }
      graph = createGraph();
      //printf("27: %c %d \n",current_function,V_size);
      //printf("%c %d ",current_function,V_size);
    }
    else if(current_char == 'T'){
      int tsp_k_size;
      int idx = 0;
      scanf("%c %d ",&current_function,&tsp_k_size);
      current_function = 'T';

      int *tspNodes  = (int*)malloc(tsp_k_size*sizeof(int));
      while(tsp_k_size > idx){
        int node_target;
        scanf("%d ",&node_target);
        tspNodes[idx] = node_target;
        idx++;
      }
      pList lst = TSP(graph, tspNodes);
      printList(lst);
      deleteList(lst);
      free(tspNodes);
    }
    else if(current_char == 'S'){
      int n1,n2;
      scanf("%c %d %d ",&current_function,&n1,&n2);
      pList lst = shortestPath(graph,n1,n2);
      printList(lst);
      deleteList(lst);
    }
    else if(current_char == 'D'){
      int node_id;
      scanf("%c %d ",&current_function,&node_id);
      removeNode(graph,n1);
    }
    else if(current_char == 'B'){
      scanf("%c %d",&current_function,&node_num);
      addNode(graph,node_num);
    }
    else if(current_function == 'A' || current_function == 'B'){
      if(current_char == 'n'){
        scanf("n %d ",&node_num);
        //printf("36: n %d \n",node_num);
        //printf("n %d ",node_num);
        //printf("%d\n",node_num);
        addNode(graph,node_num);
        //printf("node %d\n",node_num);

      }
      else{
        scanf("%d %d ",&dest,&weight);

        addEdge(graph,node_num,dest,weight);

      }
    }
    else{
      scanf("%c",&current_char);

    }
    iter++;


  }while(iter < 15 && current_char!='\n');
  printGraph(graph);
  delGraph(graph);
  printf("done");
  return 0;
}
