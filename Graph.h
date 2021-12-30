#ifndef GRAPH_
#define GRAPH_

typedef struct Node_ *pnode;
#define CHILD_TO_PARENT = 0, PARENT_TO_CHILD = 1


typedef struct Edge_{
  int weight;
  pNode dest;

}Edge, *pEdge;

typedef struct Node_{
  int id, out_edges_size, in_edges_size;
  pedge out_edges;
  pedge in_edges;
}Node, *pNode;

typedef struct Graph_{
  int size;
  pnode head;
}Graph, *pGraph



void add_node(pGraph *g,int id);
void add_edge(pNode *src, pNode *dest ,int weight);


void delete_graph(pGraph *g);






#endif
