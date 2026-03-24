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
    SensorNivel(string t) : tag(t), minimo(0.0), maximo(100.0), valorAtual(50.0) {}

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
    Bomba(string t) : tag(t), velocidade(0.0) {}

    Bomba(string t, double vel) : tag(t), velocidade(vel) {}

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
    ControladorTanque(string t) : tag(t), setpoint(50.0), kp(1.0) {}

    ControladorTanque(string t, double sp, double k) : tag(t), setpoint(sp), kp(k) {}

    void exibirResumo() const {
        cout << "[ControladorTanque] " << tag
             << " | SP=" << setpoint
             << " | Kp=" << kp << "\n";
    }
};

int main() {
    // Sensores de Nível
    SensorNivel sn1("LT-401");
    SensorNivel sn2("LT-402", 0.0, 5000.0, 2780.0);

    // Bombas
    Bomba b1("P-101");
    Bomba b2("P-102", 75.5);

    // Controladores de Tanque
    ControladorTanque ct1("CT-201");
    ControladorTanque ct2("CT-202", 3000.0, 2.5);

    // Exibir resumo de todos os objetos
    sn1.exibirResumo();
    sn2.exibirResumo();
    b1.exibirResumo();
    b2.exibirResumo();
    ct1.exibirResumo();
    ct2.exibirResumo();

    return 0;
}