#include "disjointSets.hpp"

DisjointSet::DisjointSet(int distinctSets){
	this->distinctSets=distinctSets;
	parent=vector<int>(distinctSets);
	for(int set=0;set<distinctSets;set++)
	   parent[set]=set; 
}
int DisjointSet::findParentSet(int childElement){
	if(parent[childElement]==childElement)
	   return childElement;
	else{
		parent[childElement]=findParentSet(parent[childElement]);
		return parent[childElement];
	}   
}
void DisjointSet::uniteDisjointSets(int childElement1,int childElement2){
	parent[findParentSet(childElement1)]=findParentSet(childElement2);
	return;
}
vector<vector<int>> DisjointSet::showDisjointSets(){
	vector<vector<int> > disjointSets;
 	for(auto element:parent)
	  
}
