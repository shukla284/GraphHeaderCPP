#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#define in :
using namespace std;

class Graph{
private:	
	int vertices;
	vector<vector<int>> adjacencyList;
	void topologicalSortUtility(int vertex,vector<bool> &visited,stack<int> &vertexStack);
public:
    Graph(int vertices);
	void addEdge(int source,int destination);
	vector<int> topologicalSort();
	void showEdges();
};
void Graph::showEdges(){
	
	auto count=0;
	for(auto vert:this->adjacencyList){
	  cout<<"Vertex "<<count++<<endl;
	   for(auto v:vert)
	    cout<<v<<" ";  	
	cout<<"----------------------------";    
	}    
	
}
Graph::Graph(int vertices){
	this->vertices=vertices;
	this->adjacencyList=vector<vector<int>> (this->vertices,vector<int>());
}
void Graph::addEdge(int sourceVertex,int destinationVertex){
	adjacencyList[sourceVertex].push_back(destinationVertex);
	//adjacencyList[destinationVertex].push_back(sourceVertex);
	
}
void Graph::topologicalSortUtility(int vertex,vector<bool> &visited,stack<int> &vertexStack){
	visited[vertex]=true;
	for(auto adjVertex in this->adjacencyList[vertex])
	  if(not visited[adjVertex])
	    topologicalSortUtility(adjVertex,visited,vertexStack);
	vertexStack.push(vertex);    
}
vector<int> Graph::topologicalSort(){
	
	stack<int> vertexStack;
	vector<int> sortedOrder;
 	vector<bool> visited(this->vertices);
	for(auto vertex:visited)
	  vertex=false;
	for(auto vertex=0;vertex<this->vertices;vertex++)
	   if(not visited[vertex])
	     topologicalSortUtility(vertex,visited,vertexStack);
	while(not vertexStack.empty()){
		sortedOrder.push_back(vertexStack.top());
		cout<<vertexStack.top()<<" ";
		vertexStack.pop();
	} 
	    
	return sortedOrder;	    
}
int main(int argc,char** argv){
    Graph g(6);
    
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    g.showEdges();
    auto order=g.topologicalSort();
    for(auto vertex in order)
      cout<<vertex<<" ";
}
