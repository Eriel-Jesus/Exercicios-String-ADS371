// Palindromo.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string mensagem, tratada = "";

    cout << "Digite uma mensagem: ";
    getline(cin, mensagem);

    // Remove espaços e converte para minúsculo
    for (char c : mensagem) {
        if (c != ' ') {
            tratada += tolower(c);
        }
    }

    // Cria uma cópia invertida
    string invertida = tratada;
    reverse(invertida.begin(), invertida.end());

    // Verifica se é palíndromo
    if (tratada == invertida) {
        cout << "É um palíndromo!" << endl;
    }
    else {
        cout << "Não é um palíndromo." << endl;
    }

    return 0;
}