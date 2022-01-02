#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"




void del_out_edges(pNode node){
  pEdege temp;
  while(node->edges != NULL){
    temp = node->edges;
    node->edges = node->edges->next;
    free(temp);
  }
}

void del_in_edges(pGraph g, pNode node){
  pNode current_node = g->head;
  while(current_node != NULL){
    pEdge current_edge = current_node->edges;
    pEdge temp;
    if(current_edge != NULL && current_edge->dest == node->id){
      current_node->edges = current_edge->next;
      free(current_edge);
    }
    else{
      while(current_edge->next != NULL && current_edge->dest < node->id){
        if(current_edge->next->dest == node->id){
          current_edge->next = temp;
          current_edge->next = current_edge->next->next;
          free(temp);
        }
        current_edge = current_edge->next;
      }
    }
    current_node = current_node->next;
  }
}

void init_graph(pGraph g, int size){
  g->head = malloc(sizeof(Node));
  g->size = size;
}

pNode createNode(int id){
    pNode n = malloc(sizeof(Node));
    n->id = id;
    n->edges = NULL;
    n->next = NULL;
    n->edges_size = 0;
}

void add_node(pGraph g,int id){
  pNode current;

  if(g->head != NULL || g->head->id >= id){
    if(g->head->id==id){
      del_out_edges(current->next);
    }
    else{
      pNode temp = createNode(id);
      temp->next = g->head;
      g->head = temp;
    }
  }
  else{
    current = g->head;
    while(current->next != NULL && current->next->id < id){
      current = current->next;
    }
    if(current->next->id==id){
      del_out_edges(current->next);
    }
    else{
      pNode temp = createNode(id);
      temp->next = current->next;
      current->next = temp;
    }
  }
}

void add_edge(pGraph g, int node1,int dest,int weight){
  pNode node = get_node(g,node1);
  pEdge current;
  if(node->edges != NULL || node->edges->dest >= dest){
    if(node->edges->dest==dest){
      del_out_edges(current->next);
    }
    else{
      pEdge temp = malloc(sizeof(Edge));
      temp->next = NULL;
      temp->weight t =weight;
      temp->dest = dest;
      temp->next = node->edges;
      node->edges = temp;
    }
  }
  else{
    current = node->edges;
    while(current->next != NULL && current->next->dest < dest){
      current = current->next;
    }
    if(current->next->dest==id){
      del_out_edges(current->next);
    }
    else{
      pEdge temp = malloc(sizeof(Edge));
      temp->next = NULL;
      temp->weight t =weight;
      temp->dest = dest;
      temp->next = current->next;
      current->next = temp;
    }
  }
}

void print_graph(pGraph g){
  pNode current_node = g->head;
  while(current_node != NULL){
    pEdge current_edge = current_node->edges;
    while(current_edge->next != NULL){
      printf("(%d -> %d)(%d) ",current_node->id,current_edge->dest,current_edge->weight);
      current_edge = current_edge->next;
    }
    current_node = current_node->next;
  }
}

void delete_graph(pGraph g){
  pNode current;
  while(g->head != NULL){

    delete_node(g,g->head)
    current = g->head;
    g->head = g->head->next;
    free(current);
  }
  free(g);
}

void delete_node(pGraph g,pNode node){
  del_in_edges(g,node);
  //printf("del in edges complete for %d\n",node->id);
  del_out_edges(node);
  //printf("del out edges complete for %d\n",node->id);
}

pNode get_node(pGraph g, int id){
  pNode current = g->head;
  while(current->id <= id){
    if(current->id == id ){
      return current;
    }
    current=current->next;
  }
  return NULL;
}
