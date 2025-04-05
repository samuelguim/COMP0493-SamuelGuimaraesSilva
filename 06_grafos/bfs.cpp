#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Função que implementa a busca em largura (BFS)
void bfs(int start, const vector<vector<int>> &graph) {
    vector<bool> visited(graph.size(), false);
    queue<int> q;
    
    visited[start] = true;
    q.push(start);
    
    cout << "BFS: ";
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << current << " ";
        
        // Percorre os vizinhos do vértice atual
        for (int neighbor : graph[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
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
    cout << "Digite o vértice inicial para a BFS: ";
    cin >> start;
    
    bfs(start, graph);
    
    return 0;
}
