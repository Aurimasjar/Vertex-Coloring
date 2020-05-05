#ifndef VERTEXCOLORING_H
#define VERTEXCOLORING_H

#include <vector>
#include "graph.h"

class VertexColorer
{
	public:
	
	vector<int> coloringWithBacktracking(Graph &graph, int colorCount);
	vector<int> colorB(Graph &graph, int &colorCount, int k, vector<int> &vcr, bool &exit);
	bool coloringPossible(Graph &graph, int k, vector<int> &vcr);
	
	vector<int> fiveColorColoring(Graph &graph);
	void fiveColRec(Graph &graph, vector<int> &coloring, vector<bool> &usedVertexes, int vertexesCount);
	bool areNeighboursProperlyColored(Graph &graph, vector<int> &coloring, vector<bool> &usedVertexes, int v);
	void setProperColor(Graph &graph, vector<int> &coloring, vector<bool> &usedVertexes, int v);
	vector<vector<int>> getTransitiveClosure(Graph &graph, vector<bool> &usedVertexes);
	
	void display(vector<int> &vcr);
};

#endif
