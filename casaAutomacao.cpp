#include <iostream>
#include <string>

using namespace std;

class SensorNivel {
private:
    string tag;
    double minimo;
    double maximo;
    double valorAtual;

public:
    // Construtor mínimo
    SensorNivel(string t)
        : tag(t), minimo(0.0), maximo(100.0), valorAtual(0.0) {}

    // Construtor completo
    SensorNivel(string t, double min, double max, double valor)
        : tag(t), minimo(min), maximo(max), valorAtual(valor) {}

    void exibirResumo() const {
        cout << "[SensorNivel] " << tag
             << " | faixa: " << minimo << " a " << maximo
             << " | valor atual: " << valorAtual << "\n";
    }
};

class Bomba {
private:
    string tag;
    double velocidade;

public:
    // Construtor mínimo
    Bomba(string t)
        : tag(t), velocidade(0.0) {}

    // Construtor completo
    Bomba(string t, double vel)
        : tag(t), velocidade(vel) {}

    void exibirResumo() const {
        cout << "[Bomba] " << tag
             << " | velocidade: " << velocidade << "%\n";
    }
};

class ControladorTanque {
private:
    string tag;
    double setpoint;
    double kp;

public:
    // Construtor mínimo
    ControladorTanque(string t)
        : tag(t), setpoint(50.0), kp(1.0) {}

    // Construtor completo
    ControladorTanque(string t, double sp, double ganho)
        : tag(t), setpoint(sp), kp(ganho) {}

    void exibirResumo() const {
        cout << "[ControladorTanque] " << tag
             << " | SP=" << setpoint
             << " | Kp=" << kp << "\n";
    }
};

int main() {
    // SensorNivel
    SensorNivel sn1("LT-401"); // mínimo
    SensorNivel sn2("LT-402", 0.0, 5000.0, 2780.0); // completo

    // Bomba
    Bomba b1("P-101"); // mínimo
    Bomba b2("P-102", 75.0); // completo

    // Controlador
    ControladorTanque c1("LIC-01"); // mínimo
    ControladorTanque c2("LIC-02", 3000.0, 2.5); // completo

    // Exibindo tudo
    sn1.exibirResumo();
    sn2.exibirResumo();

    b1.exibirResumo();
    b2.exibirResumo();

    c1.exibirResumo();
    c2.exibirResumo();

    return 0;
}