#include <iostream>
#include <vector>

using namespace std;

// Função auxiliar para a busca em profundidade (DFS) usando recursão
void dfsUtil(int node, const vector<vector<int>> &graph, vector<bool> &visited) {
    visited[node] = true;
    cout << node << " ";
    
    // Percorre os vizinhos do vértice atual
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfsUtil(neighbor, graph, visited);
        }
    }
}

// Função que implementa a busca em profundidade (DFS)
void dfs(int start, const vector<vector<int>> &graph) {
    vector<bool> visited(graph.size(), false);
    cout << "DFS: ";
    dfsUtil(start, graph, visited);
    cout << endl;
}

int main() {
    int vertices, edges;
    cout << "Digite o número de vértices: ";
    cin >> vertices;
    cout << "Digite o número de arestas: ";
    cin >> edges;
    
    // Cria o grafo representado por uma lista de adjacência
    vector<vector<int>> graph(vertices);
    
    cout << "Digite as arestas no formato (u v) (vértices indexados a partir de 0):" << endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        // Para um grafo não direcionado, adicionamos as arestas nos dois sentidos
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    int start;
    cout << "Digite o vértice inicial para a DFS: ";
    cin >> start;
    
    dfs(start, graph);
    
    return 0;
}
