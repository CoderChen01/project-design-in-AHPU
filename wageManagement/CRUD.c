#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dataStruct.h"


/* add record to the linked list */
void newList(info head)
{
    info p, q;
    int a;

    p = head;  /* P is a temporary variable */

    do
    {
        q = (info)malloc(sizeof(infor));

        printf("||                         Please enter info!                       ||\n");
        input(q);

        p->next = q;
        q->prior = p;

        p = q;  /* P is a temporary variable which will point next info */
        p->next = NULL;

        printf("                        Continue? 1/0: ");
        scanf("%d",&a);
    } while(a==1);
}


/* retrieve a record according name of work ID*/
info searchKey(info head)
{
    info p = head;
    int choose;

    printf("The keyword:\n1--workID\n2--name\nYour choose: ");
    scanf("%d", &choose);

    if(choose == 1)
    {
        char a[80];

        printf("workID: ");
        scanf("%s", a);

        while(p->next != NULL)
        {
            p = p->next;

            if(!strcmp(a, p->basic.workID))
            {
                return p;
            }
        }

        if(p->next == NULL)
        {
            return NULL;
        }
    }

    else if(choose == 2)
    {
        char b[80];

        printf("name: ");
        scanf("%s", b);

        while(p->next != NULL)
        {
            p = p->next;

            if(!strcmp(b, p->basic.name))
            {
                return p;
            }
        }

        if(p->next == NULL)
        {
            return NULL;
        }
    }
}


/* Traversing the list. */
void searchList(info head)
{
    info q, p = head;
    int choose;

    printf("||             You have two ways to search the information!             ||\n");
    printf("||      1--search all information!  2--search keyword information!      ||\n");

    printf("                       Your choose: ");
    scanf("%d",&choose);

    if(choose == 1)
    {
        printf("||                    The information:                          ||\n");

        int a = 1;

        while(p->next != NULL)
        {
            p = p->next;

            printf("                            (%d)                                  \n",a++);
            output(p);
        }
    }

    else if(choose == 2)
    {
        q = searchKey(head);

        if(q != NULL)
        {
            printf("||              The information you want to search:                   ||\n");
            output(q);
        }

        else if(q == NULL)
        {
            printf("||              The keyword can't find!                             ||\n");
        }
    }
}


/* update a record according a keyword */
void modifyList(info head)
{
    info p, q = head;

    printf("which one you want to modify?\nYou can search the information you want to modify in keyword!\n");
    p = searchKey(q);

    printf("The information you want to modify:\n");
    output(p);

    printf("Which one you want to modify?\n");
    printf("1--work ID\n2--ID number\n3--name\n4--gender\n5--age\n6--work age\n7--department\n8--job\n9--job ID\n10--home number\n11--person number\n12--basic wage\n13--job wage\n14--else wage\n15--reward\n16--home cost\n17--job insurance\n18--age insurance\n19--person tax\n20--water fee\n21--electricity fee\n22--clean fee\n23--TV fee\nYour choose: ");

    int a;
    scanf("%d",&a);

    printf("New data: ");

    switch(a)
    {
        case 1 : scanf("%s", p->basic.workID); break;
        case 2 : scanf("%s", p->basic.IDNumber); break;
        case 3 : scanf("%s", p->basic.name); break;
        case 4 : scanf("%s", p->basic.gender); break;
        case 5 : scanf("%d", &p->basic.age); break;
        case 6 : scanf("%d", &p->basic.workAge); break;
        case 7 : scanf("%s", p->basic.department); break;
        case 8 : scanf("%s", p->basic.job); break;
        case 9 : scanf("%d", &p->basic.jobID); break;
        case 10: scanf("%s", p->basic.homeNumber); break;
        case 11: scanf("%s", p->basic.personNumber); break;
        case 12: scanf("%d", &p->wage.basicWage); break;
        case 13: scanf("%d", &p->wage.jobWage); break;
        case 14: scanf("%d", &p->wage.elseWage); break;
        case 15: scanf("%d", &p->wage.reward); break;
        case 16: scanf("%d", &p->cost.homeCost); break;
        case 17: scanf("%d", &p->cost.jobInsurance); break;
        case 18: scanf("%d", &p->cost.ageInsurance); break;
        case 19: scanf("%d", &p->cost.personTax); break;
        case 20: scanf("%d", &p->fee.waterFee); break;
        case 21: scanf("%d", &p->fee.electricityFee); break;
        case 22: scanf("%d", &p->fee.cleanFee); break;
        case 23: scanf("%d", &p->fee.TVFee); break;
        default: printf("no this choice!"); break;
    } 
}


/* delete a record */
void deleteList(info head)
{
    info q, p = head;

    printf("Search the information you want to delete in keyword!\n");
    q = searchKey(p);

    if(q == NULL)
    {
        printf("The key can't find!\n");
    }

    else if(q != NULL)
    {
        printf("The information you want to delete: \n");
        output(q);

        printf("yes? 1/0: ");

        int a;
        scanf("%d", &a);

        if(a == 1)
        {
            if(q->next != NULL)
            {
                q->prior->next = q->next;
                q->next->prior = q->prior;
                free(q);
            }

            else
            {
                q->prior->next = q->next;
                q->prior = NULL;
                free(q);
            }
        }
    }

}


/* insert a record to linked list */
void insertList(info head)
{
    info q, l, p = head;

    printf("Search the information your want to insert in keyword!\n");
    q = searchKey(p);

    if(q == NULL)
    {
        printf("The key can't find!\n");
    }

    else if(q != NULL)
    {
        printf("The information you want to insert:\n");
        output(q);

        printf("You want to insert in the next? 1/0  ");

        int a;
        scanf("%d", &a);

        if(a == 1)
        {
            if(q->next != NULL)
            {
                l = (info)malloc(sizeof(infor));

                input(l);

                l->next = q->next;
                l->prior = q;
                q->next->prior = l;
                q->next = l;
            }

            else 
            {
                l = (info)malloc(sizeof(infor));

                input(l);

                q->next = l;
                l->prior = q;
                l->next = NULL;
            }
        }

        else if(a == 0)
        {
            l = (info)malloc(sizeof(infor));

            input(l);

            l->prior = q->prior;
            l->next = q;
            q->prior->next = l;
            q->prior = l;
        }
    }
}


/* free all linked list */
int freeList(info head)
{
    info p = head;
    int choose;

    printf("||               You have entered the information already!              ||\n");
    printf("||     Do you enter new information by clearing the old information!    ||\n");

    printf("                           Your choose:(1/0):  ");
    scanf("%d", &choose);

    if(choose == 1)
    {
        p->next->prior = NULL;
        p->next = NULL;

        printf("Your old information is cleared!\n");

        return 1;
    }

    else if(choose == 0)
    {
        return 0;
    }
}

