#include <stdio.h>

#define MAX_DIBUJOS 100

struct Tdibujo {
	char nombre[50];
	int x;
	int y;
	int escala;
}; 

int main(){
	struct Tdibujo dibujos[MAX_DIBUJOS];
	int n = 0; // n es el numero de dibujos que hay en el vector
	FILE * fichero;
	int i;
	
	fichero = fopen("datos.txt", "r");
	if (fichero == NULL) {
		printf("Error en apertura\n");
		return -1;
	}
	while (fscanf(fichero, "%s %d %d %d", dibujos[n].nombre, &dibujos[n].x, &dibujos[n].y, &dibujos[n].escala)!=EOF) {
		n++;
	}
	fclose(fichero);
	
	// COMPRUEBO QUE SE HA LEIDO EL FICHERO CORRECTAMENTE:
	printf("Contador: %d\n", n);
	for(i=0; i<n; i++) {
		printf("%s %d %d %d\n", dibujos[i].nombre, dibujos[i].x, dibujos[i].y, dibujos[i].escala);
	}
	
	fichero = fopen("salida.txt", "w");
	if (fichero == NULL) {
		printf("Error en apertura\n");
		return -1;
	}
	
	for(i=0; i<n; i++) {
		fprintf(fichero, "%s (%d, %d), %.4f\n", dibujos[i].nombre, dibujos[i].x, dibujos[i].y, dibujos[i].escala / 100.0);
	}
	
	fclose(fichero);
	
	
}
