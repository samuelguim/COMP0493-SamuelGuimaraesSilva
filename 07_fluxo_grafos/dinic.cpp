#include <iostream>
#include <vector>
#include <queue>
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
    
    bool buscaDinic(int fonte, int sumidouro, vector<int>& nivel) {
        fill(nivel.begin(), nivel.end(), -1);
        nivel[fonte] = 0;
        
        queue<int> fila;
        fila.push(fonte);
        
        while (!fila.empty()) {
            int u = fila.front();
            fila.pop();
            
            for (int v : adj[u]) {
                if (nivel[v] < 0 && capacidade[u][v] > fluxo[u][v]) {
                    nivel[v] = nivel[u] + 1;
                    fila.push(v);
                }
            }
        }
        
        return nivel[sumidouro] >= 0;
    }
    
    int fluxoDfs(int u, int sumidouro, int fluxoAtual, vector<int>& nivel, vector<int>& ponteiro) {
        if (u == sumidouro)
            return fluxoAtual;
            
        for (int& i = ponteiro[u]; i < adj[u].size(); i++) {
            int v = adj[u][i];
            
            if (nivel[v] == nivel[u] + 1 && capacidade[u][v] > fluxo[u][v]) {
                int fluxoAtualizado = min(fluxoAtual, capacidade[u][v] - fluxo[u][v]);
                int fluxoEncontrado = fluxoDfs(v, sumidouro, fluxoAtualizado, nivel, ponteiro);
                
                if (fluxoEncontrado > 0) {
                    fluxo[u][v] += fluxoEncontrado;
                    fluxo[v][u] -= fluxoEncontrado;
                    return fluxoEncontrado;
                }
            }
        }
        
        return 0;
    }
    
    int dinic(int fonte, int sumidouro) {
        int fluxoMaximo = 0;
        vector<int> nivel(V);
        
        while (buscaDinic(fonte, sumidouro, nivel)) {
            vector<int> ponteiro(V, 0);
            int fluxoAdicional;
            
            while ((fluxoAdicional = fluxoDfs(fonte, sumidouro, numeric_limits<int>::max(), nivel, ponteiro)) > 0) {
                fluxoMaximo += fluxoAdicional;
            }
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
    
    cout << "Fluxo máximo usando Dinic: " << g.dinic(fonte, sumidouro) << endl;
    
    return 0;
}