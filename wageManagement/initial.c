#include <stdio.h>
#include <stdlib.h>

#include "dataStruct.h"


/* create linked list head. */
info createHead()
{
    info head;
    
    head = (info)malloc(sizeof(infor));
    head->prior = NULL;
    head->next = NULL;
    
    return head;
}


/* record user's choose */
int userChoose()
{
	printf("                            |         |         |                       \n");
	printf("                             |       | |       |                        \n");								 
	printf("                              |     |   |     |                         \n");								  
	printf("                               |   |     |   |                          \n");								   
	printf("                                | |       | |                           \n");							    
	printf("                                 |         |                            \n");									 
	
    printf("||                    This program has seven choose!                    ||\n");
    printf("||                      Please make your choose!                        ||\n");
    printf("||           1--ENTRY INFORMATION      2--MODIFY INFORMATION            ||\n");
    printf("||           3--INSERT INFORMATION     4--DELETE INFORMATION            ||\n");
    printf("||           5--SEARCH INFORMATION     6--COUNT INFORMATION             ||\n");
    printf("||                               0--END                                 ||\n");
    printf("                              your choose is: ");
    
    int choose;
    
    scanf("%d", &choose);
    
    
    return choose;
}
