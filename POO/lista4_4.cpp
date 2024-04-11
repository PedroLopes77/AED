#include <iostream>

using namespace std;

int pesqbin(int val, int vetor[], int tamanho) {
    int inicio = 0;
    int fim = tamanho - 1;
    
    while (inicio <= fim) 
    {
        int meio = inicio + (fim - inicio) / 2;
        
        if (vetor[meio] == val) 
        {
            return meio; 
        } 
        else if (vetor[meio] < val) 
        {
            inicio = meio + 1;
        } 
        else 
        {
            fim = meio - 1;
        }
    }
    
    return -1;
}

int main() {
    int vetor[] = {1, 3, 5, 7, 9, 11, 13};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    int valorProcurado = 7;

    int posicao = pesqbin(valorProcurado, vetor, tamanho);

    if (posicao != -1) {
        cout << "O valor " << valorProcurado << " foi encontrado na posição " << posicao << " do vetor." << endl;
    } 
    else 
    {
        cout << "O valor " << valorProcurado << " não foi encontrado no vetor." << endl;
    }

    return 0;
}
