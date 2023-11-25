#include <iostream>

// Обробка виняткових ситуацій




// int main()
// {
//     //  try
//     //  {
//     //       throw()
//     //  }
//     //  catch()
//     //  {

//     //  }
          
     

//      int value;
//      std::cin >> value;

//      try
//      {
//           if (value == 0)
//                throw(2.2);
//           else
//                std::cout << "Value is: " << value << std::endl;
//      }
//     catch (const int exception)
//      {
//           std::cout << "int Error " << exception << std::endl;
//      }
//     catch (const char exception)
//     {
//           std::cout << "char Error "  << exception << std::endl;
//      }
//     catch (const char *exception)
//     {
//         std::cout << "cahr* Error "  << exception << std::endl;
//     }
//     catch(...)
//     {
//         std::cout << " Universal catch!" << std::endl;
//     }

//      return 0;
// }



// Можна використовувати вбудовані винятки !

// int divide(int numerator, int denominator) {
//     if (denominator == 0) {
//         throw std::invalid_argument("Division by zero is not allowed.");
//     }
//     return numerator / denominator;
// }

// int main() {
//     try {
//         int result = divide(10, 2);
//         std::cout << "Result of division: " << result << std::endl;

//         // Спроба поділити на нуль
//         result = divide(5, 0);
//         std::cout << "This won't be printed." << std::endl;
//     } 
//     catch (const std::invalid_argument& e) {
//         std::cerr << "Exception caught: " << e.what() << std::endl;
//     }

//     return 0;
// }




// кілька прикладів вбудованих вийняткових ситуацій у стандартній бібліотеці C++.

// std::invalid_argument:  -  Ви вже бачили цей вийняток, і він використовується, коли аргумент функції або операція недійсний.
// std::out_of_range: - Цей вийняток генерується, коли ви використовуєте індекс для доступу до масиву або контейнера, який виходить за межі його діапазону.
// std::runtime_error: - Це загальний клас для винятків, які виникають під час виконання програми і не вписуються в жоден інший конкретний клас.
// std::logic_error: - Цей клас використовується для винятків, пов'язаних із помилками логіки програми. Включає підкласи, такі як std::domain_error, std::invalid_argument і інші.
// std::overflow_error і std::underflow_error: Ці вийнятки виникають, коли відбувається переповнення або недостатність чисел під час обчислень.
// std::length_error: Виняток std::length_error генерується, коли довжина контейнера перевищує максимально допустиму довжину (зазвичай вказується для стандартних контейнерів, таких як std::vector).

// Розробники також можуть створювати власні класи вийнятків для своїх потреб, якщо вбудованих класів недостатньо.








// Ви можете мати кілька блоків catch, що обробляють різні типи вийнятків. 
int main()
{
    try {
        int x = 10;
        int y = 0;
        if (y == 0) {
            throw std::invalid_argument("Division by zero");
        }
        int result = x / y;
    } 
    catch (const std::invalid_argument& exception) {
        std::cerr << "Invalid argument exception caught: " << exception.what() << std::endl;
    } 
    catch (const std::runtime_error& exception) {
        std::cerr << "Runtime error exception caught: " << exception.what() << std::endl;
    } 
    catch (const std::exception& exception) {
        std::cerr << "General exception caught: " << exception.what() << std::endl;
    }
}








// Створення свого винятку.

class CustomException {
public:
    CustomException(const std::string& message) : message_(message) {}

    const std::string& what() const {
        return message_;
    }

private:
    std::string message_;
};


class Calculator {
public:
    int divide(int x, int y) {
        if (y == 0) {
            throw CustomException("Division by zero");
        }
        return x / y;
    }
};

int main() {
    Calculator calc;
    
    try {
        int result = calc.divide(10, 0);


        std::cout << "Result: " << result << std::endl;
    } 
    catch (const CustomException& e) {
        std::cerr << "Custom Exception caught: " << e.what() << std::endl;
    }

    return 0;
}





// class A
// {
// public:
//     A(int x) : m_value(x) {}

//     void Print() const{
//         std::cout << m_value << std::endl;
//     }

// private:
//     int m_value;
// };

// A f()
// {
//     return A(10);
// }

// int main()
// {
//     f().Print();

//     A o1 = f();
//     o1.Print();
// }