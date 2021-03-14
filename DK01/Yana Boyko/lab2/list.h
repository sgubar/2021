#ifndef list_h
#define list_h
#include <stdio.h>

typedef struct tagCharacter Character;

struct tagCharacter
{
    char value;
    Character *prev;
    Character *next;
};


Character *createCharacter(char value);
void deleteCharacter(Character *element);
void printCharacter(Character *element);

//Row
typedef struct tagRow
{
    Character *head;
  
    Character *tail;
} Row;

Row *createRow(void);

void deleteRow(Row *list);

void printReverseRow(Row *list);

// 1: success, 0 - fail

int addCharacterToRow(Row *list, char value);


#endif /* list_h */
