#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dataStruct.h"


/* count the linked list */
void countList(info head)
{
    info p = head;
    int choose;

    printf("You can count in following ways!\n1--age count\n2--wage count\n3--tax count\n4--wage sorting\nYour choose: ");
    scanf("%d", &choose);

    switch(choose)
    {
        case 1:
            {
                int a = 0, b = 0, c = 0;

                while(p->next != NULL)
                {
                    p = p->next;

                    if((p->basic.age) < 20)
                    {
                        a++;
                    }

                    else if((p->basic.age) >= 20 && (p->basic.age) <= 55)
                    {
                        b++;
                    }

                    else if((p->basic.age) > 55)
                    {
                        c++;
                    }
                }

                printf("The Young employees number:%d\nThe Middle-aged employees number:%d\nThe Retired employees number:%d\n", a, b, c);

                break;
            }

        case 2:
            {
                int basicWage1 = 0, jobWage1 = 0, elseWage1 = 0, wageTotal1 = 0;
                int basicWage2 = 0, jobWage2 = 0, elseWage2 = 0, wageTotal2 = 0;
                int basicWage3 = 0, jobWage3 = 0, elseWage3 = 0, wageTotal3 = 0;
                int d = 0, e = 0, f = 0;
                
                while(p->next != NULL)
                {
                    p = p->next;

                    if(!strcmp(p->basic.job, "human"))
                    {
                        basicWage1 += p->wage.basicWage;
                        jobWage1 += p->wage.jobWage;
                        elseWage1 += p->wage.elseWage;
                        wageTotal1 = wageTotal1 + basicWage1 + jobWage1 + elseWage1;
                        d++;
                    }

                    else if(!strcmp(p->basic.job, "finance"))
                    {
                        basicWage2 += p->wage.basicWage;
                        jobWage2 += p->wage.jobWage;
                        elseWage2 += p->wage.elseWage;
                        wageTotal2 = wageTotal2 + basicWage2 + jobWage2 + elseWage2;
                        e++;
                    }

                    else if(!strcmp(p->basic.job, "technology"))
                    {
                        basicWage3 = basicWage3 + p->wage.basicWage;
                        jobWage3 = jobWage3 + p->wage.jobWage;
                        elseWage3 = elseWage3 + p->wage.elseWage;
                        wageTotal3 = wageTotal3 + basicWage3 + jobWage3 + elseWage3;
                        f++;
                    }
                }
                printf("human:\nnum:%d\nbasic wage total:%d\njob wage total:%d\nelse wage total:%d\nwage total:%d\nwage average:%d\n",
                     d, basicWage1, jobWage1, elseWage1, wageTotal1, wageTotal1 / d);

                printf("finance:\nnum:%d\nbasic wage total:%d\njob wage total:%d\nelse wage total:%d\nwage total:%d\nwage average:%d\n",
                     e, basicWage2, jobWage2, elseWage2, wageTotal2, wageTotal2 / e);

                printf("technology:\nnum:%d\nbasic wage total:%d\njob wage total:%d\nelse wage total:%d\nwage total:%d\nwage average:%d\n",
                     f, basicWage3, jobWage3, elseWage3, wageTotal3, wageTotal3 / f);

                printf("The company total wage:%d\n", wageTotal1 + wageTotal2 + wageTotal3);

                break;
            }

        case 3:
            {
                int total, tax, taxYear, taxTotal = 0;

                while(p->next != NULL)
                {
                    p = p->next;
                    total = (p->wage.basicWage) + (p->wage.elseWage) + (p->wage.jobWage) + (p->wage.reward);

                    if(total < 3500)
                    {
                        tax=0;
                    }

                    else
                    {
                        tax = (total - 3500) * 0.1;
                    }

                    taxTotal = taxTotal + tax;
                }

                taxYear=taxTotal*12;

                printf("The company'tax one mouth:%d\nThe company'tax one year:%d\n", taxTotal, taxYear);

                break;
            }

        case 4:
            {
                info head1 = createHead();
                info headMax = createHead();
                info n = headMax;
                info l = headMax;
                info m = head1;
                info q, max;
                info t = head;
                int a = 1;

                while(t->next != NULL)
                {
                    t = t->next;
                    q = (info)malloc(sizeof(infor));
                    *q = *t;
                    m->next = q;
                    q->prior = m;
                    q->next = NULL;
                    m = q;
                }

                while(head1->next != NULL)
                {
                    max = head1->next;
                    q = head1->next;

                    while(q != NULL)
                    {
                        if(((max->wage.basicWage) + (max->wage.elseWage) + (max->wage.jobWage) + (max->wage.reward))
                                < ((q->wage.basicWage) + (q->wage.elseWage) + (q->wage.jobWage) + (q->wage.reward)))
                        {
                            max = q;
                        }
            
                        q = q->next;
                    }

                    m = max;

                    if(max->next != NULL)
                    {
                        max->prior->next = max->next;
                        max->next->prior = max->prior;
                    }

                    else
                    {
                        max->prior->next = max->next;
                        max->prior = NULL;
                    }

                    n->next = m;
                    m->prior = n;
                    m->next = NULL;
                    n = m;
                }

                free(head1);

                while(l->next != NULL)
                {
                    l = l->next;
                    printf("                                (%d)                                       \n", a++);
                    output(l);
                }

                headMax->next->prior = NULL;
                headMax->next = NULL;
                break;
            }
    }
}
