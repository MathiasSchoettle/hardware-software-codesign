#include "prioQueue.h"
using namespace std;

void PrioQueue::deleteAll() {
	Cell* current = first;
	while (current) {
		Cell* temp = current->next;
		delete current;
		current = temp;
	}
}

void PrioQueue::copyAll(const PrioQueue& other) {
	if (first) return;

	Cell* current = other.first;
	Cell* prev = NULL;

	while (current) {
		Cell* cloned = current->clone();
		cloned->next = prev;
		prev = cloned;
		current = current->next;
	}

	first = prev;
}

Cell* PrioQueue::prior(int prio) {
	Cell* current = first;

	while (current) {
		if (current->getPrio() < prio) break;
	}

	return current;
}

bool PrioQueue::insert(int prio, const string& name) {
	return insert(new ListEl(prio, name));
}

bool PrioQueue::insert(int prio, const string& name, const string& anam) {
	return insert(new ExtListEl(prio, name, anam));
}

bool PrioQueue::insert(Cell* cell) {
	if (!first) {
		first = cell;
		return true;
	}

	Cell* current = first;
	Cell* prev = NULL;

	while (current) {
		if (cell->getPrio() > current->getPrio()) {
			cell->next = current;
			if (prev) 
				prev->next = cell;
			else
				first = cell;
			return true;
		}
		else if(cell->getPrio() == current->getPrio()) {
			delete cell;
			return false;
		}

		prev = current;
		current = current->next;
	}

	prev->next = cell;
	return true;
}

void PrioQueue::deleteMax(string& name) {
	Cell* removed = first;

	if (!removed) {
		name = "";
		return;
	}

	first = removed->next;
	name = removed->getName();
	delete removed;
}

void PrioQueue::display() {
	Cell* current = first;

	while (current) {
		current->display();
		current = current->next;
	}
}