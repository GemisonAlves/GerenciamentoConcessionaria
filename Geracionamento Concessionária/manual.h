#ifndef MANUAL_H
#define MANUAL_H

#include <QObject>


class Manual
{
private:
    QString carro;
    double ano;
    QString cor;
    QString caracterista;
    QString chassi;
    double valorinicial;
    double valorfinal;
    QString carrostatus;
    double lucro;
    QString status;
    double lucronovo;


public:
    Manual();

    QString getCARRO() const;
    void setCARRO(const QString &value);

    double getANODEFABRICACAO() const;
    void setANODEFABRICACAO(double value);

    QString getCOR() const;
    void setCOR(const QString &value);

    QString getCARACTERISTICA() const;
    void setCARACTERISTICA(const QString &value);

    QString getCHASSI() const;
    void setCHASSI(const QString &value);

    double getVALORINICIAL() const;
    void setVALORINICIAL(double value);

    double getVALORFINAL() const;
    void setVALORFINAL(double value);

    QString getCARROSTATUS() const;
    void setCARROSTATUS(const QString &value);

    QString getStatus();
    void setStatus(const QString &value);

    double getLucro();
    void setLucro(double value);

    double getLucronovo();
    void setLucronovo(double value);

};

#endif // MANUAL_H

