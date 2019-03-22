#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#define N 3

typedef struct alum{
	char nombre [40];
	char apemat [40];
	char apepat [40];
	char *nom [100];
	int  edad;
	long mat;
	int  dato[100];
}Tdat;

void bub(Tdat aux[],Tdat vecm[]); 
void buscsec(Tdat vecm[],long num);
int age(void);
long genmat(void);
Tdat *genom(void);
void programa1(Tdat vecm[],Tdat vecn[],Tdat vece[]);
void programa2(Tdat vecm[]);
void programa3(Tdat aux[],Tdat vecm[]);
int programa4(void);
void menu (void);
void delay(int);

int main (void){
   menu();
   return 0;
}

void menu(void){
   int op;
   Tdat vecn[100],vecm[100],vece[100],aux[100];
   do{
      system ("cls");
      printf("\n M  E   N   U");
	  printf("\n1.- Agregar 5 alumnos");
	  printf("\n2.- Buscar por Matricula");
	  printf("\n3.- Ordenar");
	  printf("\n4.- Archivo");
	  printf("\n0.- Salir");
	  printf("\nESCOGE UNA OPCION.");
      scanf ("%d",&op);
	  switch(op)
	    {
		  case 1: programa1(vecm,vecn,vece);   	break;
		  case 2: programa2(vecm);  			break;
		  case 3: programa3(aux,vecm);  		break;
		  case 4: programa4();					break;
		}
   }while(op != 0);
}

//***********Agrega 5 Alumnos
void programa1(Tdat vecm[],Tdat vecn[],Tdat vece[]){
    system ("cls");
	
	FILE *arch = NULL;
	char *nomarch = "Fichero.txt";
	
	int i;
	Tdat reg,rmt,rge,SUP;
	
	printf("Matricula \tNom/Apat/Amat\t\tEdad\n\n");
//	arch = fopen(nomarch,"a");
//	fprintf(arch,"Matricula \tNom/Apat/Amat\t\tEdad\n\n");
//	fclose(arch);

	for(i = 0 ; i < 5 ; i++){
	rge.edad = age();
	rmt.mat = genmat();
	reg = *genom();
	vecn[i] = reg;
	vecm[i] = rmt;
	vece[i] = rge;
	
	arch = fopen (nomarch,"a");
	fprintf(arch , " %dl \t" , vecm[i].mat);
	fprintf(arch , " %s\t " , vecn[i].nombre);
	fprintf(arch , " %d\n " , vece[i].edad);
	fclose(arch);
		
	printf("%dl \t%s\t%d\n",vecm[i].mat,vecn[i],vece[i].edad);
	//printf("%dl \t%s\t%d\n",rmt.mat,reg.nombre,rge.edad);
	}

	system("pause");}

//***********Buscar  
void programa2(Tdat vecm[]){ 
	system ("cls");
	
	long num;
			
	printf("Ingrese la matricula que desea buscar: ");
	scanf("%dl",&num);
	
	buscsec(vecm,num);

	system("pause");
}

//***********Ordenar
void programa3(Tdat aux[],Tdat vecm[]){
    system ("cls");
	
	int i;
	
	bub(aux,vecm);
	
	for(i = 0 ; i < 100 ; i++){
		printf("%dl\n",aux[i].mat);	
	}
	
	system("pause");
}
//************Archivo
int programa4(void){
	
	system("cls");
	FILE* arch = NULL;
	char* nomarch = "Fichero.txt";
	char temp[80];
	int end = 0;
	
	arch = fopen(nomarch,"r");
	if(arch == NULL){
		printf("El archivo no existe");
		system("pause");
		return -1;
	}
	printf("Matricula \tNom/Apat/Amat\t\tEdad\n\n");
	
	end = fscanf(arch, "[^\n]" , &temp);
	
	//while(end != EOF){
		
		printf("%s\n",temp);
		end = fscanf(arch, "[^\n]" , &temp);	
	
	fclose(arch);
	system("pause");
}

//Funcion que genera nombres aleatorios
Tdat *genom(void){

	Tdat x;
	char nomp[100];
	
	char nom[30][30] = {"Manuel","Carlos","Fermin","Federico","Luis",
	"Jose","Lisa","Sandra","Maria","Lucia","Diana","Lorenzo",
	"Pedro","Angel","Marla","Gibran","Elver","Ignacio","Martin","Miranda"};
	
	char apem[30][30] = {" Sahagun"," Argaez", " Perez"," Hernandez"," Moxca",
	" Gonzalez"," Esparza"," Carranza", " Guerrero", " Montes"," Chu", " Parra",
	" Cardenas"," Ramirez"," Vargas"," Tellez"," Viramontes"," Martinez",
	" Parker"," Sanchez"};
	
	char apep[30][30] = {" Mendoza"," Mejia"," Gonzales"," Esparza"," Carrillo",
	" Monarrez"," Garcia"," Cardenas"," Perez"," Cruz"," Chico"," Sanchez",
	" Ramirez"," Montes"," Sanchez"," Perez"," Curiel"," Zertuche"," Gomez",
	" Vargas"};
	
	//srand(time(NULL));
	
	strcpy(nomp,nom[rand()%20]);
	strcat(nomp,apem[rand()%20]);
	strcat(nomp,apep[rand()%20]);
	strcpy(x.nombre,nomp);
}

long genmat(void){
	
	int i,j,dup;
	Tdat x;
	long matri,ale,vec[100];
	
	//srand(time(NULL));
	
	for(i = 0 ; i < 100 ; i++)
		{	
			ale = (300000 + rand()% 333999); 
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
return *vec;}

int age(void){
	
	Tdat x;
	
	//srand(time(NULL));
	
	x.edad = (18 + rand()%17);
	
return x.edad;}

void delay(int tiempo){
  int i,j;
  for(i=0;i<tiempo*100;i++)
     {
	   for(j=0;j<tiempo*100;j++);
	 }
}

void buscsec(Tdat vecm[],long num)			//Busqueda Secuencial
{
	int i,ubicado = 0;
	
	for(i = 0 ; i < 100 ; i++)
	{
		if(vecm[i].mat == num)
		{
			ubicado = 1;
			printf("El numero %d esta ubicado en la posicion: [%d]\n",num,i);
		}
	}
			if(ubicado == 0)
			{	
				printf("El numero no se encuentra en el vector\n");
			}
}

void bub(Tdat aux[],Tdat vecm[]) 			//Ordenar por burbuja
{
	int i,j;
	long temp;
	
	for(i = 0 ; i < 100 ; i++){
		aux[i].mat = vecm[i].mat;
	}
	
	for (i = 1 ; i < 100 ; i++)
	{
    	for (j = 0 ; j < (99) ; j++)
     		{
           		if ((aux[j].mat) > (aux[j+1].mat))
           		{
                	temp = aux[j].mat;
                	aux[j].mat = aux[j+1].mat;
                	aux[j+1].mat = temp;
            	}
            }
        }
}

