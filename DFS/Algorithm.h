#ifndef DFS_H
#define DFS_H

#include <vector>
#include <queue>

using namespace std;

struct node {
	public:
		int number;
		struct node *next; // Node's neighborhood list can be queried here. 
		
		// you can query neighborhood this way: while(currentNode!=NULL) { currentNode = *(currentNode->Next);}
};

class DepthFirstSearch
{
    int numberOfNodes;
    vector<node*> graph;

    public:
        DepthFirstSearch(vector<node*> graph, int numberOfNodes);
        virtual ~DepthFirstSearch();
        vector<int> SearchGraphRecursive();
		vector<int> SearchGraphStackVersion();

    protected:
    private:
};

#endif