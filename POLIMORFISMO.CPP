#include <iostream>
#include <string>
#include <vector>

using namespace std;

class AtuadorLinha {
private:
    string tag;
    string area;

protected:
    double limitarPercentual(double percentual) const {
        if (percentual < 0.0) return 0.0;
        if (percentual > 100.0) return 100.0;
        return percentual;
    }

public:
    AtuadorLinha(string novaTag, string novaArea)
        : tag(novaTag), area(novaArea) {}

    virtual ~AtuadorLinha() = default;

    string getTag() const { return tag; }
    string getArea() const { return area; }

    // virtual: permite polimorfismo (cada classe filha implementa do seu jeito)
    virtual void aplicarReferenciaPercentual(double percentual) = 0;
    virtual void exibirResumo() const = 0;
};

class MotorEsteira : public AtuadorLinha {
private:
    double frequenciaHz;

public:
    // Construtor usando a base
    MotorEsteira(string tag, string area)
        : AtuadorLinha(tag, area), frequenciaHz(0.0) {}

    // 0–100% → 0–60 Hz
    void aplicarReferenciaPercentual(double percentual) override {
        percentual = limitarPercentual(percentual);
        frequenciaHz = (percentual / 100.0) * 60.0;
    }

    void exibirResumo() const override {
        cout << "Motor Esteira\n";
        cout << "Tag: " << getTag() << "\n";
        cout << "Area: " << getArea() << "\n";
        cout << "Frequencia: " << frequenciaHz << " Hz\n\n";
    }
};

class ValvulaDosagem : public AtuadorLinha {
private:
    double aberturaPercentual;

public:
    // Construtor usando a base
    ValvulaDosagem(string tag, string area)
        : AtuadorLinha(tag, area), aberturaPercentual(0.0) {}

    // Apenas limita entre 0 e 100%
    void aplicarReferenciaPercentual(double percentual) override {
        aberturaPercentual = limitarPercentual(percentual);
    }

    void exibirResumo() const override {
        cout << "Valvula Dosagem\n";
        cout << "Tag: " << getTag() << "\n";
        cout << "Area: " << getArea() << "\n";
        cout << "Abertura: " << aberturaPercentual << " %\n\n";
    }
};

int main() {
    // Criando objetos
    MotorEsteira motor("MTR-01", "Envase");
    ValvulaDosagem valvula("VAL-01", "Envase");

    // Vetor polimórfico
    vector<AtuadorLinha*> atuadores;
    atuadores.push_back(&motor);
    atuadores.push_back(&valvula);

    // Aplicando mesma referência
    double referencia = 75.0;

    for (auto atuador : atuadores) {
        atuador->aplicarReferenciaPercentual(referencia);
    }

    // Exibindo resumo
    for (auto atuador : atuadores) {
        atuador->exibirResumo();
    }

    return 0;
}