// Citação Bibliográfica.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

// Função auxiliar para converter string para MAIÚSCULAS
std::string paraMaiuscula(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(), ::toupper);
    return s;
}

int main() {
	// Mesmo esquema do exercício anterior, mas agora o programa deve ler os nomes de um arquivo de texto chamado "nomes.txt" e gerar um arquivo de saída chamado "citacao.txt" com as citações formatadas.
    std::ifstream arquivoEntrada("nomes.txt");
    std::ofstream arquivoSaida("citacao.txt");
    std::string linha;

	//Mesma verificação de abertura do arquivo.
    if (!arquivoEntrada.is_open()) {
        std::cerr << "Erro: Arquivo 'nomes.txt' nao encontrado." << std::endl;

        //Precisa retornar 1 para indicar o erro e encerrar o programa.
        return 1;
    }

	// Lê cada linha do arquivo de entrada, processa o nome e escreve a citação formatada no arquivo de saída.
    while (std::getline(arquivoEntrada, linha)) {
		// Ignora linhas vazias
        if (linha.empty()) continue;

		// Usa stringstream para dividir a linha em palavras
        std::stringstream ss(linha);
        std::string palavra;

		// Vetor para armazenar as partes do nome
        std::vector<std::string> partes;

        // Divide a linha em palavras
        while (ss >> palavra) {
            partes.push_back(palavra);
        }

        if (partes.size() > 1) {
            // O último elemento vira o sobrenome em MAIÚSCULAS
            std::string ultimoSobrenome = paraMaiuscula(partes.back());

            arquivoSaida << ultimoSobrenome << ", ";

            // Itera sobre os prenomes para pegar as iniciais
            for (size_t i = 0; i < partes.size() - 1; ++i) {
                // Ignora preposições comuns em nomes brasileiros (da, de, do, dos)
                std::string p = partes[i];
                if (p == "de" || p == "da" || p == "do" || p == "dos" || p == "e") {
                    continue;
                }

                // Pega a primeira letra e adiciona o ponto
                arquivoSaida << (char)toupper(partes[i][0]) << ". ";
            }
            arquivoSaida << "\n";
        }
        else {
            // Se houver apenas uma palavra, apenas coloca em maiúsculas
            arquivoSaida << paraMaiuscula(linha) << "\n";
        }
    }

    std::cout << "Processamento concluído. Arquivo 'citacao.txt' gerado." << std::endl;

	// Fecha os arquivos
    arquivoEntrada.close();
    arquivoSaida.close();

    return 0;
}