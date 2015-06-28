#ifndef BFS_H
#define BFS_H

#include <vector>
#include <queue>

using namespace std;

struct node {
	public:
		int number;
		struct node *next;
};

class BreadthFirstSearch
{
    int numberOfNodes;
    vector<node*> nodes;

    public:
        BreadthFirstSearch(vector<node*> nodes, int numberOfNodes);
        virtual ~BreadthFirstSearch();
        vector<int> SearchGraph();
        bool Bipartite();

    protected:
    private:
};

#endif // BFS_H
