#include <iostream>

using namespace std;

int pesqsent(int val, int vetor[], int tamanho) {
    int ultimo = vetor[tamanho - 1]; 
    vetor[tamanho - 1] = val; 
    
    int i = 0;
    while (vetor[i] != val) 
    {
        i++; 
    }
    
    vetor[tamanho - 1] = ultimo; 
    
    if (i < tamanho - 1 || val == ultimo) 
    {
        return i;
    }
    
    return -1; 
}

int main() {
    int vetor[] = {1, 3, 5, 7, 9, 11, 13};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    int valorProcurado = 7;

    int posicao = pesqsent(valorProcurado, vetor, tamanho);

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
