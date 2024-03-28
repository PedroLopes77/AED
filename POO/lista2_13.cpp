#include <iostream>
#include <cmath>

using namespace std;

class CalculadoraMatematica {
    public:

    static double calcularDiametroCircunferencia(double raio) {
        return 2 * raio;
    }
    
    static double calcularAreaCircunferencia(double raio) {
        return M_PI * pow(raio, 2);
    }

    static double calcularAreaLateralCubo(double lado) {
        return 4 * pow(lado, 2);
    }

    static double calcularAreaTotalCubo(double lado) {
        return 6 * pow(lado, 2);
    }

    static double calcularVolumeCubo(double lado) {
        return pow(lado, 3);
    }
};

int main() {
    double raioCirculo = 5.0;
    double ladoCubo = 3.0;

    cout << "Diâmetro da circunferencia com raio " << raioCirculo << ": " << CalculadoraMatematica::calcularDiametroCircunferencia(raioCirculo) << endl;
    cout << "Área da circunferência com raio " << raioCirculo << ": " << CalculadoraMatematica::calcularAreaCircunferencia(raioCirculo) << endl;
    cout << "Área lateral do cubo com lado " << ladoCubo << ": " << CalculadoraMatematica::calcularAreaLateralCubo(ladoCubo) << endl;
    cout << "Área total do cubo com lado " << ladoCubo << ": " << CalculadoraMatematica::calcularAreaTotalCubo(ladoCubo) << endl;
    cout << "Volume do cubo com lado " << ladoCubo << ": " << CalculadoraMatematica::calcularVolumeCubo(ladoCubo) << endl;

    return 0;
}
