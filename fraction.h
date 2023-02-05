#include <stdio.h>
#include <math.h>
#ifndef FRACTION_H_
#define FRACTION_H_
typedef struct number
{
	int numerator;
	int denominator;
}FRAC;	
void frac_reduce(FRAC *num)				//reduces a fraction
{
	int a = num->numerator;
	int b = num->denominator;
	int min = (a<b)?a:b, i;
	for(i = min; i >= 1; i--)
		if(a%i == 0 && b%i == 0)
			break;
	num->numerator /= i;
	num->denominator /= i;
}
void frac_print(FRAC num)				//prints a fraction
{
	printf("%i", num.numerator);
	if(num.denominator != 1)
		printf("/%i", num.denominator);
}
FRAC frac_create(int a, int b)			//declares a FRAC variable that is equal to a/b
{
	FRAC num;
	num.numerator = a;
	num.denominator = b;
	frac_reduce(&num);
	return num;
}
FRAC frac_add(FRAC num1, FRAC num2)		//returns num1 + num2 as a fraction
{
	FRAC result = frac_create(num1.numerator * num2.denominator + num2.numerator * num1.denominator, num1.denominator * num2.denominator);
	return result;
}
FRAC frac_sub(FRAC num1, FRAC num2)		//returns num1 - num2 as a faction
{
	FRAC result = frac_create(num1.numerator * num2.denominator - num2.numerator * num1.denominator, num1.denominator * num2.denominator);
	return result;	

}
FRAC frac_pro(FRAC num1, FRAC num2)		//returns num1 * num2 as a fraction
{
	FRAC result = frac_create(num1.numerator * num2.numerator, num1.denominator * num2.denominator);
	return result;
}
FRAC frac_div(FRAC num1, FRAC num2)		//returns num1 / num2 as a fraction
{
	FRAC result = frac_create(num1.numerator * num2.denominator, num2.numerator * num1.denominator);
	return result;
}
FRAC frac_pow(FRAC num, int n)			//returns pow(num1,n) as a fraction
{
	FRAC result = frac_create(pow(num.numerator,n),pow(num.denominator,n));
	return result;
}
float frac_to_dec(FRAC num)				//returns the fraction as a float
{
	float result = (float) num.numerator / num.denominator;
	return result;
}
#endif