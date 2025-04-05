#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Aresta {
    int origem;
    int destino;
    int peso;
    
    Aresta(int o, int d, int p) : origem(o), destino(d), peso(p) {}
    
    bool operator<(const Aresta& outra) const {
        return peso < outra.peso;
    }
};

class UnionFind {
private:
    vector<int> pai;
    vector<int> tamanho;

public:
    UnionFind(int n) {
        pai.resize(n);
        tamanho.resize(n, 1);
        
        for (int i = 0; i < n; i++) {
            pai[i] = i;
        }
    }
    
    int encontrar(int x) {
        if (pai[x] != x) {
            pai[x] = encontrar(pai[x]);
        }
        return pai[x];
    }
    
    bool mesmoConjunto(int a, int b) {
        return encontrar(a) == encontrar(b);
    }
    
    void unir(int a, int b) {
        int raizA = encontrar(a);
        int raizB = encontrar(b);
        
        if (raizA == raizB) return;
        
        if (tamanho[raizA] < tamanho[raizB]) {
            pai[raizA] = raizB;
            tamanho[raizB] += tamanho[raizA];
        } else {
            pai[raizB] = raizA;
            tamanho[raizA] += tamanho[raizB];
        }
    }
};

vector<Aresta> Kruskal(int numVertices, vector<Aresta>& arestas) {
    vector<Aresta> arvoreGeradoraMinima;
    
    sort(arestas.begin(), arestas.end());
    
    UnionFind uf(numVertices);
    
    for (const Aresta& aresta : arestas) {
        int u = aresta.origem;
        int v = aresta.destino;
        
        if (!uf.mesmoConjunto(u, v)) {
            uf.unir(u, v);
            arvoreGeradoraMinima.push_back(aresta);
        }
    }
    
    return arvoreGeradoraMinima;
}

int main() {
    int numVertices = 6;
    vector<Aresta> arestas;
    
    arestas.push_back(Aresta(0, 1, 4));
    arestas.push_back(Aresta(0, 2, 3));
    arestas.push_back(Aresta(1, 2, 1));
    arestas.push_back(Aresta(1, 3, 2));
    arestas.push_back(Aresta(2, 3, 4));
    arestas.push_back(Aresta(2, 4, 3));
    arestas.push_back(Aresta(3, 4, 2));
    arestas.push_back(Aresta(3, 5, 1));
    arestas.push_back(Aresta(4, 5, 5));
    
    vector<Aresta> arvoreGeradoraMinima = Kruskal(numVertices, arestas);
    
    cout << "Arestas na Árvore Geradora Mínima (Kruskal):" << endl;
    int custoTotal = 0;
    
    for (const Aresta& aresta : arvoreGeradoraMinima) {
        cout << "Aresta: " << aresta.origem << " - " << aresta.destino << ", Peso: " << aresta.peso << endl;
        custoTotal += aresta.peso;
    }
    
    cout << "Custo total da Árvore Geradora Mínima: " << custoTotal << endl;
    
    return 0;
}