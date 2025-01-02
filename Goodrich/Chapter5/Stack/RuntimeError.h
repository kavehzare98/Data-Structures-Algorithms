#ifndef RUNTIME_H
#define RUNTIME_H

class RuntimeError {
private:
	string errorMsg;
public:
	RuntimeException(const string& err) {
		errorMsg = err;
	}

	string getMessage() const {
		return errorMsg;
	}

};

class StackFull : protected RuntimeError {
public:
	StackFull(const string &err) : RuntimeException(err) {}
};


class StackEmpty : protected RuntimeError {
public:
	StackEmpty(const string &err) : RuntimeException(err) {}
};

#endif
