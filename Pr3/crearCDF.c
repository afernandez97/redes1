/***********************************************************
 crearCDF.c	 
 Primeros pasos para implementar y validar la funcion crearCDF(). Est funcion debe devolver
 un fichero con dos columnas, la primera las muestras, la segunda de distribucion de
 probabilidad acumulada. En la version actual la funcion realiza los dos primeros pasos para
 este objetivo, cuenta el numero de muestras y las ordena.
 El alumno debe acabar su implementacion de crearCDF() y usar un main similar para validar su fucionamiento.
 
 Compila: gcc -Wall -o crearCDF crearCDF.c
 Autor: Jose Luis Garcia Dorado
 2014 EPS-UAM 
***************************************************************************/

#include <stdio.h> 
#include <stdlib.h> 
#include <strings.h> 
#include <string.h> 

#define OK 0
#define ERROR 1

int crearCDF(char* filename_data, char* filename_cdf);

int main(){
	return crearCDF("sizes.dat","ECDFsizes.dat");
}

int crearCDF(char* filename_data, char* filename_cdf) {
	char comando[255]; char linea[255]; char aux[255];
	int num_lines;
	FILE *f;

	if(!filename_data || !filename_cdf) return ERROR;

	sprintf(comando,"wc -l %s 2>&1",filename_data); //wc cuenta lineas acabadas por /n
	f = popen(comando, "r");
	if(f == NULL){
		printf("Error ejecutando el comando\n");
		return ERROR;
	}
	fgets(linea,255,f);
	sscanf(linea,"%d %s",&num_lines,aux);
	pclose(f);

	sprintf(comando,"sort -n < %s > %s 2>&1",filename_data,filename_cdf);
	f = popen(comando, "r");
	if(f == NULL){
		printf("Error ejecutando el comando\n");
		return ERROR;
	}
	bzero(linea,255);
	fgets(linea,255,f);
	pclose(f);

	return OK;
}



