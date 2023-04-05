#pragma once

#include <string>
#include <iostream>
using namespace std;

struct Cell
{
	Cell *next = NULL;
	virtual ~Cell() {};
	virtual int getPrio() const = 0;
	virtual const string& getName() const = 0;
	virtual const string& getAnam() const = 0;
	virtual Cell* clone() = 0;
	virtual void display() = 0;
};

struct ListEl : public Cell
{
	int priority;
	string name;
	const string temp;

	ListEl(int priority, string name): priority(priority), name(name), temp("") {
	}

	int getPrio() const {
		return priority;
	}

	const string& getName() const {
		return name;
	}

	const string& getAnam() const {
		return temp;
	}

	void display() {
		cout << name << " (" << priority << ")" << endl;
	}

	virtual Cell* clone() {
		return new ListEl(*this);
	}
};

struct ExtListEl : public ListEl
{
	string anam;

	ExtListEl(int priority, string name, string anam): ListEl(priority, name), anam(anam) {
	}

	const string& getAnam() const {
		return anam;
	}

	Cell* clone() {
		return new ExtListEl(*this);
	}

	void display() {
		cout << name << " (" << priority << ")" << ", " << anam << endl;
	}
};