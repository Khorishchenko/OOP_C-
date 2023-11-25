#include <iostream>

// Конструктор Деструктор, спискова ініціалізація

// Конструктори
// Параметри конструкторів
// За замовчуванням
// Деструктори
// Спискова ініціалізація
// Реалізація методів за межами класу
// Порядок виклику конструкторів та деструкторів




// =============================================//
// Конструктори - За замовчуванням/з параметрами


class Studen
{
public:
    Studen()
    {
        std::cout << " Studen()" << std::endl;
        m_age = 0;
        m_name = "no name";
    }

    Studen(int age, std::string name)
    {
        std::cout << "  Studen(int age, std::string name) " << std::endl;
        m_age = age;
        m_name = name;
    }

    Studen(int age = 0, std::string name  = "na name" )
    {
        std::cout << "  Studen(int age = 0, std::string name  = \"na name\" ) " << std::endl;
        m_age = age;
        m_name = name;
    }


    void Print() const 
    {
        std::cout << "Name: " << m_name << ". Age: " << m_age << std::endl;
    }


private:
    int m_age;
    std::string m_name;
};

int main()
{
    Studen student1;
    student1.Print();

    Studen student2(20, "Anton");
    student2.Print();
}














// =============================================//
// Деструктор







class Array
{
public:
    Array(int size)
    {
        if (size > 0)
        {
            m_ptr = new int[size];

            for (int i = 0; i < size; i++)
                m_ptr[i] = rand() % 10;

            m_size = size;
        }
        else{
            m_ptr = nullptr;
            m_size = 0;
        }
    }

    void Print() const{
        if (m_size > 0)
        {
            for (int i = 0; i < m_size; i++)
            {
                std::cout << m_ptr[i] << ' ';
            }
            std::cout << std::endl;
        }
        else{
            std::cout << "arr is empty " << std::endl;
        }
    }

    ~Array()
    {
        if (m_ptr != nullptr)
        {
            delete [] m_ptr;
            std::cout << " ~Array() " << std::endl;
        }       
    }

private:
    int *m_ptr;
    int m_size;
};


void f()
{
    Array arr(5);
}


int main()
{
    int size = 0;
    std::cin >> size;

    f();

    Array arr(size);
    arr.Print();
}










//=================================================================//
// Реалізація методів за межами класу
// Спискова ініціалізація


class Titan
{
    std::string _name;
    int m_age;
    const int size;
public:
    Titan(std::string name, int conssst) : _name(name), m_age(0), size(conssst)
    {
        // size = conssst;
    }

    void showName_Titan();
};

void Titan::showName_Titan()
{
    std::cout << _name << ' ' << m_age << ' '  << size << std::endl;
}


int main(){
    Titan b("Mark", 10);
   
    b.showName_Titan();
}






// =============================================//
// Порядок виклику конструкторів та деструкторів

class A{
public:
    A() {std::cout << "This is const A" << std::endl;}
    ~A() { std::cout << "This is dest A " << std::endl; }
};


class B{
public:
    B() {std::cout << "This is const B" << std::endl;}
    ~B() { std::cout << "This is dest B " << std::endl; }
};

int main()
{
    A a;
    B b;
}