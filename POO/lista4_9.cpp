#include <iostream>

using namespace std;

void trocar(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void ordenarDecrescente(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho - 1; ++i) 
    {
        for (int j = i + 1; j < tamanho; ++j) 
        {
            if (vetor[i] < vetor[j]) 
            {
                trocar(vetor[i], vetor[j]);
            }
        }
    }
}

int main() {
    const int tamanho = 10;
    int vetor[tamanho];

    cout << "Digite " << tamanho << " números para preencher o vetor:" << endl;
    for (int i = 0; i < tamanho; ++i) 
    {
        cout << "Digite o " << i + 1 << " número: ";
        cin >> vetor[i];
    }

    ordenarDecrescente(vetor, tamanho);

    cout << "Vetor ordenado em ordem decrescente:" << endl;
    for (int i = 0; i < tamanho; ++i) 
    {
        cout << vetor[i] << " ";
    }
    cout << endl;

    return 0;
}
