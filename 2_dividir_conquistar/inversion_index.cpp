#include <iostream>
#include <vector>

// Função que combina duas partes ordenadas e conta inversões
long long mergeAndCount(std::vector<int>& arr, int left, int mid, int right) {
    std::vector<int> temp(right - left + 1);
    int i = left;      // Índice para a primeira metade
    int j = mid + 1;   // Índice para a segunda metade
    int k = 0;         // Índice para o array temporário
    long long inversions = 0;
    
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            // Quando arr[i] > arr[j], todos os elementos de i até mid
            // formam inversões com arr[j]
            inversions += mid - i + 1;
            temp[k++] = arr[j++];
        }
    }
    
    // Copia os elementos restantes da primeira metade
    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    
    // Copia os elementos restantes da segunda metade
    while (j <= right) {
        temp[k++] = arr[j++];
    }
    
    // Copia o array temporário de volta para o array original
    for (i = left, k = 0; i <= right; i++, k++) {
        arr[i] = temp[k];
    }
    
    return inversions;
}

// Função recursiva principal que implementa dividir e conquistar
long long countInversions(std::vector<int>& arr, int left, int right) {
    long long inversions = 0;
    
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        // Conta inversões na primeira metade
        inversions += countInversions(arr, left, mid);
        
        // Conta inversões na segunda metade
        inversions += countInversions(arr, mid + 1, right);
        
        // Conta inversões entre as duas metades
        inversions += mergeAndCount(arr, left, mid, right);
    }
    
    return inversions;
}

// Função auxiliar para imprimir o array
void printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << "\n";
}

int main() {
    // Exemplos de teste
    std::vector<std::vector<int>> testCases = {
        {1, 2, 3, 4, 5},           // Ordenado (0 inversões)
        {5, 4, 3, 2, 1},           // Inversamente ordenado (10 inversões)
        {2, 4, 1, 3, 5},           // Parcialmente ordenado
        {8, 4, 2, 1},              // Outro exemplo
        {3, 1, 2}                  // Exemplo pequeno
    };
    
    for (int i = 0; i < testCases.size(); i++) {
        std::vector<int> arr = testCases[i];
        std::cout << "\nCaso de teste " << i + 1 << ":\n";
        std::cout << "Array original: ";
        printArray(arr);
        
        long long inversions = countInversions(arr, 0, arr.size() - 1);
        
        std::cout << "Array ordenado: ";
        printArray(arr);
        std::cout << "Número de inversões: " << inversions << "\n";
    }
    
    return 0;
}