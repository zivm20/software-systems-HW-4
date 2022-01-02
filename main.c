#include "Graph.h"
#include <stdio.h>
#include <stdlib.h>



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
  Graph g;
  pGraph graph = &g;





  do{
    current_char = getchar();
    ungetc(current_char,stdin);

    if(current_char == 'A'){
      scanf("%c %d ",&current_function,&V_size);

      init_graph(graph,V_size);
      //printf("27: %c %d \n",current_function,V_size);
      //printf("%c %d ",current_function,V_size);
    }
    else if(current_char == 'T'){
      break;
    }

    else if(current_function == 'A'){
      if(current_char == 'n'){
        scanf("n %d ",&node_num);
        //printf("36: n %d \n",node_num);
        //printf("n %d ",node_num);
        //printf("%d\n",node_num);
        add_node(graph,node_num);
        //printf("node %d\n",node_num);

      }
      else{
        scanf("%d %d ",&dest,&weight);

        //printf("42: %d %d \n",dest,weight);
        //printf("%d %d ",dest,weight);
        //printf("(%d,%d)(%d)\n",node_num,dest,weight);
        add_edge(graph,node_num,dest,weight);

      }
    }
    else{
      scanf("%c",&current_char);
      //printf("47: %c\n",current_char);
      //printf("%c",current_char);
    }
    iter++;


  }while(iter < 15 && current_char!='\n');
  print_graph(graph);
  delete_graph(graph);
  printf("done");
  return 0;
}
