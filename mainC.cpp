#include <iostream>
#include <vector>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <iterator>
#include <algorithm>
#include <map>
#include <set>
#include <sstream>
#include <chrono>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <list>
#include <memory>
#include <iostream>
#include <string>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <cctype>
#include <ctime>

using namespace std;

typedef std::string NameStuned;
typedef unsigned int uint;
typedef char Array[20];
typedef std::string StringTwo;
typedef int (*PtrF)(int, int);
typedef int (*Array_Func_Ptr[5])(int, int);

typedef int INT_16;
typedef char CHAR_CHAR;
typedef float FLOAt_FLOAt;


struct INt_Char
{
    int x;
    char value;
};


int main()
{
    INt_Char obj;

    obj.x = 10;
    obj.value = 'A';

    std::cout <<  obj.x << ' ' << obj.value << std::endl;
}


struct Human
{
	int age;
	std::string name;
};

int main()
{
	Human Student {23, "sergey"};

	std::cout << Student.age << ' ' << Student.name << std::endl;

	Student.age = 100;

	std::cout << Student.age << std::endl;

	return 0;
}


struct Human
{
	int age;
	const char *name;
}Student, StudenTwo;

int main()
{
	Student = {23, "sergey"};
	std::cout << Student.age << ' ' << Student.name << std::endl;


    StudenTwo = {30, "Anton"};
    std::cout << StudenTwo.age << ' ' << StudenTwo.name << std::endl;

	return 0;
}



struct 					
{
	int age;
	const char *name;
}Student, Student2, Student3;


int main()
{

	Student = {23, "sergey"};
	std::cout << Student.age << ' ' << Student.name << std::endl;

	Student2 = Student;										// Присвоєння 

	std::cout << Student2.age << ' ' << Student2.name << std::endl;


    

	return 0;
}


// Оголошення структури "Адреса"
struct Address {
    std::string street;
    std::string city;
    std::string postalCode;
};

// Оголошення структури "Контактна інформація"
struct ContactInfo {
    std::string name;
    std::string phoneNumber;
    Address address;        // Включення структури "Адреса" в "Контактну інформацію"
};

int main() {
    // Створення об'єкта типу "Контактна інформація"
    ContactInfo person;

    // Заповнення даних про контакт
    person.name = "Іван Петрович";
    person.phoneNumber = "+1234567890";
    person.address.street = "Вулиця Лісова, 5";
    person.address.city = "Київ";
    person.address.postalCode = "12345";

    // Виведення інформації про контакт на консоль
    std::cout << "Ім'я: " << person.name << std::endl;
    std::cout << "Номер телефону: " << person.phoneNumber << std::endl;
    std::cout << "Адреса: " << person.address.street << ", " << person.address.city << ", " << person.address.postalCode << std::endl;


    ContactInfo ArrPerson[2];
    int arr[10];

    for (int i = 0; i < 2; i++)
    {
        std::cin >> ArrPerson[i].name;
        std::cin >> ArrPerson[i].phoneNumber;
        std::cin >> ArrPerson[i].address.city;
        std::cin >> ArrPerson[i].address.street;
        std::cin >> ArrPerson[i].address.postalCode;
    }

    std::cout << "\n\n";
    for (int i = 0; i < 2; i++)
    {
        std::cout << ArrPerson[i].name << std::endl;
        std::cout << ArrPerson[i].phoneNumber  << std::endl;
        std::cout << ArrPerson[i].address.city  << std::endl;
        std::cout << ArrPerson[i].address.street  << std::endl;
        std::cout << ArrPerson[i].address.postalCode  << std::endl;
    }
    
    return 0;
}




// Багатовимірні динамічні масиви


// int main(void)
// {
//     const int size_row = 3, size_colum = 5;

//     float **ptrarray = new float* [size_row]; // два рядки в масиві

//     for (int count = 0; count < size_row; count++)
//     {
//         ptrarray[count] = new float [size_colum]; // і п'ять стовпців
//         for (int j = 0; j < size_colum; j++)
//             ptrarray[count][j] = ((double)(rand() % 10 - 5) / 2);
//     }

//     // де ptrarray - масив покажчиків на виділену ділянку пам'яті під масив дійсних чисел типу float


//     for (int i = 0; i < size_row; i++)
//     {
//         for (int j = 0; j < size_colum; j++)
//             std::cout << ptrarray[i][j] << ' ';
//         std::cout << std::endl;
//     }

//     // Вивільнення пам'яті відводиться під двомірний динамічний масив:
//     for (int count = 0; count < size_row; count++)      // де 2 – кількість рядків у масиві
//         delete[] ptrarray[count];

//     delete [] ptrarray;

// }