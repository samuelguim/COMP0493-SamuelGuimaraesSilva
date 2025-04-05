#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<char, int> criarTabelaCaractereRuim(string padrao) {
    unordered_map<char, int> tabela;
    int m = padrao.length();
    
    for (int i = 0; i < m - 1; i++) {
        tabela[padrao[i]] = m - 1 - i;
    }
    
    return tabela;
}

vector<int> criarTabelaSufixoBom(string padrao) {
    int m = padrao.length();
    vector<int> sufixoBom(m, 0);
    vector<int> sufixoLongo(m, 0);
    
    for (int i = m - 1; i >= 0; i--) {
        int j = i;
        while (j >= 0 && padrao[j] == padrao[m - 1 - i + j]) {
            j--;
        }
        sufixoLongo[i] = i - j;
    }
    
    for (int i = 0; i < m; i++) {
        sufixoBom[i] = m;
    }
    
    for (int i = m - 1; i >= 0; i--) {
        if (sufixoLongo[i] == i + 1) {
            for (int j = 0; j < m - 1 - i; j++) {
                if (sufixoBom[j] == m) {
                    sufixoBom[j] = m - 1 - i;
                }
            }
        }
    }
    
    for (int i = 0; i <= m - 2; i++) {
        sufixoBom[m - 1 - sufixoLongo[i]] = m - 1 - i;
    }
    
    return sufixoBom;
}

vector<int> BoyerMoore(string texto, string padrao) {
    vector<int> posicoes;
    int n = texto.length();
    int m = padrao.length();
    
    if (m == 0) return posicoes;
    
    unordered_map<char, int> tabelaCaractereRuim = criarTabelaCaractereRuim(padrao);
    vector<int> tabelaSufixoBom = criarTabelaSufixoBom(padrao);
    
    int i = 0;
    while (i <= n - m) {
        int j = m - 1;
        
        while (j >= 0 && padrao[j] == texto[i + j]) {
            j--;
        }
        
        if (j < 0) {
            posicoes.push_back(i);
            i += tabelaSufixoBom[0];
        } else {
            int deslocamentoCaractereRuim = 1;
            if (tabelaCaractereRuim.find(texto[i + j]) != tabelaCaractereRuim.end()) {
                deslocamentoCaractereRuim = tabelaCaractereRuim[texto[i + j]];
            } else {
                deslocamentoCaractereRuim = m;
            }
            
            int deslocamentoSufixoBom = tabelaSufixoBom[j];
            
            i += max(deslocamentoCaractereRuim, deslocamentoSufixoBom);
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
    
    vector<int> resultado = BoyerMoore(texto, padrao);
    
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