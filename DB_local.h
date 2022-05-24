#ifndef _DB_LOCAL_H
# define _DB_LOCAL_H
#include "Temp_Hum.h"
#include <string>
#include <sqlite3.h>

usingnamespace std;
class DB_local {
public:

DB_local();


DB_local(string path);

 bool guadar(Sensor& dato);
  
 bool vaciasDB();
 
 string getUsuarioRemoto();
    string getHostRemoto();
    string getDBNameRemoto();
    string getPassWDRemoto();
 
 Temp_Hum getpromtemperatura(double temperatura);
Temp_Hum getpromhumedad(double humedad);

private:
string path;
sqlite3 *database;

bool crearDB();

statcint recuperar (void *data, int argc, char **azColname);

};

#endif
