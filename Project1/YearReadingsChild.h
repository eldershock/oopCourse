#pragma once
#include "YearReadings.h"

class YearReadingsChild : public YearReadings {

static const int yearLen = 12;
private:
	int* additionallyPayment = new int[yearLen];
public:
	void addAdditionallyPayment(int& month, int& additionallyPayment);
	void getInfoByMonth (int& month, bool getPaymentsInfo) const;
	YearReadingsChild(int year) : YearReadings(year) {}
	~YearReadingsChild();;
};