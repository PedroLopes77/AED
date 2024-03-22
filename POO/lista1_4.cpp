#include <iostream>
#include <string>

using namespace std;

class Carro {
public:
    Carro(string marca, string placa, string cor) : marca(marca), placa(placa), cor(cor) {}
    string getMarca() 
    { 
        return marca;
    }
    string getPlaca() 
    { 
        return placa;
    }
    string getCor() 
    { 
        return cor;
    }

private:
    string marca;
    string placa;
    string cor;
};

class Dono {
public:
    Dono(string nome, string telefone) : nome(nome), telefone(telefone) {}
    string getNome() 
    { 
        return nome;
    }
    string getTelefone() 
    { 
        return telefone;
    }

private:
    string nome;
    string telefone;
};

int main() {
    const int numCarros = 2;
    Carro carros[numCarros] = 
    {
        Carro("Ford\n", "JKI8736\n", "Vermelho\n"),
        Carro("Nissan\n", "JGD5713\n", "Azul\n")
    };

    const int numDonos = 2;
    Dono donos[numDonos] = 
    {
        Dono("Pedro\n", "98122333\n"),
        Dono("Lucas\n", "99128381\n")
    };

    cout << "Carros cadastrados:\n";
    for (int i = 0; i < numCarros; ++i) 
    {
        cout << "Marca: " << carros[i].getMarca();
        cout << "Placa: " << carros[i].getPlaca();
        cout << "Cor: " << carros[i].getCor();
        cout << "Proprietário: " << donos[i].getNome();
        cout << "Telefone: " << donos[i].getTelefone();
    }

    return 0;
}

