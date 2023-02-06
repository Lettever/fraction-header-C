#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#ifndef FRACTION_H_
#define FRACTION_H_

typedef struct number
{
	int numerator;
	int denominator;
}FRAC;

void frac_reduce(FRAC* num)						//reduces a fraction
{
	int a = abs(num->numerator);
	int b = abs(num->denominator);
	int min = (a<b)?a:b, i;
	for(i = min; i >= 1; i--)
		if(a%i == 0 && b%i == 0)
			break;
	num->numerator /= i;
	num->denominator /= i;
}
void frac_print(FRAC num)						//prints a fraction
{
	printf("%i", num.numerator);
	if(num.denominator != 1)
		printf("/%i", num.denominator);
}

float frac_to_dec(FRAC num)						//returns the fraction as a float
{
	float result = (float) num.numerator / num.denominator;
	return result;
}

FRAC frac_create(int a, int b)					//declares a FRAC variable that is equal to a/b
{
	if(b == 0)
	{
		printf("ERROR: Denominator cannot be 0");
		exit(727);
	}
	if(b < 0)
	{
		a*=-1;
		b*=-1;
	}
	FRAC num;
	num.numerator = a;
	if(a == 0)
		num.denominator = 1;
	else
	{
		num.denominator = b;
		frac_reduce(&num);
	}
	return num;
}
FRAC frac_add(FRAC num1, FRAC num2)				//returns num1 + num2 as a FRAC
{
	FRAC result = frac_create(num1.numerator * num2.denominator + num2.numerator * num1.denominator, num1.denominator * num2.denominator);
	return result;
}
FRAC frac_sub(FRAC num1, FRAC num2)				//returns num1 - num2 as a FRAC
{
	FRAC result = frac_create(num1.numerator * num2.denominator - num2.numerator * num1.denominator, num1.denominator * num2.denominator);
	return result;	

}
FRAC frac_prod(FRAC num1, FRAC num2)			//returns num1 * num2 as a FRAC
{
	FRAC result = frac_create(num1.numerator * num2.numerator, num1.denominator * num2.denominator);
	return result;
}
FRAC frac_div(FRAC num1, FRAC num2)				//returns num1 / num2 as a FRAC
{
	FRAC result = frac_create(num1.numerator * num2.denominator, num2.numerator * num1.denominator);
	return result;
}
FRAC frac_pow(FRAC num, int n)					//returns pow(num1,n) as a FRAC
{
	FRAC result = frac_create(pow(num.numerator,n),pow(num.denominator,n));
	return result;
}
FRAC frac_array_mean1(int* arr, int size)		//returns the arithmetic mean of an array of ints as a FRAC
{
	int i, sum=0;
	for(i=0;i<size;i++)
		sum+=arr[i];
	FRAC result = frac_create(sum,size);
	return result;
}
FRAC frac_array_mean2(FRAC* arr, int size)		//returns the arithmetic mean of an array of FRACs as a FRAC
{
	int i;
	FRAC sum = frac_create(0,2);
	for(i=0;i<size;i++)
		sum = frac_add(sum,arr[i]);
	FRAC size2 = frac_create(1,size);
	FRAC result = frac_prod(sum,size2);
	return result;
}
FRAC* frac_array_invert1(int* arr, int size)	//returns 1/*arr as an array of FRACs
{
	FRAC* result = (FRAC*)malloc(size*sizeof(FRAC));
	int i;
	for(i=0;i<size;i++)
		result[i]=frac_create(1,arr[i]);
	return result;
}
FRAC* frac_array_invert2(FRAC* arr, int size)	//returns the inverse of *arr as an array of FRACs
{
	FRAC* result = (FRAC*)malloc(size*sizeof(FRAC));
	int i;
	for(i=0;i<size;i++)
		result[i]=frac_create(arr[i].denominator,arr[i].numerator);
	return result;
}
#endif
