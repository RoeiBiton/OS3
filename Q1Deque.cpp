#include <iostream>
#include <list>
#include <deque>
#include <stack>
#include <vector>
#include <chrono>

using namespace std;

class Graph {
    int V;
    deque<int> *adj;

    void DFSUtil(int v, vector<bool> &visited, vector<int> &component);
    void fillOrder(int v, vector<bool> &visited, stack<int> &Stack);

public:
    Graph(int V);
    void addEdge(int v, int w);
    void kosarajuSCC();
    Graph getTranspose();
};

Graph::Graph(int V) {
    this->V = V;
    adj = new deque<int>[V + 1];  // שינוי ל-deque
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}

void Graph::DFSUtil(int v, vector<bool> &visited, vector<int> &component) {
    visited[v] = true;
    component.push_back(v);

    for (int i : adj[v])
        if (!visited[i])
            DFSUtil(i, visited, component);
}

Graph Graph::getTranspose() {
    Graph g(V);
    for (int v = 1; v <= V; v++) {
        for (int i : adj[v])
            g.addEdge(i, v);
    }
    return g;
}

void Graph::fillOrder(int v, vector<bool> &visited, stack<int> &Stack) {
    visited[v] = true;

    for (int i : adj[v])
        if (!visited[i])
            fillOrder(i, visited, Stack);

    Stack.push(v);
}

void Graph::kosarajuSCC() {
    stack<int> Stack;
    vector<bool> visited(V + 1, false);

    for (int i = 1; i <= V; i++)
        if (!visited[i])
            fillOrder(i, visited, Stack);

    Graph gr = getTranspose();

    fill(visited.begin(), visited.end(), false);

    while (!Stack.empty()) {
        int v = Stack.top();
        Stack.pop();

        if (!visited[v]) {
            vector<int> component;
            gr.DFSUtil(v, visited, component);

            for (int node : component)
                cout << node << " ";
            cout << endl;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    Graph g(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }


    auto start = chrono::high_resolution_clock::now();
    g.kosarajuSCC();
    auto stop = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << "Duration with deque: " << duration.count() << " microseconds" << endl;

    return 0;
}
