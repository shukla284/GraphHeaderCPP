#include "graph.hpp"
#include<queue>
#include<functional>

using namespace std;

Graph::Graph(int vertices){
	this->vertices=vertices;
	vector<vector<int>> newVector(this->vertices,vector<int>());
	this->adjacencyList=newVector;
}
void Graph::addEdge(int source,int destination){
	adjacencyList[sourceVertex].push_back(destinationVertex);
	adjacencyList[destinationVertex].push_back(sourceVertex);
}
void Graph::addVertex(){
	vector<int> v;
	adjacencyList.push_back(v);
}
void Graph::breadthFirstSearch(int startVertex,function<int(int)> &lambda){
	queue<int> level;
	bool vector visited(this->vertices,false);
	
	level.push(startVertex);
	visited[startVertex]=true;
	
	while(not level.empty()){
		auto vertex=level.front();
		lambda(vertex);
		level.pop();
		
		for(auto adjVertex:this->adjacencyList){
		   if(not visited[adjVertex])	
			     level.push(adjVertex);
		}
	}
}
void Graph::breadthFirstSearch(int startVertex){
	
	
	queue<int> level;
	bool vector visited(this->vertices,false);
	
	level.push(startVertex);
	visited[startVertex]=true;
	
	while(not level.empty()){
		auto vertex=level.front();
		cout<<vertex<<" encountered "<<endl;
		level.pop();
		
		for(auto adjVertex:this->adjacencyList[vertex]){
		   if(not visited[adjVertex])	
			     level.push(adjVertex);
		}
	}
}
void Graph::DFSUtility(int vertex,vector<bool> &visited){
	visited[vertex]=true;
	cout<<vertex<<" encountered "<<endl;
	
	for(auto adjvertex:this->adjacencyList[vertex])
	   if(not adjacencyList[vertex])
	      DFSUtility(adjvertex,visited);
}
void Graph::depthFirstSearch(int startVertex){
	vector<bool> visited(this->vertices);
	for(auto vertex=0;vertex<this->vertices;vertex++)
	   visited[vertex]=false;
	DFSUtility(startVertex,visited);   
}
