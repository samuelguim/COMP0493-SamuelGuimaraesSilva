#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> computarTabelaLPS(string padrao) {
    int m = padrao.length();
    vector<int> lps(m, 0);
    
    int comprimento = 0;
    int i = 1;
    
    while (i < m) {
        if (padrao[i] == padrao[comprimento]) {
            comprimento++;
            lps[i] = comprimento;
            i++;
        } else {
            if (comprimento != 0) {
                comprimento = lps[comprimento - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    
    return lps;
}

vector<int> KMP(string texto, string padrao) {
    vector<int> posicoes;
    int n = texto.length();
    int m = padrao.length();
    
    if (m == 0) return posicoes;
    
    vector<int> lps = computarTabelaLPS(padrao);
    
    int i = 0;
    int j = 0;
    
    while (i < n) {
        if (padrao[j] == texto[i]) {
            i++;
            j++;
        }
        
        if (j == m) {
            posicoes.push_back(i - j);
            j = lps[j - 1];
        } else if (i < n && padrao[j] != texto[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    
    return posicoes;
}

int main() {
    string texto, padrao;
    cout << "Digite o texto: ";
    getline(cin, texto);
    cout << "Digite o padrão a ser buscado: ";
    getline(cin, padrao);
    
    vector<int> resultado = KMP(texto, padrao);
    
    if (resultado.empty()) {
        cout << "Padrão não encontrado no texto." << endl;
    } else {
        cout << "Padrão encontrado nas posições: ";
        for (int pos : resultado) {
            cout << pos << " ";
        }
        cout << endl;
    }
    
    return 0;
}