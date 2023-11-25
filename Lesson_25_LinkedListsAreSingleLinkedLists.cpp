#include <iostream>
using namespace std;


// Однозв'язний список — вид зв'язаного списку, який складається з вузлів, кожен з яких містить у собі дані 
// (інформаційну частину) та посилання на наступний вузол.

template <class T>
struct Element {
    T data;
    Element* Next;
};



template <class T>
class List {
    Element<T>* Head;
    Element<T>* Tail;
    int count;

public:
    List();
    ~List();

    void Add(T data);             //Додавання елемента до списку  (Новий елемент стає останнім)
    void Del();                   //Видалення елемента списку  (Видаляється головний елемент)
    void DelAll();                //Видалення всього списку
    void Print() const;           //Роздрук вмісту списку (Роздрук починається з головного елемента)
    int GetCount() const;         //Отримання кількості елементів
    bool IsEmpty() const;
    // void Insert(T data, int position);  // Вставка
    // void RemoveAll(const T& value); // для удаления всех элементов равных value
};


template<class T>
List<T>::List() {
    Head = Tail = nullptr;
    count = 0;
}

template<class T>
List<T>::~List() {
    DelAll();
}

template<class T>
int List<T>::GetCount() const {
    return count;
}

template<class T>
bool List<T>::IsEmpty() const {
    return (Head == nullptr);
}

template<class T>
void List<T>::Add(T data) {
    Element<T>* tmp = new Element<T>; 
    
    tmp->data = data;
    tmp->Next = nullptr;

    if (Tail != nullptr)              //Новий елемент стає останнім елементом списку якщо він не перший доданий
    {
        Tail->Next = tmp;
        Tail = tmp;
    }
    else {
        Head = Tail = tmp;
    }
    count++;
}



template<class T>
void List<T>::Del() {
    if (Head != nullptr) {
        Element<T>* tmp = Head;       //Запам'ятовуємо адресу головного елемента
        Head = Head->Next;            //перекидаємо голову на наступний елемент
        delete tmp;                   //видаляємо колишній головний елемент
        count--;
    }
}

template<class T>
void List<T>::DelAll() {
    while (Head != nullptr) {
        Del();
    }
}

template<class T>
void List<T>::Print() const {

    Element<T>* temp = Head;              //Запам'ятовуємо адресу головного елемента

    while (temp != nullptr) {             //Виводимо дані
        std::cout << temp->data << " ";
        temp = temp->Next;
    }

    std::cout << std::endl;
}


// template <class T>
// void List<T>::Insert(T data, int position) {
//     if (position < 0 || position > count) {
//         std::cout << "Invalid position for insertion." << std::endl;
//         return;
//     }

//     Element<T>* newNode = new Element<T>;
//     newNode->data = data;

//     if (position == 0) {
//         // Вставка на начало
//         newNode->Next = Head;
//         Head = newNode;

//         if (Tail == nullptr) {
//             Tail = newNode;
//         }
//     } else if (position == count) {
//         // Вставка на конец
//         Tail->Next = newNode;
//         Tail = newNode;
//         newNode->Next = nullptr;
//     } else {
//         // Вставка в середину
//         Element<T>* current = Head;
//         for (int i = 0; i < position - 1; i++) {
//             current = current->Next;
//         }

//         newNode->Next = current->Next;
//         current->Next = newNode;
//     }

//     count++;
// }


// template <class T> // Удаление
// void List<T>::RemoveAll(const T& value) {
//     while (Head != nullptr && Head->data == value) {
//         Del();
//     }

//     Element<T>* current = Head;
//     Element<T>* prev = nullptr;

//     while (current != nullptr) {
//         if (current->data == value) {
//             if (prev != nullptr) {
//                 prev->Next = current->Next;
//                 delete current;
//                 current = prev->Next;
//                 count--;
//             } else {
//                 Del();
//                 current = Head;
//             }
//         } else {
//             prev = current;
//             current = current->Next;
//         }
//     }
// }

int main() {
    List<int> lst;
    int size = 6, arr[] = { 6, 13, 4, 6, 7, 9 };

    if (lst.IsEmpty()) {
        std::cout << "The list is empty." << std::endl;
    }
    // if (lst.IsFull()) {
    //     std::cout << "The list is full." << std::endl;
    // }

    for (int i = 0; i < size; i++) {
        lst.Add(arr[i]);
    }

    lst.Print();

    if (lst.IsEmpty()) {
        std::cout << "The list is empty." << std::endl;
    }

    return 0;
}