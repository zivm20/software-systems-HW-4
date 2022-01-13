#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"
#include "List.h"


int main(){

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
      scanf("%c %d",&current_function,&V_size);
      if(graph != NULL){
        free(graph);
      }
      graph = createGraph();
    }
    else if(current_char == 'T'){
      int tsp_k_size;
      int idx = 0;
      scanf("%c %d",&current_function,&tsp_k_size);
      current_function = 'T';

      int *tspNodes  = (int*)malloc(tsp_k_size*sizeof(int));
      while(tsp_k_size > idx){
        int node_target;
        scanf(" %d",&node_target);
        tspNodes[idx] = node_target;
        idx++;
      }

      idx = 0;
      //tsp = TSP(graph,tpsNodes);
      //printf("TSP shortest path: %d\n",tsp);

      free(tspNodes);
    }
    else if(current_char == 'S'){
      int n1,n2;
      scanf("%c %d %d",&current_function,&n1,&n2);
      int* pathLens = shortestPath(graph,n1);
      

      printf("Dijsktra shortest path: %d \n",pathLens[n2]);
      free(pathLens);
    }
    else if(current_char == 'D'){
      int node_id;
      scanf("%c %d",&current_function,&node_id);

    }
    else if(current_char == 'B'){
      scanf("%c %d",&current_function,&node_num);
      addNode(graph,node_num);
    }
    else if(current_char!=' ' &&(current_function == 'A' || current_function == 'B')){
      if(current_char == 'n'){
        scanf(" n %d",&node_num);
        addNode(graph,node_num);
      }
      else{
        scanf(" %d %d",&dest,&weight);

        addEdge(graph,node_num,dest,weight);

      }
    }
    else{
      scanf("%c",&current_char);

    }
    iter++;


  }while(current_char!='\n');
  delGraph(graph);

  return 0;
}
