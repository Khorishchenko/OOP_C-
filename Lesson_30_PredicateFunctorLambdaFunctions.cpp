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
#include <list>
#include <functional>

//  Предикат, Функтор, Лямбда Функції



// Функтор

// Функтор (Functor): Функтор - це об'єкт, який перевантажує оператор додавання operator(). 
// Він дозволяє об'єкту вести себе як функція і приймати аргументи, подібно до функції.



// class Student
// {
// public:
//     Student(std::string firstName, std::string lastName, int id) :
//         m_firstName(firstName), m_lastName(lastName), m_id(id) {}

//     std::string GetFirstName() const { return m_firstName; }
//     std::string GetLastName() const { return m_lastName; }
//     int GetId() const { return m_id; }

// private:
//     std::string m_firstName;
//     std::string m_lastName;
//     int m_id;
// };





// class StudentSorter
// {
// public:
//     bool operator() (const Student& s1, const Student& s2)
//     {
//         return (s1.GetFirstName() < s2.GetFirstName());
//     }
// };



// class MyFunctor
// {
//     public:
//         void operator()()
//         {
//             std::cout << "i am functor " << std::endl;
//         }

// };


// int main()
// {
//     MyFunctor f;

//     // f();         // Як виклик звичайної функції!




//     std::list<Student> students = {
//         Student("John", "Doe", 1),
//         Student("Jane", "Smith", 2),
//         Student("Bob", "Johnson", 3),
//         Student("Alice", "Williams", 4),
//         Student("Dave", "Brown", 5)
//     };

//     students.sort(StudentSorter());

//     for (const auto& student : students)
//     {
//         std::cout << student.GetLastName() << ", " << student.GetFirstName() << " (" << student.GetId() << ")" << std::endl;
//     }


//     return 0;
// }







// Предикати с++

// Придикат (Predicate): Придикат - це функція або об'єкт, який приймає один або декілька аргументів і 
// повертає логічне значення (зазвичай true або false). Він використовується для визначення, 
// чи виконується певна умова. Придикати часто використовуються в функціях фільтрації, сортування або пошуку даних.
using namespace std;

bool f(int16_t a){
   return a < 0;
}

bool compareLength(const std::string& a, const std::string& b) {
    return a.length() < b.length();
}

bool isOdd(int x) {
    return x % 2 != 0;
}

bool isEqual(int x, int y) {
    return x == y;
}



// int main() 
// {


//     vector<int> v {-1, -2, 4, 3, 0, -3, -9};

//     // // Предикаты с++
//     cout << count_if(v.begin(), v.end(), f) << endl;


     
// //  сортування вектора за довжиною рядків, використовуючи предикат
//     std::vector<std::string> vec = {"apple", "banana", "kiwi", "orange"};

  
//     std::sort(vec.begin(), vec.end(), compareLength);

//     for (const auto& str : vec) {
//         std::cout << str << " ";
//     }
//     std::cout << std::endl;



// // Використання предиката для видалення елементів зі списку, що задовольняють певну умову:
//   std::list<int> l = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

//     l.remove_if(isOdd);

//     for (const auto& x : l) {
//         std::cout << x << ' ';
//     }
//     std::cout << '\n';


// // Використання предиката для порівняння елементів в двох масивах:
//     int arr1[] = {1, 2, 3, 4, 5};
//     int arr2[] = {1, 2, 3, 4, 5};

//     bool result = std::equal(std::begin(arr1), std::end(arr1), std::begin(arr2), isEqual);

//     std::cout << (result ? "Equal" : "Not equal") << '\n';

//     return 0;
// }










// Лямбда Функції

// Лямбда-вираз у С++ — анонімна функція, яка підтримує стан між викликами і 
// може отримати доступ до змінних зі своєї області видимості. 
// Використовуючи лямбда-вирази, можна оголошувати функції в будь-якому місці коду.







class Person {
public:
    Person(std::string name, int age) : name_(name), age_(age) {}

    std::string get_name() const { return name_; }
    int get_age() const { return age_; }

private:
    std::string name_;
    int age_;
};

void print_vector(std::vector<Person> arr, std::function<void(Person)> fun)
{
	for (auto &element : arr)
		fun(element);
}


void process_data(const std::vector<int> data, std::function<void(int)> func) {
    for (auto d : data) {
        func(d);
    }
}


int main()
{
	// std::vector<int> arr{1, 2, 3, 4, 5};

	// auto f = [](int a) 
	// {
	// 	std::cout << "Element vector is: " << a << std::endl;

	// };

    

	// process_data(arr, [](int a) 
	// {
	// 	std::cout << "Element vector is: " << a << std::endl;

	// });

	// int result = 0;

    // char str = 'A';

    // std::cout << result << std::endl;

	// auto sum = [&result, str](int a, int b) {
    //     result = a + b;
    //     std::cout << str << std::endl;
    // };

    // sum(10, 20);

	// std::cout << result << std::endl;


	// Використання лямбда-функції в якості параметру функції:

	// std::vector<int> vec = {3, 2, 1, 5, 4};
	// process_data(vec, [](int val) { std::cout << val << " "; });



	// Використання лямбда-функції для порівняння об'єктів класу:
	// Цей код відсортує вектор об'єктів класу Person за зростанням віку.

	std::vector<Person> people = {
		{"Alice", 25},
		{"Bob", 30},
		{"Charlie", 20},
	};


	std::function<void(Person)> fun = [](const Person &a)
	{
		std::cout << a.get_age() << ' ' << a.get_name() << std::endl;
	};

	print_vector(people, fun);


	std::sort(people.begin(), people.end(), [](const Person& a, const Person& b) {
		return a.get_age() < b.get_age();
	});

	print_vector(people, fun);


//     return 0;
}