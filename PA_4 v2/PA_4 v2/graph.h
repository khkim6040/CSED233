#pragma once
#include <fstream>
#include <iostream>
#include <string>
#define NodeMaxCount 101
#define INF 2147483647 
using namespace std;

/////////////////////////////////////////////////////////
///  TODO: Add Your Struct or Functions if required /////

///////////      End of Implementation      /////////////
/////////////////////////////////////////////////////////

class Graph{
public:
    Graph() { };
    ~Graph() { };

    string DFS();
    string BFS();
    
    int addDirectedEdge(string nodeA, string nodeB);
    int addDirectedEdge(string nodeA, string nodeB, int weight);
    int addUndirectedEdge(string nodeA, string nodeB);
    int addUndirectedEdge(string nodeA, string nodeB, int weight);

    string StronglyConnectedComponent();

    string getShortestPath_task5(string source, string destination);
    string getShortestPath_task6(string source, string destination);
    int primMST(ofstream &, string startNode);
    int kruskalMST(ofstream &, string endNode);


private:
    /////////////////////////////////////////////////////////
    //////  TODO: Add private members if required ///////////
    
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
};
