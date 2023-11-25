#include <iostream>
using namespace std;

// 7. Обробка виняткових ситуацій


// Правильний код, для компіляції на Windows.
class Exception {
protected:
	char message[255];
public:
	Exception(const char* str) {
		strcpy_s(message, str);
	}
	void Message() {
		cout << "Base Exception:\n";
		cout << message;
	}
};
class DivideByZeroException :public Exception {
public:
	DivideByZeroException(const char* str) :Exception(str) {}
	void Message() {
		cout << "Divide by Zero Exception\n";
		cout << message;
	}
};
 
class FileException :public Exception {
public:
	FileException(const char* str) :Exception(str) {}
	void Message() {
		cout << "File Exception\n";
		cout << message;
	}
};
 
int main()
{
	try {
		int a, b;
		a = 2;
		b = 0;
		if (b == 0)
			throw DivideByZeroException("Divide by 0");
		/*FILE* ptr = fopen_s("C:\\data.txt", "r");*/
		FILE* filePtr;
		errno_t err = fopen_s(&filePtr, "C:\\data.txt", "r");
		if (err == 0) {
			// File opened successfully, you can work with filePtr
		}
		else {
			throw FileException("File not Open !!");
		}
	}
	catch (Exception& ex) {
		ex.Message();
	}
	catch (FileException& ex) {
		ex.Message();
	}
	catch (DivideByZeroException& ex) {
		ex.Message();
	}
 
	return 0;
}

// Base Exception:
// Divide by 0







// 16. Рядки.
// Чи спрацює наступний код? Якщо так, що ми побачимо на екрані? Якщо ні, - вкажіть помилки:

#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
	char str[20];
	itoa(65, str, 8);
	cout << str;
	return 0;
}
//  101
