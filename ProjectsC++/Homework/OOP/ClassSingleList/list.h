#ifndef LIST_H
#define LIST_H

struct node {
    int data;
    node *next;	
};

class list {
    public:
        node *head, *tail;
        list();
        ~list();
        void createnode(int value);
        void display();
        void insert_start(int value);
        void insert_position(int pos, int value);
        void delete_first();
        void delete_last();
        void delete_position(int pos);
        void delete_all();
};

#endif // LIST_H