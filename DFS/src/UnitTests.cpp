#ifdef WIN32
#include "stdafx.h"
#endif

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include <vector>
#include "Algorithm.h"

using namespace std;

vector<node*> GenerateGraph(std::string input, int numberOfNodes)
{
	vector<node*> result;
	node** nodeList = new node*[numberOfNodes];
	for (int i = 0; i < numberOfNodes; i++)
	{
		nodeList[i] = static_cast<node*>(malloc(sizeof(node)));
		nodeList[i]->number = i;
		nodeList[i]->next = NULL;
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

		node* startNode = nodeList[startNodeNumber];
		startNode->number = startNodeNumber;

		node* endNode = (node*)malloc(sizeof(node));

		endNode->number = endNodeNumber;
		endNode->next = startNode->next;

		startNode->next = endNode;

		nodeList[startNodeNumber] = startNode;
	}

	for (int i = 0; i < numberOfNodes; i++) {
		result.push_back(nodeList[i]);
	}

	return result;
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
}