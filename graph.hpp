#ifndef __GRAPH_HPP_INCLUDED_
#define __GRAPH_HPP_INCLUDED_

#include "disjointSet.hpp"
#include<vector>
#include<map>
#include<queue>
#include<stack>

class Graph{
private:	
	int vertices;
	vector<vector<int>> adjacencyList(this->vertices,vector<int>());
	int calculateNumberOfComponents();
	void DFSUtility(int vertex,vector<bool> visited);
	void topologicalSortUtility()
public:
    Graph(int vertices);
	int getEdges();
	int getVertices();
	int addVertex();
	void addEdge(int source,int destination);
	void breadthFirstSearch(int startVertex);
	void breadthFirstSearch(int startVertex,function<int(int)> &lambda);
	void depthFirstSearch(int startVertex);
	int shortestPath(int source,int destination);	
	int numberOfComponents();
	void topologicalSort();
};

