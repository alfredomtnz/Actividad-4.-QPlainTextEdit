#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class Neurona
{
    private:
        int id;
        float voltaje;
        int posicion_x;
        int posicion_y;
        int red;
        int green;
        int blue;

    public:
        Neurona();
        Neurona(int id, float voltaje,int posicion_x, int posicion_y, int red, int green, int blue);
       ~Neurona();

        int getId(void);
        void setId(int);

        float getVoltaje(void);
        void setVoltaje(float);

        int getPosicion_x(void);
        void setPosicion_x(int);

        int getPosicion_y(void);
        void setPosicion_y(int);

        int getRed(void);
        void setRed(int);

        int getGreen(void);
        void setGreen(int);

        int getBlue(void);
        void setBlue(int);
};
class nodo
{
    public:
        nodo();
        ~nodo();
        Neurona dato;
        nodo *sig;
        nodo *ant;
        void eliminar_todo();
    protected:
};


class administraNeu
{
    public:
       administraNeu();
        ~administraNeu();

        nodo *h;
        nodo *t;

        //lista de operaciones

        void inicializa(void);
        void insertaInicio(Neurona);
        void insertaFinal(Neurona);
        void print();
        bool vacia();
        nodo* anterior(Neurona);
        nodo* siguiente(Neurona);
        void vaciar();
        int size();

        std::string toString();
};

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    administraNeu listaNeuronas;

private slots:


    void on_botonmostrar_clicked();

    void on_botonagregainicio_clicked();

    void on_botonagregarfinal_clicked();





private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H



