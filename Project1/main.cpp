#include "Menu.h"
#include "YearReadingsChild.h"

//���������� ���������� ��� ������
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

	vector <YearReadings*> array;

	int choice = 0;
	int year = 0;
	int month = 0;
	int currentMonth = 0;
	int payment = 0;
	float tariff = 0;
	int additionallyPayment = 0;

	bool fillFlag = false;

	while (!fillFlag) {
		cout << "���������� ���: ";
		while (!(cin >> year) || (cin.peek() != '\n')) {
			cin.clear();
			while (cin.get() != '\n');
			cout << "������: ������� �����: ";
		}
		array.push_back(new YearReadingsChild(year));
		cout << "���������? (������� 1 ��� 0) ";
		cin >> fillFlag;
	}

	bool exit = false;

	while (!exit) {
		int yearChoice = 0;
		cout << "�������� ���: ";
		cin >> yearChoice;
		for (YearReadings* arrayElement : array) {
			if (arrayElement->getCurrentYear() == yearChoice) {
				do {
					try {
						//������� ������� �������!
						menu();
						cin >> choice;
						switch (choice) {
						case 1:
							cout << "������� �����: ";
							//�������� �� ���� ������������� ����
							cin >> tariff;
							arrayElement->setTariff(tariff);
							cout << "��� ���������� �����: " << tariff << endl;
							system("pause");
							break;
						case 2:
							cout << "������� �����: ";
							cin >> month;
							currentMonth = month;
							cout << "������� �������: ";
							cin >> payment;
							arrayElement->paymentInputAndIndicationCount(month, payment);
							system("pause");
							break;
						case 3:
							arrayElement->indicationsOut();
							system("pause");
							break;
						case 4:
							arrayElement->finalSumCount();
							cout << "�������� ����� ��������: " << arrayElement->getFinalSumOut() << endl;
							system("pause");
							break;
						case 5:
							arrayElement->averageConsumptionCount();
							cout << "������� ����� �������: " << arrayElement->getAverageConsumption() << endl;
							system("pause");
							break;
						case 6:
							cout << "������� ���: " << arrayElement->getCurrentYear() << endl;
							system("pause");
							break;
						case 7:
							cout << "����� �� ������� �����: " << arrayElement[currentMonth - 1] << endl;
							system("pause");
							break;
						case 8:
							cin >> month;
							arrayElement->getInfoByMonth(month, true);
							system("pause");
							break;
						case 9:
							cout << "������� �����: ";
							cin >> month;
							cout << "������� �������������� �����: ";
							cin >> additionallyPayment;
							arrayElement->addAdditionallyPayment(month, additionallyPayment);
							system("pause");
							break;
						case 10:
							cout << "Bye" << endl;
							exit = true;
							system("pause");
							break;
						default:
							cout << "��� ������ ��������" << endl;
							system("pause");
							break;
						}
					}
					catch (const char* str) {
						cout << "Error: " << str << endl;
						system("pause");
						continue;
					}
				} while (choice != 10);
			}
		}

		//commit!

		cout << "�����: (������� 1 ��� 0) ";
		cin >> exit;
	}

}