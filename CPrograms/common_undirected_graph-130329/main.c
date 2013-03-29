#include "graph.h"

int main()
{
	Graph *gra = NULL;
	int vn;

	puts("Please input the size of vertex: ");
	scanf("%d", &vn);
	gra = init_graph(vn);
	creat_graph(gra);
	display_relation(gra);

	free_graph_edge(gra);

	return 0;
}

Graph *init_graph(int vn)
{
	Graph *gra = NULL;

	gra = (Graph *)malloc(sizeof(Graph));
	gra->data = malloc(vn * vn);
	gra->vn = vn;

	return gra;
}

int creat_graph(Graph *gra)
{
	int v1 = 0,
		v2 = 0;

	while(1)
	{
		while(2 != scanf("%d,%d", &v1, &v2))
			getchar();
		if(v1 == v2)
			break;
		if(v1 < 0 || v1 >= gra->vn || v2 < 0 || v2 >= gra->vn)
			continue;
		add_edge(gra, v1, v2);
		add_edge(gra, v2, v1);
	}
	return 0;
}

int free_graph_edge(Graph *gra)
{
	free(gra);

	return 0;
}

int add_edge(Graph *gra, int v1, int v2)
{
	((char(*)[gra->vn])gra->data)[v1][v2] = 1;	//line pointer

	return 0;
}
 
int display_relation(Graph *gra)
{
	int i,j;

	for(i = 0; i < gra->vn; i++)
	{
		printf("v%d: ", i);
		for(j = 0; j < gra->vn; j++)
			if(((char(*)[gra->vn])gra->data)[i][j])
				printf(" v%d,", j);
		puts("\b ");
	}
	return 0;
}
