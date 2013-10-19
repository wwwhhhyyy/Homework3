#ifndef SAFEARRAY_H
#define SAFEARRAY_H
#include <iostream>
#include <vector>
using namespace std;

class SafeArray
{
public:
	SafeArray(int size);
	void setArray(int data,int pos);
	inline void printErr(int pos){cout<<"Error:Index "<<pos<<" out of bounds"<<endl;}
	void getArray(int pos);
	void printArray();
private:
	int maxSize;
	int *data;
	vector<int> datapos;
};

#endif