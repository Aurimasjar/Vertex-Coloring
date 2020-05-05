#ifndef GENERATOR_H
#define GENERATOR_H

#include "graph.h"
#include <ctime>

class GraphGenerator
{
	public:
	
	GraphGenerator();

	Graph generateUniformGraph(int n, float p);
	
	Graph generateMEdgeGraph(int n, int m);
};

#endif