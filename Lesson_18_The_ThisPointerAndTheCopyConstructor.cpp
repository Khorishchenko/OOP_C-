#include <iostream>

// Покажчик this і конструктор копіювання, делегування конструкторів



// Умова завдання 2:

// Створіть клас Person, який представляє особу з ім'ям і віком. Клас повинен мати два конструктори: один, який приймає ім'я та вік, та інший, 
// який приймає лише ім'я. 
// В цьому випадку вік має ініціюватися значенням за замовчуванням (наприклад, 0). 
// Використовуйте делегування конструкторів для забезпечення можливості створювати об'єкти Person з ім'ям і віком або лише з ім'ям.


// class Person
// {
// public:
//     Person(std::string name, int age) : m_name(name), m_age(age) {}
//     Person(std::string name) : Person(name, 0) {}

//     void Print() const{
//         std::cout << "Name: " << m_name << ". Age: " << m_age << std::endl;
//     }
// private:
//     std::string m_name;
//     int         m_age;

// };

// int main()
// {
//     Person o1("Anton", 20);
//     o1.Print();

//     Person o2("Sergii");
//     o2.Print();
// }














// THIS*

// class MyClass {
// public:
//     void SetData(int data) {
//         this->data = data;  // Використовуємо this для доступу до змінної-члена data
//     }

//     int GetData() {
//         return this->data;  // Використовуємо this для отримання значення data
//     }

//     void GetPtr()
//     {
//         std::cout << this << std::endl;
//     }

// private:
//     int data;
// };

// int main() {
//     MyClass obj;
//     obj.SetData(42);  // Встановлюємо значення data за допомогою методу SetData

//     obj.GetPtr();


//     std::cout << "Data: " << obj.GetData() << std::endl;  // Отримуємо значення data за допомогою методу GetData

//     return 0;
// }





// Конструктор копіювання — особливий конструктор в мові програмування C++,
//  який використовується для створення нових об'єктів як копії існуючого об'єкта.
// Конструктор КОПІЮВАННЯ ПРИКЛАД

// Приклад 1: Копіювання простої змінної
// class Copy {
// public:
//     Copy(int value) : data(value) {}

//     // Конструктор копіювання
//     Copy(const Copy& other) : data(other.data) {
//         std::cout << "Copy(const Copy& other)" << std::endl;
//     }

//     void PrintData() const {
//         std::cout << "Data: " << data << std::endl;
//     }

// private:
//     int data;
// };

// Copy Print(const Copy obj)
// {
//    obj.PrintData();

//    Copy o2(55);

//    return o2;
// }

// int main() {
//     Copy obj1(42);
//     Copy obj2(obj1);  // Виклик конструктора копіювання

//     obj1.PrintData();
//     obj2.PrintData();

//     Copy o3 = obj2;

//     o3.PrintData();

//     Print(o3);

//     Copy o4(Print(o3));
//     o4.PrintData();

//     return 0;
// }





// Приклад 2: Копіювання класу з багатьма змінними-членами
// class Point {
// public:
//     Point(int x, int y) : x(x), y(y) {}

//     // Конструктор копіювання
    // Point(const Point& other) : x(other.x), y(other.y) {}

//     void Print() {
//         std::cout << "X: " << x << ", Y: " << y << std::endl;
//     }

// private:
//     int x;
//     int y;
// };

// int main() {
//     Point p1(10, 20);
//     Point p2 = p1;  // Виклик конструктора копіювання

//     p1.Print();
//     p2.Print();

//     return 0;
// }



// Поверхневе і глибоке копіювання

class Array
{
public:
    Array(int size)
    {
        if (size > 0)
        {
            ptr = new int[size];

            for (int i = 0; i < size; i++)
            {
                ptr[i] = rand() % 10;
            }

            m_size = size;
        }
        else{
            ptr = nullptr;
            m_size = 0;
        }
    }

    Array(const Array & obj) {
        std::cout << "Array(const Array & obj)" << std::endl;

        if (obj.ptr != nullptr)
        {
            ptr = new int[obj.m_size];

            for (int i = 0; i < obj.m_size; i++)
                ptr[i] = obj.ptr[i];

            m_size = obj.m_size;
        }
        else
        {
            ptr = nullptr;
            m_size = 0;
        }
    }

    ~Array()
    {
        if (ptr != nullptr)
        {
            delete [] ptr;
            std::cout << "~Array()" << std::endl;
        }
    }

    void Print() const{

        if (m_size > 0)
        {
            for (int i = 0; i < m_size; i++)
            {
                std::cout << ptr[i] << ' ';
            }
            std::cout << std::endl;
        }
        else{
            std::cout << "arr is empty" << std::endl;
        }
    } 

private:
    int *ptr;
    int m_size;
};

int main()
{
    Array o1(10);
    o1.Print();

    Array o2(o1);
    o2.Print();
}