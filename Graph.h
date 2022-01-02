#ifndef GRAPH_
#define GRAPH_

typedef struct Node_ *pNode;
#define CHILD_TO_PARENT = 0, PARENT_TO_CHILD = 1


typedef struct Edge_{
  int weight;
  int dest;

}Edge;
typedef Edge* pEdge;

typedef struct Node_{
  int id, edges_size;
  pEdge *edges;
}Node;
typedef Node* pNode;

typedef struct Graph_{
  int size;
  pNode *head;
}Graph;
typedef Graph* pGraph;


void init_graph(pGraph g, int size);
void add_node(pGraph g,int id);
void add_edge(pGraph g, int node1,int dest,int weight);
void delete_graph(pGraph g);
void delete_node(pGraph g,pNode node);
pNode get_node(pGraph g, int id);
void print_graph(pGraph g);





#endif
