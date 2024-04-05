#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAX_VEICULOS = 100;

class Veiculo {
private:
    double peso;
    int ano;
    string cor;
    string marca;

public:
    Veiculo() : peso(0), ano(0), cor(""), marca("") {}

    Veiculo(double peso, int ano, string cor, string marca) : peso(peso), ano(ano), cor(cor), marca(marca) {}

    double getPeso() const {
        return peso;
    }

    int getAno() const {
        return ano;
    }

    string getCor() const {
        return cor;
    }

    string getMarca() const {
        return marca;
    }
};

class Concessionaria {
private:
    Veiculo veiculos[MAX_VEICULOS]; 
    int numVeiculos;

public:
    Concessionaria() : numVeiculos(0) {
        for (int i = 0; i < MAX_VEICULOS; ++i) {
            veiculos[i] = Veiculo();
        }
    }
    
    void adicionarVeiculo(const Veiculo& veiculo) {
        if (numVeiculos < MAX_VEICULOS) {
            veiculos[numVeiculos] = veiculo;
            numVeiculos++;
        } else {
            cout << "Limite máximo de veículos atingido!" << endl;
        }
    }

    void imprimirVeiculos() const {
        for (int i = 0; i < numVeiculos; ++i) {
            cout << "Marca: " << veiculos[i].getMarca() << ", Ano: " << veiculos[i].getAno() << ", Cor: " << veiculos[i].getCor() << ", Peso: " << veiculos[i].getPeso() << endl;
        }
    }

    void imprimirVeiculosTxt(const string& nomeArquivo) const {
        ofstream arquivo(nomeArquivo, std::ios::trunc);
        if (arquivo.is_open()) {
            for (int i = 0; i < numVeiculos; ++i) {
                arquivo << "Marca: " << veiculos[i].getMarca() << ", Ano: " << veiculos[i].getAno() << ", Cor: " << veiculos[i].getCor() << ", Peso: " << veiculos[i].getPeso() << endl;
            }
            arquivo.close();
            cout << "Veículos cadastrados foram impressos em " << nomeArquivo << endl;
        } else {
            cout << "Erro ao abrir o arquivo." << endl;
        }
    }
};

int main() {
    Concessionaria concessionaria;

    concessionaria.adicionarVeiculo(Veiculo(1500, 2023, "Preto", "Ferrari"));
    concessionaria.adicionarVeiculo(Veiculo(1800, 2022, "Branco", "Audi"));
    concessionaria.adicionarVeiculo(Veiculo(1700, 2024, "Prata", "Mercedes"));

    concessionaria.imprimirVeiculos();

    concessionaria.imprimirVeiculosTxt("veiculos_cadastrados.txt");

    return 0;
}
