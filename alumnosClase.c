#include<stdio.h>
int main()
{
	char nombre[40],apellido1[50],apellido2[50],letra1,letra;
	int numero,i=0;
	FILE *pf1,*pf2;
	pf1=fopen("alumnos.txt","r");
	pf2=fopen("pantalla.txt","w");
	if(pf1==NULL)
	{
		printf("No se ha podido abrir el fichero \n");
		return -1;
	}
	if(pf2==NULL)
	{
		printf("No se ha podido abrir el fichero \n");
		return -1;
	}
	do{
		printf("Elige una letra de A-D \n");
		scanf("%c",&letra);
	}while(letra!='A'&&letra!='B'&&letra!='C'&&letra!='D');//si es verdadera se repite el do hasta que sea falsa
	//Leemos el fichero
	while(fscanf(pf1,"%s %s %s %c",nombre,apellido1,apellido2,&letra1)!=EOF)
	{
		i++;
		//printf("Hemos leido %s %s %s %c",nombre,apellido1,apellido2,letra1);
		if(letra1==letra)
		{
			fprintf(pf2,"%i %s %s %s \n",i,nombre,apellido1,apellido2);
		}
	}
	fclose(pf1);
	fclose(pf2);
	
	
}
