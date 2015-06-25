#ifndef DFS_H
#define DFS_H

#include <vector>
#include <queue>

using namespace std;

struct node {
	public:
		int number;
		struct node *next;
};

class DepthFirstSearch
{
    int numberOfNodes;
    vector<node*> nodes;

    public:
        DepthFirstSearch(vector<node*> nodes, int numberOfNodes);
        virtual ~DepthFirstSearch();
        vector<int> SearchGraphRecursive();
		vector<int> SearchGraphStackVersion();

    protected:
    private:
};

#endif