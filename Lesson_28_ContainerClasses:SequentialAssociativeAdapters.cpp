
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
using namespace std;


// Контейнерні класи: послідовні, асоціативні, адаптери


int main()
{
    vector<int> myVector(10, 4); 

    for (int i = 0; i < myVector.size(); i++)
    {
        std::cout << setw(4) << myVector[i];
    }
    std::cout << endl;

    std::cout << "My vector size is " << myVector.size() << std::endl; 
    std::cout << "My vector capacity is " <<  myVector.capacity() << std::endl;     // Размер вектора по ячейкам помяты



    // myVector.resize(6); // устанавливаем длину, равную 6

    // for (int i = 0; i < myVector.size(); i++)
    // {
    //     std::cout << setw(4) << myVector[i];
    // }
    // std::cout << std::endl;

    // std::cout << "My vector size is " << myVector.size() << std::endl; 
    // std::cout << "My vector capacity is " <<  myVector.capacity() << std::endl;     // Размер вектора по ячейкам помяты




    // myVector.resize(12); // устанавливаем длину, равную 6

    // std::cout << "My vector size is " << myVector.size() << std::endl; 
    // std::cout << "My vector capacity is " <<  myVector.capacity() << std::endl;     // Раз




    // myVector = { 8, 7, 6, 5 }; // ок, длина myVector теперь равна 4!
    // std::cout << "length: " << myVector.size() << "  capacity: " << myVector.capacity() << '\n';

    // for (auto &element : myVector)
    //     std::cout << element << ' ';
    // std::cout << std::endl;




    // myVector.push_back(5);
    // myVector.push_back(5);
    // myVector.push_back(5);
    // myVector.push_back(5);

    // for (auto &element : myVector)
    //     std::cout << element << ' ';
    // std::cout << std::endl;

    // std::cout << "length: " << myVector.size() << "  capacity: " << myVector.capacity() << '\n';




    // myVector.clear();         // Очистить вектор 

    // std::cout << "My Vector size is " << myVector.size() << std::endl;
    // std::cout << "My vector capacity is " <<  myVector.capacity() << std::endl;

    // for (auto &element : myVector)
    //     std::cout << element << '|';
    // std::cout << std::endl;




    // myVector.reserve(100);             // Выделить количество памяти по ячейкам  

    // std::cout << "My Vector size is " << myVector.size() << std::endl;
    // std::cout << "My vector capacity is " <<  myVector.capacity() << std::endl;



    // std::cout << ((bool)myVector.empty()) << std::endl;    // Проверка на наличия значения в векторе 1 нету 0 есть 




    // myVector.resize(20, 10);  // Создать вектор на 20 элементы заполнить значением 10 все элементы 

    // std::cout << "My Vector size is " << myVector.size() << std::endl;
    // std::cout << "My vector capacity is " <<  myVector.capacity() << std::endl;

    // std::cout << ((bool)myVector.empty()) << std::endl;

    // for (int i = 0; i < myVector.size(); i++)
    // {
    //     std::cout << setw(4) << myVector[i];
    // }
    // std::cout << std::endl;




    // int index = 3;
    // myVector.erase(myVector.begin() + index);

    // for (auto const &element: myVector)
    //     std::cout << std::setw(4) << element;
    // std::cout << std::endl;

    // std::cout << "My Vector size is " << myVector.size() << std::endl; 
    // cout << "My vector capacity is " <<  myVector.capacity() << std::endl;

    // cout << std::endl;
}









// SET
bool is_anagram(std::string word, std::string anagram);
int count_unique_words(std::string sentence);


// int main()
// {
// 	std::set <int> st; // пример
// 	std::multiset <int> mst;

// Щоб додати новий елемент, потрібно використовувати функцію insert():

	// for (int i = 5; i >= 0; i--){
	// 	st.insert(i); // 5 4 3 2 1 0
	// }

	// std::set<int>::iterator it = st.begin();

	// while (it != st.end()) 
	// {
	// 	std::cout << *it++ << ' ';
	// }
    // cout << endl;


// add new element value = 4;

	// std::cout << "New add element, value == 4" << std::endl;
	// st.insert(4);

	// copy(st.begin(), st.end(), std::ostream_iterator<int>(std::cout, " ")), std::cout << '\n';

// змінити бік сортування у зворотний
// std::cout << "new set rever element !!!" << std::endl;


	// std::set <int, std::greater <int> > st2; 
	// for (int i = 0; i < 5; i++){
	// 	st2.insert(i); // 0 1 2 3 4
	// }

	// std::set <int> :: iterator it2 = st2.begin();

	// copy(st2.begin(), st2.end(), std::ostream_iterator<int>(std::cout, " ")), std::cout << '\n';


// multiset 

	// std::multiset <int> mst;
 
    // std::cout << "Додавання випадкових значень: " << std::endl;
    // for (int i = 0; i < 10; i++) {
    //     int random = rand() % 10 + 1;
    //     mst.insert(random);
    //     std::cout << i + 1 << ") " << random << std::endl;
    // }
 
    // std::multiset <int> :: iterator it = mst.begin();
 
    // std::cout << "Відсортований варіант: " << std::endl;
    // for (int i = 1; it != mst.end(); i++, it++) {
    //     std::cout << *it << " ";
    // }
    // std::cout << "\n\n";

 // delete elemet
    // std::cout << "Delete element: \n";
    // mst.erase(4);
	// if (mst.end() != mst.erase(4))


	// copy(mst.begin(), mst.end(), std::ostream_iterator<int>(std::cout, " ")), std::cout << '\n';

// lower_bound
	// std::cout << "lower_bound: = ";
	// it = mst.lower_bound(2);
	// std::cout << *it << std::endl;


// count
	// std::cout << mst.count(10) << std::endl;
	// std::cout << mst.size() << std::endl;




// Вивести всі унікальні елементи з масиву arr:

   	// int arr[] = {1, 2, 3, 4, 1, 2, 5};
    // std::set<int> unique_elems;

    // for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
    //     unique_elems.insert(arr[i]);
    // }

    // for (int elem : unique_elems) {
    //     std::cout << elem << " ";
    // }
    // std::cout << std::endl;

// Перевірити, чи є дане слово word анаграмою іншого слова anagram:
// Анаграма - це слово або фраза, створена шляхом перестановки літер іншого слова або фрази. Наприклад, анаграмою слова "кінь" може бути слово "нік".

	// std::string word = "listen";
    // std::string anagram = "silent";

    // if (is_anagram(word, anagram)) {
    //     std::cout << word << " and " << anagram << " are anagrams" << std::endl;
    // } else {
    //     std::cout << word << " and " << anagram << " are not anagrams" << std::endl;
    // }

// Визначити кількість унікальних слів у рядку sentence:

	// std::string sentence = "The quick brown fox jumps over the lazy dog.";
    // int unique_word_count = count_unique_words(sentence);

    // std::cout << "There are " << unique_word_count << " unique words in the sentence." << std::endl;

//     return 0;
// }

bool is_anagram(std::string word, std::string anagram) {
    std::set<char> word_set(word.begin(), word.end());
    std::set<char> anagram_set(anagram.begin(), anagram.end());

    return word_set == anagram_set;
}

int count_unique_words(std::string sentence) {
    std::set<std::string> unique_words;
    std::stringstream ss(sentence);
    std::string word;

    while (ss >> word) {
        unique_words.insert(word);
    }

    return unique_words.size();
}



