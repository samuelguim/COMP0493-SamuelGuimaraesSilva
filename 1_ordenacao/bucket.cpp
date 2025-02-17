#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

std::vector<float> bucketSort(std::vector<float>& arr) {
    if (arr.empty()) {
        return arr;
    }

    // Encontra o valor máximo e mínimo do array
    float max_val = arr[0];
    float min_val = arr[0];
    for (float num : arr) {
        max_val = std::max(max_val, num);
        min_val = std::min(min_val, num);
    }

    // Calcula o range para cada bucket
    float bucket_range = (max_val - min_val) / arr.size() + 1;

    // Cria os buckets vazios
    std::vector<std::vector<float>> buckets(arr.size());

    // Distribui os elementos nos buckets
    for (float num : arr) {
        int index = static_cast<int>((num - min_val) / bucket_range);
        // Garante que o último elemento vá para o último bucket
        if (index == arr.size()) {
            index--;
        }
        buckets[index].push_back(num);
    }

    // Ordena cada bucket individualmente
    for (auto& bucket : buckets) {
        std::sort(bucket.begin(), bucket.end());
    }

    // Concatena todos os buckets em ordem
    std::vector<float> sorted_array;
    for (const auto& bucket : buckets) {
        sorted_array.insert(sorted_array.end(), bucket.begin(), bucket.end());
    }

    return sorted_array;
}

int main() {
    // Teste com um array de exemplo
    std::vector<float> arr = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    
    std::cout << "Array original: ";
    for (float num : arr) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    std::vector<float> sorted_arr = bucketSort(arr);

    std::cout << "Array ordenado: ";
    for (float num : sorted_arr) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    return 0;
}