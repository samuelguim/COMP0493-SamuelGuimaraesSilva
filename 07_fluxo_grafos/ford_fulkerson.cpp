#include <iostream>
#include <vector>
#include <stack>
#include <limits>
#include <algorithm>
using namespace std;

class Grafo {
private:
    int V;
    vector<vector<int>> capacidade;
    vector<vector<int>> fluxo;
    vector<vector<int>> adj;

public:
    Grafo(int vertices) {
        V = vertices;
        capacidade.resize(V, vector<int>(V, 0));
        fluxo.resize(V, vector<int>(V, 0));
        adj.resize(V);
    }

    void adicionarAresta(int u, int v, int cap) {
        capacidade[u][v] = cap;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool buscaProfundidade(int fonte, int sumidouro, vector<int>& pai) {
        vector<bool> visitado(V, false);
        stack<int> pilha;
        pilha.push(fonte);
        visitado[fonte] = true;
        pai[fonte] = -1;

        while (!pilha.empty()) {
            int u = pilha.top();
            pilha.pop();

            for (int v : adj[u]) {
                if (!visitado[v] && capacidade[u][v] > fluxo[u][v]) {
                    pilha.push(v);
                    pai[v] = u;
                    visitado[v] = true;
                }
            }
        }

        return visitado[sumidouro];
    }

    int fordFulkerson(int fonte, int sumidouro) {
        vector<int> pai(V);
        int fluxoMaximo = 0;

        while (buscaProfundidade(fonte, sumidouro, pai)) {
            int fluxoCaminho = numeric_limits<int>::max();

            for (int v = sumidouro; v != fonte; v = pai[v]) {
                int u = pai[v];
                fluxoCaminho = min(fluxoCaminho, capacidade[u][v] - fluxo[u][v]);
            }

            for (int v = sumidouro; v != fonte; v = pai[v]) {
                int u = pai[v];
                fluxo[u][v] += fluxoCaminho;
                fluxo[v][u] -= fluxoCaminho;
            }

            fluxoMaximo += fluxoCaminho;
        }

        return fluxoMaximo;
    }
};

int main() {
    int V = 6;
    Grafo g(V);
    
    g.adicionarAresta(0, 1, 16);
    g.adicionarAresta(0, 2, 13);
    g.adicionarAresta(1, 2, 10);
    g.adicionarAresta(1, 3, 12);
    g.adicionarAresta(2, 1, 4);
    g.adicionarAresta(2, 4, 14);
    g.adicionarAresta(3, 2, 9);
    g.adicionarAresta(3, 5, 20);
    g.adicionarAresta(4, 3, 7);
    g.adicionarAresta(4, 5, 4);
    
    int fonte = 0, sumidouro = 5;
    
    cout << "Fluxo máximo usando Ford-Fulkerson: " << g.fordFulkerson(fonte, sumidouro) << endl;
    
    return 0;
}