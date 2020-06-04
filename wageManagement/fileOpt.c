#include <stdio.h>
#include <stdlib.h>

#include "dataStruct.h"

#define TRUE 1
#define FALSE 0


/* read records from binary file */
int readFile(info head)
{
    info q, p = head;
    FILE *fp;

    fp = fopen("db.dat","rb");  /* open a file */

    if(!fp)
    {
        return FALSE;
    }

    else
    {
        while(!feof(fp))
        {
            q = (info)malloc(sizeof(infor));

            fread(q, sizeof(infor), 1, fp);  /* read binary data to linked list */

            p->next = q;
            q->prior = p;
            q->next = NULL;
            p = q;  /* p will point next */
        }

        p->prior->next = NULL;
        
        /* release resource */
        free(p);
        fclose(fp);

        return TRUE;
    }
}


/* Persistent linked list */
void saveFile(info head)
{
    info p = head;
    FILE *fp;

    fp = fopen("db.dat","wb+");

    while(p->next != NULL)
    {
        p = p->next;
        fwrite(p, sizeof(infor), 1, fp);
    }

    fclose(fp);
}
