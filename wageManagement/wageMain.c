#include <stdio.h>
#include <stdlib.h>

#include "dataStruct.h"
#include "wageHeadFile.h"


int wageMain()
{
    info head;
    
    head = createHead();

    printf("\n\n=============================== third problem ============================\n\n\n");

    int choose, i=0;

    i = readFile(head);

    while(1)
    {
        choose = userChoose();

        switch(choose)
        { 
            case 1:
            {
                if(i == 0) 
                {
                    newList(head);
                    saveFile(head);
                    i = 1;
                    break;
                }

                else if(i == 1) 
                {
                    int a;
                    a = freeList(head);

                    if(a == 0)
                    {
                        break;
                    }

                    else if(a == 1)
                    {
                        newList(head);
                        saveFile(head);
                        break;
                    }
                }
            }
                
            case 2:
            {
                if(i == 0) 
                {
                    printf("||                 You haven't entered the information!                 ||\n");
                    printf("||                Please enter the information firstly!                 ||\n");
                    break;
                }
                else
                {
                    modifyList(head);
                    saveFile(head);
                    break;
                }

            }

            case 3:
            {
                if(i == 0) 
                {
                    printf("||                 You haven't entered the information!                 ||\n");
                    printf("||                Please enter the information firstly!                 ||\n");
                    break;
                }

                else
                {
                    insertList(head);
                    saveFile(head);
                    break;
                }
            }
                
            case 4:
            {
                if(i == 0) 
                {
                    printf("||                 You haven't entered the information!                 ||\n");
                    printf("||                Please enter the information firstly!                 ||\n");
                    break;
                }
                else
                {
                    deleteList(head);
                    saveFile(head);
                    break;
                }

            }
               
            case 5:
            {
                if(i == 0) 
                {
                    printf("||                 You haven't entered the information!                 ||\n");
                    printf("||                Please enter the information firstly!                 ||\n");
                    break;
                }
                else
                {
                    searchList(head);
                    saveFile(head);
                    break;
                }
            }
                
            case 6:
            {
                if(i == 0) 
                {
                    printf("||                 You haven't entered the information!                 ||\n");
                    printf("||                Please enter the information firstly!                 ||\n");
                    break;
                }
                else
                {
                    countList(head);
                    break;
                }
            }
                
            case 0: exit(0);
        }
    }

    return 0;
}
