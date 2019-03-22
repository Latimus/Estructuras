//Manuel Alejandro Sahagun Mendoza 349857
//SMMA_09



#include "Manuellibreria.h"


void menu(void);					//Menu de Funciones

void delay(int);

//*****************************************************Funcion Principal
int main(void) {
	
	menu();
	return 0;
}

//*****************************************************Menu
void menu(void) {
	int op;

	do {
		system("cls");
		printf("\n M  E   N   U");
		printf("\n1.- Agregar 10 alumnos");
		printf("\n2.- Buscar por Matricula");
		printf("\n3.- Ordenar (vector)");
		printf("\n4.- Mostrar Todo");
		printf("\n\nFUNCIONES CON ARCHIVOS BINARIOS\n\n");
		printf("\n5.- Agregar datos anteriores al archivo binario");
		printf("\n6.- Mostrar todo (Binario)");
		printf("\n7.- Eliminar");
		printf("\n8.- Compactar");
		printf("\n9.- Buscar Binario");
		printf("\n10.- Mostrar borrados");
		printf("\n0.- Salir");
		printf("\nESCOGE UNA OPCION.");
		scanf("%d", &op);
		switch (op)
		{
		case 1: programa1();	break;
		case 2: programa2();	break;
		case 3: programa3();	break;
		case 4: programa4();	break;
		case 5: programa5();	break;
		case 6: programa6();	break;
		case 7: programa7();	break; 
		case 8: programa8();	break; 
		case 9: programa9();	break;
		case 10: programa10();	break;	
		}
	} while (op != 0);
}





