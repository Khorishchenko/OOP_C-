#include <iostream>
#include <vector>
#include <iomanip>
#include <iterator>
#include <algorithm>
#include <map>
#include <set>
#include <sstream>
#include <list>

//  Ітератори, Алгоритми

// Ітератор - це об'єкт, який дозволяє послідовно перебирати елементи в колекціях або контейнерах, таких як масиви, 
// списки або інші структури даних. Ітератори надають можливість 
// отримувати доступ до елементів послідовно, без необхідності знати деталі їх зберігання та доступу.


// Ітератори
// int main() {
//     std::vector<int> numbers = {1, 2, 3, 4, 5};

//     // Оголошення ітератора для масиву
//     std::vector<int>::iterator it;

//     // Перебираємо масив за допомогою ітератора і виводимо його елементи
//     for (it = numbers.begin(); it != numbers.end(); ++it) {
//         std::cout << *it << " ";
//     }

    
//     std::cout << std::endl;

//     return 0;
// }



// Застосування Ітераторів
// SET
bool is_anagram(std::string word, std::string anagram);
int count_unique_words(std::string sentence);


// int main()
// {
	// std::set<int> st; // пример
	// std::multiset <int> mst;

// Щоб додати новий елемент, потрібно використовувати функцію insert():

	// for (int i = 5; i >= 0; i--){
	// 	st.insert(i); // 5 4 3 2 1 0
	// }

	// std::set<int>::iterator it = st.begin();

	// while (it != st.end()) 
	// {
	// 	std::cout << *it++ << ' ';
	// }
    // std::cout << std::endl;


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

	// std::set<int>::iterator it2 = st2.begin();

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
    // for (; it != mst.end(); it++) {
    //     std::cout << *it << " ";
    // }
    // std::cout << "\n\n";

//  delete elemet
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
// Анаграма - це слово або фраза, створена шляхом перестановки літер іншого слова або фрази. Наприклад, анаграмою слова "кінь" може бути слово "нікь".

	// std::string word = "listen";
    // std::string anagram = "silent";

    // if (is_anagram(word, anagram)) {
    //     std::cout << word << " and " << anagram << " are anagrams" << std::endl;
    // } else {
    //     std::cout << word << " and " << anagram << " are not anagrams" << std::endl;
    // }

// Визначити кількість унікальних слів у рядку sentence:

// 	std::string sentence = "The quick brown fox jumps over The lazy dog.";
//     int unique_word_count = count_unique_words(sentence);

//     std::cout << "There are " << unique_word_count << " unique words in the sentence." << std::endl;

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

    for (auto ele: unique_words)
        std::cout << ele << std::endl;

    return unique_words.size();
}









// Застосування Алгоритмів

template <typename T>
void print(std::vector<T> &arr){
	for (auto &element : arr)
		std::cout << element << ' ';
	std::cout << std::endl;
}


// int main()
// {
	// функція sort для vector
	// std::cout << "This is VECTOR: " << std::endl;

	// std::vector <int> arr;

	// for (int i = 0; i < 10; i++){
	// 	arr.push_back(random() % 10);
	// }

	// print(arr);

	// copy(arr.begin(), arr.end(), std::ostream_iterator<int>(std::cout, " ")), std::cout <<  "\n\n";
	

	// // // sort elements arr
	// std::cout << "sort vector:  " << std::endl;
	// std::sort(arr.begin(), arr.end());
	// copy(arr.begin(), arr.end(), std::ostream_iterator<int>(std::cout, " ")), std::cout <<  "\n\n";

	// // // sort revers --- 
	// std::cout << "sort vector revers:  " << std::endl;

	// std::sort(arr.rbegin(), arr.rend());
	// copy(arr.begin(), arr.end(), std::ostream_iterator<int>(std::cout, " ")), std::cout <<  "\n\n";
	// // 



	// std::cout << "This is LIST: " << std::endl;
	// // Функция sort для list
	// std::list<int> lt;

	// for(int i = 0; i < 10; i++){
	// 	lt.push_back(random() % 10);
	// }

	// copy(lt.begin(), lt.end(), std::ostream_iterator<int>(std::cout, " ")), std::cout << "\n\n";


	// std::cout << "sort list:  " << std::endl;
	// lt.sort();
	// copy(lt.begin(), lt.end(), std::ostream_iterator<int>(std::cout, " ")), std::cout <<  "\n\n";






	// // Алгоритми min_element() и max_element()

	// std::list<int> li;
    // for (int nCount=0; nCount < 5; ++nCount)
    //     li.push_back(nCount);

	// copy(li.begin(), li.end(), std::ostream_iterator<int>(std::cout, " ")), std::cout <<  "\n\n";

 
    // std::list<int>::const_iterator it; // объявляем итератор

    // it = min_element(li.begin(), li.end());
    //     std::cout << *it << ' ';
    // it = max_element(li.begin(), li.end());
    //     std::cout << *it << ' ';
	
    // std::cout << '\n';




    // // Алгоритми find() і list::insert()

    // std::list<int> li;
    // for (int nCount=0; nCount < 5; ++nCount)
    //     li.push_back(nCount);
 
    // std::list<int>::const_iterator it = li.begin(); //оголошуємо ітератор
    // // *it = 10;
    // it = find(li.begin(), li.end(), 4); // шукаємо у списку число 2
	// copy(li.begin(), li.end(), std::ostream_iterator<int>(std::cout, " ")), std::cout <<  "\n\n";

    // if(it != li.end())
    // 	std::cout << *it << std::endl;
    // else
    // 	std::cout << "Not found element 6 in list " << std::endl;

    // std::cout << *it << std::endl;
    // advance(it, -2);
    // std::cout << *it << std::endl;
	// copy(li.begin(), li.end(), std::ostream_iterator<int>(std::cout, " ")), std::cout <<  "\n\n";



    // li.insert(it, 7); // використовуємо алгоритм list::insert() для додавання числа 7 перед числом 2
    // std::cout << *it << std::endl;

 
    // for (it = li.begin(); it != li.end(); ++it) // виводимо за допомогою циклу та ітератора елементи списку
    //     std::cout << *it << ' ';
    // std::cout << "\n";

    // std::reverse(li.begin(), li.end()); // сортуємо елементи list у зворотний бік

    //  for (it = li.begin(); it != li.end(); ++it) // виводимо за допомогою циклу та ітератора елементи списку
    //     std::cout << *it << ' ';
    // std::cout << "\n";

    	
    // std::cout << '\n';




    // // Алгоритми reverse()

    // std::vector<int> vect;
    // vect.push_back(4);
    // vect.push_back(8);
    // vect.push_back(-3);
    // vect.push_back(3);
    // vect.push_back(-8);
    // vect.push_back(12);
    // vect.push_back(5);


    // // std::sort(vect.begin(), vect.end()); // виконуємо сортування елементів вектора
 
    // std::vector<int>::const_iterator it; // оголошуємо ітератор
    // for (it = vect.begin(); it != vect.end(); ++it) // виводимо за допомогою циклу та ітератора елементи вектора
    //     std::cout << *it << ' ';
 
    // std::cout << '\n';
 
    // std::reverse(vect.begin(), vect.end()); // сортуємо елементи вектора у зворотний бік
 
    // for (it = vect.begin(); it != vect.end(); ++it) // виводимо за допомогою циклу та ітератора елементи вектора
    //     std::cout << *it << ' ';
 	
    // std::cout << '\n';
// }




