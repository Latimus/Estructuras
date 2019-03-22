//Manuel Alejandro Sahagun Mendoza	349857
//Tabla ASCII, valor de tecla, Calificaciones Validadas y Numero mayor de 6 Validado
//02 marzo 2017
//SMMA_PR02
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
#define N 6
#define ESC 27
//****************************************************************
/// variables globales 
//**********************************************************************


//****************************************************************************
// PROTOTIPOS DE FUNCIONES
//****************************************************************************

int validanum(int ri, int rf,char *msge, char *msgError);
void programa1(void);
void programa2(void);
void programa3(void);
void programa4(void);
void delay(int);
void menu (void);

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
	  printf("\n1.- Imprimir tabla ASCCI");
	  printf("\n2.- Desplegar el valor de la tecla");
	  printf("\n3.- Calificaciones con Validanum");
	  printf("\n4.- Funcion que lea 6 numeros entre 0 y 250");
	  printf("\n0.- Salir");
	  printf("\nESCOGE UNA OPCION.");
      scanf ("%d",&op);
	  switch(op)
	    {
		  case 1: programa1();  break;
		  case 2: programa2();  break;
		  case 3: programa3();  break;
		  case 4: programa4();  break;
		}
   }while(op != 0);
}

//**************************************************************************************

//***********Tabla ASCII
void programa1(void)
{
    system ("cls");
    
    int i;
    
    for(i = 0 ; i < 256 ; i++)
    {
    
    	printf(" %d\t-\t%c\n",i,i);
    	
    }
	system("pause");
}

//**************************************************************************************

//***********Desplegar el valor de la tecla
void programa2(void)
{
   system ("cls");
   	
   	int tecla;
	
	do{
		
		printf(" \nPresiona una tecla: ");
		
		tecla = getch();
		
		printf("%d - %c",tecla,tecla);
		
	}while(tecla != ESC);
	
	printf("\n2");
	system("pause");


}

//**************************************************************************************

//***********Calificaciones con Validanum
void programa3(void)
{
	
	int cal1,cal2,cal3;
	float prom;
	
	system ("cls");
	
	cal1 = validanum(0,101,"Dame la primera Calificacion: ","Error en Calificacion");
	cal2 = validanum(0,101,"Dame la segunda calificacion: ","Error en calificacion");
	cal3 = validanum(0,101,"Dame la tercera calificacion: ","Error en calificacion");

	prom = ( cal1 + cal2 + cal3 ) / 3;
	
	if ( prom < 80 )
	{
                if ( prom < 60 )
                {
                     if ( prom <= 30 )
                     {
                          printf("Repetir: %.2f",prom);
                      }
                      else
                      {
                          printf("Extraordinario: %.2f",prom);
                      }
                 }
                 else
                 {
                     if ( prom < 70)
                     {
                          printf("Suficiente: %.2f",prom);
                      }
                      else
                      {
                          printf("Regular: %.2f",prom);
                      }
                 }
     }
     else
     {
         if ( prom < 96)
         {
              if ( prom < 90 )
              {
                   printf("Bien: %.2f",prom);
               }
               else
               {
                   printf("Muy Bien: %.2f",prom);
               }
          }
          else
          {
              if (prom <= 100)
              {
                      printf("Excelente: %.2f",prom); 
              }
              else
              {
                      printf("Error: %.2f",prom);
              }
                       
          }
     }
     printf("\n");
     system("pause");
     
}

//************************************************************************

//**************************Programa que lea 6 numeros (validanum)
void programa4(void)
{
	system("cls");
	
	int num,i,mayor=-1;
	
	for(i = 0; i < N; i++)
	{
		num = validanum(0,250,"Dame un numero: ","Error");
		
		if(num > mayor)
		{
			mayor=num;
		}
	}
	
	printf("El mayor de los %d numeros es el: %d\n",N,mayor);
	
	system("pause");
}

//***********************************************************************
void delay(int tiempo)
{
  int i,j;
  for(i=0;i<tiempo*100;i++)
     {
	   for(j=0;j<tiempo*100;j++);
		

	 }
}
//************************************************************************
// Validar Numeros
//************************************************************************

int validanum(int ri, int rf,char *msge, char *msgError)
{
	int num;
	char xnum[30]; //Cadena de 30 caracteres maximo
	do{
		puts(msge);
		fflush(stdin);
		gets(xnum);
		num = atoi(xnum);
		
		if((num < ri || num > rf))
		{
			puts(msgError);
		}
		
	}while((num < ri || num > rf));
	
	return num;
}

//************************************************************************

