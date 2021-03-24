#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.14159265358979323846

/* Task1 */
typedef struct
{
	double re;
	double im;
} complex;

/* Task2 */
complex Conjugate(complex c)
{
	complex placeholder;

	placeholder.re = c.re;
	placeholder.im = -c.im;

	return (placeholder);
}

/* Task3 */
double Modulus(complex c)
{
	double real, imaginary, result;

	real = pow(c.re, 2.0);
	imaginary = pow(c.im, 2.0);
	result = sqrt(real + imaginary);

	return (result);
}

/* Task4 */
double Argument(complex c)
{
	double result;

	if (c.re > 0)
		result = atan(c.im/c.re);
	else if (c.im > 0)
		result = (PI/2) - atan(c.re/c.im);
	else if  (c.im < 0)
		result = -(PI/2) - atan(c.re/c.im);
	else if (c.re < 0)
		result = atan(c.im/c.re) + PI;
	else
		return (0);

	return (result);
}

/* Task5 */
void Addition(complex c1, complex c2, complex *c3)
{
	double real, imaginary;

	real = (c1.re + c2.re);
	imaginary = (c1.im + c2.im);
	c3->re = real;
	c3->im = imaginary;
}

/* Task6 */
void Subtraction(complex c1, complex c2, complex *c3)
{
	double real, imaginary;

	real = (c1.re - c2.re);
	imaginary = (c1.im - c2.im);
	c3->re = real;
	c3->im = imaginary;
}


/* Task7 */
void Multiplication(complex c1, complex c2, complex *c3)
{
	double real, imaginary;

	real = (c1.re * c2.re - c1.im * c2.im);
	imaginary = (c1.re * c2.im + c2.re * c1.im);
	c3->re = real;
	c3->im = imaginary;
}

/* Task8 */
void Division(complex c1, complex c2, complex *c3)
{
	double real, imaginary, x, y, z;

	if (c2.re == 0 && c2.im == 0)
		return;
	else
	{
		x = c1.re * c2.re + c1.im * c2.im;
		y = c1.im * c2.re - c1.re * c2.im;
		z = c2.re * c2.re + c2.im * c2.im;

		real = x / z;
		imaginary = y / z;

		c3->re = real;
		c3->im = imaginary;
	}
}

/* Task9 */
void ComplexFromModArg (double m, double arg, complex *c3)
{
	double real, imaginary;

	real = m * cos(arg);
	imaginary =  m * sin(arg);

	c3->re = real;
	c3->im = imaginary;
}

/* Task10 */
void ComplexNumber(complex c)
{
	double no_sign;
	if (c.im > 0)
		printf("%.2f+i%.2f\n", c.re, c.im);
	else if (c.im < 0)
	{
		no_sign = -c.im;
		printf("%.2f-i%.2f\n", c.re, no_sign);
	}
	else
		printf("%.2f\n", c.re);
}

/* main function */
int main(void)
{
	complex c1;
	complex c2;
	complex c3;

	c1.re = 3;
	c1.im = 4;
	c2.re = 1;
	c2.im = 2;

	printf("Conjugate: ");
	ComplexNumber(Conjugate(c1));

	printf("Modulus: %.2f\n", Modulus(c1));

	printf("Argument: %.2f\n", Argument(c1));

	printf("C1 is equal to: ");
	ComplexNumber(c1);
	printf("C2 is equal to: ");
	ComplexNumber(c2);

	printf("Addition: ");
	Addition(c1,c2,&c3);
	ComplexNumber(c3);

	printf("Subtraction: ");
	Subtraction(c1,c2,&c3);
	ComplexNumber(c3);

	printf("Multiplication: ");
	Multiplication(c1,c2,&c3);
	ComplexNumber(c3);

	printf("Division: ");
	Division(c1,c2,&c3);
	ComplexNumber(c3);

	printf("From Mod and Arg: ");
	ComplexFromModArg(6,7,&c3);
	ComplexNumber(c3);

	return (0);
}
