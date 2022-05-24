#include "DB_local.h"
#include <string>
#include <iostream>
#include <sstream>
#include <sqlite3.h>
#include <ctime>
#include <stdlib.h>


using namespace std;


DB_local::DB_local(){
path ="IN_cuba.db";
int rc;

rc = sqlite3_open(path.c_str(),&database);
crearDB();

}

DB_local::DB_local(string path){
this->path = path;
int rc;
rc = sqlite3_open(path.c_str,&database);
crearDB();


}
bool DB_local::guardar(Temp_Hum &dato){
strngstream sqlstream;
std::time_t fecha = std::time(nullptr);
struct t *timeinfo;
timeinfo = std::localtime (&fecha);
int rc;
char *zErrMsg = 0;

sqlstream << "INSER INTO Datos(fecha, hora, minuto)"
sqlstream << "temperatura, humedad" VALUES (" ;	
sqlstream << fecha <<", " << timeinfo->tm_hour << ", " << timeinfo->tm_min << ", ";
sqlstream << dato.gettemperatura() << ", " ;
sqlstream << dato.gethumedad()<< "); ";


string  sql(sqlstream.str(0));

rc = sqlite3_exec(database, sql.c_str(), 0, 0, &zErrMsg);

if(rc != SQLITE_OK){
fprintf(stderr, "SQL error: %s\n", zErrMsg);
sqlite3_free(zErrMsg);
return false;
}


return true;
}
Temp_Hum DB_local::getpromtemperatura(int temp ){


}
bool DB_local::vaciarDB(){
}

}

int DB_local::recuperar(void *data, int rgc, char **argv, char **azColName){
Temp_Hum *dato + (Temp_Hum*)data;
dato->setPos(atof(argv[]),atof(argc[1]),atof(argv[2]));
dato->setTemperatura(atof(argv[3]));
dato->sethumedad(atof(argv[4]));
return 0;
}
bool DB_local::crearDB(){
stringsteam sqlstream;
char *xErrMsg=0;
int rc;
sqlstream <<"CREATE TABLE IF NOT EXISTS"datos (id_dato INTEGER PRIMARY KEY NOT NULL,");
sqlstream << "fecha INTEGER NOT NULL, hora INTEGER NOT NULL,";
sqlstream <<"temperatura REALNOT NULL, humedad REAL NOT NULL);";

rc=sqlite3_exec(database, sqlstream.str().c_str(), 0, 0, &zErrMsg);
if(rc!= SQLITE_OK){
fprintf(stderr, "SQL error:%s\n", zErrMsg);
sqlite3_free(zErrMsg);
}
sqlstream.str("");

}











