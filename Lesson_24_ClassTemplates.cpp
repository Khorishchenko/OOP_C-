#include <iostream>
#include <cassert>
// using namespace std;


// Шаблонні Функції.
template <typename T>
void swap(T &a, T &b)
{
	 T tmp = a;
	 a = b;
	 b = tmp;
}

int main()
{
	int x = 10, y = 20;

	std::cout << x << ' ' << y << std::endl;
	swap(x, y);
	std::cout << x << ' ' << y << std::endl;

	char A = 'A', B = 'B';

	std::cout << A << ' ' << B << std::endl;
	swap(A, B);
	std::cout << A << ' ' << B << std::endl;
}


// Шаблони класів
template <typename T>
class vector
{
public:
	vector(int size)
	{
		if(size > 0)
		{
			ptr = new T[size];

			if (sizeof(T) == 8)
			{
				for (int i = 0; i < size; i++)
					ptr[i] = (double)(rand() % 10) / 2;
			}
			else
			{
				for (int i = 0; i < size; i++)
					ptr[i] = rand() % 26 + 65;
			}

			m_size = size;
		}
		else{
			ptr = nullptr;
			m_size = 0;
		}
	}

	~vector()
	{
		if (ptr != nullptr)
		{
			delete [] ptr;
		}
	}

	void Print() const;

private:
	T *ptr;
	int m_size;
};

template <typename T>
void vector<T>::Print() const
{
	if (m_size > 0)
	{
		for(int i = 0; i < m_size; i++)
		{
			std::cout << ptr[i] << ' ';
		}
		std::cout << std::endl;
	}
	else
	{
		std::cout << "Arr is empty" << std::endl;
	}
}

int main()
{
	vector<int> o1(10);
	o1.Print();

	vector<double> o2(10);
	o2.Print();

	vector<char> o3(10);
	o3.Print();
}















// Шаблонні обчислення:
// Створити клас для обчислення математичних операцій (наприклад, додавання, віднімання, множення) за допомогою шаблонів. 
// Клас повинен підтримувати різні числові типи (int, float, double) та виконувати відповідні операції.


// Шаблонний генератор ID: 
// Розробіть клас "IDGenerator," який створює унікальні ідентифікатори будь-якого типу даних.
// Користувач може використовувати цей клас для створення унікальних ідентифікаторів для своїх об'єктів.


// Шаблонний лічильник: 
// Створіть клас "Counter," який може використовувати будь-який тип даних як лічильник. 
// Клас повинен надавати можливість збільшувати та зменшувати значення лічильника та отримувати поточний стан лічильника.


// Шаблонна матриця: 
// Створіть клас "Matrix," який представляє двовимірну матрицю об'єктів будь-якого типу. 
// Клас повинен надавати методи для виконання операцій з матрицею, таких як додавання, віднімання та множення.


