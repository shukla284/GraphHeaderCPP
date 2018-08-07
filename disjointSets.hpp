#ifndef __DISJOINTSET_HPP_INCLUDED__
#define __DISJOINTSET_HPP_INCLUDED__

#include<vector>

class DisjointSet{
private:	 
    int distinctSets; 
	vector<int> parent;
public:
    DisjointSet(int distinctSets);
	int findParentSet(int childElement);
	void uniteDisjointSets(int childElement1,int childElement2);
	vector<vector<int>> showDisjointSets();	
};
