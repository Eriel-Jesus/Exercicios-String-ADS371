// Citação Bibliográfica.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

std::string caixaAlta(std::string s) {
    for (char& c : s) c = toupper(c);
    return s;
}

int main() {
    std::ifstream entrada("nomes.txt");
    std::ofstream saida("citacao_simples.txt");
    std::string linha;

    while (std::getline(entrada, linha)) {
        if (linha.empty()) continue;

        std::stringstream ss(linha);
        std::string palavra;
        std::vector<std::string> nomes;

        while (ss >> palavra) nomes.push_back(palavra);

        if (nomes.size() > 1) {
            // 1. Sobrenome principal em MAIÚSCULAS
            saida << caixaAlta(nomes.back()) << ", ";

            // 2. Primeiro nome completo
            saida << nomes[0] << " ";

            // 3. Iniciais dos nomes do meio (se existirem)
            for (size_t i = 1; i < nomes.size() - 1; ++i) {
                if (nomes[i].length() > 2) { // Ignora "de", "do", "da"
                    saida << (char)toupper(nomes[i][0]) << ". ";
                }
            }
            saida << "\n";
        }
        else {
            saida << caixaAlta(linha) << "\n";
        }
    }

    std::cout << "Odeio essa norma da ABNT, sério..." << std::endl;
    return 0;
}