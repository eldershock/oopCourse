#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void menu() {
	system("cls");
	cout << "1 - Выбрать тариф" << endl;
	cout << "2 - Внести траты за месяц" << endl;
	cout << "3 - Вывод показаний" << endl;
	cout << "4 - Вывод итоговой суммы платежей" << endl;
	cout << "5 - Вывод среднего потребления энергии в месяц" << endl;
	cout << "6 - Вывод текущего года" << endl;
	cout << "7 - Вывод размера платежа за текущий месяц" << endl;
	cout << "8 - Вывод информации за введённый месяц" << endl;
	cout << "9 - Выйти" << endl;
}
