#pragma once

#include "listEl.h"

struct PrioQueue
{
	Cell *first = NULL;

	PrioQueue() {
	}

	~PrioQueue() {
		deleteAll();
	}

	inline PrioQueue& operator=(PrioQueue& rhs) {
		this->deleteAll();
		this->copyAll(rhs);
		return *this;
	}

	void deleteAll();
	void copyAll(const PrioQueue& other);
	Cell* prior(int prio);
	bool insert(int prio, const string& name);
	bool insert(int prio, const string& name, const string& anam);
	void deleteMax(string& name);
	void display();

private:
	bool insert(Cell* cell);
};