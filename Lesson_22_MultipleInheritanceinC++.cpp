#include <iostream>

// Множинне спадкування в С++, перевизначення методів батьківського класу 




// приклад перевизначення методів батьківського класу 

class Parent {
public:
    void show() {
        std::cout << "This is the Parent class." << std::endl;
    }
};



class Child : public Parent {
public:
    void show() {
        std::cout << "This is the Child class." << std::endl;
    }
};



int main() {
    Parent p;
    Child c;

    p.show(); // Виклик методу батьківського класу
    c.show(); // Виклик перевизначеного методу в похідному класі

    return 0;
}







// Множинне спадкування в С++


class A
{
 

public:
    int value;
};



// Базовий клас
class Animal : virtual public A {
public:
    void speak() {
        std::cout << "Тварина говорить" << std::endl;
    }
};



// Ще один базовий клас
class Bird : virtual public A {
public:
    void chirp() {
        std::cout << "Пташка щебече" << std::endl;
    }
};




// Клас, який успадковує від обох базових класів
class Parrot : public Animal, public Bird {
public:
    void mimic() {
        std::cout << "Папуга імітує" << std::endl;
    }
};

int main() {
    Parrot parrot;
    
    parrot.speak();  // Викликає метод з базового класу Animal
    parrot.chirp();  // Викликає метод з базового класу Bird
    parrot.mimic();  // Викликає метод класу Parrot

    parrot.value = 10;
    std::cout << parrot.value << std::endl;
    
    return 0;
}