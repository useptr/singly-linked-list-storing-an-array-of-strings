#include <Windows.h>
#include <iostream>
#include <fstream>
#include <conio.h>
#include < limits >
#include "list.h"

#if defined(max) // разрешение конфликта max Windows.h и limits
#undef max
#endif
//template<class T> class Str {
//    T* str_;
//    unsigned int size_;
//    template<typename T> friend ostream& operator<<(ostream&, Str<T>&);
//public:
//    Str();
//};
//template <class T> Str<T>::Str() : str_{ nullptr }, size_{ 0 } {}
//template<typename T> ostream& operator<<(ostream& os, Str<T>& obj) {
//    os << obj.str_ << endl;
//    return os;
//}

int main()
{
    using namespace std;

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
	ListVariable::ARR_SIZE = 0;
	while (ListVariable::ARR_SIZE < 2) {
		system("cls");
		cout << "введите максимальную длину массива(не меньше 2): ";
		cin >> ListVariable::ARR_SIZE;
		if (!cin) {
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin.clear();
			cin.get();
		}
	}

    List<char> linkedList;
    
	int character = 0;
	while (character != 27) {
		system("cls");
		cout << "0 - вывод всей структуры" << endl;
		cout << "1 - добавить строку" << endl;
		cout << "2 - удалить последнюю строку" << endl;
		cout << "Esc - выход" << endl;
		linkedList.show();
		character = _getch();
		switch (character)
		{
		case 48: // 0
		{			
			linkedList.show();
			break;
		}
		case 49: // 1
		{
			linkedList.insertAtEnd();
			break;
		}
		case 50: // 2
		{
			linkedList.delLast();
			break;
		}
		case 51: // 3
		{
			break;
		}
		case 52: // 4
		{
			break;
		}
		case 53: // 5
		{
			break;
		}
		case 54: // 6
		{
			break;
		}
		case 55: // 7
		{
			break;
		}
		case 56: // 8
		{
			break;
		}
		case 57: // 9
		{
			break;
		}
		case 98: // b
		{
			break;
		}
		case 112: // p
		{
			break;
		}
		case 100: // d
		{

		}
		default:
			break;
		}
		system("pause");
	}
}
