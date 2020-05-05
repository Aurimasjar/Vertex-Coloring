#include "generator.h"

GraphGenerator::GraphGenerator() 
{
	srand(time(NULL)); 
}

Graph GraphGenerator::generateUniformGraph(int n, float p)
{
	int **mat = new int*[n];
	for(int i = 0; i < n; ++i)
	{
		mat[i] = new int [n];
	}
	
	for(int i = 0; i < n; i++)
		mat[i][i] = 0;
	
	for(int i = 0; i < n; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			mat[i][j] = ((rand() % (100) < 100*p)  ?  1  :  0);
			mat[j][i] = mat[i][j];
		}
	}
		
	Graph graph(mat, n);
	return graph;
}

Graph GraphGenerator::generateMEdgeGraph(int n, int m)
{	
	Graph graph(n);
	int a, b;
	for(int i = 0; i < m;)
	{
		a = rand() % n;
		b = rand() % n;
		if(a != b && !graph.isEdge(a, b))
		{
			graph.addEdge(a, b);
			i++;
		}
	}
	
	return graph;
}