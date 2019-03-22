//Manuel Alejandro Sahagun Mendoza 349857
//SMMA_09
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 450
#define A 10

typedef struct alumno {
	int status;
	long matricula;
	char nombre[10];
	char apellidoP[10];
	char apellidoM[10];
	int edad;
	char *sexo;
}Tdat;

struct alumno vectorExmp[N];
struct alumno vectorAux[N];

int st = 0;
int mat = 0;
int no = 0;
int app = 0;
int apm = 0;
int ed = 0;

void bub(void);						//Ordenar por burbuja
long binario(long num);				//Busqueda Binaria
void secuencial(long num);			//Busqueda secuencial
void randomNames(int *tam);         //Nombres aleatorios
void randapePat(int *tam);          //Apellidos Paternos
void randapeMat(int *tam);          //Apellidos Maternos
void age(int *tam);                 //Edad                  
void genmat(int *tam);;             //Matriculas
void status(int *tam);				//Estado
void programa1(void);				//Agregar
void programa2(void);				//Buscar
void programa3(void);				//Ordenar
void programa4(void);				//Ver todo
void programa5(void);				//Archivo
void menu(void);					//Menu de Funciones
void delay(int);

int main(void) {
	
	menu();
	return 0;
}

void menu(void) {
	int op;

	do {
		system("cls");
		printf("\n M  E   N   U");
		printf("\n1.- Agregar 10 alumnos");
		printf("\n2.- Buscar por Matricula");
		printf("\n3.- Ordenar");
		printf("\n4.- Mostrar Todo");
		printf("\n5.- Archivo");
		printf("\n0.- Salir");
		printf("\nESCOGE UNA OPCION.");
		scanf("%d", &op);
		switch (op)
		{
		case 1: programa1();       break;
		case 2: programa2();       break;
		case 3: programa3();       break;
		case 4: programa4();       break;
		case 5: programa5();       break;
		}
	} while (op != 0);
}

//*****************************************************Agrega 10 Alumnos
void programa1() { 
	system("cls");
	int i;
		status(&st);
		genmat(&mat);
		randomNames(&no);
		randapePat(&app);
		randapeMat(&apm);
		age(&ed);

		for(i=0; i<st; i++) {
		vectorAux[i].matricula = vectorExmp[i].matricula;	
		}
	//printf("%d",st);
	system("pause");
}

//*****************************************************Buscar
void programa2() {
	system("cls");
	int band = 0,i,op;
	long num,xnum;
	printf("Ingrese la matricula que desea buscar (6 numeros) : ");
	scanf("%dl",&num);
	printf("Metodo de busqueda que desea utilizar\n");
	printf("\n1.- Secuencial\n2.- Binaria\n");
	printf("Elija una opcion: ");
	scanf("%d", &op);

	if (op == 1) {
		secuencial(num);
	}
	else {

		if ((vectorAux[0].matricula < vectorAux[1].matricula) && (vectorAux[1].matricula < vectorAux[2].matricula)
			&& (vectorAux[2].matricula < vectorAux[3].matricula) && (vectorAux[3].matricula < vectorAux[4].matricula)
			&& (vectorAux[4].matricula < vectorAux[5].matricula) && (vectorAux[5].matricula < vectorAux[6].matricula)) {

			printf("Metodo Binario\n");
			xnum = binario(num);
			if (xnum > 0)
			{
				printf("La matricula es: %d\n", xnum);
			}
			else
			{
				printf("El numero no existe\n");
			}
		}
		else
		{
			printf("El vector no esta ordenado\n");
		}
	}
	system("pause");
}

//*****************************************************Ordenar
void programa3() {
	system("cls");
	int op,i;

	printf("Metodo de ordenamiento que desea utilizar:\n");
	printf("\n1.- Burbuja\n2.- Shell\n");
	printf("Elija una opcion:");
	scanf("%d", &op);

	for (i = 0; i < N; i++) {
		vectorAux[i].matricula = vectorExmp[i].matricula;
	}

	if (op == 1) {
		bub();
	}
	/*else {
		shell();
	}*/




	system("pause");
}

//*****************************************************Mostrar todo
void programa4(void) {
	system("cls");
	int i=0;
	
	printf("Estado\tMatricula\tNombre/ApePaterno/ApeMaterno\tEdad\tSexo\n");
for(i=0; i<st; i++) {
		printf("%d\t%d\t\t%s%s %s\t\t%d\t%s\n",vectorExmp[i].status,
		vectorExmp[i].matricula,vectorExmp[i].nombre,vectorExmp[i].apellidoP,
		vectorExmp[i].apellidoM, vectorExmp[i].edad, vectorExmp[i].sexo);
		}
	system("pause");
}

//*****************************************************Archivo
void programa5(void){
	
}

//Funcion que genera nombres aleatorios
void randomNames(int *tam) {
	int x = 0,j, r = 0;
//	srand(time(NULL));
//	x = (1 + (rand() % 2) - 1);

	char nom[20][10] = {"Manuel ","Carlos ","Fermin ","Fede ","Luis ",
	"Jose ","Antonio ","Sandro ","Mario ","Lucio ","Daniel ","Lorenzo ",
	"Pedro ","Angel ","Fabian ","Gibran ","Elver ","Ignacio ","Martin ",
	"Ferni "};
	char nomf[20][10] = {"Miri ","Sandra ","Maria ","Lucia ","Diana ",
	"Marla ","Chunli ","Karla ","Josefa ","Antonia ","Daniela ","Lore ",
	"Petra ","Angela ","Pamela ","Laura ","Katia ","Sami ","Ana ","Karen "};

	for (j = *tam; j<(A+*tam) ; j++) {
//		srand(time(NULL));
		x = (1 + (rand() % 2) - 1);
		r = (1 + (rand() % 20) - 1);
		if (x == 1) {
			strcpy(vectorExmp[j].nombre,nom[r]);
			vectorExmp[j].sexo = "H";
		}
		else {
			strcpy(vectorExmp[j].nombre,nomf[r]);
			vectorExmp[j].sexo = "M";
		}
	}
	*tam = *tam + A;
}

//Funcion que genera apellidos paternos aleatorios
void randapePat(int *tam) {
	int x, i;

	char apep[20][10] = { "Mendoza","Mejia","Chupi","Esparza",
	"Carril","Monrez","Garcia","Cardena","Perez","Cruz","Chico",
	"Sanchez","Ramirez","Montes","Sanchez","Perez","Curiel","Zertus",
	"Gomez","Vargas" };

	for (i = *tam; i<(A+*tam) ; i++) {
		//srand(time(NULL)); //Semilla aleatoria
		x = (rand() % 20);
		strcpy(vectorExmp[i].apellidoP,apep[x]);
	}
	*tam = *tam + A;
}

//Funcion que genera apellidos maternos aleatorios
void randapeMat(int *tam) {
	int x, i;

	char apem[20][10] = { "Sahagun","Argaez","Perez","Hendo","Moxca",
		"Gonzalo","Guino","Carol","Guerra", "Montes","Chunli",
		"Parra","Cardes","Ramir","Vargas","Tellez","Folgi","Odino",
		"Parker","Galarga"};

	for (i = *tam; i<(A+*tam) ; i++) {
		//srand(time(NULL)); //Semilla aleatoria
		x = (rand() % 20);
		strcpy(vectorExmp[i].apellidoM,apem[x]);
	}
	*tam = *tam + A;
}

//Funcion que genera Matriculas aleatorias sin repetir
void genmat(int *tam) {
	int i, j, dup;
	long ale;

	for (i = *tam; i<(A+*tam); i++) {
	//	srand(time(NULL)); 
		ale = (300000 + rand() % 333999);
		dup = 0;
		for (j = 0; j<i; j++) {
			if (ale == vectorExmp[j].matricula)
			{
				dup = 1;
			}
		}
		if (dup == 1)
		{
			i--;
		}
		else
		{
			vectorExmp[i].matricula = ale;
		}
	}
	*tam = *tam + A;
}

//Funcion que genera edades aleatorias
void age(int *tam) {
	int x, i;

	for (i = *tam; i<(A+*tam) ; i++) {
		x = (18 + rand() % 10);
		vectorExmp[i].edad = x;
	}
	*tam = *tam + A;
}

//Funcion que busca una matricula (Metodo Binario)
long binario(long num) {
	long central, med, bajo = 1, alto = st - 1;
	
	while (bajo <= alto) {
		med = (bajo + alto) / 2;
		central = vectorAux[med].matricula;
		if (num == central)
		{
			return(central);
		}
		else
		{
			if (num < central)
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

//Funcion que busca una matricula (Metodo Secuencial)
void secuencial(long num) {
	int i, ubicado = 0;

	for (i = 0; i < st; i++)
	{
		if (vectorAux[i].matricula == num)
		{
			ubicado = 1;
			printf("El numero %dl esta ubicado en la posicion: [%d]\n", num, i + 1);
		}
	}
	if (ubicado == 0)
	{
		printf("El numero no se encuentra en el vector\n");
	}
}

//Funcion que ordena el indice de matriculas (Burbuja)
void bub(void) { 
	int i, j;
	long temp;

	for(i = 1; i < st; i++) {
		for (j = 0; j < (st - 1); j++)
		{
			if ((vectorAux[j].matricula) > (vectorAux[j + 1].matricula))
			{
				temp = vectorAux[j].matricula;
				vectorAux[j].matricula = vectorAux[j + 1].matricula;
				vectorAux[j + 1].matricula = temp;
			}
		}
	}
}

//Funcion que agrega un status = 1 al registro
void status(int *tam){
	int s=1, j=0;
	
	for(j = *tam; j<(A+*tam); j++){
	vectorExmp[j].status = s;

	}
	*tam = *tam + A;
	return;}



void delay(int tiempo) {
	int i, j;
	for (i = 0; i<tiempo * 100; i++)
	{
		for (j = 0; j<tiempo * 100; j++);
	}
}
