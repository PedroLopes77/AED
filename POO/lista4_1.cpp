#include <iostream>

using namespace std;

int* preencherVetor(int tamanho) {
    int* vetor = new int[tamanho];
    
    for (int i = 0; i < tamanho; ++i) {
        cout << "Digite o " << i+1 << " número inteiro: ";
        cin >> vetor[i]; 
    }
    
    return vetor;
}

int main() {
    int tamanho;
    cout << "Digite o tamanho do vetor: ";
    cin >> tamanho;

    int* vetor = preencherVetor(tamanho); 
    
    cout << "Vetor preenchido:";
    for (int i = 0; i < tamanho; ++i) {
        cout << " " << vetor[i]; 
    }

    delete[] vetor; 
    
    return 0;
}
