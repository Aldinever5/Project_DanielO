#ifdef TEMP_H
#define TEMP_H
#include "Temp_Hum.h"
#include <iostream>
#include "sensor.h"

class Temp_Hum: public Sensor{
public:
	Temp_Hum():Sensor(2){}
	double temperatura(){return leerDato(0);}
	double humedad(){return leerDato(1)}


/**
 * @param temp
 * @param hum
 */
Temp_Hum::Temp_Hum( double& temp, double& hum) {
    
    temperatura = temp;
    humedad = hum;
//    std::cout << temperatura  << ", " << humedad << std::endl;
}

Temp_Hum::Temp_Hum(){
    temperatura = 0.;
    humedad = 0.;
}

/**
 * @param &temp
 * @param &hum
 * @return void
 */
void Temp_Hum::getDatos( double &temp, double &hum) {

    temp = temperatura;
    hum = humedad;
}

/**
 * @param temp
 * @param hum
 * @return bool
 */
bool Temp_Hum::setDatos( double &temp, double &hum) {
    try{
        temperatura = temp;
        humedad = hum;
        return true;
    }catch(...){
        return false;
    }
}
};
