#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "List.h"
#include "Node.c"
#include "Edge.c"
#include "Graph.h"

pGraph createGraph(){
  pGraph graph = (pGraph)malloc(sizeof(Graph));
  if(graph != NULL){
    graph->nodes = createList(nodeGetId,delNode,compareNode,printNode);
    if(graph->nodes == NULL){
      free(graph);
      return NULL;
    }
  }
  else{

    return NULL;
  }
  return graph;
}

pNode getNode(pGraph graph,int id){
  pNode out;
  int idx = findIndexOf(graph->nodes,id);
  if(idx!=-1){
    out = (pNode) get(graph->nodes,idx);
    return out;
  }
  return NULL;
}

pEdge getEdge(pGraph graph, int src, int dest){
  pNode node;
  pEdge edge;
  if((node = getNode(graph,src))){
    int idx = findIndexOf(node->edges_out,dest);
    if(idx != -1){
      edge = (pEdge)get(node->edges_out,idx);
      return edge;
    }
  }
  return NULL;
}


Bool addEdge(pGraph graph, int src, int dest, int weight){
  pEdge edge;
  if(!(edge = getEdge(graph,src,dest))){
    pNode node;
    if((node = getNode(graph,src))){
      if((edge = createEdge(src,dest,weight))){
        if(!addElem(node->edges_out,edge)){
          printf("couldn't add edge to node\n");
          return false;
        }
        return true;
      }
      printf("couldn't create edge\n");
      return false;
    }
    else{
      printf("src doesn't exist\n");
      return false;
    }
  }

  printf("edge exists\n");
  return false;

}



Bool addNode(pGraph graph, int id){
  pNode node = getNode(graph,id);
  if(node != NULL){
    deleteList(node->edges_out);
    if(!(node->edges_out = createList(getEdgeDest,delEdge,compareEdge,printEdge))){
        printf("could not delete node edges\n");
        return false;
    }
    return true;
  }
  else if((node = createNode(id))){
    if(!addElem(graph->nodes,node)){
      printf("could not add a new node\n");
      return false;
    }
    return true;
  }
  else{
    printf("could not create a new node\n");
    return false;
  }
  return false;
}



void printGraph(pGraph graph){
  printList(graph->nodes);
}


void delGraph(pGraph graph){
  deleteList(graph->nodes);
  free(graph);
}
pNode getINode(pGraph graph, int i){
  return (pNode)get(graph->nodes,i);
}
pEdge getIJEdge(pGraphgraph,int i, int j){
  return (pEdge) get(getINode(graph,i)->edges_out,j);
}

int* shortestPath(pGraph graph, int src){
  int* dist = malloc(sizeof(int)*getSize(graph->nodes));
  Bool* visited = malloc(sizeof(int)*getSize(graph->nodes));
  for(int i=0; i<getSize(graph->nodes); i++){
    dist[i]=INT_MAX;
    visited[i] = false;
  }
  dist[findIndexOf(graph->nodes,src)] = 0;

  for(int src_node=0; src_node<getSize(graph->nodes); src_node++){
    int min=INT_MAX, minIDX;
    for(int dest_node=0; dest_node<getSize(getINode(graph,src)->edges_out); dest_node++){
      if(getIJEdge(src_node,dest_node)->weight < min && visited==false){
        min = getIJEdge(src_node,dest_node)->weight;
        minIDX = dest_node;
      }
    }
      visited[minIDX]=true;

    for(int dest_node=0; dest_node<getSize(getINode(graph,src)->edges_out); dest_node++){
      pEdge edge = getIJEdge(minIDX,dest_node);

      if(visited[dest_node]==false && edge!=NULL && dist[edge->src]+edge->weight < dist[edge->dest]
         && dist[edge->src]!=INT_MAX ){
            dist[edge->dest] = dist[edge->src]+edge->weight;
      }
    }
  }
  free(visited);






  return dist;

}
