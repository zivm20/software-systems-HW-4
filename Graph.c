#include <stdio.h>
#include <stdlib.h>


void add_node(pGraph *g,int id){
  if(g->size <= id){
    g->head = realloc(g->head, sizeof(g->head) + (id-g->size+1)*sizeof(Node));
    if(g->head == NULL){
      delete_graph(g);
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

void add_edge(pGraph*g, pNode *src,pNode *dest,int weight){
  add_edge_(g,src->out_edges_size,src->out_edges,dest,weight);
  add_edge_(g,dest->out_edges_size,dest->in_edges,src,weight);
}

void add_edge_(pGraph *g, int edgeSize, pEdge *nodeEdges,pNode *dest,int weight){
  if(edgeSize <= dest->id){
    nodeEdges = realloc(nodeEdges, sizeof(nodeEdges) + (dest->id-nodeSize+1)*sizeof(Edge));
    if(g->head == NULL){
      delete_graph(g);
      printf("memory error, unable to alocate memory to add node!");
      exit(0);
    }
  }
  nodeEdges[dest->id]->weight = weight;
  nodeEdges[dest->id]->dest = dest;
}


void delete_graph(pGraph *g){
  for(int i=0; i<g->size; i++){
    if(get_node(g,i)){
      delete_node(get_node(g,i));
    }
  }
  free(g);
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



pNode * get_node(pGraph *g, int id){
  if(g->size > id){
    return g->head[id];
  }
  return NULL;
}
