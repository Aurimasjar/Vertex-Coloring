#include <iostream>
#include <ctime>
#include "graph.h"
#include "vertexColoring.h"
#include "generator.h"

using namespace std;

void testBacktrackColoring(Graph graph)
{
	VertexColorer painter;
	
	//color graph with 5 colors
	vector<int> result = painter.coloringWithBacktracking(graph, 5);
	
	cout << "Backtracking coloring:" << endl;
	for(int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	} cout << endl;
}

void testFiveKColoring(Graph graph)
{
	VertexColorer painter;
	
	//color graph with 5 colors
	vector<int> result = painter.fiveColorColoring(graph);
	
	cout << "5k coloring:" << endl;
	for(int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	} cout << endl;
}

void testSpeed(Graph graph, int n, int m)
{
	fstream file;
	file.open("results.txt", std::ios_base::app);
	file << n << " " << m << " ";
	vector<int> result;
	VertexColorer painter;
	
	clock_t begin = clock();
	result = painter.coloringWithBacktracking(graph, 5);
	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	file << elapsed_secs << " ";
	
	/*cout << "Backtracking coloring:" << endl;
	for(int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	} cout << endl;*/
	
	begin = clock();
	result = painter.fiveColorColoring(graph);
	end = clock();
	elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	file << elapsed_secs << endl;
	
	/*cout << "5k coloring:" << endl;
	for(int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	} cout << endl;*/
	
	file.close();
}

void findEUColoring()
{
	VertexColorer painter;
	
	string countries[27] = {"Austria", "Belgium", "Bulgaria", "Croatia", "Republic of Cyprus", "Czech Republic", "Denmark", 
	"Estonia", "Finland", "France", "Germany", "Greece", "Hungary", "Ireland", "Italy", "Latvia", "Lithuania", "Luxembourg", 
	"Malta", "Netherlands", "Poland", "Portugal", "Romania", "Slovakia", "Slovenia", "Spain", "Sweden"};
	
	
	Graph euGraph(27);
	
	euGraph.addEdge(0, 5);
	euGraph.addEdge(0, 10);
	euGraph.addEdge(0, 12);
	euGraph.addEdge(0, 14);
	euGraph.addEdge(0, 23);
	euGraph.addEdge(0, 24);
	
	euGraph.addEdge(1, 9);
	euGraph.addEdge(1, 10);
	euGraph.addEdge(1, 17);
	euGraph.addEdge(1, 19);
	
	euGraph.addEdge(2, 11);
	euGraph.addEdge(2, 22);
	
	euGraph.addEdge(3, 12);
	euGraph.addEdge(3, 24);
	
	euGraph.addEdge(5, 10);
	euGraph.addEdge(5, 20);
	euGraph.addEdge(5, 23);
	
	euGraph.addEdge(6, 10);
	
	euGraph.addEdge(7, 15);
	
	euGraph.addEdge(8, 26);
	
	euGraph.addEdge(9, 10);
	euGraph.addEdge(9, 14);
	euGraph.addEdge(9, 17);
	euGraph.addEdge(9, 25);
	
	euGraph.addEdge(10, 17);
	euGraph.addEdge(10, 19);
	euGraph.addEdge(10, 20);
	
	euGraph.addEdge(12, 22);
	euGraph.addEdge(12, 23);
	euGraph.addEdge(12, 24);
	
	euGraph.addEdge(14, 24);
	
	euGraph.addEdge(15, 16);
	
	euGraph.addEdge(16, 20);
	
	euGraph.addEdge(20, 23);
	
	euGraph.addEdge(21, 25);
	
	
	vector<int> result1 = painter.coloringWithBacktracking(euGraph, 5);
	vector<int> result2 = painter.fiveColorColoring(euGraph);
	
	cout << "EUROPEAN UNION MAP COLORING" << endl;
	cout << "i  c1 c2 Country" << endl;
	for(int i = 0; i <= 9; i++)
	{
		cout << i << "   " << result1[i] << "  " << result2[i] << "  " << countries[i] << endl;
	}
	for(int i = 10; i < 27; i++)
	{
		cout << i << "  " << result1[i] << "  " << result2[i] << "  " << countries[i] << endl;
	}
}

int main()
{
	/*Graph graph(7);
	graph.addEdge(0, 1);
	graph.addEdge(0, 2);
	graph.addEdge(0, 3);
	graph.addEdge(0, 4);
	graph.addEdge(0, 6);
	graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 3);
	graph.addEdge(2, 5);
	graph.addEdge(2, 6);
	graph.addEdge(4, 6);
	graph.addEdge(5, 6);*/
	
	/*int n = 100;
	int m = 280;
	
	GraphGenerator gen;
	Graph graph = gen.generateMEdgeGraph(n, m);
	//graph.print();
	
	testSpeed(graph, n, m);*/
	
	findEUColoring();
}