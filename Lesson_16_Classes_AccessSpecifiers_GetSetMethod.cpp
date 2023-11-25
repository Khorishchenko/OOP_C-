#include <iostream>



// Що таке ООП простими словами.
// Інкапсуляція. Поліморфізм. Успадкування.
// Що таке клас. Що таке об'єкт класу? Примірник класу це
// Методи класу. Що таке методи у програмуванні
// Модифікатори доступу класів. public private protected що це
// Що таке гетери та сеттери для класу. Методи get та set. Інкапсуляція це



class Person
{
public:
    void setAge(int age)
    {
        if (age < 0)
            m_age = 0;
        else
           m_age = age;
    }

    int getAge()
    {
        return m_age;
    }

    std::string getGander()
    {
        return m_gander;
    }

    void setName(std::string name)
    {
        m_name = name;
    }

    void setGander(std::string gander)
    {
        m_gander = gander;
    }

    void displayInfo() const{
        std::cout << "Name: " << m_name << ". Age: " << m_age << ". Gander: " << m_gander << std::endl;
    }

private:
    int m_age;
    std::string m_name;
    std::string m_gander;
};


int main()
{
    Person obj;
    Person obj2;

    // obj.m_age = 12;
    // obj.m_name = "Anton";
    // obj.m_gander = "Man";

    // obj2.m_age = 20;
    // obj2.m_name = "Sergii";
    // obj2.m_gander = "Man";

    obj.setAge(12);
    obj.setName("Anton");
    obj.setGander("Man");

    obj.displayInfo();
    // obj2.displayInfo();


    int age = obj.getAge();
    std::string gander = obj.getGander();

    std::cout << age << ' ' << gander << std::endl;
}









// Умова 1: Що таке клас. Створення класу.
// Створіть клас Person, який буде представляти особу з такими атрибутами: ім'я, вік, стать. 


// Умова 2: Що таке об'єкт класу.
// Створіть кілька об'єктів класу Person і встановіть їхні атрибути (ім'я, вік, стать) для кожного об'єкта.



// Умова 3: Примірник класу.
// За допомогою об'єктів класу Person, створіть метод displayInfo(), який виводитиме інформацію про кожну особу (ім'я, вік, стать) в консоль.


// Умова 4: Методи класу.
// Додайте метод до класу Person, який дозволить змінювати вік особи. Назвіть цей метод, наприклад, setAge(int age).



// Умова 5: Модифікатори доступу класів.
// Змініть модифікатор доступу до атрибуту "стать" класу Person з "public" на "private". Внесіть необхідні зміни в код, щоб забезпечити доступ до цього атрибуту через гетери та сетери.


// Умова 6: Що таке гетери та сеттери для класу.
// Додайте гетери (методи getGender()) та сетери (методи setGender()) для атрибуту "стать" в класі Person. Гетери повинні дозволяти отримувати значення атрибуту, а сетери - змінювати його.



// Умова 7: Інкапсуляція.
// Впевніться, що доступ до атрибуту "стать" здійснюється через гетери та сетери, що забезпечує інкапсуляцію даних.