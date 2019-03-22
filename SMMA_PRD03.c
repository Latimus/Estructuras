//Manuel Alejandro Sahagun Mendoza 349857
//Loteria
//02 abril 2017
//SSMA_PROD03

#include <stdio.h>
#include <stdlib.h>
#define V 6

int llvec(int vec[],int ri, int rf);
int busq(int vec[],int aux[]);

int main(int argc, char *argv[])
{
	int i,vec[V] = {3,9,17,22,37,41};
	llvec(vec,1,57);
	system("pause");
	return 0;
}
int llvec(int vec[],int ri, int rf)
{
	int i,j,x,aux[V],bandera = 0;
	do{
		for(i = 0 ; i < V ; i++)
		{
			aux[i] = (rand() % (rf - ri)) + ri;
		}
		x = busq(vec,aux);
		if( x > 0)
		{
			j++;
			bandera = 1;
			printf("Loteria!!!\nIntento numero: %d",j);
		}
		else
		{
			j++;
		}
	}while(bandera == 0);
}
int busq(int vec[],int aux[])
{
	int i,j,loteria = 0; 
	for(i = 0 ; i < V ; i++)
	{
		if(((vec[i])==(aux[0])) || ((vec[i])==(aux[1])) || ((vec[i])==(aux[2]))
		|| ((vec[i])==(aux[3])) || ((vec[i])==(aux[4])) || ((vec[i])==(aux[5])))
		{
			j++;
			if( j == V )
			{
				return 1;	
			}
		}
		else
		{
			return -1;
		}
	}	
}
