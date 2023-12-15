#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class YearReadings {

static const int yearLen = 12;
static const int wrongValue = -1;

protected:
	//Поля
	int year = 0;
	vector<int> indications;
	vector<int> payments;
	int finalSum = 0;
	float averageConsumption = 0;
	float tariff = 0;

	void checkYear();

public:
	//Методы рассчёта
	void paymentInputAndIndicationCount(int& month, int& payment);
	void finalSumCount();
	void averageConsumptionCount();

	//Конструкторы и деструктор
	YearReadings() = default;
	YearReadings(int year);
	/*YearReadings(float tariff);*/

	~YearReadings() = default;

	//Перегрузка операторов
	int operator[](int month);

	//Метод установки года
	void setTariff(float& tariff);

	//Метод вывода информации за все доступные месяцы
	void indicationsOut();
	void getInfoByMonth(int& month, bool getPaymentsInfo=false);
	void indicationsOutOnly(ostream& stream);

	//Селекторы
	int getCurrentYear() const;
	int getFinalSumOut() const;
	float getAverageConsumption() const;
};