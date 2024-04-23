#include <iostream>

using namespace std;

void swap(char &a, char &b) {
    char temp = a;
    a = b;
    b = temp;
}

int partition(char arr[], int low, int high) {
    char pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] >= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(char arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    const int maxSize = 100;
    char input[maxSize];

    cout << "Digite uma string: ";
    cin.getline(input, maxSize);

    int n = 0;
    while (input[n] != '\0') {
        n++;
    }

    quickSort(input, 0, n - 1);

    cout << "String ordenada em ordem decrescente: " << input << endl;

    return 0;
}
