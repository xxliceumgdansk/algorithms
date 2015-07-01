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

TEST_CASE("Test dfs for simple graph") {
	string input = "6 9\n\
		0 5\n\
		0 1\n\
		5 2\n\
		5 1\n\
		4 1\n\
		4 5\n\
		3 4\n\
		2 1\n\
		2 3";

	int numberOfEdges = 10;
	vector<node*> graph = GenerateGraph(input, numberOfEdges);
	DepthFirstSearch* testee = new DepthFirstSearch(graph, numberOfEdges);

	vector<int> visitedNodes = testee->SearchGraphRecursive();

	REQUIRE(visitedNodes.size() == numberOfEdges);

	int* requiredOrder = new int[6] {0, 1, 5, 2, 3, 4};

	for (int i = 0; i < numberOfEdges; i++) {
		REQUIRE(visitedNodes[i] == requiredOrder[i]);
	}

	delete requiredOrder;
	
	DeleteGraph(graph);
}


TEST_CASE("Test dfs, stacked version, for simple graph") {
	string input = "6 9\n\
		0 5\n\
		0 1\n\
		5 2\n\
		5 1\n\
		4 1\n\
		4 5\n\
		3 4\n\
		2 1\n\
		2 3";

	int numberOfEdges = 10;
	vector<node*> graph = GenerateGraph(input, numberOfEdges);
	DepthFirstSearch* testee = new DepthFirstSearch(graph, numberOfEdges);

	vector<int> visitedNodes = testee->SearchGraphStackVersion();

	REQUIRE(visitedNodes.size() == numberOfEdges);

	int* requiredOrder = new int[6] {0, 1, 5, 2, 3, 4};

	for (int i = 0; i < numberOfEdges; i++) {
		REQUIRE(visitedNodes[i] == requiredOrder[i]);
	}

	delete requiredOrder;
	
	DeleteGraph(graph);
}