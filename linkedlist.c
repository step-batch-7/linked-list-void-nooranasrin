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

Status add_unique(List_ptr list, Element value, Matcher is_equal) {
  Node_ptr pWalk = list->first;

  while (pWalk != NULL) {
    if(is_equal(pWalk->element, value)) {
      return Failure;
    }
    pWalk = pWalk->next;
  }

  return add_to_list(list, value);
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
  Node_ptr head = list->first;

  if(list->length == 0) {
    return NULL;
  }

  list->first = list->first->next;
  list->length--;
  Element removed = head->element;
  return removed;
}

Element remove_from_end(List_ptr list) {
  Node_ptr head = list->first;

  if(list->length ==0) {
    return NULL;
  }

  if(list->first->next == NULL) {
    return remove_from_start(list);
  }

  Node_ptr pWalk = list->first;
  Node_ptr previous = pWalk;

  while (pWalk->next != NULL) {
    previous = pWalk;
    pWalk = pWalk->next;
  }

  Node_ptr tail = previous->next;
  previous->next = NULL;
  list->last = previous;
  list->length--;
  return tail->element;
}

Element remove_at(List_ptr list, int position) {
  if(position > list->length - 1 || position < 0) {
    return NULL;
  }

  if(position == 0) {
    return remove_from_start(list);
  }

  if (position == list->length - 1) {
    return remove_from_end(list);
  }

  Node_ptr pWalk = list->first;
  Node_ptr previous = pWalk;
  int index = 0;

  while (index != position) {
    previous = pWalk;
    pWalk = pWalk->next;
    index++;
  }

  previous->next = pWalk->next;
  list->length--;
  Node_ptr removed = pWalk;
  free(pWalk);
  return removed->element;
}

Status clear_list(List_ptr list) {
  Node_ptr pWalk = list->first;
  int status;

  while(pWalk != NULL) {
    Element element =  remove_from_end(list);
    if(element != NULL) {
      status = Success;
    }
    pWalk = list->first;
  }
  return status;
}

List_ptr reverse(List_ptr list) {
  List_ptr reverse = create_list();
  if (list->first == NULL) {
    return reverse;
  }

  Node_ptr pWalk = list->first;

  while (pWalk != NULL) {
    Status status = add_to_start(reverse, pWalk->element);
    pWalk = pWalk->next;
  }

  return reverse;
}

Element remove_first_occurrence(List_ptr list, Element value, Matcher matcher) {
  Node_ptr pWalk = list->first;
  Node_ptr previous = pWalk;
  Element removed = NULL;

  if(matcher(list->first->element, value)) {
    return remove_from_start(list);
  }

  while (pWalk != NULL)
  {
    previous = pWalk;
    pWalk = pWalk->next;
    if(pWalk != NULL && matcher(pWalk->element, value)) {
      previous->next = pWalk->next;
      list->length--;
      removed = pWalk->element;
      free(pWalk);
      return removed;
    }
  }

  return removed;
}

List_ptr remove_all_occurrences(List_ptr list, Element value, Matcher matcher) {
  Node_ptr pWalk = list->first;
  List_ptr removed_list = create_list();

  while(pWalk != NULL) {
    if(matcher(pWalk->element, value)) {
      Element element =  remove_first_occurrence(list, value, matcher);
      add_to_list(removed_list, element);
      pWalk = list->first;
    } else {
      pWalk = pWalk->next;
    }
  }
  return removed_list;
}

List_ptr map(List_ptr list, Mapper mapper) {
  List_ptr mapped_elements = create_list();
  Node_ptr pWalk = list->first;

  while(pWalk != NULL) {
    Element new_element = mapper(pWalk->element);
    add_to_list(mapped_elements, new_element);
    pWalk = pWalk->next;
  }

  return mapped_elements;
}

List_ptr filter(List_ptr list, Predicate predicate) {
  List_ptr filtered_elements = create_list();
  Node_ptr pWalk = list->first;

  while(pWalk != NULL) {
    if(predicate(pWalk->element)) {
      add_to_list(filtered_elements, pWalk->element);
    }
    pWalk = pWalk->next;
  }
  return filtered_elements;
};

Element reduce(List_ptr list, Element init, Reducer reducer) {
  Element context = init;
  Node_ptr pWalk = list->first;

  while(pWalk != NULL) {
    context = reducer(context, pWalk->element);
    pWalk = pWalk->next;
  }
  return context;
}

void forEach(List_ptr list, ElementProcessor processor) {
  Node_ptr pWalk = list->first;

  while(pWalk != NULL) {
    processor(pWalk->element);
    pWalk = pWalk->next;
  }
}