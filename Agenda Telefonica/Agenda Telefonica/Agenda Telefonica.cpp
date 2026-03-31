// Agenda Telefonica.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {
	// Abre o arquivo de entrada para leitura e o arquivo de saída para escrita
    std::ifstream arquivoEntrada("nomes.txt");
    std::ofstream arquivoSaida("agenda.txt");

	// Variável para armazenar cada linha lida do arquivo de entrada
    std::string linha;

    if (!arquivoEntrada.is_open()) {

		// Exibe uma mensagem de erro se o arquivo de entrada não puder ser aberto
        std::cerr << "Erro ao abrir o arquivo de entrada!" << std::endl;

		//retornar um código de erro diferente de 0 para indicar a falha
    }
	// Lê cada linha do arquivo de entrada, processa o nome e escreve no formato "Sobrenome, Nome" no arquivo de saída
    while (std::getline(arquivoEntrada, linha)) {
        if (linha.empty()) continue;

        // Encontra a posição do último espaço
        size_t ultimoEspaco = linha.find_last_of(" ");

        if (ultimoEspaco != std::string::npos) {
            // Separa o último sobrenome e o resto do nome
            std::string nomeRestante = linha.substr(0, ultimoEspaco);
            std::string ultimoSobrenome = linha.substr(ultimoEspaco + 1);

            // Formata: Sobrenome, Nome
            arquivoSaida << ultimoSobrenome << ", " << nomeRestante << std::endl;
        }
        else {
            // Caso o nome seja uma única palavra, apenas escreve como está
            arquivoSaida << linha << std::endl;
        }
    }

    std::cout << "Processamento concluído. Verifique 'agenda.txt'." << std::endl;

    arquivoEntrada.close();
    arquivoSaida.close();

    return 0;
}