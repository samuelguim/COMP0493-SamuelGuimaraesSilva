#include <iostream>
#include <vector>

using namespace std;

class UnionFind {
private:
    vector<int> pai;
    vector<int> tamanho;
    int conjuntos;

public:
    UnionFind(int n) {
        pai.resize(n);
        tamanho.resize(n, 1);
        conjuntos = n;
        
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
        
        conjuntos--;
    }
    
    int getConjuntos() {
        return conjuntos;
    }
};

int main() {
    int n = 10;
    UnionFind uf(n);
    
    cout << "Número inicial de conjuntos: " << uf.getConjuntos() << endl;
    
    uf.unir(0, 1);
    uf.unir(2, 3);
    uf.unir(4, 5);
    uf.unir(6, 7);
    uf.unir(8, 9);
    
    cout << "Número de conjuntos após primeiras uniões: " << uf.getConjuntos() << endl;
    
    uf.unir(1, 3);
    uf.unir(5, 7);
    uf.unir(7, 9);
    
    cout << "Número de conjuntos após mais uniões: " << uf.getConjuntos() << endl;
    
    for (int i = 0; i < n; i++) {
        cout << "Elemento " << i << " pertence ao conjunto " << uf.encontrar(i) << endl;
    }
    
    return 0;
}