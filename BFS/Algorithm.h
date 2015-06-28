#ifndef BFS_H
#define BFS_H

#include <vector>
#include <queue>

using namespace std;

struct node {
	public:
		int number;
		struct node *next; // Node's neighborhood list can be queried here. 
		
		// you can query neighborhood this way: while(currentNode!=NULL) { currentNode = *(currentNode.Next);}
};

class BreadthFirstSearch
{
    int numberOfNodes;
    vector<node*> graph;

    public:
        BreadthFirstSearch(vector<node*> graph, int numberOfNodes);
        virtual ~BreadthFirstSearch();
        vector<int> SearchGraph();
        bool Bipartite();

    protected:
    private:
};

#endif // BFS_H
