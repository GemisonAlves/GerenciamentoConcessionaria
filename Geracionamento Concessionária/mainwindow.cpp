#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QInputDialog>
#include <QLineEdit>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionSalvar,SIGNAL(triggered()),this,SLOT(salvar()));
    connect(ui->actionCarregar,SIGNAL(triggered()),this,SLOT(carregar()));
}

void MainWindow::Estatisticas()
{
    double valorinicial = dados.getValorini();
    double lucroprevisto = dados.getLucroprevisto();
    double lucroreal = dados.getLucroreal();

    ui->lucroreal->setText(QString::number(lucroreal));
    ui->lucroprevisto->setText(QString::number(lucroprevisto));
    ui->valorinicial->setText(QString::number(valorinicial));

}

void MainWindow::atualizarcolunas()
{
    ui->tabelaDados->clearContents();
    for(int i=0; i<dados.size();i++){
        inserirCarroNaTabela(dados[i],i);
    }

}

void MainWindow::inserirCarroNaTabela(Manual a, int linha)
{
    ui->tabelaDados->setItem(linha,0,new QTableWidgetItem(a.getCARRO()));
    ui->tabelaDados->setItem(linha,1,new QTableWidgetItem(QString::number(a.getANODEFABRICACAO())));
    ui->tabelaDados->setItem(linha,2,new QTableWidgetItem(a.getCOR()));
    ui->tabelaDados->setItem(linha,3,new QTableWidgetItem(a.getCARACTERISTICA()));
    ui->tabelaDados->setItem(linha,4,new QTableWidgetItem(a.getCHASSI()));
    ui->tabelaDados->setItem(linha,5,new QTableWidgetItem(QString::number(a.getVALORINICIAL())));
    ui->tabelaDados->setItem(linha,6,new QTableWidgetItem(QString::number(a.getVALORFINAL())));
    ui->tabelaDados->setItem(linha,7,new QTableWidgetItem(QString::number(a.getLucro())));
    ui->tabelaDados->setItem(linha,8,new QTableWidgetItem(a.getStatus()));
    ui->tabelaDados->setItem(linha,9,new QTableWidgetItem(a.getCARROSTATUS()));
}

void MainWindow::salvar()
{
    QString nomeArquivo = QFileDialog::getSaveFileName(this,
                                                       "Lista de carros",
                                                       "",
                                                       "CSV(*.csv)");
    dados.salvarDados(nomeArquivo);
}

void MainWindow::carregar()
{
    QString nomeArquivo = QFileDialog::getOpenFileName(this,
                                                       "Lista de carros",
                                                       "",
                                                       "CSV(*.csv)");

    dados.carregarDados(nomeArquivo);
    for(int i=0;i<dados.size();i++){
        ui->tabelaDados->insertRow(i);
        inserirCarroNaTabela(dados[i],i);
        Estatisticas();

    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnsair_clicked()
{
    this->close();
}

void MainWindow::on_btnrns_clicked()
{
    QMessageBox::information(this,"Recomendações","Preencher Todos Requisitos\nGerar Lucro Acima de 5000");
}

void MainWindow::on_btninserir_clicked()
{

    manual.setCARRO(ui->entradaCARRO->text());
    if(ui->entradaCARRO->text().size()<2){
        QMessageBox::information(this,"Alerta","Dados Carro Incorreto");
        return;
    }

    manual.setANODEFABRICACAO(ui->entradaano->text().toDouble());
    if(ui->entradaano->text().size()<=3){
        QMessageBox::information(this,"Alerta","Dados Fabricação Incorreto");
        return;
    }

    manual.setCOR(ui->entradacor->text());
    if(ui->entradacor->text().size()<4){
        QMessageBox::information(this,"Alerta","Dados Cor Incorreto");
        return;
    }

    manual.setCARACTERISTICA(ui->entradacaracteristica->text());
    if(ui->entradacaracteristica->text().size()<4){
        QMessageBox::information(this,"Alerta","Dados Característica Incorreto");
        return;
    }

    manual.setCHASSI(ui->entradachassi->text());
    if(ui->entradachassi->text().size()<5){
        QMessageBox::information(this,"Alerta","Dados Chassi Incorreto");
        return;
    }

    manual.setVALORINICIAL(ui->entradavalorinicial->text().toDouble());
    if(ui->entradavalorinicial->text().size()<3){
        QMessageBox::information(this,"Alerta","Dados ValorInicial Incorreto");
        return;
    }

    manual.setVALORFINAL(ui->entradavalorfinal->text().toDouble());
    if(ui->entradavalorfinal->text().size()<3){
        QMessageBox::information(this,"Alerta","Dados ValorFinal Incorreto");
        return;
    }
    manual.setCARROSTATUS(ui->entradastatus->currentText());

    int linha = ui->tabelaDados->rowCount();
    ui->tabelaDados->insertRow(linha);
    inserirCarroNaTabela(manual,linha);

    ui->entradaCARRO->clear();
    ui->entradaano->clear();
    ui->entradacor->clear();
    ui->entradachassi->clear();
    ui->entradavalorfinal->clear();
    ui->entradavalorinicial->clear();
    ui->entradacaracteristica->clear();

    dados.inserirCarro(manual);
    Estatisticas();

}

void MainWindow::on_OrdNome_clicked()
{
    dados.OrdenarPorCarro();
    atualizarcolunas();
}

void MainWindow::on_OrdLucro_clicked()
{
    dados.OrdenarPorLucro();
    atualizarcolunas();
}

void MainWindow::on_ordVenda_clicked()
{
    dados.OrdenarPorStatus();
    atualizarcolunas();
}


void MainWindow::on_tabelaDados_cellDoubleClicked(int row, int column)
{
    if (column==0){
        bool ok;
      QString carro = QInputDialog::getText(this, "Editar Carro", "Escreva o novo nome do Carro", QLineEdit::Normal,"", &ok);

      if(ok && !carro.isEmpty()){
                   dados.editarNomeCarro(row, carro);
                   inserirCarroNaTabela(dados[row], row);
    }
        }
    if(column==1){
        bool ok;
        QString ano = QInputDialog::getText(this, "Editar Ano", "Escreva o novo Ano do Carro", QLineEdit::Normal,"", &ok);

        if(ok && !ano.isEmpty()){
                     dados.editarAnoCarro(row, ano.toDouble());
                     inserirCarroNaTabela(dados[row], row);
    }
        }

    if(column==2){
        bool ok;
        QString cor = QInputDialog::getText(this, "Editar Cor", "Escreva a nova Cor do Carro", QLineEdit::Normal,"", &ok);

        if(ok && !cor.isEmpty()){
                     dados.editarCorCarro(row, cor);
                     inserirCarroNaTabela(dados[row], row);
    }
        }

    if(column==3){
        bool ok;
        QString caracteristica = QInputDialog::getText(this, "Editar Característica", "Escreva a nova Característica do Carro", QLineEdit::Normal,"", &ok);

        if(ok && !caracteristica.isEmpty()){
                     dados.editarCaracteristicaCarro(row, caracteristica);
                     inserirCarroNaTabela(dados[row], row);
    }
        }

    if(column==4){
        bool ok;
        QString chassi = QInputDialog::getText(this, "Editar Chassi", "Escreva o novo Chassi do Carro", QLineEdit::Normal,"", &ok);

        if(ok && !chassi.isEmpty()){
                     dados.editarChassiCarro(row, chassi);
                     inserirCarroNaTabela(dados[row], row);
    }
        }

    if(column==5){
        bool ok;
        QString valorinicial = QInputDialog::getText(this, "Editar Valor Inicial", "Escreva o novo Valor Inicial do Carro", QLineEdit::Normal,"", &ok);

        if(ok && !valorinicial.isEmpty()){
                     dados.editarValorinicialCarro(row, valorinicial.toDouble());
                     inserirCarroNaTabela(dados[row], row);

                     Estatisticas();
    }
        }

    if(column==6){
        bool ok;
        QString valorfinal = QInputDialog::getText(this, "Editar Valor Final", "Escreva o novo Valor Final do Carro", QLineEdit::Normal,"", &ok);

        if(ok && !valorfinal.isEmpty()){
                     dados.editarValorfinalCarro(row, valorfinal.toDouble());
                     inserirCarroNaTabela(dados[row], row);
                     Estatisticas();
    }
        }

    if(column==7){
        bool ok;
        QString lucro = QInputDialog::getText(this, "Editar Lucro", "Escreva o novo Lucro do Carro", QLineEdit::Normal,"", &ok);

        if(ok && !lucro.isEmpty()){
                     dados.editarLucroCarro(row, lucro.toDouble());
                     inserirCarroNaTabela(dados[row], row);
    }
        }

    if(column==8){
        bool ok;
        QString situacao = QInputDialog::getText(this, "Editar Situação", "Escreva a nova Situaçao do Carro", QLineEdit::Normal,"", &ok);

        if(ok && !situacao.isEmpty()){
                     dados.editarSituacaoCarro(row, situacao);
                     inserirCarroNaTabela(dados[row], row);
    }
        }
    if(column==9){
        bool ok;
        QString status = QInputDialog::getText(this, "Editar Status", "Escreva o novo Status do Carro", QLineEdit::Normal,"", &ok);

        if(ok && !status.isEmpty()){
                     dados.editarStatusCarro(row, status);
                     inserirCarroNaTabela(dados[row], row);
                     Estatisticas();
    }
        }
}

void MainWindow::on_btnlimpar_clicked()
{
    while(ui->tabelaDados->rowCount()>0){
        ui->tabelaDados->removeRow(0);
       dados.limpar();
    }
    ui->lucroreal->clear();
    ui->lucroprevisto->clear();
    ui->valorinicial->clear();

}
