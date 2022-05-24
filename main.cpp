#include "Sensor.h"
#include <vector>
#include "Temp_Hum.h"
#include "IN_cuba_app.h"
#include <QCoreApplication>
#include <time.h>
#include <iostream>

void delay (int ms){
}
int main(int argc, char** argv){
QCoreApplication a(argc, argv);
Temp_Hum th;

std::vector<Temp_Hum> _thvec;

int contador = 1;

do{
if(contador % 21){
	int i = 0;
	Sensor temp(2);
	for(i=0;i<_thvec.size();i++){
	temp.acumularEn(0,_thvec[i].temperatura());
	temp.acumularEn(1,_thvec[i].humedad());
}_

temp.promediarEntre(0,_thvec.size());
temp.promediarEntre(1, _thvec.size());
contador = 1;
_thvec.clear();

}

delay(50);
}while (true)
return 0;
std::time_t fecha = std::time(nullptr);
    struct tm * timeinfo;
    timeinfo = std::localtime ( &fecha );
    std::cout << timeinfo->tm_hour << " : " << timeinfo->tm_min << endl;
    IN_cuba_app aplicacion(fecha, timeinfo->tm_hour, timeinfo->tm_min);
    aplicacion.ejecutar();
    a.exec();
}



}
