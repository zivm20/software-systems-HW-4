#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"


void del_out_edges(pNode node){
  node->edges_size = 0;
  free(node->edges);
  node->edges = NULL;
}

void del_in_edges(pGraph g, pNode node){
  for(int i=0; i<g->size; i++){
    pNode src_node = get_node(g,i);
    if(src_node){
      if(src_node->edges_size > node->id){
        if(src_node->edges[node->id] != NULL){
          free(src_node->edges[node->id]);
          src_node->edges[node->id]=NULL;
        }
      }
    }
  }

}

void init_graph(pGraph g, int size){
  g->head = malloc(size * sizeof(pNode) );
  g->size = size;
}

void add_node(pGraph g,int id){
  if(g->size < id){
    g->head = realloc(g->head, (id+1)*sizeof(pNode));
    g->size = id+1;
    if(g->head == NULL){
      delete_graph(g);
      printf("memory error, unable to alocate memory to add node!");
      exit(0);
    }
  }

  if(g->head[id]){
      del_out_edges(g->head[id]);
  }
  else{
    g->head[id] = malloc(sizeof(Node));
    g->head[id]->id = id;
    g->head[id]->edges_size = 0;
    g->head[id]->edges = NULL;

  }
}
void add_edge(pGraph g, int node1,int dest,int weight){


  pNode src = get_node(g,node1);


  if(src->edges==NULL){
    src->edges = malloc((dest+1)*sizeof(pEdge));
  }
  else if(src->edges_size < dest){
    src->edges = realloc(src->edges, sizeof(pEdge)*(dest+1));
    src->edges_size = dest;
    if(src->edges==NULL){
      delete_graph(g);
      printf("memory error, unable to alocate memory to add node!");
      exit(0);
    }
  }
  src->edges[dest] = malloc(sizeof(Edge));
  src->edges[dest]->weight = weight;
  src->edges[dest]->dest = dest;
  src->edges_size+=1;
}

void print_graph(pGraph g){
  for(int src=0; src<g->size; src++){
    pNode node = get_node(g,src);
    if(node){
      printf("%d: ",node->id);
      for(int dest=0; dest<node->edges_size; dest++){
        if(node->edges[dest] != NULL){
          printf("(%d -> %d) (%d) ",node->id,node->edges[dest]->dest,node->edges[dest]->weight);
        }
      }
      printf("\n");
    }
  }
}


void delete_graph(pGraph g){
  for(int i=0; i<g->size; i++){
    if(get_node(g,i)!=NULL){
      delete_node(g,get_node(g,i));
    }
  }
  printf("deleated all\n");
  free(g->head);
  printf("deleated head\n");
  free(g);
  printf("freed graph\n");

  g = NULL;
}

void delete_node(pGraph g,pNode node){
  del_in_edges(g,node);
  printf("del in edges complete for %d\n",node->id);
  del_out_edges(node);
  printf("del out edges complete for %d\n",node->id);
  int n = node->id;
  free(node);
  node = NULL;

}

pNode get_node(pGraph g, int id){

  if(g->size > id){

    return g->head[id];
  }
  return NULL;
}
