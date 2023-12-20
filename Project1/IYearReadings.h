#pragma once

class IYearReadings {
public:
	virtual void addAdditionallyPayment(int& month, int& additionallyPayment) = 0;
	virtual void getInfoByMonth(int& month, bool getPaymentsInfo) const = 0;
};