#include "Algorithm.h"

BreadthFirstSearch::BreadthFirstSearch(vector<node*> _graph, int _numberOfNodes)
{
    graph = _graph;
    numberOfNodes = _numberOfNodes;
}

BreadthFirstSearch::~BreadthFirstSearch()
{
    //dtor
}

vector<int> BreadthFirstSearch::SearchGraph() {
    vector<int> resultList;

    // Your algorithm code goes here.
    // Graph nodes are located in "graph" class field.
    // Happy coding!

    return resultList;
}

bool BreadthFirstSearch::Bipartite() {
    return false;
}
