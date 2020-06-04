#ifndef WEGE_HEAD_FILE
#define WEGE_HEAD_FILE


#include "dataStruct.h"

info createHead();
int userChoose();

void newList(info head);

info searchKey(info head);
void searchList(info head);

void modifyList(info head);
void insertList(info head);

void deleteList(info head);
int freeList(info head);

int readFile(info head);
void saveFile(info head);

void countList(info head);

#endif
