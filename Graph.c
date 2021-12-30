#include <stdio.h>
#include <stdlib.h>





void add_node(pGraph *g,int id){
  if(g->size > id){
    g->head = realloc(g->head, sizeof(g->head) + (id-g->size+1)*sizeof(pnode));
    if(g->head == NULL){
      free(g);
      printf("memory error, unable to alocate memory to add node!");
      exit(0);
    }
  }

  if(g->head[id]){
      del_out_edges(g,id);
  }
  else{
    g->head[id]->id = id;
  }
}


void add_edge(pNode *src,pNode *dest,int weight){

}


void delete_graph(pGraph *g){

}

void delete_node(pNode *node){
  del_in_edges(node);
  del_out_edges(node);
  free(node);
  node = NULL
}




void del_out_edges(pNode* node){
  for(int i=0; i<node->out_edges_size; i++){
    if(node->out_edges[i]){
      free(node->out_edges[i]->dest->in_edges[node->id]);
    }
  }
  node->out_edges_size = 0;
  free(node->out_edges);
  node->out_edges = NULL;
}

void del_in_edges(pNode *node){
  for(int i=0; i<npde->in_edges_size; i++){
    if(node->in_edges[i]){
      free(node->in_edges[i]->dest->out_edges[node->id]);
    }
  }
  node->in_edges_size = 0;
  free(node->in_edges);
  node->in_edges = NULL;
}



pnode * get_node(pGraph *g, int id){
  if(g->size > id){
    return g->head[id];
  }
  return NULL;
}
