#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Veiculo {
public:
    Veiculo() : peso(0), ano(0), cor(""), marca("") {}

    void setPeso(float peso) { this->peso = peso; }
    void setAno(int ano) { this->ano = ano; }
    void setCor(const string& cor) { this->cor = cor; }
    void setMarca(const string& marca) { this->marca = marca; }

    float getPeso() const { return peso; }
    int getAno() const { return ano; }
    string getCor() const { return cor; }
    string getMarca() const { return marca; }

private:
    float peso; 
    int ano;  
    string cor; 
    string marca; 
};

class Concessionaria {
public:
    Concessionaria() : numVeiculos(0) {}

    void adicionarVeiculo(const Veiculo& veiculo) {
        if (numVeiculos < MAX_VEICULOS) {
            veiculos[numVeiculos++] = veiculo;
        } else {
            cout << "Não é possível adicionar mais veículos. Limite atingido." << endl;
        }
    }

    void imprimirVeiculos() const {
        cout << "Veículos cadastrados na concessionária:" << endl;
        for (int i = 0; i < numVeiculos; ++i) {
            cout << "Marca: " << veiculos[i].getMarca() << ", Ano: " << veiculos[i].getAno() << ", Cor: " << veiculos[i].getCor() << ", Peso: " << veiculos[i].getPeso() << " kg" << endl;
        }
    }

    void imprimirVeiculosEmArquivo(const string& nomeArquivo) const {
        ofstream arquivo(nomeArquivo);
        if (arquivo.is_open()) {
            arquivo << "Veículos cadastrados na concessionária:" << endl;
            for (int i = 0; i < numVeiculos; ++i) {
                arquivo << "Marca: " << veiculos[i].getMarca() << ", Ano: " << veiculos[i].getAno() << ", Cor: " << veiculos[i].getCor() << ", Peso: " << veiculos[i].getPeso() << " kg" << endl;
            }
            arquivo.close();
            cout << "Veículos cadastrados foram salvos no arquivo " << nomeArquivo << endl;
        } else {
            cout << "Não foi possível abrir o arquivo para escrita." << endl;
        }
    }

private:
    static const int MAX_VEICULOS = 100; 
    Veiculo veiculos[MAX_VEICULOS]; 
    int numVeiculos;
};

int main() {
    Concessionaria concessionaria;

    Veiculo carro1, carro2;
    carro1.setMarca("Ferrari");
    carro1.setAno(2024);
    carro1.setCor("Vermelha");
    carro1.setPeso(1500);
    carro2.setMarca("Camaro");
    carro2.setAno(2018);
    carro2.setCor("Amarelo");
    carro2.setPeso(1400);

    concessionaria.adicionarVeiculo(carro1);
    concessionaria.adicionarVeiculo(carro2);

    concessionaria.imprimirVeiculos();

    concessionaria.imprimirVeiculosEmArquivo("veiculos.txt");

    return 0;
}
