#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    // Abordagem 1: Comparação Vertical
    std::string longestCommonPrefixVertical(std::vector<std::string>& strs) {
        if (strs.empty()) return "";
        
        // Para cada caractere na primeira string
        for (int i = 0; i < strs[0].length(); i++) {
            char c = strs[0][i];
            // Compara com o mesmo caractere em todas as outras strings
            for (int j = 1; j < strs.size(); j++) {
                if (i >= strs[j].length() || strs[j][i] != c) {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
    
    // Abordagem 2: Dividir e Conquistar
    std::string longestCommonPrefixDC(std::vector<std::string>& strs) {
        if (strs.empty()) return "";
        return divideAndConquer(strs, 0, strs.size() - 1);
    }
    
private:
    std::string divideAndConquer(std::vector<std::string>& strs, int left, int right) {
        if (left == right) {
            return strs[left];
        }
        
        int mid = left + (right - left) / 2;
        std::string leftPrefix = divideAndConquer(strs, left, mid);
        std::string rightPrefix = divideAndConquer(strs, mid + 1, right);
        
        return commonPrefix(leftPrefix, rightPrefix);
    }
    
    std::string commonPrefix(const std::string& str1, const std::string& str2) {
        int minLength = std::min(str1.length(), str2.length());
        for (int i = 0; i < minLength; i++) {
            if (str1[i] != str2[i]) {
                return str1.substr(0, i);
            }
        }
        return str1.substr(0, minLength);
    }
    
    // Abordagem 3: Binary Search
    std::string longestCommonPrefixBinary(std::vector<std::string>& strs) {
        if (strs.empty()) return "";
        
        // Encontra a menor string
        int minLen = INT_MAX;
        for (const string& str : strs) {
            minLen = std::min(minLen, static_cast<int>(str.length()));
        }
        
        int low = 0, high = minLen;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (isCommonPrefix(strs, mid)) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return strs[0].substr(0, (low + high) / 2);
    }
    
    bool isCommonPrefix(const std::vector<std::string>& strs, int len) {
        std::string prefix = strs[0].substr(0, len);
        for (int i = 1; i < strs.size(); i++) {
            if (strs[i].substr(0, len) != prefix) {
                return false;
            }
        }
        return true;
    }
};

// Função para testar as implementações
void testLongestCommonPrefix() {
    Solution solution;
    
    // Casos de teste
    std::vector<std::vector<std::string>> testCases = {
        {"flower", "flow", "flight"},
        {"dog", "racecar", "car"},
        {"interspecies", "interstellar", "interstate"},
        {"throne", "throne"},
        {""},
        {"prefix", "prefix", "prefix"},
        {"abc", "abc", "abc", "abc"}
    };
    
    for (const auto& testCase : testCases) {
        std::cout << "\nTeste com strings: ";
        for (const auto& str : testCase) {
            std::cout << str << " ";
        }
        std::cout << "\n";
        
        std::cout << "Método Vertical: " 
                  << solution.longestCommonPrefixVertical(testCase) << "\n";
        std::cout << "Método Dividir e Conquistar: " 
                  << solution.longestCommonPrefixDC(testCase) << "\n";
        std::cout << "Método Binary Search: " 
                  << solution.longestCommonPrefixBinary(testCase) << "\n";
    }
}

int main() {
    testLongestCommonPrefix();
    return 0;
}