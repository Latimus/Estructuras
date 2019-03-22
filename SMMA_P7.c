//Manuel Alejandro Sahagun Mendoza 349857
//Ordenar y buscar binario y secuencial
//31 03 2017
//SMMA_P7
//****************************************************************************
//    LIBRERIAS
//****************************************************************************

#include <string.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//****************************************************************
/// Constantes
//**********************************************************************

#define N 20
//****************************************************************
/// variables globales
//**********************************************************************


//****************************************************************************
// PROTOTIPOS DE FUNCIONES
//****************************************************************************

int buscsec(int vec[],int num);
int buscbin(int vec[],int num);
void programa1(int vec[]);
void programa2(int vec[]);
void programa3(int vec[]);
void programa4(int vec[]);
void delay(int);
void menu (void);

//****************************************************************************
// MAIN PRINCIPAL  ...  funcion principal
//****************************************************************************

int main (void)
{
	system("color 76");
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
   int vec[N];
   
   do{
      system ("cls");
      printf("\n M  E   N   U");
	  printf("\n1.- 20 numeros aleatorios");
	  printf("\n2.- Buscar Secuencial/Binario");
	  printf("\n3.- Tabla de multiplicar");
	  printf("\n4.- Imprimir todo");
	  printf("\n0.- Salir");
	  printf("\nESCOGE UNA OPCION.");
      scanf ("%d",&op);
	  switch(op)
	    {
		  case 1: programa1(vec);	break;
		  case 2: programa2(vec);	break;
		  case 3: programa3(vec);	break;
		  case 4: programa4(vec);	break;
		}
   }while(op != 0);
}

//*******************************************************

//***********PROGRAMA QUE GENERA 20 NUMEROS ALEATORIOS 
void programa1(int vec[])
{
    system ("cls");

	int i,j,ale;
	srand(time(0));
	
	for(i = 0 ; i < N ; i++)
		{	
			//Genera un numero aleatorio entre 1 y 30
			ale = (1 + rand()% 30); 
			for(j = 0 ; j < N ; j++)
				{
					if(ale == vec[j])
						{
							ale = (1 + rand()% 30);
							j = -1;
						}
				}
			vec[i] = ale;
			printf("%d\n",vec[i]);
		}
	system("pause");
}
//***********Programa para buscar en el vector 
void programa2(int vec[])
{
	system("cls");
	int num,xnum,band = 0;
	
	printf("Ingrese el numero que desea buscar: ");
	scanf("%d",&num);
	
	if((vec[0] < vec[1]) && (vec[1] < vec[2]) && (vec[2] < vec[3]) && 
		(vec[3] < vec[4]) && (vec[4] < vec[5]) && (vec[5] < vec[6]))
	
		{
			printf("Metodo Binario\n");
			xnum = buscbin(vec,num);
			if(xnum > 0)
			{
				printf("El numero es: %d\n",xnum);
			}
			else
			{
				printf("El numero no existe");
			}
		}
		else
		{
			printf("Metodo secuencial\n");
			buscsec(vec,num);
		}
	system("pause");
}
//***********Programa que ordena un vector
void programa3(int vec[])
{
    system ("cls");
	
	
	
	system("pause");
}
//*************Programa que imprime todo el vector
void programa4(int vec[])
{
	
}
//******************Funcion para buscar por metodo binario
int buscbin(int vec[],int num)
{
	int central,med,bajo = 1,alto = N-1;
	
	while(bajo <= alto){
		med = (bajo+alto)/2;
		central = vec[med];
		if(num == central)
		{
			return(central);
		}
		else
		{
			if(num < central)
			{
				alto = central - 1;
			}
			else
			{
				bajo = central + 1;
			}
		}	
	}
	return -1;}
//******************Funcion para buscar por metodo secuencial
int buscsec(int vec[],int num)
{
	int i,x1,ubicado = 0;
	
	for(i = 0 ; i < N ; i++)
	{
		if(vec[i] == num)
		{
			ubicado = 1;
			printf("El numero %d esta ubicado en la posicion: [%d]\n",num,i+1);
		}
	}
			if(ubicado == 0)
			{
				printf("El numero no se encuentra en el vector\n");
			}
}
//************************************************************************
void delay(int tiempo)
{
  int i,j;
  for(i=0;i<tiempo*100;i++)
     {
	   for(j=0;j<tiempo*100;j++);
	 }
}

