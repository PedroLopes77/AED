#include <iostream>
#include <algorithm>

using namespace std;

struct pessoa {
    int Matricula;
    string Nome;
    float Nota;
};

void merge(pessoa arr[], int l, int m, int r, int field) {
    int n1 = m - l + 1;
    int n2 = r - m;

    pessoa L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (field == 1 ? L[i].Matricula <= R[j].Matricula : field == 2 ? L[i].Nota <= R[j].Nota : L[i].Nome <= R[j].Nome) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(pessoa arr[], int l, int r, int field) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m, field);
        mergeSort(arr, m + 1, r, field);
        merge(arr, l, m, r, field);
    }
}

void printArray(pessoa arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Matricula: " << arr[i].Matricula << ", Nome: " << arr[i].Nome << ", Nota: " << arr[i].Nota << endl;
    }
}

int main() {
    int N;
    cout << "Digite o tamanho do array: ";
    cin >> N;

    pessoa arr[N];

    for (int i = 0; i < N; i++) {
        cout << "Digite a matricula da pessoa " << i + 1 << ": ";
        cin >> arr[i].Matricula;
        cout << "Digite o nome da pessoa " << i + 1 << ": ";
        cin >> arr[i].Nome;
        cout << "Digite a nota da pessoa " << i + 1 << ": ";
        cin >> arr[i].Nota;
    }

    int field;
    cout << "Escolha o campo para ordenacao (1 - Matricula, 2 - Nota, 3 - Nome): ";
    cin >> field;

    mergeSort(arr, 0, N - 1, field);

    cout << "\nArray ordenado:" << endl;
    printArray(arr, N);

    return 0;
}
