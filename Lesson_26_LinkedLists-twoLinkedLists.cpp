#include <iostream>
using namespace std;

// Зв'язні списки - двох зв'язкові списки

class Node {
public:
    int data;
    Node* prev;
    Node* next;
    
    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};


class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
    
public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}
    
    void append(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
            tail->next = nullptr;
        }
    }

    void insert(int value, int position)         // код з можливістю вставки елементу в двозв'язний список:
    {

        Node* newNode = new Node(value);

        if (position == 0) {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        } 
        else 
        {
            Node* current = head;
            for (int i = 0; i < position - 1 && current != nullptr; i++) {
                current = current->next;
            }
            if (current != nullptr) {
                newNode->next = current->next;
                newNode->prev = current;

                if (current->next != nullptr) 
                {
                    current->next->prev = newNode;
                }

                current->next = newNode;
                if (current == tail) {
                    tail = newNode;
                }
            }
        }
    }

    void remove(int position) 
    {
        if (position == 0 && head != nullptr) 
        {
            Node* toRemove = head;
            head = head->next;

            if (head != nullptr) 
            {
                head->prev = nullptr;
            }
            delete toRemove;

        } 
        else 
        {
            Node* current = head;
            for (int i = 0; i < position && current != nullptr; i++) {
                current = current->next;
            }

            if (current != nullptr) {
                Node* toRemove = current;
                if (current->prev != nullptr) {
                    current->prev->next = current->next;
                }
                if (current->next != nullptr) {
                    current->next->prev = current->prev;
                }
                if (toRemove == head) {
                    head = head->next;
                }
                if (toRemove == tail) {
                    tail = tail->prev;
                }
                delete toRemove;
            }
        }
    }
    
    void display() {
        Node* current = head;

        while (current != nullptr) 
        {
            std::cout << current->data << " <-> ";
            current = current->next;
        }

        std::cout << "nullptr" << std::endl;
    }
};

int main() {
    DoublyLinkedList list;
    list.append(1);
    list.append(2);
    list.append(3);
    
    list.display();

    // list.insert(4, 0); // Вставка елементу 4 на початок
    // list.insert(5, 2); // Вставка елементу 5 на позицію 2
    
    // list.display();

    // list.remove(1); // Видалення елементу на позиції 1
    // list.display();
    
    return 0;
}