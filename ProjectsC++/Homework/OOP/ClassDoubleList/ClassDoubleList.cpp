#include <iostream>
#include "list.h"

double_list::double_list() {
    start = NULL;
}

double_list::~double_list(){ }

void double_list::create_list(int value)
{
    node *s, *temp;
    temp = new(node); 
    temp->data = value;
    temp->next = NULL;
    if (start == NULL) {
        temp->prev = NULL;
        start = temp;
    } else {
        s = start;
        while (s->next != NULL) {
            s = s->next;
        }
        s->next = temp;
        temp->prev = s;
    }
}

void double_list::display()
{
    node *q;
    if (start == NULL) {
        std::cout << "List empty,nothing to display\n";
        return;
    }
    q = start;
    std::cout << "Display: ";
    while (q != NULL) {
        std::cout << q->data << " <-> ";
        q = q->next;
    }
    std::cout << "NULL\n";
}

void double_list::insert_start(int value)
{
    if (start == NULL) {
        std::cout << "First Create the list.\n";
    }
    node *temp;
    temp = new(node);
    temp->prev = NULL;
    temp->data = value;
    temp->next = start;
    start->prev = temp;
    start = temp;
    std::cout << "Element Inserted\n";
}

void double_list::add_after(int value, int pos)
{
    if (start == NULL) {
        std::cout << "First Create the list.\n";
    }
    node *tmp, *q;
    int i;
    q = start;
    for (i = 0; i < pos - 1; i++) {
        q = q->next;
        if (q == NULL) {
            std::cout << "There are less than ";
            std::cout << pos << " elements.\n";
        }
    }
    tmp = new(node);
    tmp->data = value;
    if (q->next == NULL) {
        q->next = tmp;
        tmp->next = NULL;
        tmp->prev = q;      
    } else {
        tmp->next = q->next;
        tmp->next->prev = tmp;
        q->next = tmp;
        tmp->prev = q;
    }
    std::cout << "Element Inserted\n";
}

void double_list::delete_element(int value)
{
    node *tmp, *q;
    if (start->data == value) {
        tmp = start;
        start = start->next;  
        start->prev = NULL;
        std::cout << "Element Deleted\n";
        free(tmp);
    }
    q = start;
    while (q->next->next != NULL) {
        if (q->next->data == value) {
            tmp = q->next;
            q->next = tmp->next;
            tmp->next->prev = q;
            std::cout << "Element Deleted\n";
            free(tmp);
            return;
        }
        q = q->next;
    }
    if (q->next->data == value) { 	
        tmp = q->next;
        free(tmp);
        q->next = NULL;
        std::cout << "Element Deleted\n";
        return;
    }
    std::cout << "Element " << value << " not found\n";
}

void double_list::count()
{ 	
    node *q = start;
    int cnt = 0;
    while (q != NULL) {
        q = q->next;
        cnt++;
    }
    std::cout << "Number of elements are: " << cnt << "\n";
}

void double_list::reverse()
{
    node *p1, *p2;
    p1 = start;
    p2 = p1->next;
    p1->next = NULL;
    p1->prev = p2;
    while (p2 != NULL)
    {
        p2->prev = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p2->prev; 
    }
    start = p1;
    std::cout << "List Reversed\n";
}

void double_list::delete_all() {
    start = NULL;
}