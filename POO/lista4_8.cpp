#include <iostream>

using namespace std;

int main() {
    int N;
    cout << "Digite o tamanho do vetor: ";
    cin >> N;

    if (N <= 0) 
    {
        cout << "Tamanho do vetor inválido." << endl;
        return 1;
    }

    int X[N];

    for (int i = 0; i < N; ++i) 
    {
        cout << "Digite o " << i + 1 << " número do elemento: ";
        cin >> X[i];
    }

    int maiorElemento = X[0];
    int posicaoMaiorElemento = 0;

    for (int i = 1; i < N; ++i) 
    {
        if (X[i] > maiorElemento) 
        {
            maiorElemento = X[i];
            posicaoMaiorElemento = i;
        }
    }

    cout << "O maior elemento do vetor é: " << maiorElemento << endl;
    cout << "Ele está na posição: " << posicaoMaiorElemento << endl;

    return 0;
}
