//Anthony Franklin afranklin18@cnm.edu
//PROGRAM TO DEMONSTRATE CIRCULAR QUEUE USING UNIQUE_PTR
//04/17/2022
//CirQueue.h

#ifndef CIR_QUEUE_H
#define CIR_QUEUE_H

#include "FranklinPersonGen/PersonGen.h"
#include <memory>
#include <fstream>
#include <string>

const int SIZE{ 10 };
class CirQueue
{
private:
	unique_ptr<Person> pArray[SIZE];
	int count{ 0 };
	int first{ 0 };
	int last{ 0 };
	ofstream logger;
public:
	CirQueue();
	~CirQueue() { cout << "CirQueue now out of scope.\n"; logger << "CirQueue now out of scope.\n";
	}
	bool Empty();
	bool Full();
	void Show();
	string ShowString();
	bool Push(unique_ptr<Person> p);
	bool Pop();
	string Front();
	string Rear();
	int Size();

};


#endif // !CIR_QUEUE_H



