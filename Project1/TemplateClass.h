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
			{1, "€нварь"},
			{2, "ферваль"},
			{3, "март"},
			{4, "апрель"},
			{5, "май"},
			{6, "июнь"},
			{7, "июль"},
			{8, "август"},
			{9, "сент€брь"},
			{10, "окт€брь"},
			{11, "но€брь"},
			{12, "декабрь"}
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
		/*std::cout << "–аботает xD: " << accounting[year][month] << std::endl;*/
	}
};