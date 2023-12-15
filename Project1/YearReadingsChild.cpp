
#include "YearReadingsChild.h"

void YearReadingsChild::addAdditionallyPayment(int& month, int& additionallyPayment) {
	this->additionallyPayment[month - 1] = additionallyPayment;
	payments[month - 1] += this->additionallyPayment[month - 1];
	indications[month - 1] = payments[month - 1] * tariff;
}

void YearReadingsChild::getInfoByMonth(int& month, bool getPaymentsInfo) const {
	if (getPaymentsInfo) {
		cout << indications[month - 1] << ' ' << payments[month - 1] << ' ' << this->additionallyPayment[month - 1] << endl;
	}
	else {
		cout << indications[month - 1] << ' ' << payments[month - 1] << endl;
	}
}

YearReadingsChild::~YearReadingsChild() {
	delete[] additionallyPayment;
}