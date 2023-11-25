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

//  Розумні покажчики Smart pointer, unique_ptr, shared_ptr and weak_ptr

//  Розумні вказівники реалізують механізми автоматичного видалення або вивільнення ресурсів, 
//  коли на них не залишається посилань.


template <typename T>
class smart_pointUnique
{
    public:
   
    smart_pointUnique(T *ptr = nullptr){
        this->ptr = ptr;
    }

    smart_pointUnique(smart_pointUnique<T> &&obg)
    {
        this->ptr = obg.ptr;
        obg.ptr = nullptr;
    }

    T& operator *()
    {
        return *ptr;
    }

    ~smart_pointUnique()
    {
        if (ptr != nullptr)
        {
            delete ptr;
            cout << "Delete is good !" << std::endl;
        }
     
    }
    private:
    T *ptr;

    T operator =(smart_pointUnique<T> obg) = delete;

};

template <typename T>
class smart_pointShared
{
    public:
    static int count;

    smart_pointShared(T *ptr = nullptr)
    {
        this->ptr = ptr;
        count++;
    }

    T& operator *()
    {
        return *ptr;
    }

    ~smart_pointShared()
    {
        if (count > 1)
        {
            count--;
        }
        else{
            cout << "Delete is good !" << std::endl;
            delete ptr;
        }
    }

    private:
    T *ptr;
};

template <typename T>
int smart_pointShared<T>::count = 0;



// int main()
// {
    // smart_pointUnique<int> ptr(new int(100));

    // cout << *ptr << endl;
    // *ptr = 200;
    // cout << *ptr << endl;

    // smart_pointUnique<int> ptr2(move(ptr));
    // // ptr2 = ptr;
    // cout << *ptr2 << endl;

  
    // smart_pointShared<int> ptr3(new int(88));

    // cout << *ptr3 << endl;

    // smart_pointShared<int> ptr4;

    // ptr4 = ptr3;

    // cout << *ptr4 << endl;

    // smart_pointShared<int> ptr5;


    // ptr5 = ptr4;

    // cout << *ptr5 << endl;

    // smart_pointShared<int> ptr6(new int(100));
  
    // cout << *ptr6 << endl;




//     return 0;
// }




// Розумний покажчик std::unique_ptr, shared_ptr

// int main()
// {
    // unique_ptr<int> ptr(new int(34));

    // cout << "this is ptr " << *ptr << endl;

    // unique_ptr<int> ptr2;

    // ptr2 = move(ptr);

    // // ptr2.swap(ptr);


    // cout  << "this is ptr2 "  << *ptr2 << endl;


    // cout << "this is ptr " << *ptr << endl;

   
    // shared_ptr<int> ptr(new int(10));

    // cout << "this is ptr " << *ptr << endl;
   
    // shared_ptr<int> ptr2(ptr);
    // cout  << "this is ptr2 "  << *ptr2 << endl;
    // cout << "this is ptr " << *ptr << endl;

    // *ptr = 10000;

    // cout  << "this is ptr2 "  << *ptr2 << endl;

    // shared_ptr<int> ptr3(new int(30));

    // std::cout << *ptr3 << std::endl; 

    
//     return 0;
// }