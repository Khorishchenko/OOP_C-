#include <iostream>

// Перевантаження оператора =, Конструктор перенесення

class MyString {
public:
    // Конструктор за замовчуванням
    MyString() : data(nullptr) {}

    MyString(const char *str)
    {
        if (str != nullptr) {
            data = new char[strlen(str) + 1];
            strcpy(data, str);
        } else {
            data = nullptr;
        }
    }

    // Конструктор копіювання
    MyString(const MyString &other) {
        if (other.data != nullptr) 
        {
            data = new char[strlen(other.data) + 1];
            strcpy(data, other.data);
        } 
        else 
        {
            data = nullptr;
        }
    }

    // Конструктор переміщення
    MyString(MyString &&other)  {
        data = other.data;
        other.data = nullptr;
    }

    // Перевантаження оператора присвоювання
    MyString& operator=(const MyString &other) {
        if (this != &other) 
        {
            if (data != nullptr)
                delete[] data;

            if (other.data != nullptr) {
                data = new char[strlen(other.data) + 1];
                strcpy(data, other.data);
            } 
            else 
            {
                data = nullptr;
            }
        }
        return *this;
    }

    // Деструктор
    ~MyString() {
        if (data != nullptr)
            delete[] data;
    }

    // Виведення рядка
    void print()  {
        // std::cout << (data ? data : "Empty") << std::endl;

        if (data != nullptr)
        {
            std::cout << data << std::endl;
        }
        else{
            std::cout <<  "Empty" << std::endl;
        }
    }

private:
    char* data;
};

int main() 
{
    MyString s1;
    MyString s2("Hello, World");
    MyString s3 = s2; // Виклик конструктору копіювання
    MyString s4("hello");

    s4 = s2; // Виклик перевантаженого оператора присвоювання

    s2.print();
    s4.print();






    MyString s5 = std::move(s4); // Виклик конструктору переміщення

    // s1.print(); // "Empty"
    // s2.print(); // "Hello, World"
    // s3.print(); // "Hello, World"
    s4.print(); // "Empty"
    s5.print(); // "Hello, World"

    return 0;
}