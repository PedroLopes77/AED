#include <iostream>

using namespace std;

int pesqseq(int val, int vetor[], int tamanho) {
    int comp = 0;
    for (int i = 0; i < tamanho; ++i) 
    {
        comp++;
        if (vetor[i] == val) return comp;
    }
    return comp;
}

int pesqbin(int val, int vetor[], int tamanho) {
    int comp = 0;
    int inicio = 0, fim = tamanho - 1;
    while (inicio <= fim) 
    {
        int meio = inicio + (fim - inicio) / 2;
        comp++;
        if (vetor[meio] == val)
        {
            return comp;
        }
        else if (vetor[meio] < val) inicio = meio + 1;
        else 
        {
            fim = meio - 1;
        }
    }
    return comp;
}

int pesqsent(int val, int vetor[], int tamanho) {
    int comp = 0;
    int ultimo = vetor[tamanho - 1];
    vetor[tamanho - 1] = val;
    int i = 0;
    while (vetor[i] != val) 
    {
        comp++;
        i++;
    }
    vetor[tamanho - 1] = ultimo;
    if (i < tamanho - 1 || val == ultimo) 
    {
        return comp;
    }
    return comp;
}

int main() {
    int vetor[] = {1, 3, 5, 7, 9, 11, 13};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    int valorProcurado = 7;

    int comp_seq = pesqseq(valorProcurado, vetor, tamanho);
    int comp_bin = pesqbin(valorProcurado, vetor, tamanho);
    int comp_sent = pesqsent(valorProcurado, vetor, tamanho);

    cout << "Comparacoes na pesquisa sequencial: " << comp_seq << endl;
    cout << "Comparacoes na pesquisa binaria: " << comp_bin << endl;
    cout << "Comparacoes na pesquisa com sentinela: " << comp_sent << endl;

    if (comp_seq < comp_bin && comp_seq < comp_sent)
    { 
        cout << "A pesquisa sequencial fez menos comparacoes." << endl;
    }
    else if (comp_bin < comp_seq && comp_bin < comp_sent)
    {
        cout << "A pesquisa binaria fez menos comparacoes." << endl;
    }
    else 
    
    cout << "A pesquisa com sentinela fez menos comparacoes." << endl;

    if (comp_seq > comp_bin && comp_seq > comp_sent)
    { 
        cout << "A pesquisa sequencial fez mais comparacoes." << endl;
    }
    else if (comp_bin > comp_seq && comp_bin > comp_sent)
    {
        cout << "A pesquisa binaria fez mais comparacoes." << endl;
    }
    else cout << "A pesquisa com sentinela fez mais comparacoes." << endl;

    return 0;
}
