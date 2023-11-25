#include <iostream>

// Перевантаження операторів: відношення, арифметичних, введення/виведення.

class Complex {
public:
    Complex(double real, double imag) : real_(real), imag_(imag) {}


    // // Перевантаження оператору віднімання (-)
    Complex operator-(const Complex& other) {
        return Complex(real_ - other.real_, imag_ - other.imag_);
    }

    // // Перевантаження оператору додавання (+)
    friend Complex operator+(const Complex& other, const Complex& otherTwo);
    friend Complex operator-(const Complex& other, const Complex& otherTwo);
    friend Complex operator/(const Complex& other, const Complex& otherTwo);
    friend Complex operator+(const Complex& other, int value);
    friend Complex operator+(int value, const Complex& other);

    friend void Print(const Complex& other);



    // // Перевантаження оператору виведення на консоль (<<)
    friend std::ostream& operator<<(std::ostream& os, const Complex& complex);

private:
    double real_;
    double imag_;
};

std::ostream& operator<<(std::ostream& os, const Complex& complex) {
    os << complex.real_ << "  " << complex.imag_ << std::endl;
    return os;
}

Complex operator+(const Complex& other, const Complex& otherTwo) {
    return Complex(otherTwo.real_ + other.real_, otherTwo.imag_ + other.imag_);
}

Complex operator-(const Complex& other, const Complex& otherTwo) {
    return Complex(otherTwo.real_ - other.real_, otherTwo.imag_ - other.imag_);
}

Complex operator/(const Complex& other, const Complex& otherTwo) {
    return Complex(otherTwo.real_ / other.real_, otherTwo.imag_ / other.imag_);
}

Complex operator+(const Complex& other, int value) {
    return Complex(other.real_, other.imag_ + value);
}

Complex operator+(int value, const Complex& other) {
    return Complex(other.real_, other.imag_ + value);
}

void Print(const Complex& other)
{
    std::cout << other.imag_ << ' ' << other.real_ << std::endl;
}


// int main() {
//     Complex c1(3.0, 4.0);
//     Complex c2(1.5, 2.5);

//     Complex sum = c1 + c2;
//     Complex diff = c1 - c2;
//     Complex del = c1 / c2;

//     Complex o1 = c1 + 10;
//     Complex o2 = 20 + c2;


//     std::cout << "Sum: " << sum << std::endl;
//     std::cout << "Difference: " << diff << std::endl;
//     std::cout << "Del: " << del << std::endl;
//     std::cout << "O1: " << o1 << std::endl;

//     Print(o2);



//     return 0;
// }








// Перевантажимо оператори порівняння >, <, >= та <= == and !=


class Sum{
    int a;
    public:
        Sum(int a) : a (a) {}


        friend bool operator >(const Sum &o, const Sum &o2);
        // friend bool operator == (const Sum &o, const Sum &o2);
        friend bool operator < (const Sum &o, const Sum &o2);
        friend bool operator !=(const Sum &o, const Sum &o2);

        bool operator ==(const Sum &o)
        {
            return a == o.a;
        }

};

bool operator >(const Sum &o, const Sum &o2)
{
    return o.a > o2.a;
}

// bool operator ==(const Sum &o, const Sum &o2)
// {
//     return o.a == o2.a;
// }

bool operator <(const Sum &o, const Sum &o2)
{
    return o.a < o2.a;
}

bool operator !=(const Sum &o, const Sum &o2)
{
    return o.a != o2.a;
}





// int main()
// {
//     Sum a(30);
//     Sum b(30);


//     if(a > b)
//         std::cout << "a > b" << std::endl;
//     else if(a == b)
//         std::cout << "a == b" << std::endl;
//     else
//         std::cout << " a < b" << std::endl;

// }




 
// Перевантаження операторів інкременту та декременту
// Оскільки оператори інкременту та декременту є унарними та змінюють свої операнди,
// то навантаження слід виконувати через методи класу.


class Number
{
    int a;
    public:
    Number(int a ) : a(a){}


    Number operator++(){
        ++(this->a);
        return *this;
    }

    Number operator++(int){
         Number tmp(this->a);
        ++(this->a);
        return tmp;
    }


    friend std::ostream& operator<<(std::ostream &out, const Number &obj);
};

std::ostream& operator<<(std::ostream &out, const Number &obj)
{
    out << obj.a;
    return out;
}

// int main()
// {
//     Number a(10);



//     std::cout << ++a << std::endl;
//     std::cout << a++ << std::endl;
//     std::cout << a << std::endl;



//     // int x = 10;

//     // std::cout << ++x << std::endl;
//     // std::cout << x++ <<  ' ' << x << std::endl;
//     // std::cout << x   <<   std::endl;

//     return 0;
// }




// Перегрузка оператора индексации []

class Int
{
public:
    Int()
    {
        for (int i = 0; i < 10; i++)
        {
            arr[i] = rand() % 10;
        }
    }

    int getArray(int index)
    {
        return arr[index];
    }

    void SetArray(int index, int value)
    {
        arr[index] = value;
    }

    int& operator[](int index)
    {
        return arr[index];
    }


    void Print() const{
        for (int i = 0; i < 10; i++)
        {
            std::cout << arr[i] << ' ';
        }
        std::cout << std::endl;
    }

private:
    int arr[10];    

};



// int main()
// {

//         Int o1;
//         o1.Print();

// // початок

    // int arr[10];

    // arr[5] = 6;
    // std::cout << arr[5] << std::endl;

// // Можна використовувати геттери і сеттери:


    // std::cout << o1.getArray(4) << std::endl;

    // o1.SetArray(4, 10);

    // std::cout << o1.getArray(4) << std::endl;



    // o1[4] = 20;
    // std::cout << o1[4] << std::endl;





// // Можна також просто повертати весь масив (array) і використовувати оператор [] для доступу до його елементів:

//     Int a;
  
//     a.getArr()[4] = 6;
//     std::cout << a.getArray(4) << std::endl;


// // Але можна зробити ще простіше, перевантаживши оператор індексації.
//     a[4] = 7;

//     std::cout << a[4] << std::endl;
//     return 0;
// }




//  Перегрузка оператора ()


class Operaor
{
    private:
        int arr[5][5];
    public:
        Operaor(){
            for (int i = 0; i < 5; i++){
                for(int j = 0; j < 5; j++)
                    arr[i][j] = rand() % 10;
            }
        }

        int& operator()(int row, int col){
            return arr[row][col];
        }

        // int& operator[](int row)
        // {
        //     return arr[row];
        // }

        void operator()(){
             for (int i = 0; i < 5; i++){
                for(int j = 0; j < 5; j++)
                    arr[i][j] = 0;
            
            }
        }

        void operator()(int value){
              for (int i = 0; i < 5; i++){
                for(int j = 0; j < 5; j++)
                    arr[i][j] = value;
            
            }
        }
     
        friend std::ostream& operator<<(std::ostream &out, Operaor &o);
};

std::ostream& operator<<(std::ostream &out, Operaor &o){
    for (int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
               out << o.arr[i][j] << ' ';
            }
            out << std::endl;
        }
        return out;
        
}


int main()
{
    Operaor a;

    std::cout << a << std::endl;

    a(3, 3) = 5;

    std::cout << a << std::endl;


    a();

    std::cout << a << std::endl;

    a(10);

    std::cout << a << std::endl;

}






// Завдання №1: Робота з комплексними числами
// Створіть клас "ComplexNumber" для представлення комплексних чисел (чисел у формі a + bi, де a і b - дійсні числа). 
// Реалізуйте перевантаження операторів +, - та *, щоб можна було виконувати арифметичні операції з комплексними числами.

// Завдання №2: Математичні операції над точками
// Створіть клас "Point", який представляє точку в двовимірному просторі (з координатами x і y). 
// Перевантажте оператори +, - та *, щоб вони дозволяли виконувати арифметичні операції між точками.

// Завдання №3: Робота з дробами
// Створіть клас "Fraction" для представлення дробів. Кожен дріб має чисельник і знаменник (цілі числа). 
// Перевантажте оператори +, - та *, щоб можна було виконувати арифметичні операції з дробами.

// Завдання №4: Кольорові точки
// Створіть клас "ColorPoint", який представляє кольорову точку. 
// Кожна кольорова точка має координати x і y, а також колір (наприклад, червоний, зелений, синій). 
// Перевантажте оператори +, - та *, щоб можна було виконувати арифметичні операції між кольоровими точками.

// Завдання №5: Робота зі строками
// Створіть клас "MyString" для роботи зі строками. 
// Перевантажте оператор +, щоб можна було об'єднувати дві строки, і оператор -, щоб видаляти одну строку з іншої.
