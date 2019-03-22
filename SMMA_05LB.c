#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//agregar 5 nombres autom
//Imprimir (tdos)

typedef struct tdato{
	long matri;
	char nombre[60];
	int edad;
	int sexo;
}Talum;

int buscar(Talum alumno[],int datos,int n);
char *generar(int sexo);
Talum datos(void);
void impdato(Talum reg);
void programa2(void);
void menu(void);

int main(int argc, char *argv[]) {
	
	menu();

	return 0;
}

void menu(void){
	
	system("cls");
	int op,lim = 0,i,ban = 0,matric,busq;
	Talum registro[100];
	do{
	system("cls");	
		
	printf("\tM\tE\tN\tU\n");
	printf("\n1.- Agregar");
	printf("\n2.- Imprimir");
	printf("\n3.- Buscar");
	printf("\n4.- Ordenar");
	printf("\n0.- Salir\n\t\t");
	scanf("%d",&op);
	switch(op){
		
		case 1: 
		system("cls");
		if(lim <= 95)
		{
			for(i = 0; i < lim+5 ; i++)
			{
				registro[i]	= datos();
				impdato(registro[i]);
			}
			lim = lim + 5;	
		}
			else
			{
				printf("Ha sobre pasado el limite de registros");	
			}
		system("pause"); 
		break;
		case 2: 
		system("cls");
		for(i = 0 ; i < lim ; i++)
		{
			impdato(registro[i]);	
		}
		system("pause");
		; 
		break;
		case 3:
		system("cls");	
		printf("\nInserta la matricula que quieres buscar");
		scanf("%d",&matric);
        system("cls");
        busq = buscar(registro,matric,lim);
		if(busq==-1)
               {
               printf("\n La Matricula no ha sido encontrada");
               getch();
               }
            else
               {
               printf("\nLa Matricula esta en la posicion %d\n",busq); 
			   impdato(registro[busq]);  		
                system("pause");
               }
              
		;
		break;
		}
	}while(op != 0);
}

//**********************************
	Talum datos(void)
	{
	Talum reg;
	
	reg.matri = 300000+(rand()%250000+rand()%15000);
	strcpy(reg.nombre,generar((rand()%10000)%2));
	reg.edad=(rand()%60)+5;
	
	return reg;}
//***********************************


void impdato(Talum alumno)
{
	printf("%ld\t\t%s\t\t%d\n",alumno.matri,alumno.nombre,alumno.edad);
}

int buscar(Talum alumno[],int datos,int n)
{	
	int i;
  	for(i=0;i<n;i++)
  		{
    		if(alumno[i].matri == datos)
    		{
    			return(i+1);
    		}
  		}
  	 return -1;
}

char *generar(int sexo)
{
	
	char Apellido[20][30] = {
	 " Garcia ",
	 " Gonzalez ",
	 " Orozco ", 
	 " Rodriguez ", 
	 " Ortiz ", 
	 " Hernandez ", 
	 " Fernandez ", 
	 " Campos ", 
	 " Montenegro ", 
	 " Perez ", 
	 " Gutierrez ", 
	 " Aguilar ", 
	 " Medina ", 
	 " Marquez ", 
	 " Cardenas "};
    char NomHombre[20][30] = {
	"Federico ",
	"Juan ",
	"Fermin ",
	"Ramon ",
	"Alex ",
	"Socrates ",
	"Pipin ",
	"Frodo ",
	"Manuel ",
	"Gandalf ",
	"Goku ",
	"Astroboy ",
	"Felipo ",
	" ",
	"Carlos "};
    char NomMujer[20][30] = {
	"karla ", 
	"Federica ", 
	"Miranda ", 
	"Josefa ", 
	"Paula ", 
	"Marimar ", 
	"Rosa ", 
	"Estefania ", 
	"Diana ", 
	"Alejandra ", 
	"Valeria ", 
	"Isabel ", 
	"Sofia ", 
	"Lucinda ", 
	"Marla "};
    char Nombre[50];
     
    if(sexo == 0)
      {       
        strcpy(Nombre,NomHombre[(rand()%500)%15]);
      }
    else
      {
        strcpy(Nombre,NomMujer[(rand()%500)%15]);
      }       
	   
      strcat(Nombre,Apellido[rand()%15]);
      strcat(Nombre,Apellido[rand()%15]);      
      return Nombre;}
