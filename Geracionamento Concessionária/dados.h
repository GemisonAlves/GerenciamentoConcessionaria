#ifndef DADOS_H
#define DADOS_H

#include <QObject>
#include <QVector>
#include <algorithm>
#include <QFile>
#include "manual.h"
#include <QDebug>

class Dados
{

private:
    QVector<Manual>dados;

public:
    Dados();
    Manual operator[](int i);
    double getValorini();
    double getLucroreal();
    double getLucroprevisto();
    void inserirCarro(Manual a);
    int size();
    void OrdenarPorStatus();
    void OrdenarPorCarro();
    void OrdenarPorLucro();
    bool salvarDados(QString arquivo);
    bool carregarDados(QString arquivo);
    void editarNomeCarro(int i, QString carro);
    void editarAnoCarro(int i, double ano);
    void editarCorCarro(int i, QString cor);
    void editarCaracteristicaCarro(int i, QString caracteristica);
    void editarChassiCarro(int i, QString chassi);
    void editarValorinicialCarro(int i, double valorinicial);
    void editarValorfinalCarro(int i, double valorfinal);
    void editarLucroCarro(int i, double lucro);
    void editarSituacaoCarro(int i, QString situacao);
    void editarStatusCarro(int i, QString status);
    void limpar();

};
bool compararPorCarro(Manual a, Manual b);
bool compararPorLucro(Manual a, Manual b);
bool compararPorStatus(Manual a, Manual b);

#endif // DADOS_H
