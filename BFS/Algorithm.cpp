#include "Algorithm.h"

BreadthFirstSearch::BreadthFirstSearch(vector<node*> _nodes, int _numberOfNodes)
{
    nodes = _nodes;
    numberOfNodes = _numberOfNodes;
}

BreadthFirstSearch::~BreadthFirstSearch()
{
    //dtor
}

vector<int> BreadthFirstSearch::SearchGraph() {
    vector<int> resultList;

    return resultList;
}

bool BreadthFirstSearch::Bipartite() {
    return false;
}
