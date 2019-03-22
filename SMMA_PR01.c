//Manuel Alejandro Sahagun Mendoza	349857
//Programa que realice 5 funciones, factorial, serie, tablas, factorial y serie con do/while
//21 Febrero 2017
//SMMA_PR01
//***************************************************************************************
//    LIBRERIAS
//**************************************************************************************

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
void programa4(void);
void programa5(void);
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
	  printf("\n1.- Factorial");
	  printf("\n2.- Seria de numeros");
	  printf("\n3.- Tabla de multiplicar");
	  printf("\n4.- Factorial do/while");
	  printf("\n5.- Serie de numeros do/while");
	  printf("\n0.- Salir");
	  printf("\nESCOGE UNA OPCION.");
      scanf ("%d",&op);
	  switch(op)
	    {
		  case 1: programa1();  break;
		  case 2: programa2();  break;
		  case 3: programa3();  break;
		  case 4: programa4();  break;
		  case 5: programa5();  break;
		}
   }while(op != 0);
}

//**************************************************************************************

//***********FACTORIAL
void programa1(void)
{
    system ("cls");
	
	int i,j,fac,num;

	printf("Ingrese el numero del cual se quiere conocer su factorial: ");
	scanf("%d",&num);
	
	if(num>20)
	{
		printf("ingrese un numero del 0 al 20");
	}
	else
	{
		j=1;
		for( i=2 ; i<num+1 ; i++)
		{
			fac = j*i;
			printf("%d x %d = %d\n",j,i,fac);
			j=fac;
		}
		printf("Factorial 5 = %d\n",fac);
	}	
	system("pause");
	
	}

//**************************************************************************************

//***********SERIE DE NUMEROS
void programa2(void)
{
   system ("cls");
   
    int vi,vf,te,i,ser;
    
    printf("Dame el valor inicial de la serie de nuemros: ");
    scanf("%d",&vi);
    printf("Dame el valor final de la seria de numeros: ");
    scanf("%d",&vf);
    printf("Dame el valor del intervalo: ");
    scanf("%d",&te);
    
    if(vf<vi)
    {
    	printf("El valor final debe ser mayor que el valor inicial");
    }
    else
	{
		ser=vi;
    	for( i=vi ; i<vf ; i+=te) // i = i + te
    	{
    		
    		printf(" %d \n",i);
    		
    		
    		
		}
    }

	system("pause");


}

//**************************************************************************************

//***********PROGRAMA QUE IMPRIME LA TABLA DE MULTIPLICAR DE UN NUMERO DADO
void programa3(void)
{
    system ("cls");
	
	int num,i,mult;
	
	printf("Dame el numero del que quieres su tabla de multiplicar: ");
	scanf("%d",&num);
	
	for( i=1 ; i<11 ; i++ )
	{
		mult=num*i;
		printf(" %d x %d = %d \n",num,i,mult);
		
	}
	
	
	system("pause");

}

//************************************************************************

//***********************************************************************
void programa4(void)
{
    system ("cls");
	
	int i,j,fac,num;

	printf("Ingrese el numero del cual se quiere conocer su factorial: ");
	scanf("%d",&num);
	
	if(num>20)
	{
		printf("ingrese un numero del 0 al 20");
	}
	else
	{
		j=1;
		i=2;
		do{
			
			fac = j*i;
			printf("%d x %d = %d\n",j,i,fac);
			
			j=fac;
			i++;	
			
		}while(i<num+1);
	}	


	system("pause");

}
//*****************************************************************************

//******************************************************************************

void programa5(void)
{
    system ("cls");

	int vi,vf,in,i,ser;
    
    printf("Dame el valor inicial de la serie de nuemros: ");
    scanf("%d",&vi);
    printf("Dame el valor final de la seria de numeros: ");
    scanf("%d",&vf);
    printf("Dame el valor del intervalo: ");
    scanf("%d",&in);
	ser=vi;
	if(vi>vf)
	{
		printf("El valor final debe ser mayor que el valor inicial");
	}
	else
	{
		do{
		
			printf(" %d \n",ser);
			ser=vi+in;
			vi=ser;
		
		}while(ser<vf);
	}
	system("pause");

}

//*******************************************************************************

//******************************************************************************
void delay(int tiempo)
{
  int i,j;
  for(i=0;i<tiempo*100;i++)
     {
	   for(j=0;j<tiempo*100;j++);
		

	 }
}
