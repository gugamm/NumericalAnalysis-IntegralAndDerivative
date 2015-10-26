/*********************************
* NOME : GUSTAVO MARQUES MARTINS
* MATRICULA : 1310630
* LAB8
* DERIVADA
**********************************/

#include <stdio.h>
#include <conio.h>
#include <math.h>

static double f(double x) {
	return 1 / (1+x);
}

static double analitica(double x) {
	return - (1 / ((x+1)*(x+1))); 
}

static double fd(double x, double h) {
	return (f(x + h) - f(x - h)) / (2*h);
}

static double f3(double x) {
	return -6 / pow((x + 1),4);
}

static double erroteorico (double h) {
	double flll = f3(1);
	return (h*h)/6 * flll + pow(2.0,-52)/h; 
}

int main(void) {
	int i;
	double h;
	double anali;
	double derivada;
	double errodiferenca;
	double teorico;
	double menorteorico = -1;
	double menorerro = -1;
	int menorindice, indiceteorico;
	for (i = 1; i <= 12; i++) {
		h = pow(10.0,-i);
		derivada = fd(1,h);
		anali = analitica(1);
		errodiferenca = fabs(anali - derivada);
		teorico = fabs(erroteorico(h));
		if (menorteorico == -1) {
			menorteorico = teorico;
			indiceteorico = i;
		} else if (menorteorico > teorico) {
			menorteorico = teorico;
			indiceteorico = i;
		}
		if (menorerro == -1) {
			menorerro = errodiferenca;
			menorindice = i;
		} else if (menorerro > errodiferenca) {
			menorerro = errodiferenca;
			menorindice = i;
		}
		printf("H : %.12f  F'(1) : %.12f  f'(1)[analitica] : %.12f  err : %.12f  ErrTeorico : %.12f\n",h,derivada,anali,errodiferenca,teorico);
	}

	printf("MENOR ERRO DA TABELA: %.12f\n"
		   "Melhor valor de h da tabela: %.12f\n"
		   "MENOR ERRO TEORICO : %.12f\n"
		   "Melhor valor de h teorico : %.12f\n",menorerro,pow(10.0,-menorindice),menorteorico,pow(10.0,-indiceteorico));
	_getch();
	return 0;
}