//Manuel Alejandro Sahagun Mendoza 349857
//Generar Datos para Curp
//14 Mayo 2017
//SMMA_PR12 A
//****************************************************************************
//    LIBRERIAS
//****************************************************************************
//****************************************************************************
/// Constantes
//****************************************************************************
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//****************************************************************************
/// variables globales
//****************************************************************************



#define T 76
#define N 450
#define A 1
int PO = 0;

//****************************************************************************
// Estructuras
//****************************************************************************
//typedef struct curp {
//	char al[1];
//	char av[1];
//	char am[1];	
//	char no[1];
//	char a[2];
//	char m[2];
//	char d[2];
//	char sex[1];
//	char edo[3];
//	char conp[1];
//	char conm[1];
//	char conN[1];
//	char ho[3];
//} Cdat;


typedef struct alumno {
	int status;
	long matricula;
	char nombre[10];
	char apellidoP[10];
	char apellidoM[10];
	char day[10];
	char month[10];
	char year[10];
	int sexo;
	char estado[2];
//	Cdat CRP;
} Tdat;

struct alumno vectorExmp[N];


//****************************************************************************
// PROTOTIPOS DE FUNCIONES
//****************************************************************************

int ELI(void);
int BIN(int *pos);
void estad(int *pos);
void nacimiento(int *pos);
void randapeMat(int *pos);
void randapePat(int *pos);
void randomNames(int *pos);
void genmat(int *pos);
void statu(int *pos);
int ordena(void);
int busca(long mat);
//Cdat creacurp(int *pos);
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
	long mat;
	
	printf("Escriba la matricula que desea buscar\nMatricula:\t");
	scanf("%dl",&mat);
	busca(mat);

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

//Funcion que agrega un status = 1 al registro
void statu(int *pos) {
	
	vectorExmp[*pos].status = 1;
}

//Funcion que genera Matriculas aleatorias sin repetir
void genmat(int *pos) {
	int i, j, dup;
	long ale,und;
	
	und = ((rand() % 30000) + 1);
	
	for (i = 0; i<(*pos+1); i++) {
		srand(time(NULL)); 
		ale = (300000 + rand() % 333999);
		ale = ale +und;
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
			vectorExmp[*pos].matricula = ale;
		}
	}
}

//Funcion que genera nombres aleatorios
void randomNames(int *pos) {
	int x = 0, r = 0, i;
	srand(time(NULL));
	x = (1 + (rand() % 2) - 1);

	char nom[20][10] = {"Manuel ","Carlos ","Fermin ","Fede ","Luis ",
	"Jose ","Antonio ","Sandro ","Mario ","Lucio ","Daniel ","Lorenzo ",
	"Pedro ","Angel ","Fabian ","Gibran ","Elver ","Ignacio ","Martin ",
	"Ferni "};
	char nomf[20][10] = {"Miris ","Sandra ","Maria ","Lucia ","Diana ",
	"Marla ","Chunli ","Karla ","Josefa ","Antonia ","Daniela ","Lore ",
	"Petra ","Angela ","Pamela ","Laura ","Katia ","Samis ","Analu ","Karen "};

	
		srand(time(NULL));
		x = (1 + (rand() % 2) - 1);
		r = (1 + (rand() % 20) - 1);
		if (x == 1) {
			strcpy(vectorExmp[*pos].nombre,nom[r]);
			vectorExmp[*pos].sexo = 1;
		}
		else {
			strcpy(vectorExmp[*pos].nombre,nomf[r]);
			vectorExmp[*pos].sexo = 2;
		}
}

//Funcion que genera apellidos paternos aleatorios
void randapePat(int *pos) {
	int x, i;

	char apep[20][10] = { "Mendoza","Mejia","Chupi","Esparza",
	"Carril","Monrez","Garcia","Cardena","Perez","Cruz","Chico",
	"Sanchez","Ramirez","Montes","Sanchez","Perez","Curiel","Zertus",
	"Gomez","Vargas" };

		srand(time(NULL)); //Semilla aleatoria
		x = (rand() % 20);
		strcpy(vectorExmp[*pos].apellidoP,apep[x]);
}

//Funcion que genera apellidos maternos aleatorios
void randapeMat(int *pos) {
	int x, i;

	char apem[20][10] = { "Sahagun","Argaez","Perez","Hendo","Moxca",
		"Gonzalo","Guino","Carol","Guerra", "Montes","Chunli",
		"Parra","Cardes","Ramir","Vargas","Tellez","Folgi","Odino",
		"Parker","Galarga"};

	
		srand(time(NULL)); 
		x = (rand() % 20);
		strcpy(vectorExmp[*pos].apellidoM,apem[x]);
}

//Funcioon que genera fechas de nacimiento aleatorias
void nacimiento(int *pos) {    
    int d,m,a;
    char dia[20],mes[20],anio[20];
    srand(time(NULL));
    
	a = ((rand()% 12) + 1988);		//Añadimos el año
     
	if((a%4==0) && !(a%100==0)) {	//Verificar si es bisiesto
		m = (rand()%11)+1;			//
		if(m == 2) {  				//
        	d = (rand()%28)+1;  	//				
     		}						//
     	else {						//
        	d = (rand()%30)+1;  	//
    		}						//
	}								//			
	else if (a%400==0)				//
	{								//
		m = (rand()%11)+1;			// 
		if(m == 2) {  				// Si es bisiesto y es febrero
			d = (rand()%28)+1;  	// Febrero puede tener 29 dias...
     		}
     	else {
        	d = (rand()%30)+1;  
     		}
	}
	else {
     	m = (rand()%11)+1;
     	if(m == 2) {  
        d = (rand()%27)+1; 
     	}
     	else {
        	d = (rand()%30)+1;  
     	}		
	}
	
	itoa(a,anio,10);
	itoa(m,mes,10);
	itoa(d,dia,10);
	
	strcpy(vectorExmp[*pos].year,anio);
	strcpy(vectorExmp[*pos].month,mes);
	strcpy(vectorExmp[*pos].day,dia);
}

//Funcion que agrega un Estado de la Republica 
void estad(int *pos) {
	int E;
	char es[2];
	srand(time(NULL));
	
	E = (rand()%32)+1;
	switch(E) {
		case 1: strcpy(es,"AS");  break;	
		case 2: strcpy(es,"BC");  break;
		case 3: strcpy(es,"BS");  break;
		case 4: strcpy(es,"CC");  break;
		case 5: strcpy(es,"CL");  break;
		case 6: strcpy(es,"CM");  break;
		case 7: strcpy(es,"CS");  break;
		case 8: strcpy(es,"CH");  break;
		case 9: strcpy(es,"DF");  break;
		case 10: strcpy(es,"DG"); break;
		case 11: strcpy(es,"GT"); break;
		case 12: strcpy(es,"GR"); break;
		case 13: strcpy(es,"HG"); break;
		case 14: strcpy(es,"JC"); break;
		case 15: strcpy(es,"MC"); break;
		case 16: strcpy(es,"MN"); break;
		case 17: strcpy(es,"MS"); break;
		case 18: strcpy(es,"NT"); break;
		case 19: strcpy(es,"NL"); break;
		case 20: strcpy(es,"OC"); break;
		case 21: strcpy(es,"PL"); break;
		case 22: strcpy(es,"QT"); break;
		case 23: strcpy(es,"QR"); break;
		case 24: strcpy(es,"SP"); break;
		case 25: strcpy(es,"SL"); break;
		case 26: strcpy(es,"SR"); break;
		case 27: strcpy(es,"TC"); break;
		case 28: strcpy(es,"TS"); break;
		case 29: strcpy(es,"TL"); break;
		case 30: strcpy(es,"VZ"); break;
		case 31: strcpy(es,"YN"); break;
		case 32: strcpy(es,"ZS"); break;
		case 33: strcpy(es,"NE"); break;
	}
	
	strcpy(vectorExmp[*pos].estado,es);
}

//Agregar a binario
int BIN(int *pos) {
	
	FILE *arch = NULL;
	Tdat reg;
	int i=0;
	
	arch = fopen("Datos.dat","ab+");
	if(arch == NULL) return -1;
	
	reg = vectorExmp[*pos];
	fwrite(&reg,sizeof(Tdat),1,arch);
	
	fseek(arch,0,SEEK_SET);
	
	while(!(feof(arch))) {
		fread(&reg,sizeof(Tdat),1,arch);
		vectorExmp[i++] = reg;	
	}
	fclose(arch);
	
	*pos = (i-1) + A;	
}

//Leer Binario
int LEBIN(void) {
	FILE *arch = NULL;
	Tdat reg;
	int i=0,j;
	
	arch = fopen("Datos.dat","rb");
	if(arch == NULL) {
	printf("El archivo no se encuentra o no existe...\n\n");
	return -1;}
	
	fseek(arch,0,SEEK_SET);
	
	while(!(feof(arch))) {
		fread(&reg,sizeof(Tdat),1,arch);
		vectorExmp[i++] = reg;	
	}
		
	printf("\tDatos del Alumno: \n\n");	
	for(j=0; j<(i-1); j++) {
		
		printf("(Acitvo:1,Inactivo:0):\t%d\n",vectorExmp[j].status);
		printf("Matricula:\t\t%d\n",vectorExmp[j].matricula);
		printf("Nombre:\t\t\t%s\n",vectorExmp[j].nombre);
		printf("Apellido Paterno:\t%s\n",vectorExmp[j].apellidoP);
		printf("Apellido Materno:\t%s\n",vectorExmp[j].apellidoM);
		printf("Fecha de Nacimiento:\t%s ",vectorExmp[j].day);
		printf("%s ",vectorExmp[j].month);
		printf("%s\n",vectorExmp[j].year);
		printf("(1:Hombre,2:Mujer):\t%d\n",vectorExmp[j].sexo);
		printf("Lugar de nacimiento:\t%s\n\n\n",vectorExmp[j].estado);
		//printf("\n%d\n",ftell(arch));
	}
	fclose(arch);
}

//Eliminar Binario
int ELI(void) { 	
	Tdat reg;
	FILE *arch, *leer;
	long DEL;
	int ubicado = 0,
		i = 0,
		j = 0,
		k = 0,
		op;

	leer = fopen("Datos.dat","rb+");
	if(leer == NULL) {
	printf("El archivo no existe o no se encuentra\n");
	return-1;}
	
	fseek(leer,0,SEEK_SET);
	
	while(!(feof(leer))) {		
		fread(&reg,sizeof(Tdat),1,leer);
		vectorExmp[j] = reg;
		j++;
	}
	fclose(leer);
	
	printf("Ingrese la matricula que desea eliminar\n");
	scanf("%dl",&DEL);
		
	for(i=0; i<(j-1); i++) {
		k++;
		if(DEL == vectorExmp[i].matricula && vectorExmp[i].status == 1) {
		printf("El dato que desea eliminar es correcto?\nElija una opcion:\n");
		printf("\n\n1.-Si\n2.-No\n\n");	
		//Imprime los datos que desea eliminar	
		printf("(Acitvo:1,Inactivo:0):\t%d\n",vectorExmp[i].status);
		printf("Matricula:\t\t%d\n",vectorExmp[i].matricula);
		printf("Nombre:\t\t\t%s\n",vectorExmp[i].nombre);
		printf("Apellido Paterno:\t%s\n",vectorExmp[i].apellidoP);
		printf("Apellido Materno:\t%s\n",vectorExmp[i].apellidoM);
		printf("Fecha de Nacimiento:\t%s ",vectorExmp[i].day);
		printf("%s ",vectorExmp[i].month);
		printf("%s\n",vectorExmp[i].year);
		printf("(1:Hombre,2:Mujer):\t%d\n",vectorExmp[i].sexo);
		printf("Lugar de nacimiento:\t%s\n\n\n",vectorExmp[i].estado);
		//printf("%d",i);
		scanf("%d",&op);
		
		arch = fopen("Datos.dat","rb+");
		
			if(op == 1) {
				vectorExmp[i].status = 0;
				reg = vectorExmp[i];
				
				fseek(arch,(T*i),SEEK_SET);
				fwrite(&reg,sizeof(Tdat),1,arch);
				fclose(arch);
				}
			else {
				fclose(arch);
				return 0;
				}
				ubicado = 1;
			}
		}	
		if(ubicado == 0){
			printf("La matricula no existe\n");	
			}
}

//Ordenar vector
int ordena(void) {
	Tdat vec[N],reg;
	long tem;
	int cant=0,tot,i,j;
	FILE *arch,*arc;
	
	arch = fopen("Datos.dat","rb");			//Abre
	if(arch == NULL) {
	printf("El archivo no existe o no hay datos para ordenar...\n\n");
	return -1;}
	
	fseek(arch,0,SEEK_SET);

	while(!feof(arch)) {
		fread(&reg,sizeof(Tdat),1,arch);
		vec[cant++] = reg;
	}
	fclose(arch);							//Cierra
	tot = cant - 1;
	
	for(i=1; i<tot; i++) {
		for(j=0; j<(tot-i); j++) {
			if(vec[j].matricula < vec[j+1].matricula) {	
				tem = vec[j].matricula;
				vec[j].matricula = vec[j+1].matricula;
				vec[j+1].matricula = tem;
			}
		}
	}
	
	arc = fopen("Datos.dat","wb");			//Abre
	fseek(arc,0,SEEK_SET);
	
	for(i=0; i<tot; i++) {
		reg = vec[i];
		fwrite(&reg,sizeof(Tdat),1,arc);	
	}
	fclose(arc);							//Cierra
return 0;}

//Buscar en vector
int busca(long mat) {
	Tdat reg,vec[N];
	int i,j = 0,ubicado = 0;
	FILE *arch;
	
	arch = fopen("Datos.dat","rb");			//Abre
	if(arch == NULL) {
	printf("El archivo no existe o no hay datos para ordenar...\n\n");
	return -1;}
	
	while(!feof(arch)) {
		fread(&reg,sizeof(Tdat),1,arch);
		vec[j++] = reg;
	}
	fclose(arch);
	
	for (i = 0; i < (j-1); i++)
	{
		if (vec[i].matricula == mat)
		{
			ubicado = 1;
			printf("\nMatricula encontrada\n\n");
			printf("(Acitvo:1,Inactivo:0):\t%d\n",vec[i].status);
			printf("Matricula:\t\t%d\n",vec[i].matricula);
			printf("Nombre:\t\t\t%s\n",vec[i].nombre);
			printf("Apellido Paterno:\t%s\n",vec[i].apellidoP);
			printf("Apellido Materno:\t%s\n",vec[i].apellidoM);
			printf("Fecha de Nacimiento:\t%s ",vec[i].day);
			printf("%s ",vec[i].month);
			printf("%s\n",vec[i].year);
			printf("(1:Hombre,2:Mujer):\t%d\n",vec[i].sexo);
			printf("Lugar de nacimiento:\t%s\n",vec[i].estado);
		}
	}
	if (ubicado == 0)
	{
		printf("La matricula no existe o no se encuentra...\n");
	}
	

}


//Generar Curp
//Cdat creacurp(int *pos) { 
//	
//	Cdat reg;
//	char temp[3],recibe[10];
//	int i,tam,tem;
//	
//	strcpy(recibe,vectorExmp[*pos].apellidoP);
//	temp[0] = recibe[0];
//	strcpy(reg.al,temp);	//Captura 
//	
//	strcpy(recibe,vectorExmp[*pos].apellidoP);
//	tam = strlen(recibe);
//	for(i=0; i<tam; i++) {
//		if(recibe[i] == 'a' || recibe[i] == 'e'|| recibe[i] == 'i' || 
//		recibe[i] == 'o' || recibe[i] == 'u') {
//			temp[0] = recibe[i];
//		}
//	}	
//	strcpy(reg.av,temp);	//Captura
//	
//	strcpy(recibe,vectorExmp[*pos].apellidoM);
//	temp[0] = recibe[0];
//	strcpy(reg.am,temp);	//Captura
//	
//	strcpy(recibe,vectorExmp[*pos].nombre);
//	temp[0] = recibe[0];
//	strcpy(reg.no,temp);	//Captura	
//	
//	strcpy(recibe,vectorExmp[*pos].year);
//	temp[0] = recibe[2];
//	temp[1] = recibe[3];
//	strcpy(reg.a,temp);		//Captura año
//	
//	strcpy(recibe,vectorExmp[*pos].month);
//	tem = atoi(recibe);
//	
//	if(tem < 10) {
//	temp[0] = 48;
//	}
//	else {
//	temp[0]	= recibe[0];
//	temp[1] = recibe[1];
//	}
//	strcpy(reg.m,temp);		//Captura mes
//	
//	
//	
//}
//




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

