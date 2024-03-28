#include <iostream>
#include <string>

using namespace std;

class Dono {
public:
    Dono(const string& nome, const string& telefone) : nome(nome), telefone(telefone) {}

    string getNome() const { return nome; }
    string getTelefone() const { return telefone; }

private:
    string nome;
    string telefone;
};

class Carro {
public:
    Carro(const string& marca, const string& placa, const string& cor, const Dono& dono) : marca(marca), placa(placa), cor(cor), dono(dono) {}

    string getMarca() const { return marca; }
    string getPlaca() const { return placa; }
    string getCor() const { return cor; }
    Dono getDono() const { return dono; }

private:
    string marca;
    string placa;
    string cor;
    Dono dono;
};

class Estacionamento {
public:
    Estacionamento() : numCarros(0) {
        for (int i = 0; i < MAX_CARROS; ++i) {
            carros[i] = nullptr;
        }
    }

    ~Estacionamento() {
        for (int i = 0; i < numCarros; ++i) {
            delete carros[i];
        }
    }

    void cadastrarCarro(const Carro& carro) {
        if (numCarros < MAX_CARROS) {
            carros[numCarros++] = new Carro(carro);
        } else {
            cout << "Limite de carros cadastrados atingido." << endl;
        }
    }

    void imprimirCarrosCadastrados() const {
        cout << "Carros cadastrados no estacionamento:" << endl;
        for (int i = 0; i < numCarros; ++i) {
            cout << "Marca: " << carros[i]->getMarca() << ", Placa: " << carros[i]->getPlaca() << ", Cor: " << carros[i]->getCor() << endl;
            cout << "Proprietário: " << carros[i]->getDono().getNome() << ", Telefone: " << carros[i]->getDono().getTelefone() << endl;
            cout << endl;
        }
    }

private:
    static const int MAX_CARROS = 100; 
    Carro* carros[MAX_CARROS]; 
    int numCarros; 
};

int main() {

    Dono dono1("Pedro", "123456789");
    Dono dono2("João", "987654321");

    Carro carro1("Ferrari", "ABC1234", "Vermelho", dono1);
    Carro carro2("Camaro", "XYZ5678", "Prata", dono2);

    Estacionamento estacionamento;
    estacionamento.cadastrarCarro(carro1);
    estacionamento.cadastrarCarro(carro2);

    estacionamento.imprimirCarrosCadastrados();

    return 0;
}
