#include "graph.h"

using namespace std;

Graph::Graph(int **graph, int vertex) : vertex_amount(vertex), matrix(vertex_amount, std::vector<int>(vertex_amount, 0))
{
	//std::cout<<"Graph(m)"<<std::endl;
	deg.resize(vertex_amount);
    ///graph init
    for(int i = 0; i < vertex_amount; i++)
    {
        for(int j = 0; j < vertex_amount; j++)
        {
            matrix[i][j] = graph[i][j];
			deg[i] += matrix[i][j];
        }
    }
}

Graph::Graph(int vertex)
{
	//std::cout<<"Graph()"<<std::endl;
    ///graph size init
    vertex_amount = vertex;

    ///graph init
    matrix.resize(vertex_amount);
    for(int i = 0; i < vertex_amount; i++)
    {
        matrix[i].resize(vertex_amount);
        for(int j = 0; j < vertex_amount; j++)
        {
            matrix[i][j] = 0;
        }
    }

    ///error bounds init
    //not able to do and not necessary while graph is implemented with bool matrix
    /*for(int i = vertex; i < V; i++)
    {
        for(int j = 0; j < V; j++)
        {
            matrix[i][j] = 0;
        }
    }
    for(int i = 0; i < vertex; i++)
    {
        for(int j = vertex; j < V; j++)
        {
            matrix[i][j] = 0;
        }
    }*/
    //std::cout<<"leaving Graph()"<<std::endl;
}

Graph::Graph(const Graph &copy) : vertex_amount(copy.vertex_amount), matrix(copy.vertex_amount, std::vector<int>(copy.vertex_amount, 0))
{
	//std::cout<<"Graph(copy)"<<std::endl;

	for(int i = 0; i < vertex_amount; i++)
    {
        for(int j = 0; j < vertex_amount; j++)
        {
            matrix[i][j] = copy.matrix[i][j];
        }
    }
}

Graph::~Graph(){ /*std::cout<<"~Graph()"<<std::endl;*/ }

bool Graph::isEdge(int x, int y)
{
    if(x < 0 || x >= vertex_amount || y < 0 || y >= vertex_amount)
    {
        cout<<"Out of bounds!"<<endl;
        return false;
    }
    else if(x == y)
    {
        //cout<<"Loop edge is not possible: this is an disoriented graph!"<<endl;
        return false;
    }
    else if(matrix[x][y] != 0)
    {
        //cout<<"Edge ("<<x<<","<<y<<") exists"<<endl;
        return true;
    }
    return false;
}

void Graph::addEdge(int x, int y)
{
    if(x < 0 || x >= vertex_amount || y < 0 || y >= vertex_amount)
    {
        cout<<"Out of bounds!"<<endl;
    }
    else if(x == y)
    {
        cout<<"Loop addition is impossible: this is an disoriented graph!"<<endl;
    }
    else if(matrix[x][y] != 0)
    {
        cout<<"Edge ("<<x<<","<<y<<") already exists!"<<endl;
    }
    else
    {
        matrix[x][y] = 1;
        matrix[y][x] = 1;
    }
}

void Graph::removeEdge(int x, int y)
{
    if(x < 0 || x >= vertex_amount || y < 0 || y >= vertex_amount)
    {
        cout<<"Out of bounds!"<<endl;
    }
    else if(x == y)
    {
        cout<<"Loop removal is impossible: this is an disoriented graph!"<<endl;
    }
    else if(matrix[x][y] == 0)
    {
        cout<<"No edge found!"<<endl;
    }
    else
    {
        matrix[x][y] = 0;
        matrix[y][x] = 0;
    }
}

void Graph::addVertex(int n)
{
    if(n <= 0)
    {
        cout<<"Vertex quantity should be positive!"<<endl;
    }
	else
	{
		for(int k = 0; k < n; k++)
		{
			for(int i = 0; i < vertex_amount; i++)
				matrix[i][vertex_amount + k - 1] = 0;

			for(int j = 0; j < vertex_amount + 1; j++)
				matrix[vertex_amount  + k - 1][j] = 0;

			vertex_amount++;
		}
	}
}

void Graph::removeVertex(int v)
{
    if(v < 0 || v >= vertex_amount)
    {
        cout<<"Wrong vertex number ("<<v<<"): it must be positive and less than vertex quantity ("<<vertex_amount<<")"<<endl;
    }
    if(vertex_amount > 0)
    {
        /*for(int i = 0; i < vertex_amount; i++)
            matrix[i][vertex_amount - 1] = -1;

        vertex_amount--;

        for(int j = 0; j < vertex_amount; j++)
            matrix[vertex_amount][j] = 0;*/

        for(int i = 0; i < vertex_amount; i++)
        {
            for(int j = v; j < vertex_amount; j++)
            {

                matrix[i][j - 1] = matrix[i][j];
            }
        }

        for(int j = 0; j < vertex_amount; j++)
        {
            for(int i = v; i < vertex_amount; i++)
            {

                matrix[i - 1][j] = matrix[i][j];
            }
        }

        vertex_amount--;
    }
    else
        cout<<"No vertexes left!"<<endl;
}

int Graph::getEdgeAmount()
{
    int count = 0;
    for(int i = 0; i < vertex_amount; i++)
    {
        for(int j = i + 1; j < vertex_amount; j++)
        {
            if(matrix[i][j] == 1)
                count++;
        }
    }
    return count;
}

int Graph::getVertexAmount()
{
    return vertex_amount;
}

int Graph::getVertexNeighboursAmount(int v)
{
    if(v < 0 || v >= vertex_amount)
    {
        cout<<"Vertex "<<v<<" out of bounds"<<endl;
        return -1;
    }

    int count = 0;
    for(int i = 0; i < vertex_amount; i++)
    {
        if(matrix[i][v] == 1)
            count++;
    }
    return count;
}

int Graph::getVertexNeighbour(int v, int i)
{
    if(v < 0 || v >= vertex_amount)
    {
        cout<<"Vertex "<<v<<" out of bounds"<<endl;
        return -1;
    }
    if(i < 0)
    {
        cout<<"Vertex "<<i<<" must be higher than 0"<<endl;
        return -1;
    }

    int count = -1;
    for(int k = 0; k < vertex_amount; k++)
    {
        if(matrix[k][v] == 1)
            count++;

        if(count == i)
            return i;
    }

    cout<<"Cannot find "<<i<<"th vertex"<<endl;
    return -1;
}

int Graph::getMaxDeg()
{
	int max = 0;
	int pos = 0;
	for(int i = 0; i < vertex_amount; i++)
	{
		if(deg[i] > max)
		{
			max = deg[i];
			pos = i;
		}
	}
	return pos;
}

int Graph::maxDeg()
{
	int max = 0;
	for(int i = 0; i < vertex_amount; i++)
	{
		if(deg[i] > max)
		{
			max = deg[i];
		}
	}
	return max;
}

std::vector<int> Graph::getDegrees()
{
    return deg;
}

void Graph::print()
{
    for(int i = 0; i < vertex_amount; i++)
    {
        for(int j = 0; j < vertex_amount; j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
