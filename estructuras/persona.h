#ifndef PERSONA_H
#define PERSONA_H

#define MAX_LONG_NOMBRE 100
#define MAX_LONG_APELLIDO 100


typedef struct $
{
	short int anyo;
	short int mes;
	short int dia;
}fecha;

typedef struct persona
{
	char nombre [MAX_LONG_NOMBRE];
	char apellido[MAX_LONG_APELLIDO];
	int edad;
	fecha fecha_nac;
	
}persona;


unsigned short int obtener_edad (persona *);

#endif