#ifndef DOUBLE_LIST_H
#define DOUBLE_LIST_H


struct node {
    int data;
    node *next;
    node *prev;
};

class double_list {
    public:
        node *start;
        double_list();
        ~double_list();
        void create_list(int value);
        void display();
        void insert_start(int value);
        void add_after(int value, int position);
        void delete_element(int value);
        void count();
        void reverse();
        void delete_all();
};

#endif // DOUBLE_LIST_H