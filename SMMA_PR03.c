//Manuel Alejandro Sahagun Mendoza	349857
//Programa que modifique una cadena en diferentes formtamos (MUNDO) y contar vocales y consonantes
//07 Marzo 2017
//SMMA_PR03

//***************************************************************************************
//    LIBRERIAS
//**************************************************************************************

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//****************************************************************
/// Constantes
//**********************************************************************

#define N 10
//****************************************************************
/// variables globales
//**********************************************************************


//****************************************************************************
// PROTOTIPOS DE FUNCIONES
//****************************************************************************
void menu (void);
void programa1(void);
void programa2(void);
void programa3(void);
void delay(int);

//****************************************************************************
// MAIN PRINCIPAL  ...  funcion principal
//****************************************************************************

int main (void)
{
   menu();
   return 0;
}

//****************************************************************************
// desarollo de las funciones en el mismo orden de como listamos los prototipos
//****************************************************************************

//*****************   FUNCION MENU DESDE DONDE SE MANDA LLAMAR LAS DEMAS FUNCIONES
void menu(void)
{
   int op;
   
   do{
      system ("cls");
      printf("\n M  E   N   U");
	  printf("\n1.- MUNDO en diferentes formatos");
	  printf("\n2.- Contar vocales y consonantes");
	  printf("\n0.- Salir");
	  printf("\nESCOGE UNA OPCION.");
      scanf ("%d",&op);
	  switch(op)
	    {
		  case 1: programa1();  break;
		  case 2: programa2();  break;
		}
   }while(op != 0);
}

//**************************************************************************************

//***********Programa que de varios formatos de la cadena MUNDO 
void programa1(void)
{
    system ("cls");
	
	char cad1[10] = {"MUNDO"};	//Cadena original #1
	int tam,i,j,k;
	
	tam = strlen(cad1);
	
	printf("2.-Mundo al reves: \n\n");
	
	for(i = (tam-1);i != -1; i--)	//Mundo al reves #2
	{
		printf("%c",cad1[i]);
	}
	
	printf("\n\n3.-Mundo Vertical: \n\n");
	
		for(i = 0; i < tam; i++)	//Mundo vertical #3
	{
		printf("%c\n",cad1[i]);
	}
	
	printf("\n\n4.-Mundo vertical al reves\n\n");
	
	for(i = (tam-1);i != -1; i--)	//Mundo vertical al reves #4
	{
		printf("%c\n",cad1[i]);
	}
	
	printf("\n\n5.-Mundo en filas con una letra menos al final: \n\n");
	
	for(i = 0 ; i < tam ; i++)				//Mundo en filas con una letra menos al final #5
	{
		for(j = 0 ; j < (tam - i) ; j++)
		{
			printf("%c",cad1[j]);
		}
		printf("\n");
	}
	
	printf("\n\n6.-Mundo al reves en filas con una letra menos al final: \n\n");
	
	for(i = 0 ; i < tam ; i++)
	{
		for(j = (tam-1) ; j != (-1); j--)	//Mundo al reves en filas con una letra menos al final #6
		{
			printf("%c",cad1[j+(i)]);		
		}
		printf("\n");
	}
	
	printf("\n\n7.-Mundo en filas con una letra menos al inicio  \n\n");
	
	for(i = 0 ; i < tam ; i++)
	{
		for(j = 0 ; j < tam ; j++)	//Mundo en filas con una letra menos al inicio #7
		{
		
			printf("%c",cad1[i+j]);	
				
		}
		printf("\n");
	}
	
	printf("\n\n8.-Mundo al reves en filas con una letra menos al inicio: \n\n");
	
	for(i = 0 ; i < tam ; i++)
	{
		for(j = tam ; j != (-1) ; j--)	//Mundo en filas con una letra menos al inicio (reves) #8
		{
		
			printf("%c",cad1[j-(i+1)]);	
				
		}
		printf("\n");
	}
	
	printf("\n\n");
	
	system("pause");
	

}

//**************************************************************************************

//***********Programa que cuente las vocales y consonates de una cadena
void programa2(void)
{
    system ("cls");
	
	char cad1[10] = {"MUNDO"};	//Cadena original
	int tam,i,a = 0 ,e = 0 ,y = 0 ,o = 0 ,u = 0 
	;
	
	tam = strlen(cad1);
	
	for(i = 1 ; i < (tam) ; i++)
	{
		switch(cad1[i])
		{
			case 'A': a++; break;
				
			case 'E': e++; break;
			
			case 'I': y++; break;
			
			case 'O': o++; break;
			
			case 'U': u++; break;
			
		}	
	}
	
	printf("La frase Mundo tiene :\n%d = 'A'\n%d = 'E'\n%d = 'I'\n%d = 'O'\n%d = 'U'\n%d =  Consonantes\n",a,e,y,o,u,(i-(a+e+y+o+u)));
	
	system("pause");


}

//**************************************************************************************


//************************************************************************
void delay(int tiempo)
{
  int i,j;
  for(i=0;i<tiempo*100;i++)
     {
	   for(j=0;j<tiempo*100;j++);
		

	 }
}











