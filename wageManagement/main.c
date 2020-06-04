#include <stdio.h>
#include <stdlib.h> 
#include "projectDesign.h"

int main()
{
	void teacherCheck(); 
	printf("================ Project Design =================\n");
	printf("             author: 计算机193陈俊杰\n");
	printf("             mychoose: 工资管理系统\n");
	printf("      1-first problem        2-second problem\n");
	printf("               3-wage management\n\n");
	
	while(1)
	{
		teacherCheck();
	}
}


void teacherCheck()
{
	int choose;
	
	printf("\n\nnow, please teacher input problem number to check my work: ");
    scanf("%d", &choose);

    switch (choose)
    {
    case 1:
    {
    	sellFishMain();
        break;
    }
        
    case 2:
    {
        numberRhombusMain();
        break;
    }
    
    case 3:
    {
        wageMain();
        break;
    }
    
    default:
    {
    	printf("Oh, my dear teacher, no this problem %d", choose);
    	
    	getchar(); getchar();
    	
        exit(1);
         
	}
    
    }
}
