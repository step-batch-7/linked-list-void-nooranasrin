#include<stdio.h>
#include<stdlib.h>
#include "linkedlist.h"

List_ptr create_list(void) {
  List_ptr list =  malloc(sizeof(LinkedList));

  if(list == NULL) {
    return list;
  }

  list->first = NULL;
  list->last = list->first;
  list->length = 0;
  return list;
}

Node_ptr create_node(void *value) {
  Node_ptr new_node = malloc(sizeof(Node));

  if(new_node == NULL) {
    return new_node;
  }

  new_node->element = value;
  new_node->next = NULL;
  return new_node;
}

Status add_to_start(List_ptr list, Element value) {
  Node_ptr new_node = create_node(value);

  if(new_node == NULL) {
    return Failure;
  }

  if(list->first == NULL) {
    list->first = new_node;
    list->last = list->first;
  } else {
    new_node->next = list->first;
    list->first = new_node;
  }

  list->length++;
  return Success;
}

Status add_to_list(List_ptr list, Element value) {
  Node_ptr new_node = create_node(value);

  if(new_node == NULL) {
    return Failure;
  }

  if(list->first == NULL) {
    list->first = new_node;
  } else {
    list->last->next = new_node;
  }

  list->last = new_node;
  list->length++;
  return Success;
}

Status insert_at(List_ptr list, Element value, int position) {
  if (position > list->length || position < 0) {
    return Failure;
  }

  if(position == 0) {
    return add_to_start(list, value);
  }

  if (position == list->length) {
    return add_to_list(list, value);
  }

  int index = 0;
  Node_ptr pWalk = list->first;
  Node_ptr previous = pWalk;
  Node_ptr new_node = create_node(value);

  if(new_node == NULL) {
    return Failure;
  }

  while (index != position) {
    previous = pWalk;
    pWalk = pWalk->next;
    index++;
  }

  new_node->next = previous->next;
  previous->next = new_node;
  list->length++;
  return Success;
}

Element remove_from_start(List_ptr list) {
  if(list->length == 0) {
    return NULL;
  }

  Node_ptr head = list->first;
  list->first = list->first->next;
  list->length--;
  free(head);
  return head;
}