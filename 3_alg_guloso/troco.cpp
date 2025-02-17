#include <iostream>
#include <vector>

using namespace std;

int main() {
    int valor;
    cout << "Digite o valor para o troco (em centavos): ";
    cin >> valor;
    
    // Vetor com os valores das moedas disponíveis, em ordem decrescente.
    vector<int> moedas = {100, 50, 25, 10, 5, 1};
    vector<int> contagem(moedas.size(), 0); // Armazena a quantidade de cada moeda usada.
    
    // Algoritmo guloso para calcular o troco
    for (size_t i = 0; i < moedas.size(); i++) {
        if (valor >= moedas[i]) {
            contagem[i] = valor / moedas[i];  // Quantas moedas do tipo atual cabem no valor
            valor %= moedas[i];               // Atualiza o valor restante
        }
    }
    
    cout << "\nTroco:\n";
    for (size_t i = 0; i < moedas.size(); i++) {
        if (contagem[i] > 0) {
            cout << contagem[i] << " moeda(s) de " << moedas[i] << " centavos\n";
        }
    }
    
    return 0;
}
