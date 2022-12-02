#include <Windows.h>
#include <iostream>
#include <conio.h>
#include < limits >
#include "list.h"

#if defined(max) // разрешение конфликта max Windows.h и limits
#undef max
#endif
void showMenu() {
	cout << "0 - вывод всей структуры" << endl;
	cout << "1 - добавить строку" << endl;
	cout << "2 - удалить последнюю строку" << endl;
	/*cout << "3 - включение строки по логическому номеру" << endl;
	cout << "4 - извлечение строки по логическому номеру" << endl;*/
	cout << "5 - включение строки с сохранением порядка" << endl;
	cout << "6 - загрузка строк из бинарного файла" << endl;
	cout << "7 - сохранение строк в бинарный файл" << endl;
	cout << "8 - загрузка строк из текстового файла" << endl;
	cout << "9 - сохранение строк в текстовый файл" << endl;
	cout << "s - сортировка" << endl;
	//cout << "b - балансировка" << endl;
	cout << "Esc - выход" << endl;
}
int main()
{
    using namespace std;

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

	/*ListVariable::ARR_SIZE = 0;
	while (ListVariable::ARR_SIZE < 2) {
		system("cls");
		cout << "введите максимальную длину массива(не меньше 2): ";
		cin >> ListVariable::ARR_SIZE;
		if (!cin) {
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin.clear();
			cin.get();
		}
	}*/
    List<char> linkedList;
    
	int character = 0;
	while (character != 27) {
		system("cls");		
		linkedList.show();
		showMenu();
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
			linkedList.insertWithOrder();
			break;
		}
		case 54: // 6
		{
			linkedList.readBinFIle();
			break;
		}
		case 55: // 7
		{
			linkedList.writeBinFIle();
			break;
		}
		case 56: // 8
		{
			linkedList.redFIle();
			break;
		}
		case 57: // 9
		{
			linkedList.writeFIle();
			break;
		}
		case 98: // b
		{
			break;
		}
		case 115: // s
		{
			linkedList.sort();
			break;
		}
		default:
			break;
		}
		system("pause");
	}
}
