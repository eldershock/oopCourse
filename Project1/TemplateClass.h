#pragma once
#include "YearReadings.h"
#include <map>
template<typename PAYMENTS_TYPE = int, const int YEAR_START = 3>
class TemplateClass : public YearReadings {
private:
	map<int, vector<PAYMENTS_TYPE>> accounting;
	map<int, string> monthes;
public:
	TemplateClass() {
		monthes = {
			{1, "������"},
			{2, "�������"},
			{3, "����"},
			{4, "������"},
			{5, "���"},
			{6, "����"},
			{7, "����"},
			{8, "������"},
			{9, "��������"},
			{10, "�������"},
			{11, "������"},
			{12, "�������"}
		};
	}

	void addNewYearAccounting(int& year) {
		accounting[year].resize(12);
		/*std::cout << "It's worked " << accounting[year].size() << std::endl;*/
	}

	void getList(int& year) {
		int index = 0;
		for (const auto& payment : accounting[year]) {
			if (payment == 0)
				continue;
			std::cout << monthes[YEAR_START + index] << ' ' << payment << std::endl;
			++index;
		}
	}

	void addPaymentInAccounting(int& year, int& month, PAYMENTS_TYPE& payment) {
		accounting[year][month] = payment;
		/*std::cout << "�������� xD: " << accounting[year][month] << std::endl;*/
	}
};