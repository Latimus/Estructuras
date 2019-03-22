#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>

//****************************************************************************
/// Constantes
//****************************************************************************

#define H 72
#define M 77
#define T 96
#define N 450
#define A 1

//****************************************************************************
/// variables globales
//****************************************************************************

int PO = 0;

//****************************************************************************
// Estructuras
//****************************************************************************
typedef struct curp {
	char al[1];
	char av[1];
	char am[1];	
	char no[1];
	char a[2];
	char m[2];
	char d[2];
	char sex[1];
	char edo[2];
	char conp[1];
	char conm[1];
	char conN[1];
	char ho[1];
	char h2[1];
} Cdat;


typedef struct alumno {
	Cdat CRP;
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
	
} Tdat;

struct alumno vectorExmp[N];

void validanu(int ri,int rf,char* msge,long *DEL);
void validanum(int ri,int rf,char* msge,int *op);
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
Cdat creacurp(int *pos);






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

	char nom[20][10] = {"MANUEL","CARLOS","FERMIN","FEDE","LUIS",
	"JOSE","ANTONIO","SANDRO","MARIO","LUCIO","DANIEL","LORENZO",
	"PEDRO","ANGEL","FABIAN","GIBRAN","ELVER","IGNACIO","MARTIN",
	"FENRI"};
	char nomf[20][10] = {"MIRANDA","SANDRA","MARIA","LUCIA","DIANA",
	"MARLA","CHUNLI","KARLA","JOSEFA","ANTONIA","DANIELA","LORE",
	"PETRA","ANGELA","PAMELA","LAURA","KATIA","SAMIS","ANALU","KAREN"};

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

	char apep[20][10] = { "MENDOZA","MEJIA","CHUPI","ESPARZA",
	"CARRIL","MONAREZ","GARCIA","CADENA","PEREZ","CRUZ","CHICO",
	"SANCHEZ","RAMIREZ","MONTES","SANCHEZ","PEREZ","CURIEL","ZERTUS",
	"GOMEZ","VARGAS" };

		srand(time(NULL)); //Semilla aleatoria
		x = (rand() % 20);
		strcpy(vectorExmp[*pos].apellidoP,apep[x]);
}

//Funcion que genera apellidos maternos aleatorios
void randapeMat(int *pos) {
	int x, i;

	char apem[20][10] = { "SAHAGUN","ARGAEZ","PEREZ","HENDO","MOXCA",
		"GONZALO","GUINO","CAROL","GUERRA","MONTES","CHUNLI",
		"PARRA","CARDES","RAMIR","VARGAS","TELLEZ","FOLGI","ODIN",
		"PARKER","HERNANDEZ"};

	
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
		printf("CURP: %s \n\n",vectorExmp[j].CRP);
		printf("\n%d\n",ftell(arch));
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
	validanu(48,57,"Matricula:\t",&DEL);
		
	for(i=0; i<(j-1); i++) {
		k++;
		if(DEL == vectorExmp[i].matricula && vectorExmp[i].status == 1) {
		printf("\n\nEl dato que desea eliminar es correcto?\nElija una opcion:\n");
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
		printf("CURP: %s \n\n",vectorExmp[i].CRP);
		//printf("%d",i);
		validanum(48,57,"ESCOGE UNA OPCION.",&op);
		
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
			printf("\nLa matricula no existe o ya ha sido eliminada...\n");	
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
	printf("\n\nEl archivo no existe o no hay datos para ordenar...\n\n");
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
	printf("Los datos ahora estan ordenados ;) \n");
return 0;}

//Buscar en vector
int busca(long mat) {
	Tdat reg,vec[N];
	int i,j = 0,ubicado = 0;
	FILE *arch;
	
	arch = fopen("Datos.dat","rb");			//Abre
	if(arch == NULL) {
	printf("\n\nEl archivo no existe o no hay datos para ordenar...\n\n");
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
			printf("CURP: %s \n\n",vectorExmp[i].CRP);
		}
	}
	if (ubicado == 0)
	{
		printf("La matricula no existe o no se encuentra...\n");
	}
	

}

//Generar Curp
Cdat creacurp(int *pos) { 
	srand(time(NULL));
	Cdat reg;
	char temp[2],recibe[10],vali[4];
	int i,j,tam,tem,con = 0;
	
	strcpy(recibe,vectorExmp[*pos].apellidoP);		//Recibe Apellido Paterno
	
	temp[0] = recibe[0];
	strcpy(reg.al,temp);	//Captura Primer Letra Ape Pat
	
	strcpy(recibe,vectorExmp[*pos].apellidoP);		//Recibe el apellido paterno
								
	i=0;						//Ubica la primer vocal
	if(recibe[0] == 'A' || recibe[0] == 'E' || recibe[0] == 'I' 
		|| recibe[0] == 'O' || recibe[0] == 'U') {		 //primera es vocal
		j=1;
		while((recibe[j] != 'A') && (recibe[j] != 'E') && 
			(recibe[j] != 'I') && (recibe[j] != 'O') && (recibe[j] != 'U')){
			j++;
			temp[0] = recibe[j];
		}
	}
	else {			
		while((recibe[i] != 'A') && (recibe[i] != 'E') && (recibe[i] != 'I') && 
			(recibe[i] != 'O') && (recibe[i] != 'U')) {
			i++;
			temp[0] = recibe[i];
		}
	}
		
	strcpy(reg.av,temp);	//Captura Primer Vocal Ape Pat
	
	strcpy(recibe,vectorExmp[*pos].apellidoM);		//Recibe Apellido Materno
	temp[0] = recibe[0];
	strcpy(reg.am,temp);	//Captura la primer letra del apellido materno
	
	strcpy(recibe,vectorExmp[*pos].nombre);			//Recibe el nombre
	temp[0] = recibe[0];
	strcpy(reg.no,temp);	//Captura La primer letra del nombre
	
	strcpy(recibe,vectorExmp[*pos].year);			//Recibe el año
	temp[0] = recibe[2];
	temp[1] = recibe[3];
	strcpy(reg.a,temp);		//Captura año
	
	strcpy(recibe,vectorExmp[*pos].month);			//Recibe el mes
	tem = atoi(recibe);
	
	if(tem < 10) {
		temp[0] = 48;
		temp[1] = recibe[0];
	}
	else {
		temp[0]	= recibe[0];
		temp[1] = recibe[1];
	}
	strcpy(reg.m,temp);		//Captura mes
	
	strcpy(recibe,vectorExmp[*pos].day);			//Recibe el dia
	tem = atoi(recibe);
	
	if(tem < 10) {
		temp[0] = 48;
		temp[1] = recibe[0];
	}
	else {
		temp[0] = recibe[0];
		temp[1] = recibe[1];
	}
	strcpy(reg.d,temp);		//Caputra dia
	
	tem = vectorExmp[*pos].sexo;					//Recibe sexo en *int
	
	if(tem == 1) {
		temp[0] = H;	
	}
	else {
		temp[0]	= M;
	}
	strcpy(reg.sex,temp);	//Captura sexo
	
	strcpy(temp,vectorExmp[*pos].estado);	//Captura la Entidad Federativa
	strcpy(reg.edo,temp);//////////************************************////////
	
	strcpy(recibe,vectorExmp[*pos].apellidoP);		//Recibe el apellido paterno
	i=1;
	while (recibe[i] != 'B' && recibe[i] != 'C' && recibe[i] != 'D' && 
		recibe[i] != 'F' && recibe[i] != 'G' && recibe[i] != 'H' && 
		recibe[i] != 'J' && recibe[i] != 'K' && recibe[i] != 'L' && 
		recibe[i] != 'M' && recibe[i] != 'N' && recibe[i] != 'P' && 
		recibe[i] != 'Q' && recibe[i] != 'R' && recibe[i] != 'S' && 
		recibe[i] != 'T' && recibe[i] != 'V' && recibe[i] != 'W' && 
		recibe[i] != 'X' && recibe[i] != 'Y' && recibe[i] != 'Z') {
		i++;
		temp[0] = recibe[i];
	}
	strcpy(reg.conp,temp);	//Captura la segunda consonante del apellido paterno
	
	strcpy(recibe,vectorExmp[*pos].apellidoM);		//Recibe el apellio Materno

	i=1;
	while (recibe[i] != 'B' && recibe[i] != 'C' && recibe[i] != 'D' && 
		recibe[i] != 'F' && recibe[i] != 'G' && recibe[i] != 'H' && 
		recibe[i] != 'J' && recibe[i] != 'K' && recibe[i] != 'L' && 
		recibe[i] != 'M' && recibe[i] != 'N' && recibe[i] != 'P' && 
		recibe[i] != 'Q' && recibe[i] != 'R' && recibe[i] != 'S' && 
		recibe[i] != 'T' && recibe[i] != 'V' && recibe[i] != 'W' && 
		recibe[i] != 'X' && recibe[i] != 'Y' && recibe[i] != 'Z') {
		i++;
		temp[0] = recibe[i];
	}

	strcpy(reg.conm,temp);	//Caputra la segunda consonante del apellio materno
	
	strcpy(recibe,vectorExmp[*pos].nombre);		//Recibe el nombre

	i=1;
	while (recibe[i] != 'B' && recibe[i] != 'C' && recibe[i] != 'D' && 
		recibe[i] != 'F' && recibe[i] != 'G' && recibe[i] != 'H' && 
		recibe[i] != 'J' && recibe[i] != 'K' && recibe[i] != 'L' && 
		recibe[i] != 'M' && recibe[i] != 'N' && recibe[i] != 'P' && 
		recibe[i] != 'Q' && recibe[i] != 'R' && recibe[i] != 'S' && 
		recibe[i] != 'T' && recibe[i] != 'V' && recibe[i] != 'W' && 
		recibe[i] != 'X' && recibe[i] != 'Y' && recibe[i] != 'Z') {
		i++;
		temp[0] = recibe[i];
	}

	strcpy(reg.conN,temp);	//Captura la segunda consonante del nombre
	
	strcpy(recibe,vectorExmp[*pos].year);	//recibe el año
	tem = atoi(recibe);
	if(tem < 1999) {
		temp[0] = (48+(rand()%9));
	}
	else {
		tam = (65+(rand()%35));
		switch(tam) {
			case 65: strcpy(temp,"A"); break;
			case 66: strcpy(temp,"B"); break; 
			case 67: strcpy(temp,"C"); break;
			case 68: strcpy(temp,"D"); break;
			case 69: strcpy(temp,"E"); break;
			case 70: strcpy(temp,"F"); break;
			case 71: strcpy(temp,"G"); break;
			case 72: strcpy(temp,"H"); break;
			case 73: strcpy(temp,"I"); break;
			case 74: strcpy(temp,"J"); break;
			case 75: strcpy(temp,"K"); break;
			case 76: strcpy(temp,"L"); break;
			case 77: strcpy(temp,"M"); break;
			case 78: strcpy(temp,"N"); break;
			case 79: strcpy(temp,"O"); break;
			case 80: strcpy(temp,"P"); break;
			case 81: strcpy(temp,"Q"); break;
			case 82: strcpy(temp,"R"); break;
			case 83: strcpy(temp,"S"); break;
			case 84: strcpy(temp,"T"); break;
			case 85: strcpy(temp,"U"); break;
			case 86: strcpy(temp,"V"); break;
			case 87: strcpy(temp,"W"); break;
			case 88: strcpy(temp,"X"); break;
			case 89: strcpy(temp,"Y"); break;
			case 90: strcpy(temp,"Z"); break;		
		}
	}
	strcpy(reg.ho,temp);	//Caputra homoclave segun el año
	
	//recibe[0] = reg.al;
	
	temp[0] = 48;
	strcpy(reg.h2,temp);	//Caputra homoclave 2	
	
	vectorExmp[*pos].CRP = reg;
}

//Validar numeros tipo int
void validanum(int ri,int rf,char* msge,int *op) {
	int val,i = 0;
	char cad[50];
	
	puts(msge);
	do{
		val = getch();
		if((val >= ri) && (val <= rf))
		{
			printf("%c",val);
			cad[i] = val;
			i++;
		}		
	}while(val != 13);
	//cad[i] = '\0';
	*op = atoi(cad);
}

//Validar numeros tipo long
void validanu(int ri,int rf,char* msge,long *DEL) {
	int val,i = 0;
	char cad[50];
	
	puts(msge);
	do{
		val = getch();
		if((val >= ri) && (val <= rf))
		{
			printf("%c",val);
			cad[i] = val;
			i++;
		}		
	}while(val != 13);
	//cad[i] = '\0';
	*DEL = atoi(cad);
}

