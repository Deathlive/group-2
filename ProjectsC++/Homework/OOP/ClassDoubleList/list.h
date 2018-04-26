#ifndef DOUBLE_LIST_H
#define DOUBLE_LIST_H

class Double_List {
    private:
        struct Node {
            int data;
            Node *next;
            Node *prev;
        };
        Node* first;
        Node* current;
        Node* last;
        int count;
    public:
        Double_List();
        Double_List(const Double_List& obj);
        ~Double_List();
        const int& operator [](int index);
        bool isEmpty() const;
        void addHead(int value);
        void addLast(int value);
        int getCount() const;
        void print();
        void delHead();
        void delLast();
        void del(int);
        void clear();
        void reverse();
        int search(int value);
};

#endif // DOUBLE_LIST_H