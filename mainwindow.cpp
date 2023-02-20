#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>
#include <qfiledialog.h>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->plainTextEdit->setPlainText(QString::fromStdString(lista.print()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

administraNeu::administraNeu()
{
    inicializa();
}

administraNeu::~administraNeu()
{
}

bool administraNeu::vacia()
{
    if(h==NULL and t== NULL)
    return true;
    else
    return false;
}

void administraNeu::inicializa(void)
{
    h=NULL;
    t=NULL;
}

void administraNeu::insertaInicio(Neurona x)
{
    nodo *tmp=new nodo();
    tmp->dato=x;

    if(vacia())
    {
        h=tmp;
        t=tmp;
    }
    else
    {
        tmp->sig=h;
        h->ant=tmp;
        h=tmp;
    }
}
void administraNeu::insertaFinal(Neurona x)
{
    nodo *tmp=new nodo();
    tmp->dato=x;
    nodo *aux=h;

    if(aux==NULL)
    {
        h=tmp;
    }
    else
    {
        while(aux->sig) //null=false
        {
            aux=aux->sig;
        }
        aux->sig=tmp;
    }
}

void administraNeu::print()
{
    nodo *aux=h;


    if(aux)
    {
        while(aux)
        {

        cout << " Id:     #" << aux->dato.getId() << endl;
        cout << " Voltaje: " << aux->dato.getVoltaje() << endl;
        cout << " posicion_x: " << aux->dato.getPosicion_x() << endl;
        cout << " posicion_y: " << aux->dato.getPosicion_y() << endl;
        cout << " Red: " << aux->dato.getRed() << endl;
        cout << " Green: " << aux->dato.getGreen() << endl;
        cout << " Blue: " << aux->dato.getBlue() << endl;
            aux=aux->sig;
        }
    }
    else
        cout<<"Lista vacia"<<endl;
}


void administraNeu::vaciar()
{
    h=NULL;
    t=NULL;
}



int administraNeu::size()
{
    int i = 0;
    nodo* p = h;

    while(p)
    {
        i++;
        p = p->sig;
    }
    return i;
}

std::string administraNeu::toString()//capturar datos para su impresion
{
    nodo *aux=h;
    std::string stringAdmin;


    if(aux)
    {
        while(aux)
        {

        stringAdmin += " Id:     #"; stringAdmin += std::to_string(aux->dato.getId()); stringAdmin += "\n";
        stringAdmin += " Voltaje: "; stringAdmin += std::to_string(aux->dato.getVoltaje()); stringAdmin += "\n";
        stringAdmin += " posicion_x: "; stringAdmin += std::to_string(aux->dato.getPosicion_x()); stringAdmin += "\n";
        stringAdmin += " posicion_y: "; stringAdmin += std::to_string(aux->dato.getPosicion_y()); stringAdmin+= "\n";
        stringAdmin += " Red: "; stringAdmin+= std::to_string(aux->dato.getRed()); stringAdmin += "\n";
        stringAdmin += " Green: "; stringAdmin+= std::to_string(aux->dato.getGreen()); stringAdmin += "\n";
        stringAdmin += " Blue: "; stringAdmin += std::to_string(aux->dato.getBlue()); stringAdmin += "\n";
        stringAdmin += "---------------------------------- \n";
            aux=aux->sig;
        }
    }
    else
        stringAdmin+= "La lista esta vacia";

    return stringAdmin;
}


nodo::nodo()
{
    sig=NULL;
    ant=NULL;
}

nodo::~nodo()
{
}

void nodo::eliminar_todo()
{
    if(sig and ant)
    sig->eliminar_todo();
    delete this;
}

Neurona::Neurona()
{
}


Neurona::Neurona(int id, float voltaje,int posicion_x, int posicion_y, int red, int green, int blue)
{
    this->id = id;
    this->voltaje = voltaje;
    this->posicion_x= posicion_x;
    this->posicion_y= posicion_y  ;
    this->red = red;
    this->green= green;
    this->blue = blue;

}

Neurona::~Neurona()
{
}

int Neurona::getId(void){return id;}
void Neurona::setId(int id){this->id = id;}

float Neurona::getVoltaje(void){return voltaje;}
void Neurona::setVoltaje(float voltaje){this->voltaje = voltaje;}

int Neurona::getPosicion_x(void){return posicion_x;}
void Neurona::setPosicion_x(int posicion_x){this->posicion_x = posicion_x;}

int Neurona::getPosicion_y(void){return posicion_y;}
void Neurona::setPosicion_y(int posicion_y){this->posicion_y = posicion_y;}

int Neurona::getRed(void){return red;}
void Neurona::setRed(int red){this->red = red;}


int Neurona::getGreen(void){return green;}
void Neurona::setGreen(int green){this->green = green;}

int Neurona::getBlue(void){return blue;}
void Neurona::setBlue(int  blue){this-> blue = blue;}





void MainWindow::on_botonmostrar_clicked()
{
    ui->plainTextEdit->setPlainText(QString::fromStdString(listaNeuronas.toString()));//mostramos los datos en el plaintext
}


void MainWindow::on_botonagregainicio_clicked()//agregar datos al inicio
{
    listaNeuronas.insertaInicio
    (
        Neurona(ui->spinBox->text().toInt(),
                ui->line_voltaje->text().toFloat(),
                ui->line_posx->text().toInt(),
                ui->line_posy->text().toInt(),
                ui->line_red->text().toInt(),
                ui->line_green->text().toInt(),
                ui->line_blue->text().toInt())

    );

}


void MainWindow::on_botonagregarfinal_clicked()//agregar datos al final
{
    listaNeuronas.insertaFinal
    (
        Neurona(ui->spinBox->text().toInt(),
                ui->line_voltaje->text().toFloat(),
                ui->line_posx->text().toInt(),
                ui->line_posy->text().toInt(),
                ui->line_red->text().toInt(),
                ui->line_green->text().toInt(),
                ui->line_blue->text().toInt())
    );
}





