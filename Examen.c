#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define N 500
#define C 50

typedef struct traba {
	int matricula;
	char nombre[10];
	char apellidoP[10];
	char apellidoM[10];
	int sexo;
	int edad;
} Tdat;

//****************************************************************

int busca(int mat);
void genmat(int *pos,Tdat *vec);
void randapeMat(int *pos,Tdat *vec);
void randapePat(int *pos,Tdat *vec);
void randomNames(int *pos,Tdat *vec);
void age(int *pos,Tdat *vec);
void programa1(int *pas,Tdat *vectorExmp);
void programa2(int *pos,Tdat *vec,Tdat *VECH,Tdat *VECM,int *H,int *M);
void programa3(int *pos,Tdat *vec,Tdat *VECH,Tdat *VECM,int *H,int *M);
void programa4(int *pos,Tdat *vec);
int programa5(int *pos,Tdat *vec);
int programa6(int *pos);
int programa7(void);
void programa8(void);
void programa9(int *pos,Tdat *vec);
int programa10(void);
void menu(void);

//Funcion principal
int main (void) {
    menu();
   	return 0;
}

//Menu
void menu(void) {
	
	Tdat vectorExmp[N],VECH[N],VECM[N];
	
  	int op,PO=0,H=0,M=0;
  	
   do{
      system ("cls");
      printf("%d",PO);
      printf("\n M  E   N   U");
	  printf("\n1.- Llenar Vector con 50 Reg");
	  printf("\n2.- Llenar 2 vectores");
	  printf("\n3.- Imprimir Vectores");
	  printf("\n4.- Ordenar");
	  printf("\n5.- Generar Archivo de texto con datos de vector 1");
	  printf("\n6.- Imprimir Archvo de Texto");
	  printf("\n7.- Generar archivo binario");
	  printf("\n8.- Buscar archivo binario");
	  printf("\n9.- Buscar En el vector");
	  printf("\n10.- Imprimir archivo binario");
	  printf("\n0.- Salir\n");
	  
	  printf("ELIGE UNA OPCION");
	  scanf("%d",&op);
	  switch(op)
	    {
		  case 1: programa1(&PO,&*vectorExmp);  break;
		  case 2: programa2(&PO,&*vectorExmp,&*VECH,&*VECM,&H,&M);  break;
		  case 3: programa3(&PO,&*vectorExmp,&*VECH,&*VECM,&H,&M);  break;
		  case 4: programa4(&PO,&*vectorExmp);  break;
		  case 5: programa5(&PO,&*vectorExmp);  break;
		  case 6: programa6(&PO);	break;
		  case 7: programa7(); break;
		  case 8: programa8(); break;
		  case 9: programa9(&PO,&*vectorExmp); break;
		  case 10: programa10(); break;
		}
   }while(op != 0);
}

//Llenar vector con 50 reg
void programa1(int *pas,Tdat *vectorExmp) {
    system ("cls");
	Tdat vec[N];
	
	int X=(*pas),i;

	for(i=0; i<C; i++) {
	
	randomNames(&X,&*vec);
	randapePat(&X,&*vec);
	randapeMat(&X,&*vec);
	genmat(&X,&*vec);
	age(&X,&*vec);
	
	vectorExmp[i] = vec[i];

	}	
	*pas = (*pas) + C;
	printf("%d",X);
	system("pause");
}

//Funcion que genera nombres aleatorios
void randomNames(int *pos,Tdat *vec) {
	int x = 0, r = 0, i;
	///srand(time(NULL));
	x = (1 + (rand() % 2) - 1);

	char nom[20][10] = {"MANUEL","CARLOS","FERMIN","FEDE","LUIS",
	"JOSE","ANTONIO","SANDRO","MARIO","LUCIO","DANIEL","LORENZO",
	"PEDRO","ANGEL","FABIAN","GIBRAN","ELVER","IGNACIO","MARTIN",
	"FENRI"};
	char nomf[20][10] = {"MIRANDA","SANDRA","MARIA","LUCIA","DIANA",
	"MARLA","CHUNLI","KARLA","JOSEFA","ANTONIA","DANIELA","LORE",
	"PETRA","ANGELA","PAMELA","LAURA","KATIA","SAMIS","ANALU","KAREN"};


		x = (1 + (rand() % 2) - 1);
		r = (1 + (rand() % 20) - 1);
		if (x == 1) {
			strcpy(vec[*pos].nombre,nom[r]);
			vec[*pos].sexo = 1;

		}
		else {
			strcpy(vec[*pos].nombre,nomf[r]);
			vec[*pos].sexo = 2;
	
		}
}

//Funcion que genera apellidos paternos aleatorios
void randapePat(int *pos,Tdat *vec) {
	int x, i;

	char apep[20][10] = { "MENDOZA","MEJIA","CHUPI","ESPARZA",
	"CARRIL","MONAREZ","GARCIA","CADENA","PEREZ","CRUZ","CHICO",
	"SANCHEZ","RAMIREZ","MONTES","SANCHEZ","PEREZ","CURIEL","ZERTUS",
	"GOMEZ","VARGAS" };


		x = (rand() % 20);
		strcpy(vec[*pos].apellidoP,apep[x]);

}

//Funcion que genera apellidos maternos aleatorios
void randapeMat(int *pos,Tdat *vec) {
	int x, i;

	char apem[20][10] = { "SAHAGUN","ARGAEZ","PEREZ","HENDO","MOXCA",
		"GONZALO","GUINO","CAROL","GUERRA","MONTES","CHUNLI",
		"PARRA","CARDES","RAMIR","VARGAS","TELLEZ","FOLGI","ODIN",
		"PARKER","HERNANDEZ"};
	
		x = (rand() % 20);
		strcpy(vec[*pos].apellidoM,apem[x]);
		
}

//Funcion que genera edades aleatorias
void age(int *pos,Tdat *vec) {
	int x;
	
	x = (18 + rand() % 10);
	vec[*pos].edad = x;
	 
	 *pos = 1 + (*pos);
}

//Funcion que genera numero de trabajador
void genmat(int *pos,Tdat *vec) {
	int i, j,dup,ale;
	
	for (i = 0; i<(*pos); i++) {
 
		ale = ((rand() % 499)+1);
		dup = 0;
		for (j = 0; j<i; j++) {
			if (ale == vec[*pos].matricula)
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
			vec[*pos].matricula = ale;
		}
	}
}




void programa2(int *pos,Tdat *vec,Tdat *VECH,Tdat *VECM,int *H,int *M) {
	system("cls");
	Tdat V[N];
	int i,j=0,k=0;
	
	for(i=0; i<(*pos); i++) {
		V[i] = vec[i];	
	}	
	
	for(i=0; i<(*pos); i++) {
		if(V[i].sexo == 1) {
			VECH[j] = V[i];
			j++;
		}
		else {
			VECM[k] = V[i];
			k++;	
		}
	}
	*H = *H + j;
	*M = *M + k;
	system("pause");
}

void programa3(int *pos,Tdat *vec,Tdat *VECH,Tdat *VECM,int *H,int *M) {
	int i,j,k,op;
	
	do {
		j=0,k=0;
		system("cls");
	printf("\n1.-Datos mixtos\n2.-Datos de Hombres\n3.-Datos de Mujeres");
	printf("\n0.-Salir");
	printf("ESCOGE UNA OPCION\n\n");
	scanf("%d",&op);
	switch(op){
		case 1:
	printf("\n\n-Datos Mixtos-\n\n");
	for(i=0; i<(*pos); i++) {
		printf("\nNumero de trabajador: \t%d",vec[i].matricula);
		printf("\nNombre: \t\t%s\n",vec[i].nombre);
		printf("Apellido Paterno: \t%s\n",vec[i].apellidoP);
		printf("Apellido Materno: \t%s\n",vec[i].apellidoM);
		printf("Sexo (1=Homre,2=Mujer): %d\n",vec[i].sexo);
		printf("Edad: \t\t\t%d\n",vec[i].edad);
	}
	system("pause");
		break;
		
		case 2:
				for(i=0; i<(*H); i++) {
		printf("\nNumero de trabajador: \t%d",VECH[i].matricula);		
		printf("\nNombre: \t\t%s\n",VECH[i].nombre);
		printf("Apellido Paterno: \t%s\n",VECH[i].apellidoP);
		printf("Apellido Materno: \t%s\n",VECH[i].apellidoM);
		printf("Sexo (1=Homre,2=Mujer): %d\n",VECH[i].sexo);
		printf("Edad: \t\t\t%d\n",VECH[i].edad);
		//printf("%d",j++);
		}
		system("pause");
		break;
		
		case 3:
				for(i=0; i<(*M); i++) {
		printf("\nNumero de trabajador: \t%d",VECM[i].matricula);			
		printf("\nNombre: \t\t%s\n",VECM[i].nombre);
		printf("Apellido Paterno: \t%s\n",VECM[i].apellidoP);
		printf("Apellido Materno: \t%s\n",VECM[i].apellidoM);
		printf("Sexo (1=Homre,2=Mujer): %d\n",VECM[i].sexo);
		printf("Edad: \t\t\t%d\n",VECM[i].edad);
	//	printf("%d",k++);
		}
		system("pause");
		break;
		
		}	
	
	}while(op != 0);
	system("pause");
	
}

void programa4(int *pos,Tdat *vec) {
	system("cls");
	
	int tem,i,j;
	
	
	
		for(i=1; i<(*pos); i++) {
		for(j=0; j<(*pos-i); j++) {
			if(vec[j].matricula < vec[j+1].matricula) {	
				tem = vec[j].matricula;
				vec[j].matricula = vec[j+1].matricula;
				vec[j+1].matricula = tem;
			}
		}
	}
	
	system("pause");
}

int programa5(int *pos,Tdat *vectorExmp) {
	system("cls");
	FILE *arch = NULL;
	Tdat reg;
	int i;
	
	arch = fopen("Datos.txt","a");
	if(arch == NULL) return -1;
	//printf("El archivo no existe");
	
	//fseek(arch,0,SEEK_SET);

	for(i=0; i<(*pos); i++) {
		reg = vectorExmp[i];
		fwrite(&reg,sizeof(Tdat),1,arch);
	}
	
	fclose(arch);
	printf("%d",*pos);
	system("pause");
}



int programa6(int *pos) {
	system("cls");
	FILE *arch = NULL;
	Tdat reg,v[N];
	int i=0,j;
	
	arch = fopen("Datos.txt","r");
	if(arch == NULL) {
	printf("El archivo no se encuentra o no existe...\n\n");
	return -1;}
	
	fseek(arch,SEEK_SET,0);
	
	while(!(feof(arch))) {
		fread(&reg,sizeof(Tdat),1,arch);
		v[i++] = reg;	
	}
	
	
	printf("\tDatos del Trabajador: \n\n");	
	for(j=0; j<(i); j++) {

		printf("\nMatricula:\t\t%d\n",v[j].matricula);
		printf("Nombre:\t\t\t%s\n",v[j].nombre);
		printf("Apellido Paterno:\t%s\n",v[j].apellidoP);
		printf("Apellido Materno:\t%s\n",v[j].apellidoM);
		printf("(1:Hombre,2:Mujer):\t%d\n",v[j].sexo);
		//printf("\n%d\n",ftell(arch));
		printf("%d",i);
	}
	fclose(arch);
	system("pause");
}

int programa7(void) {
	system("cls");
	
	FILE *arch=NULL,*ar=NULL;
	Tdat reg,v[N];
	int i=0,j;
	
	arch = fopen("Datos.txt","a+");
	if(arch == NULL) return -1;
	
//	reg = vectorExmp[*pos];
//	fwrite(&reg,sizeof(Tdat),1,arch);
	
	fseek(arch,0,SEEK_SET);
	
	while(!(feof(arch))) {
		fread(&reg,sizeof(Tdat),1,arch);
		v[i++] = reg;	
	}
	fclose(arch);
	
	ar = fopen("datos.dat","ab+");
	if(ar == NULL) 
	
	return -1;
	fseek(ar,0,SEEK_SET);
	
	for(j=0; j<i; j++) { 
		reg = v[j];
		fwrite(&reg,sizeof(Tdat),1,arch);
	}
	fclose(ar);
	system("pause");
}

void programa8(void) {
	    system ("cls");
	int DEL;
	
	printf("Escriba la matricula que desea buscar\nMatricula:\t");
	scanf("%d",&DEL);
	busca(DEL);

	system("pause");
	
}

//Buscar en vector
void programa9(int *pos,Tdat *vec) {
	system ("cls");
	Tdat v[N];
	int i, ubicado = 0,num;
	
	printf("\nIngrese la matricula que desea buscar: ");
	scanf("%d",&num);


	for (i = 0; i < (*pos) ; i++)
	{
		if (vec[i].matricula == num)
		{
			ubicado = 1;

		printf("\nMatricula:\t\t%d\n",v[i].matricula);
		printf("Nombre:\t\t\t%s\n",v[i].nombre);
		printf("Apellido Paterno:\t%s\n",v[i].apellidoP);
		printf("Apellido Materno:\t%s\n",v[i].apellidoM);
		printf("(1:Hombre,2:Mujer):\t%d\n",v[i].sexo);
			
		}
	}
	if (ubicado == 0)
	{
		printf("El numero no se encuentra en el vector\n");
	}
	system("pause");
}

int programa10(void) {
	
	system("cls");
	FILE *arch = NULL;
	Tdat reg,v[N];
	int i=0,j;
	
	arch = fopen("datos.dat","rb");
	if(arch == NULL) {
	printf("El archivo no se encuentra o no existe...\n\n");
	return -1;}
	
	fseek(arch,0,SEEK_SET);
	
	while(!(feof(arch))) {
		fread(&reg,sizeof(Tdat),1,arch);
		v[i++] = reg;	
	}
		
	printf("\tDatos del Trabajador: \n\n");	
	for(j=0; j<(i); j++) {

		printf("\nMatricula:\t\t%d\n",v[j].matricula);
		printf("Nombre:\t\t\t%s\n",v[j].nombre);
		printf("Apellido Paterno:\t%s\n",v[j].apellidoP);
		printf("Apellido Materno:\t%s\n",v[j].apellidoM);
		printf("(1:Hombre,2:Mujer):\t%d\n",v[j].sexo);
		//printf("\n%d\n",ftell(arch));
	}
	fclose(arch);
	
	system("pause");
	
	
	
}

//Buscar en binario
int busca(int DEL) {
	Tdat reg,vec[N];
	int i,j = 0,ubicado = 0;
	FILE *arch;
	
	arch = fopen("datos.dat","rb");			//Abre
	if(arch == NULL) {
	printf("\n\nEl archivo no existe o no hay datos para ordenar...\n\n");
	return -1;}
	
	while(!feof(arch)) {
		fread(&reg,sizeof(Tdat),1,arch);
		vec[j++] = reg;
	}
	fclose(arch);
	
	for (i = 0; i < (j); i++)
	{
		
		if (vec[i].matricula == DEL)
		{
			ubicado = 1;
			printf("\nMatricula encontrada\n\n");
			printf("Matricula:\t\t%d\n",vec[i].matricula);
			printf("Nombre:\t\t\t%s\n",vec[i].nombre);
			printf("Apellido Paterno:\t%s\n",vec[i].apellidoP);
			printf("Apellido Materno:\t%s\n",vec[i].apellidoM);
			printf("(1:Hombre,2:Mujer):\t%d\n",vec[i].sexo);

		}
	}
	if (ubicado == 0)
	{
		printf("La matricula no existe o no se encuentra...\n");
	}


}


