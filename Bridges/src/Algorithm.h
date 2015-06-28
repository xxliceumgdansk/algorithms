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

class Bridges
{
    int numberOfNodes;
    vector<node*> nodes;

    public:
        Bridges(vector<node*> nodes, int numberOfNodes);
        virtual ~Bridges();
		vector<vector<int>> Find();

    protected:
    private:
};

#endif