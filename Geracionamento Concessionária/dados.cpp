#include "dados.h"


Dados::Dados()
{

}

double Dados::getValorini()
{
    int valorinicial = 0;
    for(Manual a : dados){
        valorinicial+=a.getVALORINICIAL();
    }
    return valorinicial;
}

double Dados::getLucroprevisto()
{

    int valorinicial = 0;
    for(Manual a : dados){
        valorinicial+=a.getVALORINICIAL();

    }
    int valorfinal = 0;
    for(Manual a : dados){
        valorfinal+=a.getVALORFINAL();
    }
    return valorfinal-valorinicial;
}

double Dados::getLucroreal()
{
    int valorinicial = 0;
    for(Manual a : dados){
        if(a.getCARROSTATUS()== "Vendido")
        valorinicial+=a.getVALORINICIAL();

    }
    int valorfinal = 0;
    for(int i=0; i<dados.size(); i++){
        if(dados[i].getCARROSTATUS() == "Vendido")
           valorfinal+=dados[i].getVALORFINAL();
    }
        if (valorfinal==0)
            return 0;
        for(int i=0; i<dados.size(); i++){
            qDebug() << dados[i].getCARRO() << " " << dados[i].getCARROSTATUS() <<endl;
    }
    return (valorfinal-valorinicial);
}

void Dados::inserirCarro(Manual a)
{
    dados.push_back(a);
}


Manual Dados::operator[](int i)
{
    return dados[i];
}

void Dados::OrdenarPorCarro()
{
    std::sort(dados.begin(),dados.end(),compararPorCarro);
}

int Dados::size()
{
    return dados.size();
}


bool compararPorCarro(Manual a, Manual b)
{
    return a.getCARRO()<b.getCARRO();
}

void Dados::OrdenarPorLucro()
{
    std::sort(dados.begin(),dados.end(),compararPorLucro);
}


bool compararPorLucro(Manual a, Manual b)
{
    return a.getLucro()>b.getLucro();
}

void Dados::OrdenarPorStatus()
{
    std::sort(dados.begin(),dados.end(),compararPorStatus);
}

bool compararPorStatus(Manual a, Manual b)
{
    return a.getCARROSTATUS()<b.getCARROSTATUS();
}

bool Dados::salvarDados(QString arquivo)
{
    QFile file(arquivo);
    QString linha;
    if(!file.open(QIODevice::WriteOnly))
        return false;

    for(Manual a : dados){
        linha = a.getCARRO() + ',' + QString::number(a.getANODEFABRICACAO()) + ',' + a.getCOR() + ',' + a.getCARACTERISTICA() + ',' + (a.getCHASSI()) + ',' + QString::number(a.getVALORINICIAL()) + ',' + QString::number(a.getVALORFINAL()) + ',' + QString::number(a.getLucro()) + ',' + a.getStatus() + ',' + a.getCARROSTATUS() + ',' + QString::number(a.getLucronovo()) +'\n';
        file.write(linha.toLocal8Bit());
    }
    return true;

}

bool Dados::carregarDados(QString arquivo)
{
    QFile file(arquivo);
    if(!file.open(QIODevice::ReadOnly))
        return false;

    QString linha;
    Manual a;
    while(!file.atEnd()){
        linha = file.readLine();
        QStringList dados = linha.split(",");
        a.setCARRO(dados[0]);
        a.setANODEFABRICACAO(dados[1].toDouble());
        a.setCOR(dados[2]);
        a.setCARACTERISTICA(dados[3]);
        a.setCHASSI(dados[4]);
        a.setVALORINICIAL(dados[5].toDouble());
        a.setVALORFINAL(dados[6].toDouble());
        a.setLucro(dados[7].toDouble());
        a.setStatus(dados[8]);
        a.setCARROSTATUS(dados[9]);
        inserirCarro(a);
    }
    return true;
}

void Dados::editarNomeCarro(int i, QString carro)
{
    dados[i].setCARRO(carro);
}

void Dados::editarAnoCarro(int i, double ano)
{
    dados[i].setANODEFABRICACAO(ano);
}

void Dados::editarCorCarro(int i, QString cor)
{
    dados[i].setCOR(cor);
}

void Dados::editarCaracteristicaCarro(int i, QString caracteristica)
{
    dados[i].setCARACTERISTICA(caracteristica);
}

void Dados::editarChassiCarro(int i, QString chassi)
{
    dados[i].setCHASSI(chassi);
}

void Dados::editarValorinicialCarro(int i, double valorinicial)
{
    dados[i].setVALORINICIAL(valorinicial);
}

void Dados::editarValorfinalCarro(int i, double valorfinal)
{
    dados[i].setVALORFINAL(valorfinal);
}

void Dados::editarLucroCarro(int i, double lucro)
{
    dados[i].setLucro(lucro);
}

void Dados::editarSituacaoCarro(int i, QString situacao)
{
    dados[i].setStatus(situacao);
}

void Dados::editarStatusCarro(int i, QString status)
{
    dados[i].setCARROSTATUS(status);
}

void Dados::limpar()
{
    dados.clear();
}


