#include <iostream>
#include <string>

using namespace std;

class AtivoCampo {
private:
    string tag;      
    int bloqueado;   // 0 = liberado, 1 = bloqueado

protected:
    string area;     

    void redefinirArea(string novaArea) {
        area = novaArea;
    }

public:
    AtivoCampo(string novaTag, string novaArea)
        : tag(novaTag), bloqueado(0), area(novaArea) {}

    string getTag() const {
        return tag;
    }

    int estaBloqueado() const {
        return bloqueado;
    }

    void bloquear() {
        bloqueado = 1;
    }

    void liberar() {
        bloqueado = 0;
    }
};

class SensorNivel : public AtivoCampo {
private:
    double nivelAtual;
    double limiteAlto;

public:
    SensorNivel(string tag, string area, double limite)
        : AtivoCampo(tag, area), nivelAtual(0), limiteAlto(limite) {}

    void atualizarNivel(double novoNivel) {
        if (estaBloqueado() == 1) return;
        if (novoNivel < 0) return;

        nivelAtual = novoNivel;
    }

    void exibirResumo() {
        cout << "SensorNivel\n";
        cout << "Tag: " << getTag() << endl;
        cout << "Area: " << area << endl;
        cout << "Nivel: " << nivelAtual << endl;
        cout << "Limite Alto: " << limiteAlto << endl;
        cout << "----------------------\n";
    }

    friend void inspecaoTecnica(const SensorNivel& s);
};

void inspecaoTecnica(const SensorNivel& s) {
    cout << "----- INSPECAO TECNICA -----\n";
    cout << "Nivel atual: " << s.nivelAtual << endl;
    cout << "Limite alto: " << s.limiteAlto << endl;
    cout << "----------------------\n";
}

class BombaDosadora : public AtivoCampo {
private:
    double vazaoPercentual;

public:
    BombaDosadora(string tag, string area)
        : AtivoCampo(tag, area), vazaoPercentual(0) {}

    void ajustarVazao(double v) {
        if (estaBloqueado() == 1) return;
        if (v < 0 || v > 100) return;

        vazaoPercentual = v;
    }

    void moverParaArea(string novaArea) {
        redefinirArea(novaArea);
    }

    void exibirResumo() {
        cout << "BombaDosadora\n";
        cout << "Tag: " << getTag() << endl;
        cout << "Area: " << area << endl;
        cout << "Vazao (%): " << vazaoPercentual << endl;
        cout << "----------------------\n";
    }
};

int main() {
    SensorNivel sensor("SN-01", "Tanque A", 80);
    BombaDosadora bomba("BD-01", "Area 1");

    sensor.atualizarNivel(50);
    bomba.ajustarVazao(75);

    sensor.bloquear();
    sensor.atualizarNivel(90); // não altera

    bomba.moverParaArea("Area 2");

    sensor.exibirResumo();
    bomba.exibirResumo();

    inspecaoTecnica(sensor);

    return 0;
}