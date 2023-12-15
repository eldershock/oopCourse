#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class YearReadings {

static const int yearLen = 12;
static const int wrongValue = -1;

protected:
	//����
	int year = 0;
	vector<int> indications;
	vector<int> payments;
	int finalSum = 0;
	float averageConsumption = 0;
	float tariff = 0;

	void checkYear();

public:
	//������ ��������
	void paymentInputAndIndicationCount(int& month, int& payment);
	void finalSumCount();
	void averageConsumptionCount();

	//������������ � ����������
	YearReadings() = default;
	YearReadings(int year);
	/*YearReadings(float tariff);*/

	~YearReadings() = default;

	//���������� ����������
	int operator[](int month);

	//����� ��������� ����
	void setTariff(float& tariff);

	//����� ������ ���������� �� ��� ��������� ������
	void indicationsOut();
	void getInfoByMonth(int& month, bool getPaymentsInfo=false);
	void indicationsOutOnly(ostream& stream);

	//���������
	int getCurrentYear() const;
	int getFinalSumOut() const;
	float getAverageConsumption() const;
};