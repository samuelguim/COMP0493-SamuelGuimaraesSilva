#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Estrutura que representa um item com valor, peso e a razão valor/peso
struct Item {
    int peso;
    int valor;
    double razao; // valor/peso
};

// Função de comparação para ordenar os itens em ordem decrescente da razão
bool compararItens(const Item &a, const Item &b) {
    return a.razao > b.razao;
}

int main() {
    int n;
    double capacidade;
    
    cout << "Digite o número de itens: ";
    cin >> n;
    
    cout << "Digite a capacidade da mochila: ";
    cin >> capacidade;
    
    vector<Item> itens(n);
    
    // Leitura dos itens: valor e peso
    for (int i = 0; i < n; i++) {
        cout << "\nItem " << i + 1 << ":\n";
        cout << "Valor: ";
        cin >> itens[i].valor;
        cout << "Peso: ";
        cin >> itens[i].peso;
        // Calcula a razão valor/peso
        itens[i].razao = (double)itens[i].valor / itens[i].peso;
    }
    
    // Ordena os itens pela razão valor/peso em ordem decrescente
    sort(itens.begin(), itens.end(), compararItens);
    
    double valorTotal = 0.0;
    
    // Itera sobre os itens, adicionando-os na mochila de forma fracionária se necessário
    for (int i = 0; i < n && capacidade > 0; i++) {
        if (itens[i].peso <= capacidade) {
            // Adiciona o item inteiro
            capacidade -= itens[i].peso;
            valorTotal += itens[i].valor;
            cout << "\nItem " << i + 1 << " adicionado por inteiro: Valor " 
                 << itens[i].valor << ", Peso " << itens[i].peso;
        } else {
            // Adiciona somente a fração do item que cabe na mochila
            double fracao = capacidade / itens[i].peso;
            valorTotal += itens[i].valor * fracao;
            cout << "\nItem " << i + 1 << " adicionado parcialmente (" << fracao * 100 
                 << "%): Valor " << itens[i].valor * fracao << ", Peso " << capacidade;
            capacidade = 0; // Mochila cheia
        }
    }
    
    cout << "\n\nValor total obtido na mochila: " << valorTotal << endl;
    
    return 0;
}
