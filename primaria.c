#include <stdio.h>

#define MAX_ALUMNOS 100

struct Talumno {
	char nombre[50];
	char apellido1[50];
	char apellido2[50];
	char clase;
};

int main() {
	// Vector de estructuras de alumnos de primaria
	struct Talumno primaria[MAX_ALUMNOS];
	int n=0; // n es el numero de alumnos que hay en el vector
	int i, contador;
	FILE *fichero;
	char opcion;
	// PRIMERO: LEER LOS DATOS DEL FICHERO Y CARGARLOS EN MEMORIA
	fichero = fopen("entrada.txt", "r");
	if (fichero == NULL) {
		printf("Error en la apertura de fichero");
		return -1; // Se sale del programa
	}
	while (fscanf(fichero, "%s %s %s %c", primaria[n].nombre, primaria[n].apellido1, primaria[n].apellido2, &primaria[n].clase) != EOF) {
		n++; // Se incrementa la n cuando se lee un alumno
	}
	// SE CIERRA EL FICHERO (PARA SIEMPRE)
	fclose(fichero);
	
	printf("Contador: %d\n", n);
	
	// ESTO ES SIMPLEMENTE PARA COMPROBAR QUE SE HA LEIDO BIEN:
	for (i=0; i<n; i++) {
		printf("%s %s %s %c\n", primaria[i].nombre, primaria[i].apellido1, primaria[i].apellido2, primaria[i].clase);
	}
	
	do {
		fflush(stdin);
		printf("Introduce la clase: A, B, C, D\n");
		scanf("%c", &opcion);
	} while (opcion != 'A' && opcion != 'B' && opcion != 'C' && opcion != 'D');
	
	contador = 1;
	for (i=0; i<n; i++) {
		if (primaria[i].clase == opcion) {
			printf("%d. %s %s %s\n", contador, primaria[i].nombre, primaria[i].apellido1, primaria[i].apellido2);
			contador++;
		}
	}
	
	if (contador == 1) {
		printf("No hay alumnos en la clase %c\n", opcion);
	}
	
}
