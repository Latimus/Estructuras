//Manuel Alejandro Sahagun Mendoza 349857
//Generar Datos para Curp
//21 Mayo 2017
//SMMA_PR13 
//****************************************************************************
//    LIBRERIAS
//****************************************************************************

#include "Manuel.h"

//****************************************************************************
// PROTOTIPOS DE FUNCIONES
//****************************************************************************

void programa1(void);
void programa2(void);
void programa3(void);
void programa4(void);
void programa5(void);
void menu (void);
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
//Desarollo de las funciones en el mismo orden de como listamos los prototipos
//****************************************************************************

//*********FUNCION MENU DESDE DONDE SE MANDA LLAMAR LAS DEMAS FUNCIONES
void menu(void) {
	
  	int op;
   do{
      system ("cls");
      printf("\n M  E   N   U");
	  printf("\n1.- Agregar");
	  printf("\n2.- Eliminar");
	  printf("\n3.- Buscar");
	  printf("\n4.- Ordenar");
	  printf("\n5.- Mostrar Todo");
	  printf("\n0.- Salir\n");
	  validanum(48,57,"ESCOGE UNA OPCION.",&op);
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

//***********Agregar		(READY)
void programa1(void) {
    system ("cls");

	statu(&PO);
	genmat(&PO);
	randomNames(&PO);
	randapePat(&PO);
	randapeMat(&PO);
	nacimiento(&PO);
	estad(&PO);
	
	creacurp(&PO);
	BIN(&PO);
	
	system("pause");
}

//************Eliminar 		(READY)
void programa2(void) {
	system ("cls");
	
	ELI();
	
	system("pause");
}

//*************Buscar
void programa3(void) {
    system ("cls");
	long DEL;
	
	printf("Escriba la matricula que desea buscar\nMatricula:\t");
	validanu(48,57,"Matricula:\t",&DEL);
	busca(DEL);

	system("pause");
}

//*************Ordenar
void programa4(void) {
    system ("cls");

	ordena();
	
	system("pause");
}

//*************Mostrar Todo	(READY)
void programa5(void) {
    system ("cls");

	LEBIN();

	system("pause");
}



//************************************************************************
//************************************************************************
void delay(int tiempo)
{
  int i,j;
  for(i=0;i<tiempo*100;i++)
     {
	   for(j=0;j<tiempo*100;j++);
	 }
}
//*************************************************************************
//*************************************************************************

//	printf("(Acitvo:1,Inactivo:0):\t%d\n",vectorExmp[PO-1].status);
//	printf("Matricula:\t\t%d\n",vectorExmp[PO-1].matricula);
//	printf("Nombre:\t\t\t%s\n",vectorExmp[PO-1].nombre);
//	printf("Apellido Paterno:\t%s\n",vectorExmp[PO-1].apellidoP);
//	printf("Apellido Materno:\t%s\n",vectorExmp[PO-1].apellidoM);
//	printf("Fecha de Nacimiento:\t%s ",vectorExmp[PO-1].day);
//	printf("%s ",vectorExmp[PO-1].month);
//	printf("%s\n",vectorExmp[PO-1].year);
//	printf("(1:Hombre,2:Mujer):\t%d\n",vectorExmp[PO-1].sexo);
//	printf("Lugar de nacimiento:\t%s\n",vectorExmp[PO-1].estado);
