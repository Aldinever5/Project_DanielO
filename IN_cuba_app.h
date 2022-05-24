/**
 * Project Untitled
 */
#include <QtCore/QTimer>

#ifndef IN_CUBA_APP_H
#define IN_CUBA_APP_H

#include "DB_local.h"
#include "Temp_Hum.h"
#include <ctime>
#include <vector>


class Seguidor_app:QObject {
    Q_OBJECT
public: 
    
/**
 * @param fecha
 * @param hora
 * @param minuto
 */
Seguidor_app(std::time_t fecha, int hora, int minuto);
    
int ejecutar();
private: 
    std::time_t fecha;
    int hora;
    int minuto;
    QTimer *timer1;
    QTimer *timer2;
    DB_local *base_datos;
    vector<Temp_Hum> _datos;

    IN_cuba_app();

    void adquirirDatos();

    bool almacenarpromedio();

    double leerTemperatura();

    double leerHumedad();

    
    void cada60Seg(void);
    void cada24Horas(void);
};

#endif 
