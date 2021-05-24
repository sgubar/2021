#include <iostream>
#include <stdlib.h> 
typedef struct Node
{
  int value;
  struct Node* next;
} Spisok;

Spisok* create(int data)
{
  Spisok* tmp = (Spisok*)malloc(sizeof(Spisok));
 tmp->value = data;
  tmp->next = NULL;
  return(tmp);
}

Spisok* add_element_start(int data, Spisok* head)
{
  Spisok* tmp = (Spisok*)malloc(sizeof(Spisok));
  tmp->value = data;
  tmp->next = head;
  return(tmp);
}
void add_element_end(int data, Spisok* head)
{
  Spisok* tmp = (Spisok*)malloc(sizeof(Spisok));
   tmp->value = data;
  tmp->next = NULL;
  Spisok* p = head;
  while (p->next != NULL)
    p = p->next;
 p->next = tmp;
}
Spisok* add_element_n_position(int data, int n, Spisok* head)
{
  
  Spisok* p = head;
  int count = 1;
  while (count < n - 1 && p->next != NULL)
  {
    p = p->next;
    count++;
  }
  Spisok* tmp = (Spisok*)malloc(sizeof(Spisok));
  tmp->value = data;
  tmp->next = p->next;
  p->next = tmp;
  return head;
}

Spisok* remove_all(Spisok* head)
{
  while (head != NULL)
  {
    Spisok* p = head;
    head = head->next;
    free(p);
  }
  return NULL;
}

Spisok* remove_element(int data, Spisok* head)
{
  Spisok* tmp = head, * p = NULL;
  if (head == NULL)
    return NULL;
  while (tmp && tmp->value != data)
  {
    p = tmp;
    tmp = tmp->next;
  }
  if (tmp == head)
  {
    free(head);
    return tmp->next;
  }
   
   if (!tmp)
    return head;
   p->next = tmp->next;
  free(tmp);
  return head;
}  

int main()
{
  Spisok* tmp = create(2);
  add_element_end(3, tmp);
  add_element_end(3, tmp);
  add_element_end(6, tmp);
  add_element_end(7, tmp);
  add_element_end(8, tmp);
  add_element_end(8, tmp);
  add_element_end(9, tmp);
  Spisok* nTmp = create(0);

  int mass[8];
  int i = 0;

  while (tmp != NULL)
  {
    printf("%d ", tmp->value);
    mass[i] = tmp->value;
    bool finded = false;

    int k = 0;
    while (k != 8)
    {
      if (mass[k] == mass[i] && k != i)
      {
        printf("\n\tremove: %d \n", mass[i]);
        finded = true;
      }
      k++;
    }

    if (!finded)
    {
      add_element_end(mass[i], nTmp);
    }
      
      tmp = tmp->next;
    i++;
  }

  printf("\nNew list\n ");


  while (nTmp!= NULL)
  {
   printf("%d ", nTmp->value);
    nTmp= nTmp->next;
  }
}
