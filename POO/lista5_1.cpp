#include <iostream>
#include <string>

using namespace std;

void insertionSort(string arr[], int n) {
    for (int i = 1; i < n; i++) {
        string key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int n;
    cout << "Digite a quantidade de nomes: ";
    cin >> n;
    
    string nomes[n];
    for (int i = 0; i < n; i++) {
        cout << "Digite o nome: ";
        cin >> nomes[i];
    }

    insertionSort(nomes, n);

    cout << "\nNomes ordenados:\n";
    for (int i = 0; i < n; i++) {
        cout << nomes[i] << endl;
    }

    return 0;
}
