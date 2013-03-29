#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _graph_nopoint_{
	void *data;
	int vn;
}Graph;

Graph *init_graph(int vn);
int creat_graph(Graph *gra);
int free_graph_edge(Graph *gra);
int add_edge(Graph *gra, int v1, int v2);
int display_relation(Graph *gra);
