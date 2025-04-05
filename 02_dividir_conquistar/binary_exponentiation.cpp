#include <iostream>
#include <cassert>

// Versão recursiva usando dividir e conquistar
long long binPowRecursive(long long base, long long exponent) {
    // Casos base
    if (exponent == 0) return 1;
    if (exponent == 1) return base;
    
    // Divide o problema pela metade
    long long half = binPowRecursive(base, exponent / 2);
    
    // Conquista: combina as soluções
    // Se o expoente for par: resultado = half * half
    // Se o expoente for ímpar: resultado = half * half * base
    if (exponent % 2 == 0) {
        return half * half;
    } else {
        return half * half * base;
    }
}

// Versão iterativa (mais eficiente em termos de memória)
long long binPowIterative(long long base, long long exponent) {
    long long result = 1;
    
    while (exponent > 0) {
        // Se o bit atual é 1, multiplica o resultado pela base atual
        if (exponent & 1) {
            result *= base;
        }
        // Eleva a base ao quadrado para o próximo bit
        base *= base;
        // Move para o próximo bit
        exponent >>= 1;
    }
    
    return result;
}

// Versão modular (para números muito grandes)
long long binPowModular(long long base, long long exponent, long long modulo) {
    base %= modulo;
    long long result = 1;
    
    while (exponent > 0) {
        if (exponent & 1) {
            result = (result * base) % modulo;
        }
        base = (base * base) % modulo;
        exponent >>= 1;
    }
    
    return result;
}

// Função para testar as implementações
void testBinaryExponentiation() {
    // Testes básicos
    assert(binPowRecursive(2, 3) == 8);
    assert(binPowIterative(2, 3) == 8);
    assert(binPowModular(2, 3, 1000000007) == 8);
    
    // Teste com expoente 0
    assert(binPowRecursive(5, 0) == 1);
    assert(binPowIterative(5, 0) == 1);
    assert(binPowModular(5, 0, 1000000007) == 1);
    
    // Teste com expoente 1
    assert(binPowRecursive(5, 1) == 5);
    assert(binPowIterative(5, 1) == 5);
    assert(binPowModular(5, 1, 1000000007) == 5);
    
    std::cout << "Todos os testes passaram!" << std::endl;
}

int main() {
    // Exemplo de uso
    long long base = 2;
    long long exponent = 10;
    
    std::cout << "Calculando " << base << "^" << exponent << " usando diferentes métodos:\n";
    
    // Usando a versão recursiva
    std::cout << "Método recursivo: " 
              << binPowRecursive(base, exponent) << "\n";
    
    // Usando a versão iterativa
    std::cout << "Método iterativo: " 
              << binPowIterative(base, exponent) << "\n";
    
    // Usando a versão modular (com módulo 1000000007)
    std::cout << "Método modular (mod 1000000007): " 
              << binPowModular(base, exponent, 1000000007) << "\n";
    
    // Executando os testes
    testBinaryExponentiation();
    
    return 0;
}