#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <limits>

using namespace std;

typedef pair<int, int> iPair;

class Grafo {
private:
    int numVertices;
    vector<vector<pair<int, int>>> listaAdjacencia;

public:
    Grafo(int v) : numVertices(v) {
        listaAdjacencia.resize(v);
    }
    
    void adicionarAresta(int u, int v, int peso) {
        listaAdjacencia[u].push_back(make_pair(v, peso));
        listaAdjacencia[v].push_back(make_pair(u, peso));
    }
    
    vector<pair<int, iPair>> Prim() {
        priority_queue<iPair, vector<iPair>, greater<iPair>> filaPrioridade;
        
        int verticeInicial = 0;
        vector<int> chave(numVertices, numeric_limits<int>::max());
        vector<int> pai(numVertices, -1);
        vector<bool> naAGM(numVertices, false);
        
        filaPrioridade.push(make_pair(0, verticeInicial));
        chave[verticeInicial] = 0;
        
        while (!filaPrioridade.empty()) {
            int u = filaPrioridade.top().second;
            filaPrioridade.pop();
            
            if (naAGM[u])
                continue;
                
            naAGM[u] = true;
            
            for (const auto& vizinho : listaAdjacencia[u]) {
                int v = vizinho.first;
                int peso = vizinho.second;
                
                if (!naAGM[v] && chave[v] > peso) {
                    chave[v] = peso;
                    filaPrioridade.push(make_pair(chave[v], v));
                    pai[v] = u;
                }
            }
        }
        
        vector<pair<int, iPair>> resultado;
        for (int i = 1; i < numVertices; i++) {
            resultado.push_back({chave[i], {pai[i], i}});
        }
        
        return resultado;
    }
};

int main() {
    int numVertices = 6;
    Grafo g(numVertices);
    
    g.adicionarAresta(0, 1, 4);
    g.adicionarAresta(0, 2, 3);
    g.adicionarAresta(1, 2, 1);
    g.adicionarAresta(1, 3, 2);
    g.adicionarAresta(2, 3, 4);
    g.adicionarAresta(2, 4, 3);
    g.adicionarAresta(3, 4, 2);
    g.adicionarAresta(3, 5, 1);
    g.adicionarAresta(4, 5, 5);
    
    vector<pair<int, iPair>> arvoreGeradoraMinima = g.Prim();
    
    cout << "Arestas na Árvore Geradora Mínima (Prim):" << endl;
    int custoTotal = 0;
    
    for (const auto& aresta : arvoreGeradoraMinima) {
        cout << "Aresta: " << aresta.second.first << " - " << aresta.second.second << ", Peso: " << aresta.first << endl;
        custoTotal += aresta.first;
    }
    
    cout << "Custo total da Árvore Geradora Mínima: " << custoTotal << endl;
    
    return 0;
}