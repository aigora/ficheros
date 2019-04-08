#include <stdio.h>
#include <string.h>

struct TUsuario{
	int identificador;
	char usuario[50];
	float puntos;
};

int main() {
	FILE *puntero;
	struct TUsuario vector[100];
	int i;
	
	puntero = fopen("datos.txt", "r");
	
	if (puntero == NULL) {
		printf("No se ha podido abrir el fichero\n");
		return -1; // Se termina el programa
	}
	i=0;
	while (fscanf(puntero, "%d %s %f", &vector[i].identificador, vector[i].usuario, &vector[i].puntos)!=EOF) {
		printf("Leyendo: %d %s %f\n", vector[i].identificador, vector[i].usuario, vector[i].puntos);
		i++;
	}
	fclose(puntero);
	
	// EJERCICIO: 
	// ¿Cuantos puntos tiene mafalda?
	// Añadir un nuevo usuario (en memoria, al final del vector)
	// Guardar los datos al fichero
	
}
