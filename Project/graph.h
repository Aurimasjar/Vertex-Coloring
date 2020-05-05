#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

class Graph
{
    private:

    int vertex_amount;
	std::vector<std::vector<int>> matrix;
	std::vector<int> deg;
	
    public:

    //bool matrix[V][V];

    //Graph(bool graph[V][V], int vertex = V);
	//Graph(int **graph, int vertex = 1);
	Graph(int **graph, int vertex = 1);
    Graph(int vertex = 1);
	Graph(const Graph &copy);
    ~Graph();
	
    bool isEdge(int x, int y);
    void addEdge(int x, int y);
    void removeEdge(int x, int y);

    void addVertex(int n = 1);
    void removeVertex(int v);

    int getEdgeAmount();
    int getVertexAmount();

    int getVertexNeighboursAmount(int v);
    int getVertexNeighbour(int v, int i);
	
	int getMaxDeg(); //returns position of maxdeg vertex
	int maxDeg(); //returns value of maxdeg vertex

    std::vector<int> getDegrees();
	
	int size() { return vertex_amount; }

    void print();
	
};

class Row
{
	public:
	int value;
	int pos;
	Row(int v = 0, int p = 0) : value(v), pos(p) {}
};

#endif
