#ifndef RUNTIME_H
#define RUNTIME_H
#include <string>

using std::string;

class RuntimeError {
private:
	string errorMsg;
public:
	RuntimeError(const string& err) {
		errorMsg = err;
	}

	string getMessage() const {
		return errorMsg;
	}

};

class StackFull : public RuntimeError {
public:
	StackFull(const string &err) : RuntimeError(err) {}
};


class StackEmpty : public RuntimeError {
public:
	StackEmpty(const string &err) : RuntimeError(err) {}
};

#endif
