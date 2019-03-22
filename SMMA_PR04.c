//Manuel Alejandro Sahagun Mendoza   349857
//Concatenar, Validar un rango, Validar letras,mayusculas y espacios
//17 marzo 2017
//SMMA_PR04
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>

char *nomcom(char *nom,char *ape);
char *validanum(int ri,int rf,char *msge);
char *stringvalida(char *caract);
void programa1(void);
void programa2(void);
void programa3(void);
void delay(int);
void menu (void);

int main (void)				//Funcion Principal
{
   menu();
   return 0;
}
void menu(void)				//Menu de funciones
{
   int op;
   do{
      system ("cls");
      printf("\n M  E   N   U");
	  printf("\n1.- Nombres y Apellidos");
	  printf("\n2.- Validar numeros entre un rango");
	  printf("\n3.- Validar espacio, letras y mayusculas");
	  printf("\n0.- Salir");
	  printf("\nESCOGE UNA OPCION.");
      scanf ("%d",&op);
	  switch(op)
	    {
		  case 1: programa1();  break;
		  case 2: programa2();  break;
		  case 3: programa3();  break;
		}
   }while(op != 0);
}
void programa1(void)		//Concatenar nombres y apellidos
{
    system ("cls");
	int i;
	char nomp[100];
	char nom[20][30] = {
	"Manuel Sahagun",
	"Carlos Argaez",
	"Francisco Perez",
	"Federico Gonzalez",
	"Luis Alonso",
	"Luis Angel Moxca",
	"Jose Hernandez",
	"Guadalupe Esparza",
	"Sandra Gutierrez",
	"Maria Fernandez",
	"Lucia Fernanda",
	"Diana Gomez",
	"Lorenzo Cardenas",
	"Pedro Guerrero",
	"Angel Montes",
	"Marla Parra",
	"Gibran Vargas",
	"Elver Viramontes",
	"Ignacio Ramirez",
	"Martin Cruz"
	};
	char ape[30][30] = {
	" Mendoza",
	" Mejia",
	" Gonzales",
	" Esparza",
	" Carrillo",
	" Monarrez",
	" Garcia",
	" Cardenas",
	" Perez",
	" Cruz",
	" Chico",
	" Sanchez",
	" Ramirez",
	" Montes",
	" Sanchez",
	" Perez",
	" Curiel",
	" Zertuche",
	" Gomez",
	" Vargas",
	" Carranza"};
	
	for(i = 0 ; i < 20 ; i++)
	{
	strcpy(nomp,nomcom(nom[rand()%20],ape[rand()%20]));
	printf("%s\n",nomp);
	}
	system("pause");
}
void programa2(void)		//Validar Numeros
{
	system ("cls");
	char nom[11],impt[11];
	
	strcpy(nom,validanum(48,57,"Introduce un numero"));
	
	impt[0] = nom[0];
	impt[1] = nom[1];
	impt[2] = nom[2];
	impt[3] = nom[3];
	impt[4] = nom[4];
	impt[5] = nom[5];
	impt[6] = nom[6];
	impt[7] = nom[7];
	impt[8] = nom[8];
	impt[9] = nom[9];
	impt[10] = nom[10];
	
	printf("\nNumeros Que se obutiveron:\n%s\n",impt);
	system("pause");
}
void programa3(void)		//Validar Numeros,Letras y espacios
{
    system ("cls");
    
    char letras[70];
    
    strcpy(letras,stringvalida("Escribe Tu nombre: "));
    
    printf("\n%s",letras);

	system("pause");
}
void delay(int tiempo) 		//Tiempo Delay
{
  int i,j;
  for(i=0;i<tiempo*100;i++)
     {
	   for(j=0;j<tiempo*100;j++);
	 }
}
char* validanum(int ri,int rf,char* msge)	//Funcion que Valida numeros
{
	int val,i = 0;
	char cad[50];
	
	puts(msge);
	do{
		val = getch();
		if((val >= ri) && (val <= rf))
		{
			printf("%c",val);
			cad[i] = val;
			i++;
		}		
	}while(val != 13);
	cad[i] = '\0';
return cad;		
}
char *nomcom(char *nom,char *ape) //Funcion que concatena nombres con apellidos
{
char *com;
	com = strcat(nom,ape);
	return com;
}
char *stringvalida(char *caract)
{
	char cadena[70];
	int i = 0,j = 0,espacio,tecla,tam;
	tam = strlen(cadena);
	puts(caract);
	//do{
		do{
			tecla = getch();
			if(((tecla >= 65) && (tecla <= 90)) || (tecla == 32))
			{
				printf("%c",tecla);
				cadena[i] = tecla;
				i++;
			}
			
		}while((tecla != 13) && (cadena[0] != 32));
		if(cadena[0] == 32)
		{
		printf("La cadena no puede comenzar con espacio");
		}
	//}while(tecla != 13);
			cadena[i] = '\0';	
return cadena;}
