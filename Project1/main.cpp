#include "Menu.h"
#include "YearReadingsChild.h"

//Перегрузка операторов вне класса
ostream& operator<<(ostream& stream, YearReadings& ourObject) {
	ourObject.indicationsOutOnly(stream);
	return stream;
}

double& operator += (double& sum, YearReadings& ourObject) {
	sum += ourObject.getAverageConsumption();
	return sum;
}

int main() {
	setlocale(LC_ALL, "Russian");

	YearReadingsChild info{2023};
	YearReadings infoTwo{2022};
	vector <YearReadings> array;
	/*array.push_back(info);
	array.push_back(infoTwo);
	int year = 2023;
	array[0].setYear(year);
	year -= 10;
	array[1].setYear(year);
	cout << array[0].getCurrentYear() << endl;
	cout << array[1].getCurrentYear() << endl;
	system("pause");*/

	int choice = 0;
	int year = 0;
	int month = 0;
	int currentMonth = 0;
	int payment = 0;
	float tariff = 0;

	bool fillFlag = false;

	while (!fillFlag) {
		cout << "Установите год: ";
		while (!(cin >> year) || (cin.peek() != '\n')) {
			cin.clear();
			while (cin.get() != '\n');
			cout << "Ошибка: введите число: ";
		}
		array.push_back(YearReadingsChild(year));
		cout << "Закончить? (введите 1 или 0) ";
		cin >> fillFlag;
	}

	bool exit = false;

	while (!exit) {
		int yearChoice = 0;
		cout << "Выберите год: ";
		cin >> yearChoice;
		for (auto& arrayElement : array) {
			if (arrayElement.getCurrentYear() == yearChoice) {
				do {
					try {
						//Выбрать элемент массива!
						menu();
						cin >> choice;
						switch (choice) {
						case 1:
							cout << "Введите тариф: ";
							//Проверка на ввод исключительно цифр
							cin >> tariff;
							arrayElement.setTariff(tariff);
							cout << "Был установлен тариф: " << tariff << endl;
							system("pause");
							break;
						case 2:
							cout << "Введите месяц: ";
							cin >> month;
							currentMonth = month;
							cout << "Введите затраты: ";
							cin >> payment;
							arrayElement.paymentInputAndIndicationCount(month, payment);
							system("pause");
							break;
						case 3:
							arrayElement.indicationsOut();
							system("pause");
							break;
						case 4:
							arrayElement.finalSumCount();
							cout << "Итоговая сумма платежей: " << arrayElement.getFinalSumOut() << endl;
							system("pause");
							break;
						case 5:
							arrayElement.averageConsumptionCount();
							cout << "Средняя трата энергии: " << arrayElement.getAverageConsumption() << endl;
							system("pause");
							break;
						case 6:
							cout << "Текущий год: " << arrayElement.getCurrentYear() << endl;
							system("pause");
							break;
						case 7:
							cout << "Платёж за текущий месяц: " << arrayElement[currentMonth - 1] << endl;
							system("pause");
							break;
						case 8:
							cin >> month;
							info.getInfoByMonth(month, true);
							system("pause");
							break;
						case 9:
							cout << info;
							cout << "Bye" << endl;
							exit = true;
							system("pause");
							break;
						default:
							cout << "Нет такого варианта" << endl;
							system("pause");
							break;
						}
					}
					catch (const char* str) {
						cout << "Error: " << str << endl;
						system("pause");
						continue;
					}
				} while (choice != 9);
			}
		}

		//commit

		cout << "Выйти: (введите 1 или 0) ";
		cin >> exit;
	}

}