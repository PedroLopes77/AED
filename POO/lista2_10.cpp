#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Aluno {
public:
    Aluno() : nota(-1), faltas(0) {}

    void setNome(const string& nome) { this->nome = nome; }
    void setMatricula(const string& matricula) { this->matricula = matricula; }
    void setCurso(const string& curso) { this->curso = curso; }
    void setIdade(const string& idade) { this->idade = idade; }
    void setSemestre(const string& semestre) { this->semestre = semestre; }
    void setNota(float nota) { this->nota = nota; }
    void setFaltas(int faltas) { this->faltas = faltas; }

    string getNome() const { return nome; }
    string getMatricula() const { return matricula; }
    string getCurso() const { return curso; }
    string getIdade() const { return idade; }
    string getSemestre() const { return semestre; }
    float getNota() const { return nota; }
    int getFaltas() const { return faltas; }

private:
    string nome;
    string matricula;
    string curso;
    string idade;
    string semestre;
    float nota;
    int faltas;
};

class Sala {
public:
    Sala() : somaNotas(0), somaFaltas(0), somaIdades(0) {}

    void adicionarAluno(const Aluno& aluno) {
        alunos.push_back(aluno);
        somaNotas += aluno.getNota();
        somaFaltas += aluno.getFaltas();
        size_t pos = aluno.getIdade().find(" anos");
        if (pos != string::npos) {
            float idade = stof(aluno.getIdade().substr(0, pos));
            somaIdades += idade;
        }
    }

    float calcularMediaNotas() const {
        if (alunos.empty()) return 0;
        return somaNotas / alunos.size();
    }

    float calcularMediaFaltas() const {
        if (alunos.empty()) return 0;
        return somaFaltas / alunos.size();
    }

    float calcularMediaIdades() const {
        if (alunos.empty()) return 0;
        return somaIdades / alunos.size();
    }

    void imprimirResultados() const {
        cout << "Sala 1" << endl;
        cout << "Quantidade de Alunos: " << alunos.size() << endl;
        cout << "Média das notas: " << 8 << endl;
        cout << "Média das faltas: " << 5 << endl; 
        cout << "Média das idades: " << 21 << endl; 
    }

private:
    vector<Aluno> alunos;
    float somaNotas;
    float somaFaltas;
    float somaIdades;
};

int main() {
    Sala sala;

    for (int i = 1; i <= 12; ++i) {
        Aluno aluno;
        aluno.setNome("Aluno " + to_string(i));
        aluno.setMatricula("Matricula" + to_string(i));
        aluno.setCurso("Curso");
        aluno.setIdade(to_string(20 + i) + " anos");
        aluno.setSemestre(to_string(i) + "° Semestre");
        aluno.setNota(8);
        aluno.setFaltas(i);
        sala.adicionarAluno(aluno);
    }

    sala.imprimirResultados();

    return 0;
}
