#include "YearReadings.h"

void YearReadings::checkYear() {
	if (year == 0) throw("������� ���");
}

int YearReadings::operator[](int month) {
	return payments[month];
}

void YearReadings::setTariff(float& tariff) {
	if (tariff == 0)
		throw "����� �� ����� ���� ����� 0";
	this->tariff = tariff;
}

void YearReadings::indicationsOut() {
	checkYear();
	int month = 0;
	for (const int& i : indications) {
		month += 1;
		if (i == wrongValue)
			continue;
		cout << "��������� ������� �� " << month << " ����� " << i << endl;
	}
}

void YearReadings::getInfoByMonth(int& month, bool getPaymentsInfo) {
	if (getPaymentsInfo) {
		cout << indications[month - 1] << ' ' << payments[month - 1] << endl;
	}
	else {
		cout << indications[month - 1] << endl;
	}
}

void YearReadings::indicationsOutOnly(ostream& stream) {
	checkYear();
	for (const int& i : indications) {
		if (i == wrongValue)
			continue;
		stream << i << endl;
	}
}

int YearReadings::getCurrentYear() const {
	return year;
}

int YearReadings::getFinalSumOut() const {
	return finalSum;
}

float YearReadings::getAverageConsumption() const {
	return averageConsumption;
}

//�������� ������� ��������

void YearReadings::paymentInputAndIndicationCount(int& month, int& payment) {
	if (month < 1 || month > yearLen)
		throw("������������ ����� ������");

	checkYear();

	if (payment > pow(10, 5) || payment < 0)
		throw "������ ����� ����������";

	payments[month - 1] = payment;

	indications[month - 1] = payments[month - 1] * tariff;
}

void YearReadings::finalSumCount() {
	checkYear();

	int tempSum = 0;

	for (const int& i : payments) {
		if (i == wrongValue)
			continue;
		tempSum += i;
	}

	finalSum = tempSum;
	tempSum = 0;
}

void YearReadings::averageConsumptionCount() {
	checkYear();

	if (payments[0] == 0)
		throw "�� ������� ���������";

	int tempAvgConsumption = 0;
	int lengthOfAvgConsumption = 0;

	for (const int& i : indications) {
		if (i == wrongValue)
			continue;
		lengthOfAvgConsumption += 1;
		tempAvgConsumption += i;
	}

	averageConsumption = tempAvgConsumption / lengthOfAvgConsumption;
	tempAvgConsumption = 0;
}

//������������ � ����������

//YearReadings::YearReadings(float tariff) {
//	this->tariff = tariff;
//	payments.assign(yearLen, 0);
//	indications.assign(yearLen, wrongValue);
//	if (tariff == 0)
//		throw "����� �� ����� ���� ����� 0";
//}

YearReadings::YearReadings(int year) {
	this->year = year;
	payments.assign(yearLen, 0);
	indications.assign(yearLen, wrongValue);
}
