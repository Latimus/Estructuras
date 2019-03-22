

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define N 450
#define A 10

typedef struct alumno {
	int status;
	long matricula;
	char nombre[10];
	char apellidoP[10];
	char apellidoM[10];
	int edad;
	int sexo;
} Tdat;

struct alumno vectorExmp[N];
struct alumno vectorAux[N];
struct alumno vectorBin[N];
struct alumno vecBorra[N];

typedef struct detalles {
	char fech[128];
	char motivo[200];
	char quien[60];
} dtll;

struct detalles vecdet[N];

int st  = 0;
int mat = 0;
int no  = 0;
int app = 0;
int apm = 0;
int ed  = 0;
int de 	= 0;



void randomNames(int *tam);         //Nombres aleatorios
void randapePat(int *tam);          //Apellidos Paternos
void randapeMat(int *tam);          //Apellidos Maternos
void age(int *tam);                 //Edad                  
void genmat(int *tam);;             //Matriculas
void status(int *tam);				//Estado
void leerdet(int *pos);				//Captura los detalles de eliminacion

void bub(void);						//Ordenar por burbuja
long binario(long num);				//Busqueda Binaria
void secuencial(long num);			//Busqueda secuencial
char *fecha(void);					//Fecha del sistema
void programa1(void);				//Agregar
void programa2(void);				//Buscar
void programa3(void);				//Ordenar
void programa4(void);				//Ver todo
void programa5(void);				//Archivo Binario
void programa6(void);				//Mostrar Binario
int  programa7(void);				//Eliminar (logico)
void programa8(void);				//Compactar
void programa9(void);				//Buscar Binario
void programa10(void);				//Mostrar Borrados
Tdat busB(char *FileName,long mat); //Buscar en archivo binario

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
		vectorAux[i] = vectorExmp[i];	
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

		if ((vectorAux[0].matricula < vectorAux[1].matricula) && 
			(vectorAux[1].matricula < vectorAux[2].matricula) && 
			(vectorAux[2].matricula < vectorAux[3].matricula) && 
			(vectorAux[3].matricula < vectorAux[4].matricula) && 
			(vectorAux[4].matricula < vectorAux[5].matricula) && 
			(vectorAux[5].matricula < vectorAux[6].matricula)) {

			printf("Metodo Binario\n");
			xnum = binario(num);
			if (xnum > 0)
			{
				printf("La matricula esta en la posicion: %d\n", xnum);
			}
			else
			{
				printf("La matricula no existe\n");
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
		printf("%d\t%d\t\t%s%s %s\t\t%d\t%d\n",vectorAux[i].status,
		vectorAux[i].matricula,vectorAux[i].nombre,vectorAux[i].apellidoP,
		vectorAux[i].apellidoM, vectorAux[i].edad, vectorAux[i].sexo);
		}
	system("pause");
}

//*****************************************************Agregar Binario
void programa5(void) {
	system("cls");
	Tdat reg;
	FILE *arch;
	int i;
	
	arch = fopen("Datos.dat","wb");
	
	for(i=0; i<st; i++) {
		reg = vectorAux[i];
		fwrite(&reg,sizeof(Tdat),1,arch);		
	}
	fclose(arch);
	printf("Se han agregado los datos al archivo\n");
	system("pause");
}

//*****************************************************Mostrar Todo (binario)
void programa6(void) {
	system("cls");
	
	Tdat reg;
	FILE *leer;
	int i,j=0;
	
	leer = fopen("Datos.dat","rb+");		
	
	fseek(leer, SEEK_SET, 1);
	
	while(!(feof(leer))) {		
		fread(&reg,sizeof(Tdat),1,leer);
		vectorBin[j++] = reg;
		}
	fclose(leer);
	printf("\t\t\tLista de usuarios activos\n\n");
	printf("Estado\tMatricula\tNombre/ApePaterno/ApeMaterno\tEdad\tSexo\n\n");
	for(i=0; i<(j-1); i++) {
	printf("%d\t%d\t\t%s%s %s\t\t%d\t%d\n",vectorBin[i].status,
			vectorBin[i].matricula, vectorBin[i].nombre, vectorBin[i].apellidoP,
			vectorBin[i].apellidoM, vectorBin[i].edad, vectorBin[i].sexo);
		}
	system ("pause");
}

//*********************************************Funcion que elimina logicamente
int programa7(void) {
	system("cls");
	Tdat reg;
	FILE *arch,*leer;
	int i=0,ubicado=0,op,j=0,k=0;
	long DEL;


		leer = fopen("Datos.dat","rb+");
		fseek(leer, SEEK_SET, 1);
	
		while(!(feof(leer))) {		
		fread(&reg,sizeof(Tdat),1,leer);
		vectorBin[j++] = reg;
		}
		fclose(leer);
		printf("Ingrese la matricula que desea eliminar\n");
		scanf("%dl",&DEL);
		
		
		
		for(i=0; i<j; i++) {
			k++;
		if(DEL == vectorBin[i].matricula) {
		printf("El dato que desea eliminar es correcto?\nElija una opcion:\n");
		printf("1.-Si\n2.-No\n\n");	
	//Imprime los datos que desea eliminar	
		printf("Estado (1 = Activo, 0 = Inactivo):\t%d\n",
		vectorBin[i].status);
		printf("Matricula:\t\t\t\t%d\nNombre:\t\t\t\t\t%s%s %s\n",
		vectorBin[i].matricula, 
		vectorBin[i].nombre, vectorBin[i].apellidoP, 
		vectorBin[i].apellidoM);
		printf("Edad:\t\t\t\t\t%d\nSexo (1 = Hombre, 0 = Mujer):\t\t%d\n",
		vectorBin[i].edad, vectorBin[i].sexo);
	//*******************************************************
		arch = fopen("Datos.dat","rb+");
		fseek(arch, SEEK_SET, 0);
		scanf("%d",&op);
		if(op == 1){
			leerdet(&de);
			vectorBin[i].status = 0;
			fseek(arch, SEEK_SET, k);
			fwrite(&vectorBin,sizeof(Tdat),k,arch);

			fclose(arch);
		}
		else
			{
			fclose(arch);
			return 0;
			}
			ubicado = 1;
			}
		}	
		if(ubicado == 0){
			printf("La matricula no existe\n");	
		}
	system("pause");
}
//**********************************Funcion para compactar los estados activos
void programa8(void) {
	system("cls");
	FILE *Temp,*arch;
	Tdat reg;
	
	Temp = fopen("Filetemp.tmp","wb");
	arch = fopen("Datos.dat","rb");
	rewind(arch);
	if(arch) {
	while(fread(&reg,sizeof(Tdat),1,arch)) {
		if(reg.status == 1) {
			fwrite(&reg,sizeof(Tdat),1,Temp);		
		}
	
	}
		fclose(Temp);
		fclose(arch);
		remove("Datos.bak");
		rename("Datos.dat","Datos.bak");
		rename("Filetemp.tmp","Datos.dat");
	}
	else{
		printf("No se puede compactar, el archivo no existe\n");
	}
	printf("Compactado con exito\n");
	system("pause");
}

//Funcion que busca un dato en una arvhivo binario*********************
void programa9(void) {
	system("cls");
	long mat;
	Tdat reg;
	printf("Ingrese la matricula del usuario que desea buscar\n\n");
	printf("Matricula:\t");
	scanf("%dl",&mat);
	
	reg = busB("Datos.dat",mat);
	if(reg.status == 1 && reg.matricula == mat) {
		printf("Informacion del usuario\n\n");
		printf("Matricula:\t\t%d\n",reg.matricula);
		printf("Nombre:\t\t\t%s\n",reg.nombre);
		printf("Apellido Paterno:\t%s\n",reg.apellidoP);
		printf("Apellido Materno:\t%s\n",reg.apellidoM);
		printf("Edad:\t\t\t%d\n",reg.edad);
		printf("Sexo:\n(1 = Hombre)\n(2 = Mujer):\t\t%d\n",reg.sexo);
		
	}
	else {
	printf("El usuraio con esa matricula no existe o ha sido borrado");
	}
	
	system("pause");
}

//Funcion que muestra los archivos borrados
void programa10(void) {
	system("cls");
	dtll rag;
	Tdat reg;
	FILE *ler,*arch;
	int i,op,mos,j=0,k=0;
	
	ler = fopen("Datos.bak","rb+");		
	fseek(ler, SEEK_SET, 0);
	
	while(!(feof(ler))) {		
		fread(&reg,sizeof(Tdat),1,ler);
		if(reg.status == 0){
		vecBorra[j++] = reg;}
	}
	fclose(ler);
	printf("\t\t\tLista de usuarios borrados\n\nIndice  ");
	printf("Estado\tMatricula\tNombre/ApePaterno/ApeMaterno\tEdad\tSexo\n\n");
	for(i=0; i<(j); i++) {
	printf("%d\t%d\t%d\t\t%s%s %s\t\t%d\t%d\n",(i),vecBorra[i].status,
			vecBorra[i].matricula, vecBorra[i].nombre, vecBorra[i].apellidoP,
			vecBorra[i].apellidoM, vecBorra[i].edad, vecBorra[i].sexo);
		}
	
	printf("\n\nDesea ver los detalles del usuario...\n");
	printf("1.- Si\t\t\t2.- No\n\n");
	scanf("%d",&op);
	if(op == 1) {
		printf("\n\n Elija un folio del indice...\n");
		scanf("%d",&mos);
		
	arch = fopen("Detall.dat","rb");
	fseek(arch,SEEK_SET, (mos));
	
	fread(&rag,sizeof(dtll),1,arch);
	vecdet[k] = rag;
		
	fclose(arch);
	printf("Detalles de Eliminacion\n\n");
	printf("\n\nFecha y hora:\t%s\nMotivo:\t\t%s\nQuien autorizo:\t%s\n",
	vecdet[k].fech, vecdet[k].motivo, vecdet[k].quien );
	k++;
	}
	system ("pause");
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
	char nomf[20][10] = {"Miris ","Sandra ","Maria ","Lucia ","Diana ",
	"Marla ","Chunli ","Karla ","Josefa ","Antonia ","Daniela ","Lore ",
	"Petra ","Angela ","Pamela ","Laura ","Katia ","Samis ","Analu ","Karen "};

	for (j = *tam; j<(A+*tam) ; j++) {
//		srand(time(NULL));
		x = (1 + (rand() % 2) - 1);
		r = (1 + (rand() % 20) - 1);
		if (x == 1) {
			strcpy(vectorExmp[j].nombre,nom[r]);
			vectorExmp[j].sexo = 1;
		}
		else {
			strcpy(vectorExmp[j].nombre,nomf[r]);
			vectorExmp[j].sexo = 2;
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

//Funcion que agrega un status = 1 al registro
void status(int *tam) {
	int s=1, j=0;
	
	for(j = *tam; j<(A+*tam); j++){
	vectorExmp[j].status = s;

	}
	*tam = *tam + A;
	return;}
	
//Funcioon para capturar los detalles 
void leerdet(int *pos) {
	system("cls");
	FILE *arch;
	dtll reg;
	char name[60],moti[150],fe[128];
	int i;
	
	printf("Caputa de Datos de quien da la baja\n\n");
	printf("Ingresa tu nombre: \n");
	fflush(stdin);
	gets(name);
	strcpy(vecdet[*pos].quien,name);

	printf("Ingrese el motivo de la baja: \n");
	fflush(stdin);
	gets(moti);
	strcpy(vecdet[*pos].motivo ,moti);
	strcpy(vecdet[*pos].fech,fecha());
	
	arch = fopen("Detall.dat","wb");
	
	for(i=0; i<(*pos+1); i++) {
		reg = vecdet[*pos];
		fwrite(&reg,sizeof(dtll),1,arch);
		}
	fclose(arch);
	*pos = *pos + 1;
	fclose(arch);
}

//Funcion que busca una matricula (Metodo Binario)
long binario(long num) {
	long central, bajo = 0, alto = st - 1;
	
	while (bajo <= alto) {
		central = ((alto - bajo) / 2) + bajo;
		if ((vectorAux[central].matricula) == num)
		{
			return(central);
		}
		else
		{
			if (num < (vectorAux[central].matricula))
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
	system("cls");
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
	printf("El vector se ha ordenado con exito...\n");
	system("pause");
}

//Funcion que revisa si el vector esta ordenado 
int ord(void) {
	system("cls");
	int resp = 1;
	int pos = 0;
	
	if(pos < st){
		
		
	}
		
}

//Funcion para insertar la fecha del sistema
char *fecha(void) {
	time_t tiempo = time(0);
    struct tm *tlocal = localtime(&tiempo);

    char output[128];

    strftime(output, 128, "%d/%m/%y %H:%M:%S\n", tlocal);
    printf("Fecha y Hora: %s",output);
    
    return output;
}

//Funcion que busca en un archivo binario(binario)
Tdat busB(char *FileName,long mat) {
	FILE *arch;
	Tdat reg;
	//reg.status = 0;
	
	arch = fopen(FileName,"r+b");
	if(arch){
		while(fread(&reg,sizeof(Tdat),1,arch)) {
			if(reg.matricula == mat) {
				fclose(arch);
				return reg;
			}
		}
		fclose(arch);
	}
	return reg;
}


void delay(int tiempo) {
	
		int i, j;
	for (i = 0; i<tiempo * 100; i++)
	{
		for (j = 0; j<tiempo * 100; j++);
	}
}

