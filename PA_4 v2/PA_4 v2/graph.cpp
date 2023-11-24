#include "graph.h"
#include <fstream>
#include <iostream>
#include <string>
#define INF 2147483647 
using namespace std;


/////////////////////////////////////////////////////////
//////////  TODO: Implement From Here      //////////////
/*  Write your codes if you have additional functions  */

void Graph::sortLexOrder(Node (&lex_order)[NodeMaxCount], int arr_size) {
    // Selection Sort
    for(int i=0; i<arr_size; i++) {
        Node target = lex_order[i];
        int pos = i;
        for(int j=i+1; j<arr_size; j++) {
            if(lex_order[j].name < target.name) {
                target = lex_order[j];
                pos = j;
            }
        }
        lex_order[pos] = lex_order[i];
        lex_order[i] = target;
    }
}

void Graph::sortLexOrder(string (&lex_order)[NodeMaxCount], int arr_size) {
    for(int i=0; i<arr_size; i++) {
        string target = lex_order[i];
        int pos = i;
        for(int j=i+1; j<arr_size; j++) {
            if(lex_order[j] < target) {
                target = lex_order[j];
                pos = j;
            }
        }
        lex_order[pos] = lex_order[i];
        lex_order[i] = target;
    }
}

void Graph::findRouteByDFS(int cur, const int &source, Stack<string> &stack, const int &dist) {
    if(cur==source) {
        //정답 작성해서 routes에 저장
        Stack<string> temp;
        string route;
        while(!stack.empty()) {
            string node = stack.top();
            temp.push(node);
            route += node;
            route += " ";
            stack.pop();
        }
        route += to_string(dist);
        routes[num_of_route++] = route;
        // 다시 stack 채우기
        while(!temp.empty()) {
            stack.push(temp.top());
            temp.pop();
        }
        return;
    }

    for(int i=0; i<size; i++) {
        int parent_index = parent[cur][i];
        if(parent_index != -1) {
            stack.push(original_mat[parent_index].name);
            findRouteByDFS(parent_index, source, stack, dist);
            stack.pop();
        }
    }
}

int Graph::findSCC(int cur_index, Stack<Node> &stack) {
    number[cur_index] = visited_index++;
    int res = number[cur_index];
    stack.push(original_mat[cur_index]);
    // 끝까지 탐색
    for(int i=0; i<size; i++) {
        if(!adj_mat[cur_index][i]) continue;

        if(number[i]==-1) {
            res = min(res, findSCC(i, stack));
        }
        else if(!selected[i]) {
            res = min(res, number[i]);
        }
    }
    // SCC 요건 됐을 떄
    if(res == number[cur_index]) {
        num_of_SCC++;
        string route[NodeMaxCount];
        int route_size = 0;
        while(true) {
            Node cur = stack.top();
            selected[cur.index] = true;
            stack.pop();
            route[route_size++] = cur.name;
            if(cur.index == cur_index) break;
        }
        // route 요소들 오름차순 정렬 후 routes에 넣기
        sortLexOrder(route, route_size);
        string temp = "";
        for(int i=0; i<route_size; i++) {
            temp += route[i];
            temp += " ";
        }
        temp.pop_back();
        routes[num_of_route++] = temp;
    }
    
    return res;
}
void Graph::sortEdges(Edge (&arr)[NodeMaxCount*NodeMaxCount], const int &arr_size) {
    for(int i=0; i<arr_size; i++) {
        Edge target = arr[i];
        int pos = i;
        for(int j=i+1; j<arr_size; j++) {
            if(arr[j].weight < target.weight) {
                target = arr[j];
                pos = j;
            }
        }
        arr[pos] = arr[i];
        arr[i] = target;
    }    
}
///////////      End of Implementation      /////////////
/////////////////////////////////////////////////////////


string Graph::DFS() {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    Node lex_order[NodeMaxCount];
    for(int i=0; i<size; i++) {
        lex_order[i] = original_mat[i];
    }
    sortLexOrder(lex_order, size);
    // adj_mat 확인
    // for(int i=0; i<size; i++) {
    //     cout << original_mat[i].name << '\n';
    //     for(int j=0; j<size; j++) {
    //         cout << adj_mat[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    string answer = "";
    int num_of_component = 0;
    while(true) {
        Stack<Node> stack;
        bool unvisitor_checker = false;
        for(int i=0; i<this->size; i++) {
            Node node = lex_order[i];
            if(!visited[node.index]) {
                stack.push(node);
                unvisitor_checker = true;
                num_of_component++;
                break;
            }
        }
        // 모든 노드 방문했을 때 종료
        if(!unvisitor_checker) {
            break;
        }
        // DFS
        visited[stack.top().index] = true;
        answer += stack.top().name;
        answer += " ";
        bool is_pushed = false;
        while(!stack.empty()) {
            Node cur = stack.top();
            if(is_pushed) {
                answer += cur.name;
                answer += " ";
            }
            // 인접한 노드 중 가장 사전순으로 앞선 것 찾음
            Node next_node = {-1, ""};
            is_pushed = false;
            for(int i=0; i<size; i++) {
                if(adj_mat[cur.index][i] && !visited[i]) {
                    if(next_node.name=="" || original_mat[i].name < next_node.name) {
                        next_node = original_mat[i];
                    }
                }
            }
            // 인접한 노드 있으면 넣음
            if(next_node.index != -1) {
                stack.push(next_node);
                visited[next_node.index] = true;
                is_pushed = true;
            }
            else {
                stack.pop();
            }

        }
        answer += "\n";

    }
    string temp = answer;
    answer = to_string(num_of_component);
    answer += "\n";
    answer.append(temp);
    answer.pop_back();
    return answer;
    ///////////      End of Implementation      /////////////
    ///////////////////////////////////////////////////////
}


string Graph::BFS() {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    Node lex_order[NodeMaxCount];
    for(int i=0; i<size; i++) {
        lex_order[i] = original_mat[i];
    }
    sortLexOrder(lex_order, size);
    string answer = "";
    int num_of_component = 0;
    while(true) {
        Queue queue;
        bool unvisitor_checker = false;
        for(int i=0; i<this->size; i++) {
            Node node = lex_order[i];
            if(!visited[node.index]) {
                queue.push(node);
                unvisitor_checker = true;
                num_of_component++;
                break;
            }
        }
        // 모든 노드 방문했을 때 종료
        if(!unvisitor_checker) {
            break;
        }
        // BFS
        visited[queue.front().index] = true;
        while(!queue.empty()) {
            Node cur = queue.front();
            queue.pop();
            answer += cur.name;
            answer += " ";
            // 인접한 노드 모두 리스트에 넣고 사전순 정렬 후 큐에 넣음 
            Node temp[NodeMaxCount];
            int temp_size = 0;
            for(int i=0; i<size; i++) {
                if(adj_mat[cur.index][i] && !visited[i]) {
                    temp[temp_size++] = original_mat[i];
                    visited[i] = true;
                }
            }
            sortLexOrder(temp, temp_size);
            for(int i=0; i<temp_size; i++) {
                queue.push(temp[i]);
            }
        }
        answer += "\n";
    }
    string temp = answer;
    answer = to_string(num_of_component);
    answer += "\n";
    answer.append(temp);
    answer.pop_back();
    return answer;
    ///////////      End of Implementation      /////////////
    ///////////////////////////////////////////////////////
}


int Graph::addDirectedEdge(string nodeA, string nodeB) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    addDirectedEdge(nodeA, nodeB, 1);
    return 0;
    ///////////      End of Implementation      /////////////
    ///////////////////////////////////////////////////////
}

int Graph::addDirectedEdge(string nodeA, string nodeB, int weight) {
	/////////////////////////////////////////////////////////
	//////////  TODO: Implement From Here      //////////////
    bool flag1, flag2;
    int index1, index2;
    flag1 = flag2 = false;
    index1 = index2 = -1;
    // 기존에 존재하는 노드 있는지 확인
    for(int i=0; i<this->size; i++) {
        if(original_mat[i].name==nodeA) {
            flag1 = true;
            index1 = i;
        }
        if(original_mat[i].name==nodeB) {
            flag2 = true;
            index2 = i;
        }
    }
    // 노드 생성
    if(flag1 && flag2) {
        // 이미 같은 edge 있음. 무시
        if(adj_mat[index1][index2]) {
            return 0;
        }
        else {
            adj_mat[index1][index2] = weight;
        }
    }
    else if(!flag1 && flag2) {
        // nodeA, edge 추가
        Node node = {size, nodeA};
        original_mat[size] = node;
        adj_mat[size][index2] = weight;
        size++;
    }
    else if(flag1 && !flag2) {
        // nodeB, edge 추가
        Node node = {size, nodeB};
        original_mat[size] = node;
        adj_mat[index1][size] = weight;
        size++;
    }
    else {
        // nodeA, nodeB, edge 추가
        index1 = size;
        index2 = size+1;
        Node node1 = {index1, nodeA};
        Node node2 = {index2, nodeB};
        original_mat[index1] = node1;
        original_mat[index2] = node2;
        adj_mat[index1][index2] = weight;
        size += 2;
    }
    return 0;
	///////////      End of Implementation      /////////////
	///////////////////////////////////////////////////////
}


int Graph::addUndirectedEdge(string nodeA, string nodeB) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    addUndirectedEdge(nodeA, nodeB, 1);
    return 0;
    ///////////      End of Implementation      /////////////
    ///////////////////////////////////////////////////////
}

int Graph::addUndirectedEdge(string nodeA, string nodeB, int weight) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    bool flag1, flag2;
    int index1, index2;
    flag1 = flag2 = false;
    index1 = index2 = -1;
    // 기존에 존재하는 노드 있는지 확인
    for(int i=0; i<this->size; i++) {
        if(original_mat[i].name==nodeA) {
            flag1 = true;
            index1 = i;
        }
        if(original_mat[i].name==nodeB) {
            flag2 = true;
            index2 = i;
        }
    }
    // 노드 생성
    if(flag1 && flag2) {
        // 이미 같은 edge 있음. 무시
        if(adj_mat[index1][index2] && adj_mat[index2][index1]) {
            return 0;
        }
        else {
            adj_mat[index1][index2] = weight;
            adj_mat[index2][index1] = weight;
        }
    }
    else if(!flag1 && flag2) {
        // nodeA, edge 추가
        Node node = {size, nodeA};
        original_mat[size] = node;
        adj_mat[size][index2] = weight;
        adj_mat[index2][size] = weight;
        size++;
    }
    else if(flag1 && !flag2) {
        // nodeB, edge 추가
        Node node = {size, nodeB};
        original_mat[size] = node;
        adj_mat[size][index1] = weight;
        adj_mat[index1][size] = weight;
        size++;
    }
    else {
        // nodeA, nodeB, edge 추가
        index1 = size;
        index2 = size+1;
        Node node1 = {index1, nodeA};
        Node node2 = {index2, nodeB};
        original_mat[index1] = node1;
        original_mat[index2] = node2;
        adj_mat[index1][index2] = weight;
        adj_mat[index2][index1] = weight;
        size += 2;
    }
    return 0;
    ///////////      End of Implementation      /////////////
    ///////////////////////////////////////////////////////
}

string Graph::StronglyConnectedComponent() {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    for(int i=0; i<size; i++) {
        number[i] = -1;
    }
    Stack<Node> stack;
    for(int i=0; i<size; i++) {
        if(number[i]==-1) {
            findSCC(i, stack);
        }
    }

    sortLexOrder(routes, num_of_route);
    string answer = to_string(num_of_SCC);
    answer += "\n";
    for(int i=0; i<num_of_route; i++) {
        answer += routes[i];
        answer += "\n";
    }
    answer.pop_back();
    return answer;
    ///////////      End of Implementation      /////////////
    ///////////////////////////////////////////////////////
}


string Graph::getShortestPath_task5(string source, string destination) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    // distance, parent 초기화
    // source, destination 노드 index 찾기
    int source_index, destination_index;
    for(int i=0; i<size; i++) {
        if(original_mat[i].name == source) {
            source_index = i;
        }
        if(original_mat[i].name == destination) {
            destination_index = i;
        }
        distance[i] = INF;
        for(int j=0; j<size; j++) {
            parent[i][j] = -1;
        }
    }
    // cout << source_index << ' ' << destination_index << '\n';

    // source 노드로부터 첫 거리 초기화
    visited[source_index] = true;
    distance[source_index] = 0;

    for(int i=0; i<size; i++) {
        if(adj_mat[source_index][i]) {
            distance[i] = adj_mat[source_index][i];
            parent[i][0] = source_index;
        }
    }
        // adj_mat 확인
    // for(int i=0; i<size; i++) {
    //     cout << original_mat[i].name << '\n';
    //     for(int j=0; j<size; j++) {
    //         cout << adj_mat[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // for(int i=0; i<size; i++) {
    //     cout << distance[i] << ' ';
    // }
    // 다익스트라
    int counter = size;
    while(counter--) {
        // 확정시킬(시작할) 노드 찾기
        long long min_dist = INF;
        int start_index = -1;
        for(int i=0; i<size; i++) {
            if(!visited[i] && distance[i]<min_dist) {
                min_dist = distance[i];
                start_index = i;
                // cout << i << '\n';
            }
        }
        // 더이상 확정시킬 노드 없으면 끝
        // cout << start_index << '\n';
        if(start_index==-1) break;
        // 시작 노드 확정 후 인접 노드 거리 업데이트
        visited[start_index] = true;
        for(int i=0; i<size; i++) {
            long long weight = adj_mat[start_index][i];
            // 작거나 "같은"것도 넣어야 같은 거리의 모든 path 탐색가능
            if(weight && distance[start_index]+weight == distance[i]) {
                // 노드 i의 parent 업데이트. 모든 path 출력을 위해 
                for(int j=0; i<size; j++) {
                    if(parent[i][j]==-1) {
                        parent[i][j] = start_index;
                        break;
                    }
                }
            }
            // 새로운 거리가 기존보다 작다면 distance 업데이트 후 parent 갈아엎어야함
            else if(weight && distance[start_index]+weight < distance[i]) {
                distance[i] = distance[start_index]+weight;
                parent[i][0] = start_index;
                for(int j=1; j<size; j++) {
                    if(parent[i][j]==-1) break;
                    else {
                        parent[i][j] = -1;
                    }
                }
            }
        }
    }
    // 루트 출력
    if(distance[destination_index]==INF) {
        return "error";
    }
    // 가능한 모든 route 뽑아내기. routes에 저장됨
    Stack<string> route_stack;
    route_stack.push(original_mat[destination_index].name);
    findRouteByDFS(destination_index, source_index, route_stack, distance[destination_index]);
    // routes 배열 사전순으로 route 정렬
    sortLexOrder(routes, num_of_route);
    string answer = "";
    for(int i=0; i<num_of_route; i++) {
        answer += routes[i];
        answer += "\n";
    }
    answer.pop_back();
    return answer;
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}

string Graph::getShortestPath_task6(string source, string destination) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    // distance, parent 초기화
    // source, destination 노드 index 찾기
    int source_index, destination_index;
    for(int i=0; i<size; i++) {
        if(original_mat[i].name == source) {
            source_index = i;
        }
        if(original_mat[i].name == destination) {
            destination_index = i;
        }
        for(int j=0; j<size; j++) {
            if(i==j) {
                distance_6[i][j] == 0;
                next[i][j] = -1;
            }
            // edge 있는 경우
            else if(adj_mat[i][j] != 0) {
                distance_6[i][j] = adj_mat[i][j];
                next[i][j] = j;
            }
            // edge 없는 경우
            else {
                distance_6[i][j] = INF;
                next[i][j] = -1;
            }
        }
    }

    // 플로이드-워셜
    for(int k=0; k<size; k++) {
        for(int i=0; i<size; i++) {
            for(int j=0; j<size; j++) {
                if(distance_6[i][k]!=INF && distance_6[k][j]!=INF && distance_6[i][k]+distance_6[k][j] < distance_6[i][j] && i!=j) {
                    // 음수 사이클 안생기게 처리
                    // 1. i->k로 가는 path에 j가 있는 경우
                    int route_index = i;
                    bool have_cycle = false;
                                        
                    while(route_index != k) {
                        if(route_index == j) {
                            have_cycle = true;
                            break;
                        }
                        route_index = next[route_index][k];
                    }
                    if(have_cycle) continue;
                    // 2. k->j로 가는 path에 i가 있는 경우
                    route_index = k;
                    while(route_index != j) {
                        if(route_index == i) {
                            have_cycle = true;
                            break;
                        }
                        route_index = next[route_index][j];
                    }
                    
                    // 음수 사이클 안생겼을 때만 거리 업데이트
                    if(!have_cycle) {
                        distance_6[i][j] = distance_6[i][k]+distance_6[k][j];
                        next[i][j] = next[i][k];
                    }
                }
            }
        }
    }

    // cout << "NEXT" << '\n';
    // for(int i=0; i<size; i++) {
    //     cout << original_mat[i].name << '\n';
    //     for(int j=0; j<size; j++) {
    //         cout << next[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << "DIST" << '\n';
    // for(int i=0; i<size; i++) {
    //     cout << original_mat[i].name << '\n';
    //     for(int j=0; j<size; j++) {
    //         cout << distance_6[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    // find route
    if(distance_6[source_index][destination_index] == INF) {
        return "INF";
    }
    string answer = "";
    int temp = source_index;
    answer += original_mat[temp].name;
    answer += " ";
    int count = NodeMaxCount;
    while(count-- && temp!=destination_index) {
        temp = next[temp][destination_index];
        answer += original_mat[temp].name;
        answer += " ";
    }
    answer += to_string(distance_6[source_index][destination_index]);
    return answer;
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}

int Graph::primMST(ofstream &fout, string startNode) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    int source_index;
    Node lex_order[NodeMaxCount];
    for(int i=0; i<size; i++) {
        if(original_mat[i].name == startNode) {
            source_index = i;
        }
        lex_order[i] = original_mat[i];
        distance[i] = INF;
        parent_7[i] = -1;
    }
    sortLexOrder(lex_order, size);
    // Prim algorithm
    distance[source_index] = 0;
    visited[source_index] = true;
    parent_7[source_index] = -2;
    // source와 인접한 노드 거리 업데이트
    for(int i=0; i<size; i++) {
        if(adj_mat[source_index][i]) {
            distance[i] = adj_mat[source_index][i];
            parent_7[i] = source_index;
        }
    }
    string answer = "";
    long long total_dist = 0;
    int counter = size;
    while(counter--) {
        long long min_dist = INF;
        int next_index = -1;
        for(int i=0; i<size; i++) {
            int cur = lex_order[i].index;
            if(visited[cur]) continue;
            if(distance[cur] < min_dist && parent_7[cur] != -1) {
                next_index = cur;
                min_dist = distance[cur];
            }
        }
        // 거리 업데이트되는거 없을 때 끝냄
        if(next_index == -1) break;
        // 새로 확정된 next_index로부터 거리 업데이트
        visited[next_index] = true;
        for(int i=0; i<size; i++) {
            if(adj_mat[next_index][i] == 0) continue;
            if(!visited[i] && adj_mat[next_index][i]<distance[i]) {
                distance[i] = adj_mat[next_index][i];
                parent_7[i] = next_index;
            }
        }
        // route 업데이트
        int temp = next_index;
        Stack<string> stack;
        while(temp != -2) {
            stack.push(original_mat[temp].name);
            temp = parent_7[temp];
        }
        string route;
        while(!stack.empty()) {
            route += stack.top();
            route += " ";
            stack.pop();
        }
        route.pop_back();
        fout << route << endl;
        total_dist += distance[next_index];
    }

	return total_dist;
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}

int Graph::kruskalMST(ofstream &fout, string endNode) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    Node lex_order[NodeMaxCount];
    int end_index;
    for(int i=0; i<size; i++) {
        if(original_mat[i].name == endNode) {
            end_index = i;
        }
        lex_order[i] = original_mat[i];
    }
    sortLexOrder(lex_order, size);
    // 사전순으로 정렬된 노드를 순차적으로 edges에 넣음
    Edge edges[NodeMaxCount*NodeMaxCount];
    int edge_size = 0;
    for(int i=0; i<size; i++) {
        set[i] = i;
        for(int j=0; j<size; j++) {
            connected_node[i][j] = -1;
            int a = lex_order[i].index;
            int b = lex_order[j].index;
            if(j>i && adj_mat[a][b]) {
                edges[edge_size++] = {a, b, adj_mat[a][b]};
            }
        }
    }
    sortEdges(edges, edge_size);
    // Kruskal
    long long total_weight = 0;
    for(int i=0; i<edge_size; i++) {
        Edge cur = edges[i];
        int a = cur.index1;
        int b = cur.index2;
        if(find(a) != find(b)) {
            fout << original_mat[a].name << ' ' << original_mat[b].name << ' ' << cur.weight << endl;
            // path 찾기 위한 연결 요소 추가
            for(int j=0; j<size; j++) {
                if(connected_node[a][j]==-1) {
                    connected_node[a][j] = b;
                    break;
                }
            }
            for(int j=0; j<size; j++) {
                if(connected_node[b][j]==-1) {
                    connected_node[b][j] = a;
                    break;
                }
            }
            unionNodex(a, b);
            total_weight += cur.weight;
        }
    }
    // endNode까지 역추적으로 path 계산. DFS
    Stack<Node> stack;
    Node start_node = lex_order[0];
    Node end_node = original_mat[end_index];
    stack.push(end_node);
    visited[end_index] = true;
    bool is_pushed = false;
    while(!stack.empty()) {
        Node cur = stack.top();
        // 첫 지점으로 돌아오면 탐색 끝냄
        if(cur.index == start_node.index) {
            break;
        }
        // 인접한 노드 중 가장 사전순으로 앞선 것 찾음
        is_pushed = false;
        for(int i=0; i<size; i++) {
            int next_index = connected_node[cur.index][i]; 
            if(next_index != -1 && !visited[next_index]) {
                stack.push(original_mat[next_index]);
                visited[next_index] = true;
                is_pushed = true;
                break;
            }
        }
        // 인접한 노드 있으면 넣음
        if(!is_pushed) {
            stack.pop();
        }
    }
    string route = "";
    while(!stack.empty()) {
        route += stack.top().name;
        route += " ";
        stack.pop();
    }
    fout << route;

	return total_weight;
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}
