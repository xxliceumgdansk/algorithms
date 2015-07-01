#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include <vector>
#include "Algorithm.h"

using namespace std;

vector<node*> GenerateGraph(std::string input, int numberOfNodes)
{
	
	vector<node*> graph;


	for (int i = 0; i < numberOfNodes; i++)
	{
		node* newNode = static_cast<node*>(malloc(sizeof(node)));
		newNode->number = i;
		newNode->next = NULL;
		graph.push_back(newNode);
	}

	vector<string> lines;
	std::stringstream stringstream(input);
	std::string line;

	while (std::getline(stringstream, line, '\n')){
		lines.push_back(line);
	}

	for (size_t i = 0; i < lines.size(); i++) {
		std::string edgeLine = lines[i];

		std::string startString = edgeLine.substr(0, edgeLine.find(" "));
		std::string endString = edgeLine.substr(startString.length(), edgeLine.length());

		int startNodeNumber = atoi(startString.c_str());
		int endNodeNumber = atoi(endString.c_str());

		node* startNode = graph[startNodeNumber];
		startNode->number = startNodeNumber;

		node* endNode = (node*)malloc(sizeof(node));

		endNode->number = endNodeNumber;
		endNode->next = startNode->next;

		startNode->next = endNode;

		graph[startNodeNumber] = startNode;
	}

	return graph;
}

void DeleteGraph(vector<node*> graph) {
	node* currentNode = nullptr;
	
	for(int i=0;i<graph.size(); i++) {
		currentNode = graph[i]->next;
		while (currentNode != nullptr)	{
			node* toDelete = currentNode;
			currentNode = currentNode->next;
			delete toDelete;
		}
		delete graph[i];
	}
}


TEST_CASE("Test bfs for simple graph") {
	string input = "0 1\n\
				   0 2\n\
				   0 8\n\
				   1 4\n\
				   1 5\n\
				   1 7\n\
				   2 9\n\
				   3 0\n\
				   3 10\n\
				   3 11\n\
				   4 13\n\
				   5 6\n\
				   5 7\n\
				   5 13\n\
				   7 8\n\
				   8 9\n\
				   10 9\n\
				   10 11\n\
				   12 0\n\
				   12 3\n\
				   13 12";

	int numberOfNodes = 14;
	vector<node*> graph = GenerateGraph(input, numberOfNodes);
	BreadthFirstSearch* testee = new BreadthFirstSearch(graph, numberOfNodes);

	vector<int> visitedNodes = testee->SearchGraph();

	REQUIRE(visitedNodes.size() == numberOfNodes);

	int* requiredOrder = new int[numberOfNodes] {0, 8, 2, 1, 9, 7, 5, 4, 13, 6, 12, 3, 11, 10};

	for (int i = 0; i < numberOfNodes; i++) {
		REQUIRE(visitedNodes[i] == requiredOrder[i]);
	}

	DeleteGraph(graph);
	
	delete requiredOrder;
}

TEST_CASE("Test if bipartite graph for bipartite one") {
	string input = "0 1\n\
0 2\n\
0 3\n\
1 2\n\
1 14\n\
2 6\n\
3 4\n\
3 6\n\
3 13\n\
4 7\n\
4 12\n\
5 6\n\
5 9\n\
5 10\n\
6 7\n\
6 8\n\
6 12\n\
7 13\n\
8 9\n\
10 11\n\
10 14\n\
10 15\n\
11 16\n\
12 16\n\
13 16";

	vector<node*> graph = GenerateGraph(input, 14);

    BreadthFirstSearch* testee = new BreadthFirstSearch(graph, 14);

	REQUIRE(testee->Bipartite()== true);
	
	DeleteGraph(graph);
}

TEST_CASE("Test if bipartite graph for not bipartite one") {
	string input = "0 2\n\
0 3\n\
1 2\n\
1 14\n\
2 6\n\
3 4\n\
3 6\n\
3 13\n\
4 7\n\
4 12\n\
5 6\n\
5 9\n\
5 10\n\
6 7\n\
6 8\n\
6 12\n\
7 13\n\
8 9\n\
10 11\n\
10 14\n\
10 15\n\
11 16\n\
12 16";

	vector<node*> graph = GenerateGraph(input, 14);

    BreadthFirstSearch* testee = new BreadthFirstSearch(graph, 14);

	REQUIRE(testee->Bipartite()== false);
	
	DeleteGraph(graph);
}