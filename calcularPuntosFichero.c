#include <stdio.h>

int main() {
	FILE * fichero;
	FILE * fsalida;
	char nombre[50], respuestas[5];
	int i, puntos;
	
	fichero = fopen("entrada.txt", "r");
	if (fichero == NULL) {
		printf("Error abriendo fichero\n");
		return -1;
	}
	fsalida = fopen("salida.txt", "w");
	if (fsalida == NULL) {
		printf("Error abriendo fichero\n");
		return -1;
	}	
	
	while (fscanf(fichero, "%s %s", nombre, respuestas) != EOF) {
		puntos = 0;
		i = 0;
		while (respuestas[i] != '\0') {
			if (respuestas[i]!='-') {
				puntos++;
			}
			i++;
		}
		fprintf(fsalida, "%s %d\n", nombre, puntos);
	}
	
	fclose(fichero);
	fclose(fsalida);
	
}
