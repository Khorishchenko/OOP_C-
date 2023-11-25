#include <iostream>

class Animal
{
    public:
        void sound() const 
        {
            std::cout << "wo wo wo" << std::endl;
        }
};

class Cat : public Animal
{
      public:
        // void sound() const 
        // {
        //     std::cout << "Meou Meou meou" << std::endl;
        // }
};

class Dog : public Cat
{
    public:
        void sound() const 
        {
            std::cout << "gav gav gav" << std::endl;
        } 
};

int main()
{
    // Dog o1;
    // o1.sound();

    // Cat o2;
    // o2.sound();
}






// Віртуальні функції
// добавити ключове слово virtual

// class Animal {
// public:
//      void speak() {
//         std::cout << "Animal makes a sound" << std::endl;
//     }
// };

// class Dog : public Animal {
// public:
//      void speak()  {
//         std::cout << "Dog barks" << std::endl;
//     }
// };

// class Cat : public Animal {
// public:
//      void speak()  {
//         std::cout << "Cat meows" << std::endl;
//     }
// };

// int main() {

//     Animal *myPet = new Dog();
//     myPet->speak();                                 // Викликається метод speak() класу Dog: "Dog barks"

//     myPet = new Cat();
//     myPet->speak();                                 // Викликається метод speak() класу Cat: "Cat meows"

//     delete myPet;

//     return 0;
// }








// class Animal {
// public:
//     Animal(const std::string& name) : name(name) {}

//     const std::string& getName() const {
//         return name;
//     }

//     virtual std::string speak() const {
//         return "Animal sound";
//     }

// private:
//     std::string name;
// };

// class Cat : public Animal {
// public:
//     Cat(const std::string& name) : Animal(name) {}

//      std::string speak() const  {
//         return "Meow";
//     }
// };

// class Dog : public Animal {
// public:
//     Dog(const std::string& name) : Animal(name) {}

//      std::string speak() const  {
//         return "Woof";
//     }
// };



// 1. Якщо ми працюємо з вказівником або посиланням типу базового класу(батьківського класу), на об'єкти дочірнього класу !
//  і хочемо перевизначити методи батьківського класу, то такий метод повинен бути virtual в батьківському класи !!!


// void Print(const Animal *o1)
// {
//     std::cout << o1->speak() << ' ' << o1->getName() << std::endl;
// }


// int main()
// {
//     Cat matros("Matros"), ivan("Ivan"), martun("Martun");
//     Dog barsik("Barsik"), tolik("Tolik"), tyzik("Tyzik");

//     Print(&matros);
//     Print(&barsik);

    // std::cout << matros.getName() << std::endl;
    // std::cout << matros.speak() << std::endl;

    // std::cout << barsik.getName()<< std::endl;
    // std::cout << barsik.speak()<< std::endl;

 
    // Створюємо масив покажчиків на наші об'єкти Cat та Dog
    // Animal *animals[] = { &matros, &ivan, &martun, &barsik, &tolik, &tyzik};

    // for (int i = 0; i < 6; i++)
    //     std::cout << animals[i]->getName() << " says " << animals[i]->speak() << '\n';
 
//     return 0;
// }





// Тема: Розробка текстового редактора.

// Опис завдання: Створити клас TextEditor, який має віртуальну функцію displayText(), 
// яка виводить текстовий вміст на екран. Створити два підкласи: PlainTextEditor і HtmlEditor. 
// Кожен з цих підкласів має перевизначити метод displayText(), де PlainTextEditor виводить звичайний текст, а 
// HtmlEditor виводить HTML-код.

// Створити об'єкти для кожного з редакторів і вивести текстовий вміст, 
// використовуючи віртуальну функцію displayText(). Ця робота показує, 
// як віртуальні функції дозволяють використовувати один і той же інтерфейс для об'єктів різних підкласів і 
// виконувати різні дії в залежності від конкретного типу об'єкта.



//------------------------------------------------------------------------------------------------------------------------


// a
 
// class A
// {
// public:
//     virtual const char* getName() { return "A"; }
// };
 
// class B: public A
// {
// public:
//     virtual const char* getName() { return "B"; }
// };
 
// class C: public B
// {
// public:
// // Примітка: Тут немає методу getName()
// };
 
// class D: public C 
// {
// public:
//     virtual const char* getName() { return "D"; }
// };
 
// int main()
// {
//     C c;
//     A &rParent = c;
//     std::cout << rParent.getName() << '\n';
 
//     return 0;
// }


// ========================================================//
// b

 
// class A
// {
// public:
//     const char* getName() { return "A"; }
// };
 
// class B: public A
// {
// public:
//     virtual const char* getName() { return "B"; }
// };
 
// class C: public B
// {
// public:
//     virtual const char* getName() { return "C"; }
// };
 
// class D: public C
// {
// public:
//     virtual const char* getName() { return "D"; }
// };
 
// int main()
// {
//     D o1;
//     B &rParent = o1; // Примітка: rParent цього разу клас B
//     std::cout << rParent.getName() << '\n';
 
//     return 0;
// }


// //----------------------------------------------------------------------//
// //c
 
// class A
// {
// public:
//     const char* getName() { return "A"; }       // Примітка: Немає ключового слова virtual
// };
 
// class B: public A
// {
// public:
//     virtual const char* getName() { return "B"; }
// };
 
// class C: public B
// {
// public:
//     virtual const char* getName() { return "C"; }
// };
 
// class D: public C
// {
// public:
//     virtual const char* getName() { return "D"; }
// };
 
// int main()
// {
//     C o1;
//     B &rParent = o1;
//     std::cout << rParent.getName() << '\n';
 
//     return 0;
// }


// //----------------------------------------------------------------------//
//  //d


// class A
// {
// public:
//     virtual const char* getName() { return "A"; }
// };
 
// class B: public A
// {
// public:
//    const char* getName() { return "B"; } // Примітка: Немає ключового слова virtual
// };
 
// class C: public B
// {
// public:
//     const char* getName() { return "C"; } // Примітка: Немає ключового слова virtual
// };
 
// class D: public C
// {
// public:
//     const char* getName() { return "D"; } // Примітка: Немає ключового слова virtual
// };
 
// int main()
// {
//     C o1;
//     B &rParent = o1; // Примітка: rParent цього разу клас B
//     std::cout << rParent.getName() << '\n';
 
//     return 0;
// }



// //----------------------------------------------------------------------//
// //e

 
// class A
// {
// public:
//     virtual const char* getName() const { return "A"; } // Примітка: Метод є const
// };
 
// class B: public A
// {
// public:
//     virtual const char* getName() { return "B"; }
// };
 
// class C: public B
// {
// public:
//     virtual const char* getName() { return "C"; }
// };
 
// class D: public C
// {
// public:
//     virtual const char* getName() { return "D"; }
// };
 
// int main()
// {
//     C o1;
//     A &rParent = o1;
//     std::cout << rParent.getName() << '\n';
 
//     return 0;
// }


// //----------------------------------------------------------------------//
// //f

 
// class A
// {
// public:
//  A() { 
    
//         std::cout << getName(); 
    
//     }                // Зверніть увагу на наявність конструктора
 
//  virtual const char* getName() { return "A\n"; }
// };
 
// class B : public A
// {
// public:
//  virtual const char* getName() { return "B"; }
// };
 
// class C : public B
// {
// public:
//  virtual const char* getName() { return "C"; }
// };
 
// class D : public C
// {
// public:
//  virtual const char* getName() { return "D"; }
// };
 
// int main()
// {
//  C c;
 
// }




//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------




// Ключове слово override

// class A{
//     public:
//         virtual void print() const {
//             std::cout << "class A" << std::endl;
//         }
// };

// class B : public A{
//     public:
//         void print() const override {
//             std::cout << "class B" << std::endl;
//         }
// };

// class C : public B
// {
//      public:
//         void print() const override {
//             std::cout << "class C" << std::endl;
//         }
// };

// int main(){
    // B objB;

    // A &rObjA = objB;
    // rObjA.print();


    // C oC;
    // B &roB = oC;

    // roB.print();
// }




//------------------------------------------------------------------------------------------------------------------------
// Віртуальні деструктори 

// class A
// {
// public:
// 	virtual ~A(){
// 		std::cout << "~A" << std::endl;
//     }
// };

// class B : public A{
//    int *ptr;
// public:
// 	B(int size) : ptr(new int[size]){}
   
//   ~B(){
//    	 delete[] ptr;
//    	 std::cout << "~B" << std::endl;
//    }   
// };

// int main()
// {
// 	A *ptr = new B(10);
// 	delete ptr;
   
//     return 0;
// }



//------------------------------------------------------------------------------------------------------------------------
// Абстрактні класи


// class A{                             // Абстрактний клас
//     public:
//     virtual int getA() = 0;          // чисто віртуальна функція 
// };


// class B : public A
// {
//     int a;
// public:
//     B(int a) : a(a){}

//     int getA() 
//     {
//         return a;
//     }

// };


// class C : public A
// {
//     int a;
// public:
//     C(int a) : a(a){}

//     int getA() 
//     {
//         return a;
//     }
// };

// int main()
// {

//     B a1(10), a2(2), a3(33), a4(10), a5(10);
//     C b1(29), b2(44), b3(11), b4(88), b5(10), b6(22);

// =======================================================//


    // std::cout << a1.getA() << std::endl;
    // std::cout << a2.getA() << std::endl;
    // std::cout << a3.getA() << std::endl;
    // std::cout << a4.getA() << std::endl;
    // std::cout << a5.getA() << std::endl;
    // std::cout << b1.getA() << std::endl;
    // std::cout << b2.getA() << std::endl;
    // std::cout << b3.getA() << std::endl;
    // std::cout << b4.getA() << std::endl;
    // std::cout << b4.getA() << std::endl;
    // std::cout << b4.getA() << std::endl;



// =======================================================//

    // B *ptr2[] = {&a1, &a2, &a3, &a4};
    // C *ptr3[] = {&b1, &b2, &b3, &b4, &b5, &b6};

    

    // for(int i = 0; i < 4; i++){
    //     std::cout << ptr2[i]->getA() << std::endl;
    // }

    // for(int i = 0; i < 6; i++){
    //     std::cout << ptr3[i]->getA() << std::endl;
    // }

//  =======================================================//

//     A *ptr[] = {&a1, &a2, &a3, &a4, &b1, &b2, &b3, &b4, &b5, &b6};

//     for(int i = 0; i < 10; i++){
//         std::cout << ptr[i]->getA() << std::endl;
//     }

// }
