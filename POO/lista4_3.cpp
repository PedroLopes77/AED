#include <iostream>

using namespace std;

int pesqseq(int val, int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; ++i) 
    {
        if (vetor[i] == val) 
        {
            return i; 
        }
    }
    return -1; 
}

int main() {
    int vetor[] = {1, 3, 5, 7, 9, 11, 13};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    int valorProcurado = 7;

    int posicao = pesqseq(valorProcurado, vetor, tamanho);

    if (posicao != -1) 
    {
        cout << "O valor " << valorProcurado << " foi encontrado na posição " << posicao << " do vetor." << endl;
    } 
    else 
    {
        cout << "O valor " << valorProcurado << " não foi encontrado no vetor." << endl;
    }

    return 0;
}
