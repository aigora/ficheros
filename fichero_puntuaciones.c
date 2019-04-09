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
	int i,j,verifica=0;
	char comprobador_nombre[50], salir;
	
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
	
	for(j=0;j<i;j++){
		strcpy(comprobador_nombre,vector[j].usuario);
		_strupr(comprobador_nombre);
		if(strcmp(comprobador_nombre,"MAFALDA")==0){
			printf("\nMafalda tiene %f puntos\n",vector[j].puntos);
			verifica=1;
		}
	}
		if (verifica==0)
			printf("Mafalda no esta registrada\n");
		
	// Añadir un nuevo usuario (en memoria, al final del vector)
	
	do{
		printf("Introduzca nombre y puntuacion del usuario %d\n",i);
		vector[i].identificador=i;
		scanf("%s %f",vector[i].usuario, &vector[i].puntos);
		printf("Pulse s para salir, o enter para continuar\n",i);
		fflush(stdin);
		scanf("%c",&salir);
		i++;
		if(salir=='s')
			break;
		
		
	}while (i<=100);
	if(i==100)
		printf("Revise el codigo, ha alcanzado el limite de memoria\n");
	
	
	puntero = fopen("datos.txt", "w");
	
	if (puntero == NULL) {
		printf("No se ha podido abrir el fichero\n");
		return -1;
		}
		
	
	for(j=0;j<i;j++){
		fprintf(puntero,"%d\t%s\t%f\n", vector[j].identificador, vector[j].usuario, vector[j].puntos);
		}
		
	fclose(puntero); 
}
