#pragma once
#include <fstream>
#include <iostream>
#include <string>
#define NodeMaxCount 101
#define INF 2147483647 
using namespace std;

/////////////////////////////////////////////////////////
///  TODO: Add Your Struct or Functions if required /////
struct Node {
    int index;
    string name;
};

template<typename T>
struct Stack {
    int size = 0;
    T arr[NodeMaxCount];

    void push(T node) {
        arr[size++] = node;
    }
    T top() {
        return arr[size-1];
    }
    void pop() {
        size--;
    }
    bool empty() {
        return size>0 ? false : true;
    }
};

struct Queue {
    int size = 0;
    Node arr[2*NodeMaxCount];
    int front_pointer = 0;
    int end_pointer = 0;

    void push(Node node) {
        arr[end_pointer++] = node;
        size++;
    }
    Node front() {
        return arr[front_pointer];
    }
    void pop() {
        if(size>0) {
            size--;
            front_pointer++;
        }
    }
    bool empty() {
        return size==0 ? true : false;
    }
};
// for 8
struct Edge {
    int index1;
    int index2;
    long long weight;
};

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
    int size = 0;
    long long adj_mat[NodeMaxCount][NodeMaxCount] = {0, };
    Node original_mat[NodeMaxCount];
    string name[NodeMaxCount];
    void sortLexOrder(Node (&lex_order)[NodeMaxCount], int arr_size);
    bool visited[NodeMaxCount] = {0, };
    // for 4
    int findSCC(int cur_index, Stack<Node> &stack);
    int number[NodeMaxCount];
    bool selected[NodeMaxCount]; // 스택에서 뽑혀 이미 SCC에 들어가 있을 때
    int num_of_SCC = 0;
    // string routes[max]
    int visited_index = 0;
    // for 5
    void findRouteByDFS(int cur, const int &source, Stack<string> &stack, const int &dist);
    string routes[NodeMaxCount];
    int num_of_route = 0;
    void sortLexOrder(string (&lex_order)[NodeMaxCount], int arr_size);
    long long distance[NodeMaxCount];
    int parent[NodeMaxCount][NodeMaxCount]; //p[i][j] -> i 노드의 prev 노드 번호. 모든 path 계산 위해 2차원으로
    // for 6
    long long distance_6[NodeMaxCount][NodeMaxCount];
    int next[NodeMaxCount][NodeMaxCount];
    // for 7
    // distance[nodeMacCount], visited 
    int parent_7[NodeMaxCount];
    // for 8
    // weight 오름차순. 순서 보존
    void sortEdges(Edge (&arr)[NodeMaxCount*NodeMaxCount], const int &arr_size);
    int connected_node[NodeMaxCount][NodeMaxCount];
    int set[NodeMaxCount];
    int find(int node) {
        if(node == set[node]) return node;
        set[node] = find(set[node]);
        return set[node];
    }
    void unionNodex(int a, int b) {
        int root_a = find(a);
        int root_b = find(b);
        if(root_a < root_b) {
            set[root_b] = root_a;
        }
        else if(root_a > root_b) {
            set[root_a] = root_b;
        }
    }
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
};