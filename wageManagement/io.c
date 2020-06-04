#include <stdio.h>

#include "dataStruct.h"


/* enter a new record */
void input(info p)
{
    printf("||                   Now enter the basic information!                   ||\n");
    printf("                         work ID:");
    scanf("%s", p->basic.workID);
    printf("                         ID number:");
    scanf("%s", p->basic.IDNumber);
    printf("                         name:");
    scanf("%s", p->basic.name);
    printf("                         gender:");
    scanf("%s", p->basic.gender);
    printf("                         age:");
    scanf("%d", &p->basic.age);
    printf("                         work age:");
    scanf("%d", &p->basic.workAge);
    printf("                         department:");
    scanf("%s", p->basic.department);
    printf("                         job:");
    scanf("%s", p->basic.job);
    printf("                         job ID:");
    scanf("%d", &p->basic.jobID);
    printf("                         home number:");
    scanf("%s", p->basic.homeNumber);
    printf("                         person number:");
    scanf("%s", p->basic.personNumber);
    
    printf("||                 Now enter your basic wage information!               ||\n");
    printf("                         basic wage:");
    scanf("%d", &p->wage.basicWage);
    printf("                         job wage:");
    scanf("%d", &p->wage.jobWage);
    printf("                         else wage:");
    scanf("%d", &p->wage.elseWage);
    printf("                         reward:");
    scanf("%d", &p->wage.reward);

    printf("||                   Now enter the cost information!                    ||\n");
    printf("                         home cost:");
    scanf("%d", &p->cost.homeCost);
    printf("                         job insurance:");
    scanf("%d", &p->cost.jobInsurance);
    printf("                         age insurance:");
    scanf("%d", &p->cost.ageInsurance);
    
    p->wage.wageTotal = p->wage.basicWage + p->wage.elseWage + p->wage.jobWage + p->wage.reward;

    if(p->wage.wageTotal<3500)
    {
        p->cost.personTax=0;
    }

    else
    {
        p->cost.personTax = (p->wage.wageTotal-3500) * 0.1;
    }

    printf("||                   Now enter the fee information!                     ||\n");
    printf("                     water fee:");
    scanf("%d", &p->fee.waterFee);
    printf("                          electricity fee:");
    scanf("%d", &p->fee.electricityFee);
    printf("                          clean fee:");
    scanf("%d", &p->fee.cleanFee);
    printf("                          TV fee:");
    scanf("%d", &p->fee.TVFee);
}


/* print a record */
void output(info p)
{
    printf("||                         Basic information:                           ||\n");
    printf("                           work ID:%s                                     \n", p->basic.workID);
    printf("                           ID number:%s                                   \n", p->basic.IDNumber);
    printf("                           name:%s                                        \n", p->basic.name);
    printf("                           gender:%s                                      \n", p->basic.gender);
    printf("                           age:%d                                         \n", p->basic.age);
    printf("                           work age:%d                                    \n", p->basic.workAge);
    printf("                           department:%s                                  \n", p->basic.department);
    printf("                           job:%s                                         \n", p->basic.job);
    printf("                           job ID:%d                                      \n", p->basic.jobID);
    printf("                           home number:%s                                 \n", p->basic.homeNumber);
    printf("                           person number:%s                               \n", p->basic.personNumber);

    printf("||                      Basic wage information:                           \n");
    printf("                           basic wage:%d                                  \n", p->wage.basicWage);
    printf("                           job wage:%d                                    \n", p->wage.jobWage);
    printf("                           else wage:%d                                   \n", p->wage.elseWage);
    printf("                           reward:%d                                      \n", p->wage.reward);

    printf("||                        Cost information:                             ||\n");
    printf("                           home cost:%d                                   \n", p->cost.homeCost);
    printf("                           job insurance:%d                               \n", p->cost.jobInsurance);
    printf("                           age insurance:%d                               \n", p->cost.ageInsurance);
    printf("                           person tax:%d                                  \n", p->cost.personTax);
    
    printf("||                        Fee information:                              ||\n");
    printf("                           water fee:%d                                   \n", p->fee.waterFee);
    printf("                           electricity fee:%d                             \n", p->fee.electricityFee);
    printf("                           clean fee:%d                                   \n", p->fee.cleanFee);
    printf("                           TV fee:%d                                      \n", p->fee.TVFee);
}

