#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <iterator>
#include <cstring>
#include <cstdlib> // Для функції rand()
#include <ctime>   // Для функції time()
#include <string>
#include <vector>
#include <cstdint> // Для доступу до  uint8_t
#include <fstream>
#include <stdexcept>
#include <set>


using namespace std;


int main() {
   
    std::string names[] = { "Sasha", "Ivan", "John", "Orlando", "Leonardo", "Nina", "Anton", "Molly" };

    std::cout << "Enter a name: ";
    std::string userInput;
    std::cin >> userInput;

    std::transform(userInput.begin(), userInput.end(), userInput.begin(), ::tolower);

    auto it = std::find_if(std::begin(names), std::end(names), [&userInput](const std::string& name) {
        std::string lowercaseName = name;
        std::transform(lowercaseName.begin(), lowercaseName.end(), lowercaseName.begin(), ::tolower);
        return lowercaseName == userInput;
        });

    if (it != std::end(names)) {
        std::cout << userInput << " was found." << std::endl;
    }
    else {
        std::cout << userInput << " was not found." << std::endl;
    }

    return 0;
}








int main() {
    
    std::string names[] = { "Sasha", "Ivan", "John", "Orlando", "Leonardo", "Nina", "Anton", "No1ly" };

    
    std::cout << "Enter a name: ";
    std::string userInput;
    std::cin >> userInput;

    
    bool found = false;
    for (const std::string& name : names) {
        if (name == userInput) {
            found = true;
            break;
        }
    }

    
    if (found) {
        std::cout << userInput << " was found." << std::endl;
    }
    else {
        std::cout << userInput << " was not found." << std::endl;
    }

    
}






int main() {
    
    std::set<int> set1 = { 1, 2, 3, 4, 5 };
    std::set<int> set2 = { 3, 4, 5, 6, 7 };
    std::cout << "Set 1: ";
    for (const auto& element : set1) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
    std::cout << "Set 2: ";
    for (const auto& element : set2) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
    std::cout << "Common elements: ";
    std::set<int> commonElements;

    for (const auto& element : set1) {
        if (set2.count(element) > 0) {
            commonElements.insert(element);
            std::cout << element << " ";
        }
    }
    std::cout << std::endl;
    std::cout << "Number of common elements: " << commonElements.size() << std::endl;

}








template <typename T, typename Compare>
T findMax(const std::vector<T>& vec, Compare comp) {
    if (vec.empty()) {
        throw std::invalid_argument("Vector is empty");
    }

    
    auto maxElement = std::max_element(vec.begin(), vec.end(), comp);

    return *maxElement;
}

int main() {
    
    std::vector<int> numbers = { -5, 10, -3, 8, -1 };

    
    auto absoluteCompare = [](int a, int b) {
        return std::abs(a) < std::abs(b);
    };

    try {
        
        int maxAbsolute = findMax(numbers, absoluteCompare);

        
        std::cout << "Max absolute value: " << maxAbsolute << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    
}