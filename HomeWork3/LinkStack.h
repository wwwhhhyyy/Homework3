#ifndef LINKSTACK_H
#define LINKSTACK_H
#include <iostream>
using namespace std;
class LinkNode
{
public:
	LinkNode(){};
	LinkNode(int n){data=n;next=NULL;}
	int data;
	LinkNode *next;
};

class LinkStack
{
public:
	LinkStack();
	void push(int datum);
	void pop();
private:
	LinkNode *linkList,*linkPtr;
	int size;

};

#endif