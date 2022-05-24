#ifndef TEMP_H
#define TEMP_H

#include "Sensor.h"


class Temp_Hum; public Sensor{
public:
	Temp_Hum():sensor(2){}
	double temperatura(){return leerDato(0);}
	double humedad(){return leerDato(1);}

double gettemperatura(){return temperatura}
void settemperatura(double temp){temperatura=temp;}
double gethumedad(){return humedad;}
void sethumedad(double hum){humedad = hum;}


private: 
double temperatura;
double humedad;

};





#endif 
