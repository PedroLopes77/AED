#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void bubbleSort(float arr[], int size) {
    for (int i = 0; i < size - 1; ++i) 
    {
        for (int j = 0; j < size - i - 1; ++j) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                float temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    srand(time(NULL)); 

    const int numAlunos = 100;
    float alturas[numAlunos];

    for (int i = 0; i < numAlunos; ++i) 
    {
        alturas[i] = 1 + rand() % 201 / 100.0;
    }

    cout << "Alturas coletadas:" << endl;
    for (int i = 0; i < numAlunos; ++i) 
    {
        cout << alturas[i] << " ";
    }
    cout << endl;

    bubbleSort(alturas, numAlunos);

    cout << "\nAlturas ordenadas em ordem crescente:" << endl;
    for (int i = 0; i < numAlunos; ++i) 
    {
        cout << alturas[i] << " ";
    }
    cout << endl;

    return 0;
}
