#ifndef DFS_H
#define DFS_H

#include <vector>
#include <queue>

using namespace std;

struct node {
	public:
		int number;
		struct node *next; // Node's neighborhood list can be queried here. 
		
		// you can query neighborhood this way: while(currentNode!=NULL) { currentNode = *(currentNode.Next);}
};

class Bridges
{
    int numberOfNodes;
    vector<node*> graph;

    public:
        Bridges(vector<node*> graph, int numberOfNodes);
        virtual ~Bridges();
		vector<vector<int> > Find();

    protected:
    private:
};

#endif