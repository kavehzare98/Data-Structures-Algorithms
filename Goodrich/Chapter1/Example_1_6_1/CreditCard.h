#ifndef CREDIT_CARD_H
#define CREDIT_CARD_H

#include <iostream>
#include <string>
using std::string;

class CreditCard {
public:
	CreditCard(const string& no, const string& nm, int lim, double bal=0);

	// In-line functions
	string getNumber() const {
		return number;
	}
	string getName() const {
		return name;
	}
	int getLimit() const {
		return limit;
	}
	double getBalance() const {
		return balance;
	}

	bool chargeIt(double price);
	void makePayment(double payment);

private:
	string number;
	string name;
	int limit;
	double balance;
};

std::ostream& operator<<(std::ostream& out, const CreditCard& c);

#endif
