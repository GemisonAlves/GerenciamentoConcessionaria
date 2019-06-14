
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "manual.h"
#include <QVector>
#include <QDebug>
#include <QFileDialog>
#include "dados.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    Manual manual;
    Dados dados;

    void Estatisticas();
    void inserirCarroNaTabela(Manual a, int linha);
    void atualizarcolunas();

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnsair_clicked();

    void on_btnrns_clicked();

   void on_btninserir_clicked();

    void on_OrdNome_clicked();

    void on_OrdLucro_clicked();

    void on_ordVenda_clicked();

    void salvar();

    void carregar();

    void on_tabelaDados_cellDoubleClicked(int row, int column);

    void on_btnlimpar_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H


