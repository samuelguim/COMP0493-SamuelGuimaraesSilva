#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

const int PRIMO = 101;

vector<int> RabinKarp(string texto, string padrao) {
    vector<int> posicoes;
    int n = texto.length();
    int m = padrao.length();
    
    if (m == 0 || m > n) return posicoes;
    
    int base = 256;
    int hashPadrao = 0;
    int hashTexto = 0;
    int h = 1;
    
    for (int i = 0; i < m - 1; i++) {
        h = (h * base) % PRIMO;
    }
    
    for (int i = 0; i < m; i++) {
        hashPadrao = (base * hashPadrao + padrao[i]) % PRIMO;
        hashTexto = (base * hashTexto + texto[i]) % PRIMO;
    }
    
    for (int i = 0; i <= n - m; i++) {
        if (hashPadrao == hashTexto) {
            bool correspondencia = true;
            for (int j = 0; j < m; j++) {
                if (texto[i + j] != padrao[j]) {
                    correspondencia = false;
                    break;
                }
            }
            
            if (correspondencia) {
                posicoes.push_back(i);
            }
        }
        
        if (i < n - m) {
            hashTexto = (base * (hashTexto - texto[i] * h) + texto[i + m]) % PRIMO;
            
            if (hashTexto < 0) {
                hashTexto += PRIMO;
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
    
    vector<int> resultado = RabinKarp(texto, padrao);
    
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