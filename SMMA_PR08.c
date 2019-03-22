//Manuel Alejandro Sahagun Mendoza 349857
//Ordenamiento y busqueda, Estadisticas de fuciones
//06 abril 2017
//SMMA_PR08
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define V 500
#define R 800

int  buscbin(int aux[],int num,int p);
void stad(int z,int p,int y,int w);
void selec(int aux[],int w);
void buscsec(int vec[],int num,int z);
void bub(int aux[],int y);
void impaux(int aux[]);
void llvec(int vec[]);
void imp(int vec[]);
void buscar(int vec[],int aux[],int z,int p);
void ordenar(int vec[],int aux[],int y,int w);
void delay(int);
void menu (void);

int main (void)									//Funcion Principal
{
   menu();
   return 0;
}
void menu(void)									//Menu 
{
   int op,vec[V],aux[V];
   int z,p,y,w;		//variables para contabilizar procesos
   do{
      system ("cls");
      printf("\n\tM  E   N   U");
	  printf("\n1.- Llenar Vector");
	  printf("\n2.- Buscar");  //a)Secuencial b)Binaria
	  printf("\n3.- Ordenar"); //a)Burbuja	b)Seleccion
	  printf("\n4.- Imprimir");
	  printf("\n5.- Estadisticas");
	  printf("\n0.- Salir");
	  printf("\nESCOGE UNA OPCION.");
      scanf ("%d",&op);
	  switch(op)
	    {
		  case 1: llvec(vec);    		break;
		  case 2: buscar(vec,aux,z,p);  break;
		  case 3: ordenar(vec,aux,y,w);	break;
		  case 4: imp(vec);		 		break;
		  case 5: stad(z,p,y,w);		break;
		}
   }while(op != 0);
}
void llvec(int vec[])							//Llenar Vector
{
    system ("cls");
	int i,j,ale,dup;
	srand(time(0));
	
	for(i = 0 ; i < V ; i++)
		{	
			ale = (1 + rand()% R); 
			dup = 0;
			for(j = 0 ; j < i ; j++)
			{
				if(ale == vec[j])
				{
				 dup = 1;	
				}
			}
			if(dup == 1)
			{
				i--;
			}
			else
			{
				vec[i] = ale;
			}
		}
	printf("Vector ahora esta lleno\n");
	printf("Presione cualquier tecla para continuar...");
	getch();
}
void buscar(int vec[],int aux[],int z,int p)	//Buscar
{
	system ("cls");
	int num,op,x;
	printf("Ingrese el numero que desea buscar: ");
	scanf("%d",&num);
	printf("Metodo de busqueda que desea utlizar: ");
	printf("\n1.- Secuencial\n2.- Binaria\n");
	printf("Elija una opcion: ");
	scanf("%d",&op);
	if(op == 1)
	{
		buscsec(vec,num,z);
	}
	else
	{
		if(((aux[0])<(aux[1]))&&((aux[1])<(aux[2]))&&((aux[2])<(aux[3]))&&
		((aux[3])<(aux[4]))&&((aux[4])<(aux[5]))&&((aux[5])<(aux[6]))&&
		((aux[6])<(aux[7]))&&((aux[7])<(aux[8])))
		{
			x =	buscbin(aux,num,p); 
			if(x < 0)
			{
				printf("El numero no se encuentra en el vector");
			}
			else
			{
				printf("Numero que mas aproximado al que busco es: %d",x);
			}
		}
		else
		{
			printf("El vector no esta ordenado");
		}
	}
	
	printf("\nPresione cualquier tecla para continuar...");
	getch();
}
void ordenar(int vec[],int aux[],int y,int w)	//Ordenar
{
    system("cls");
    
    int i,temp,op;
    
    for(i = 0 ; i < V ; i++)
	{
		temp = vec[i];
		aux[i] = temp;
	}
	printf("Seleccione el metodo de ordenamiento que desee utilizar");
	printf("\n1.-Burbuja\n2.-Seleccion\nElija una opcion\n");
	scanf("%d",&op);
	if(op == 1)
	{
    	bub(aux,y);
    	impaux(aux);
    	printf("El vector ahora esta ordenado\n");
	}
    else
    {
    	selec(aux,w);
    	impaux(aux);
    }
	printf("Presione cualquier tecla para continuar...");
	getch();	
}
void imp(int vec[])								//Imprimir Vector
{
	system("cls");
	
	int i;
	
	for(i = 0 ; i < V ; i++)
	{
		printf("%d\n",vec[i]);
	}
	printf("Presione cualquier tecla para continuar...");
	getch();
}
void buscsec(int vec[],int num,int z)			//Busqueda Secuencial
{
	int i,x1,ubicado = 0;
	z = 0;
	for(i = 0 ; i < V ; i++)
	{
		z++;
		if(vec[i] == num)
		{
			z++;
			ubicado = 1;
			printf("El numero %d esta ubicado en la posicion: [%d]\n",num,i);
		}
	}
			if(ubicado == 0)
			{	
				z++;
				printf("El numero no se encuentra en el vector\n");
			}
}
int buscbin(int aux[],int num,int p)			//Busqueda Binaria
{
	int med,bajo = 0,alto = V-1;
	p = 0;
	while(bajo <= alto){
		p++;
		med = ((alto - bajo) / 2) + bajo;
		p++;
		if((aux[med]) == num)
		{
			p++;
			return(med);
		}
		else
		{
			p++;
			if(num < (aux[med]))
			{
				p++;
				alto = med - 1;
			}
			else
			{
				p++;
				bajo = med + 1;
			}
		}	
	}
	p++;
	return -1;}
void bub(int aux[],int y) 						//Ordenar por burbuja
{
	int i,j,temp;
	y = 0;
	
	for (i = 1 ; i < V ; i++)
	{
		y++;
    	for (j = 0 ; j < (V-1) ; j++)
     		{
     			y++;
           		if ((aux[j]) > (aux[j+1]))
           		{
           			y++;
                	temp = aux[j];
                	y++;
                	aux[j] = aux[j+1];
                	y++;
                	aux[j+1] = temp;
                	y++;
            	}
            }
        }
}
void impaux(int aux[])							//Imprime la matriz auxiliar
{
	system("cls");
	
	int i;
	
	for(i = 0 ; i < V ; i++)
	{
		printf("%d\n",aux[i]);
	}	
}
void selec(int aux[],int w)						//Ordenamiento por seleccion
{
	system("cls");
	int i,j,min,temp;
	w = 0;
	for(i = 0 ; i < (V - 1) ; i++)
	{
		w++;
		min = i;
		w++;
		for(j = (i + 1) ; j < V ; j++)
		{
			w++;
			if(aux[j] < aux[min])
			{
				w++;
				min = j;
			}
		}
		if(i != min)
		{
			w++;
			temp = aux[i];
			w++;
			aux[i] = aux[min];
			w++;
			aux[min] = temp;
			w++;
		}
	}
}
void stad(int z,int p,int y,int w)				//Estadisticas de procesos
{
	system("cls");
	
	printf("\t\t   Estadisticas");
	printf("\n===================================================\n");
	printf("\nMetodos de busqueda\t\tNumero de procesos\n");
	printf("\nSecuencial\t\t\t %d",z);
	printf("\nBinario\t\t\t\t %d",p);
	printf("\n\nMetodos de ordenamiento\t\tNumero de procesos\n");
	printf("\nBurbuja\t\t\t\t %d",y);
	printf("\nSeleccion\t\t\t %d",w);

	printf("\n\nPresione cualquier tecla para continuar...");
	getch();	
}
void delay(int tiempo)
{
  int i,j;
  for(i=0;i<tiempo*100;i++)
     {
	   for(j=0;j<tiempo*100;j++);	
	 }
}


