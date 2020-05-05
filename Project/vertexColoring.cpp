#include "vertexColoring.h"


vector<int> VertexColorer::coloringWithBacktracking(Graph &graph, int colorCount)
{
	vector<int> vcr(graph.size(), 0);
	bool exit = false;
	vcr = colorB(graph, colorCount, 0, vcr, exit);
	return vcr;
}

vector<int> VertexColorer::colorB(Graph &graph, int &colorCount, int k, vector<int> &vcr, bool &exit)
{
	if(k >= graph.size())
	{
		exit = true;
		//display(vcr);
		return vcr;
	}
	for(int i = 1; i <= colorCount; i++)
	{	
		vcr[k] = i;
		if(coloringPossible(graph, k, vcr))
		{
			colorB(graph, colorCount, k + 1, vcr, exit);
			if(exit) return vcr;
		}
	}
	return vcr;
}

bool VertexColorer::coloringPossible(Graph &graph, int k, vector<int> &vcr)
{
	for(int i = 0; i < k; i++)
	{
		if(graph.isEdge(i, k) && vcr[i] == vcr[k])
		{
			return false;
		}
	}
	return true;
}


void VertexColorer::display(vector<int> &vcr)
{
	for(int i = 0; i < vcr.size(); i++)
	{
		cout << vcr[i] << " ";
	} cout << endl;
}


vector<int> VertexColorer::fiveColorColoring(Graph &graph)
{
	vector<int> coloring(graph.size(), 0);
	vector<bool> usedVertexes(graph.size(), true);
	fiveColRec(graph, coloring, usedVertexes, graph.size());
	return coloring;
}

void VertexColorer::fiveColRec(Graph &graph, vector<int> &coloring, vector<bool> &usedVertexes, int vertexesCount)
{
	if(vertexesCount <= 5)
	{
		int colors = 1;
		for(int i = 0; i < graph.size(); i++)
		{
			if(usedVertexes[i])
			{
				coloring[i] = colors;
				colors++;
			}
		}
		return;
	}
	for(int i = 0; i < graph.size(); i++)
	{
		if(usedVertexes[i] && graph.getVertexNeighboursAmount(i) <= 5)
		{
			usedVertexes[i] = false;
			fiveColRec(graph, coloring, usedVertexes, vertexesCount - 1);
			
			/*if(!areNeighboursProperlyColored(graph, coloring, usedVertexes, i))
			{
				//modify coloring for G-i
				vector<vector<int>> transitiveClosure = getTransitiveClosure(graph, usedVertexes);
				
				for(int j = 0; j < graph.size(); j++)
				{
					for(int k = 0; k < graph.size(); k++)
					{
						if(!graph.isEdge(j, k) && usedVertexes[j] && graph.isEdge(i, j) && usedVertexes[k] && graph.isEdge(i, k))
						{
							//recolor vertex j and this component
							int color1 = coloring[j];
							int color2 = coloring[k];
							for(int l = 0; l < graph.size(); l++)
							{
								if(!transitiveClosure[l][k])
								{
									if(coloring[l] == color1) coloring[l] = color2;
									else if(coloring[l] == color2) coloring[l] = color1;
								}
							}
						}
					}
				}
			}*/
			
			setProperColor(graph, coloring, usedVertexes, i);
			usedVertexes[i] = true;
			break;
		}
	}
}

bool VertexColorer::areNeighboursProperlyColored(Graph &graph, vector<int> &coloring, vector<bool> &usedVertexes, int v)
{
	bool canBeColored;
	for(int i = 1; i <= 5; i++)
	{
		canBeColored = true;
		for(int j = 0; j < graph.size(); j++)
		{
			if(usedVertexes[j] && graph.isEdge(v, j) && coloring[j] == i)
			{
				canBeColored = false;
				break;
			}
		}
		if(canBeColored)
		{
			return true;
		}
	}
	return false;
}

void VertexColorer::setProperColor(Graph &graph, vector<int> &coloring, vector<bool> &usedVertexes, int v)
{
	bool colored;
	for(int i = 1; i <= 5; i++)
	{
		colored = true;
		for(int j = 0; j < graph.size(); j++)
		{
			if(usedVertexes[j] && graph.isEdge(v, j) && coloring[j] == i)
			{
				colored = false;
				break;
			}
		}
		if(colored)
		{
			coloring[v] = i;
			break;
		}
	}
}

vector<vector<int>> VertexColorer::getTransitiveClosure(Graph &graph, vector<bool> &usedVertexes)
{
	vector<vector<int>> transitiveClosure(graph.size(), vector<int>(graph.size()));
	for(int i = 0; i < graph.size(); i++)
	{
		for(int j = 0; j < graph.size(); j++)
		{
			for(int k = 0; k < graph.size(); k++)
			{
				if(graph.isEdge(i, j) || usedVertexes[k] && graph.isEdge(i, k) && graph.isEdge(k, j))
				{
					transitiveClosure[i][j] = 1;
				}
			}
		}
	}
	return transitiveClosure;
}