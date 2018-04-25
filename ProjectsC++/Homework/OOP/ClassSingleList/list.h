#ifndef LIST_H
#define LIST_H

class List {
    private:
        struct Node {
            int data = 0;
            Node* next = nullptr;
        };
        Node* head;
        Node* tail;
        int count;
    public:
        List();
        List(const List& obj);
        ~List();
        const int& operator [](int index) const;
        void addHead(int data);
        void addTail(int data);
        void insert(int data, int position);
        void delHead();
        void delTail();
        void del(int position);
        void clear();
        void print() const;
        int getCount() const;
        int search(int data) const;
        bool isEmpty() const;
        void reverse();
};

#endif // LIST_H