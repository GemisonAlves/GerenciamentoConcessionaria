#include "manual.h"

Manual::Manual()
{

}
QString Manual::getCARRO() const
{
    return carro;
}
void Manual::setCARRO(const QString &value)
{
    carro = value;
}
double Manual::getANODEFABRICACAO() const
{
    return ano;
}

void Manual::setANODEFABRICACAO(double value)
{
    ano = value;
}

QString Manual::getCOR() const
{
    return cor;
}
void Manual::setCOR(const QString &value)
{
    cor = value;
}

QString Manual::getCARACTERISTICA() const
{
    return caracterista;
}
void Manual::setCARACTERISTICA(const QString &value)
{
    caracterista = value;
}

QString Manual::getCHASSI() const
{
    return chassi;
}

void Manual::setCHASSI(const QString &value)
{
    chassi = value;
}

double Manual::getVALORINICIAL() const
{
    return valorinicial;
}

void Manual::setVALORINICIAL(double value)
{
    valorinicial = value;
}

double Manual::getVALORFINAL() const
{
    return valorfinal;
}

void Manual::setVALORFINAL(double value)
{
    valorfinal = value;
}

QString Manual::getCARROSTATUS() const
{
    return carrostatus;
}
void Manual::setCARROSTATUS(const QString &value)
{
    carrostatus = value;
}

QString Manual::getStatus()
{
  return valorfinal >= (valorinicial + 5000) ? "Aprovado" : "Reprovado";
}
void Manual::setStatus(const QString &value)
{
    status = value;
}

double Manual::getLucro()
{
    return valorfinal - valorinicial;
}
void Manual::setLucro(double value)
{
    lucro = value;
}

double Manual::getLucronovo()
{
    return lucronovo;
}
void Manual::setLucronovo(double value)
{
    lucronovo = value;
}
