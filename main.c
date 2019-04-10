#include <stdio.h>
#define NUM_MAX_ALUMNOS 150

struct alumno {
	char nombre[50];
	int edad;
};

int main() {
	struct alumno alumnos[NUM_MAX_ALUMNOS];
	int nalumnos = 0, i;
	char opcion;
	FILE *fichero;
	
	// PRIMERO: Leer el fichero
	fichero = fopen("usuarios.txt", "r");
	while (fscanf(fichero, "%s %d", alumnos[nalumnos].nombre, &alumnos[nalumnos].edad) != EOF){
		nalumnos++;
	}
	fclose(fichero);
	
	do {
		fflush(stdin);
		printf("Menu de opciones: A, L, S\n");
		scanf("%c", &opcion);
		if (opcion == 'A') {
			printf("Nombre: \n");
			scanf("%s", alumnos[nalumnos].nombre);
			printf("Edad: \n");
			scanf("%d", &alumnos[nalumnos].edad);
			nalumnos++;
		}
		else if (opcion == 'L') {
			for (i=0; i<nalumnos; i++) {
				printf("Nombre: %s\t", alumnos[i].nombre);
				printf("Edad: %d\n", alumnos[i].edad);		
			}
		}
		else if (opcion == 'S') {
			// GRABAR LOS DATOS EN EL FICHERO
			fichero = fopen("usuarios.txt", "w");
			for (i=0; i<nalumnos; i++) {
				fprintf(fichero, "%s\t", alumnos[i].nombre);
				fprintf(fichero, "%d\n", alumnos[i].edad);		
			}
			fclose(fichero);
			printf("Adios\n");
		}
	}while(opcion != 'S');
	
	
}
