#include "stdafx.h"
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include <vector>
#include <unordered_map>
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

		node* endNode = graph[endNodeNumber];

		endNode->number = endNodeNumber;
		endNode->next = startNode->next;

		startNode->next = endNode;

		graph[startNodeNumber] = startNode;
	}

	return graph;
}


TEST_CASE("Test dfs for simple graph") {
	string input = "0 1\n\
0 2\n\
0 3\n\
1 2\n\
1 14\n\
4 11\n\
4 12\n\
5 6\n\
5 9\n\
6 7\n\
6 8\n\
10 15\n\
11 15\n\
12 15\n\
13 14\n\
13 16\n\
14 16";

	int numberOfEdges = 17;

	vector<node*> graph = GenerateGraph(input, numberOfEdges);
	Bridges* testee = new Bridges(graph, numberOfEdges);

	vector<vector<int>> bridgeEdges = testee->Find();

	REQUIRE(bridgeEdges.size() == 7);

	vector<vector<int>> requiredEdges({ 
		{ 5, 6 }, 
		{ 6, 7 }, 
		{ 6, 8 }, 
		{ 5, 9 }, 
		{ 15, 10 }, 
		{ 1, 14 }, 
		{ 0, 3 } 
	});

	for (int i = 0; i < requiredEdges.size(); i++) {
		bool found = false;
		vector<int> currentEdge = requiredEdges[i];

		// Check whether an edge can be found in the algorithm result.
		for (int j = 0; j < bridgeEdges.size(); j++) {
			if (bridgeEdges[j][0] == currentEdge[0] && bridgeEdges[j][1] == currentEdge[1]
				|| bridgeEdges[j][1] == currentEdge[1] && bridgeEdges[j][0] == currentEdge[0]) {
				found = true;
			}
		}

		// Write a message which edge wasn't found.
		if (!found) {
			std::ostringstream stringStream;
			stringStream << "Edge not found (" << currentEdge[0] << ", " << currentEdge[1] << ")";

			WARN(stringStream.str());
		}

		REQUIRE(found);
	}

	for (int i; i < numberOfEdges; i++) {
		delete graph[i];
	}

	delete testee;
}


