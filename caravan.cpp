/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class name here>
 *-----------------------------------------------------------------------------
 * Exercise Number: #exercise_number#
 * File:			caravan.c
 * Author(s):		Peter Bauer
 * Due Date:		#due#
 *-----------------------------------------------------------------------------
 * Description:
 * <your description here>
 *-----------------------------------------------------------------------------
*/

#include "caravan.h"
Caravan new_caravan()
{
  Caravan caravan = (Caravan)malloc(sizeof(caravan));
  caravan->head = 0;
  return caravan;
}

int get_length(Caravan caravan)
{
  int count=0;
  Node* currentNode=caravan->head;

  while(currentNode!=0)
  {
    count++;
    currentNode=currentNode->next;
  }
return count;
}

void delete_caravan(Caravan caravan){
  int length = get_length(caravan);

  for(int i = 0; i < length; i++){
  Node* head = caravan->head;
  caravan->head = head->next;
  sfree(head);
}

sfree(caravan);
}


void add_pack_animal(Caravan caravan, PackAnimal animal)
{
  if ((animal == 0) || (animal->caravan == caravan)){
    return;
  }
  struct Node *current = (struct Node *)malloc(sizeof(struct Node));

  animal->caravan = caravan;

  current->data = animal;
  current->next = caravan->head;
  caravan->head = current;

  caravan->length++;
  caravan->loadOfCaravan += animal->load;
}

void remove_pack_animal(Caravan caravan, PackAnimal animal)
{
  return;
}

int get_caravan_load(Caravan caravan)
{
  return caravan->loadOfCaravan;
}

void unload(Caravan caravan)
{
  int length = get_length(caravan);

  Node *current = caravan->head;

  caravan->loadOfCaravan = 0;

  for (int i = 0; i < length; i++){
    current->data->load = 0;
    current = current->next;
  }
}

int get_caravan_speed(Caravan caravan)
{
  return 0;
}
