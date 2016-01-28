/********************************
* NOME : GUSTAVO MARQUES MARTINS
* LAB8
* INTEGRAL
**********************/

#include <stdio.h>
#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES //para usar M_PI (VALOR DE PI)
#endif
#include <math.h>
#include <conio.h> //para _getch();

//Calcula o valor aproximado de uma integral usando o metodo de simpson simples
static double simpson(double a, double b, double(*f) (double));

// Como a formula de simpson não funciona bem para intervalos muito grandes, utiliza-se o metodo
// de simpson composto. Divide-se o intervalo [a,b] em sub-intervalos e utiliza-se a formula de 
// simpson simples nesses sub-intervalos
static double simpsonComposto(double a, double b, int n, double(*f) (double));

// Formula de simpson usando-se valores medios dos sub-intervalos
// integral = h * (soma dos valores medios dos sub-intervalos)
static double simpsonMedio(double a, double b, int n, double(*f) (double));

static double fa(double x);
static double fb(double x);
static double fc(double x);

int main(void) {
	printf("-----INTEGRAL A-----\n");
	printf("M16 : %.10f\n", simpsonMedio(0.0, 4.0, 16, fa));
	printf("M32 : %.10f\n", simpsonMedio(0.0, 4.0, 32, fa));
	printf("S16 : %.10f\n", simpsonComposto(0.0, 4.0, 16, fa));
	printf("S32 : %.10f\n", simpsonComposto(0.0, 4.0, 32, fa));

	printf("\n");

	printf("-----INTEGRAL B-----\n");
	printf("M16 : %.10f\n", simpsonMedio(1.0, 3.0, 16, fb));
	printf("M32 : %.10f\n", simpsonMedio(1.0, 3.0, 32, fb));
	printf("S16 : %.10f\n", simpsonComposto(1.0, 3.0, 16, fb));
	printf("S32 : %.10f\n", simpsonComposto(1.0, 3.0, 32, fb));

	printf("\n");

	printf("-----INTEGRAL C-----\n");
	printf("M16 : %.10f\n", simpsonMedio(0.0, M_PI, 16, fc));
	printf("M32 : %.10f\n", simpsonMedio(0.0, M_PI, 32, fc));
	printf("S16 : %.10f\n", simpsonComposto(0.0, M_PI, 16, fc));
	printf("S32 : %.10f\n", simpsonComposto(0.0, M_PI, 32, fc));

	_getch();
	return 0;
}

static double simpson(double a, double b, double(*f) (double)) {
	return ((b - a) / 6) * (f(a) + 4*f((a+b)/2) + f(b));
}

static double simpsonComposto(double a, double b, int n, double(*f) (double)) {
	double aPart = f(a) + f(b);
	double bPart;
	double sum = 0.0;
	int i;
	double xi = a;
	double h = (b - a) / (n);

	for (i = 1; i < n; i++) {
		xi += h;
		if (i & 1)//Se o valor eh impar
			sum += 4 * f(xi);
		else //Valor eh par 
			sum += 2 * f(xi);
	}
	bPart = sum;
	return (h / 3.0) * (aPart + bPart);
}

static double simpsonMedio(double a, double b, int n, double(*f) (double)) {
	double sum = 0.0;
	int i;
	double xi = a;
	double h = (b - a) / (n);
	double m;
	for (i = 0; i < n; i++) {
		m = (2 * xi + h) / 2.0;
		sum += f(m);
		xi += h;
	}
	return h * sum;
}

static double fa(double x) {
	return x / (sqrt(x*x + 9));
}

static double fb(double x) {
	return (x*x) * log(x);
}

static double fc(double x) {
	return (x*x) * sin(x);
}
