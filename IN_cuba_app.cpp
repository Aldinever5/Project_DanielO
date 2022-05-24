/**
 * Project Untitled
 */


#include "IN_cuba_app.h"
#include <iostream>

using namespace std;

/**
 * IN_cuba_app implementación
 */recuperar


/**
 * @param fecha
 * @param hora
 * @param minuto
 */
IN_cuba_app::IN_cuba_app(std::time_t fecha, int hora, int minuto) {
    this->fecha = fecha;
    this->hora = hora;
    this->minuto = minuto;
    timer1 = new QTimer(this);
    timer2 = new QTimer(this);
    connect(timer1, SIGNAL(timeout()), this, SLOT(cada60Seg()) );
    connect(timer2, SIGNAL(timeout()), this, SLOT(cada24Horas()) );
}

/**
 * @return int
 */
int IN_cuba_app::ejecutar() {

    // Teniendo en cuenta que se utilizarán dos QTimers para el desarrollo
    // de la aplicación, se procede a crear los configurarlos y a crear los slots
    timer1->setInterval(5000);
    timer2->setInterval(8640000);
    timer1->start();
    timer2->start();
    return 0;
}

IN_cuba_app::IN_cuba_app() {

}

/** This method reads sensor data and save them inside a Muestra objet,
 * then push it inside the vector _datos
 * @return void
 */
void IN_cuba_app::adquirirDatos() {
    
    Temp_Hum dato;
    double a,b;
    a = leerTemperatura();
    b = leerHumedad();
    dato.setDatos( a, b );
    _datos.push_back( dato );
}

/** Esta función calcula el promedio de las doce muestras que conforman
 * el minuto y lo guarda en la base de datos local.
 * @return bool
 */
bool IN_cuba_app::almacenarpromedio() {
    double  temp, hum;
    temp = hum = 0.;
    for( int i = 0; i < _datos.size(); i++ ){
        
        temp += _datos[i].getTemperatura();
        hum  += _datos[i].getHumedad();
    }
    
    temp /= _datos.size();
    hum  /= _datos.size();

    Temp_Hum dato(temp, hum );

    DB_local conexion;
    bool guardo = conexion.guardar( dato );
    _datos.clear();
    return guardo;
}



/**
 * @return double
 */
double IN_cuba_app::leerTemperatura() {
    double a = rand() % 30 + 9.;
    return a;
}

/**
 * @return double
 */
double IN_cuba_app::leerHumedad() {
    double a = rand() % 50 + 50.;
    return a;
}



void IN_cuba_app::cada60Seg(){
    adquirirDatos();
    if( _datos.size() == 12 )
        almacenarDatoMin();
    timer1->start();
    //cout << "Pasaron 60 seg" << endl;
}
void IN_cuba_app::cada24Horas(){

}
