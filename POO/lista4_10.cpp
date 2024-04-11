#include <iostream>

using namespace std;

int pesqseq(int N, int vetor[], int tamanho, int& numComparacoes) {
    for (int i = 0; i < tamanho; ++i) 
    {
        numComparacoes++;
        if (vetor[i] == N) 
        {
            return i; 
        }
    }
    return -1; 
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

    int valorProcurado;
    cout << "Digite o valor a ser procurado: ";
    cin >> valorProcurado;

    int numComparacoes = 0;
    int posicao = pesqseq(valorProcurado, vetor, tamanho, numComparacoes);

    if (posicao != -1) 
    {
        cout << "O valor " << valorProcurado << " foi encontrado na posição " << posicao << " do vetor." << endl;
        cout << "Número de comparações realizadas: " << numComparacoes << endl;
    } 
    else 
    {
        cout << "O valor " << valorProcurado << " não foi encontrado no vetor." << endl;
        cout << "Número de comparações realizadas: " << numComparacoes << endl;
    }

    return 0;
}
