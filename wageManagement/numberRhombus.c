/***************************************
author: ChenJunjie
descripthion: input an odd number less than or equal to 17 then print a number rhombus.
input: an odd number less than or equal to 17
output: for example -> 7
         1
       22  22
    333      333
4444            4444
    333      333
       22  22
         1
****************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define FAILURE -1


int numberRhombusMain()
{
	int sideSpaceNum(int lineNum, int middleNum);
	int middleSpaceNum(int lineNum, int middleNum);
	void printLine(int sideSpaceNum, int number, int middleSpaceNum);
	
	int n, i, middleNum, lineNum, sideSpace, middleSpace;
	
	printf("\n\n======================== second problem =========================\n");
	printf("Please enter your number: ");	
	scanf("%d", &n);
	
	if (n % 2 == 0 || n > 17)
	{
		printf("error: The number you enter must be an odd number less than or equal to 17!\n");
		return;
	}
	
	middleNum = (n + 1) / 2;
	
	for (i = 1; i <= n; ++i)
	{
		if (i > middleNum)
		{
			lineNum = 2 * middleNum - i;
		}
		else
		{
			lineNum = i;
		}
		
		printLine(sideSpaceNum(lineNum, middleNum), lineNum,
							 middleSpaceNum(lineNum, middleNum));
	}
}


/*************************************************
Function: sideSpaceNum
Description: Count the number of Spaces on the edge
Called By: main, middleSpaceNum
Input: current line number and middle line number
Return: the number of spaces on the edge
*************************************************/
int sideSpaceNum(int lineNum, int middleNum)
{
	int i, sum = 0;
	
	for (i = 0; i < fabs(middleNum - lineNum); ++i)
	{
		sum += middleNum - i;
	}
	
	return sum;
}


/*************************************************
Function: middleSpaceNum
Description: Count the number of Spaces in between
Call: sideSpaceNum
Called By: main
Input: current line number and middle line number
Return: the number of spaces in between
*************************************************/
int middleSpaceNum(int lineNum, int middleNum)
{
	int sideSpaceNum(int lineNum, int middleNum);
	int i, sideSpace, sumSpace;
	
	sideSpace = sideSpaceNum(lineNum, middleNum);
	
	sumSpace = (1 + middleNum) * middleNum / 2;
	
	return (sumSpace - sideSpace - lineNum);
 } 
 
 
void _printSideSpace(int sideSpaceNum)
{
	int j;
	
	for (j = 0; j < sideSpaceNum; ++j)
	{
		printf(" ");	
	} 
} 


void _printNumber(int number)
{
	int j;
	
	for (j = 0; j < number; ++j)
	{
		printf("%d", number);	
	} 
} 


void _printMiddleSpace(int middleSpaceNum)
{
	int j;
	
	for (j = 0; j < middleSpaceNum; ++j)
	{
		printf(" ");
	}
	
	for (j = 0; j < middleSpaceNum; ++j)
	{
		printf(" ");
	}
	
}


void printLine(int sideSpaceNum, int number, int middleSpaceNum)
{
	void _printSideSpace(int sideSpaceNum);
	void _printNumber(int number);
	void _printMiddleSpace(int middleSpaceNum);
		
		
	_printSideSpace(sideSpaceNum);
	_printNumber(number);
	
	_printMiddleSpace(middleSpaceNum);
	
	if (number != 1)
	{
		_printNumber(number);
	}
	
	_printSideSpace(sideSpaceNum);
	
	printf("\n");	

}
 
