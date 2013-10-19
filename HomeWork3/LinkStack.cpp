#include "LinkStack.h"

LinkStack::LinkStack()
{
	linkList=new LinkNode();
	size=0;
}

void LinkStack::push(int datum)
{
	linkPtr=new LinkNode(datum);
	linkPtr->next=linkList->next;
	linkList->next=linkPtr;
	size++;
}

void LinkStack::pop()
{
	if(size==0)
	{
		cout<<"Empty Stack!"<<endl;
		return;
	}
	if(linkPtr!=NULL)
	{
		cout<<"Pop element:"<<linkPtr->data<<endl;
		linkList->next=linkPtr->next;
		delete linkPtr;
		linkPtr=linkList->next;
		size--;
	}
}

int main(int argc,char **argv)
{
	LinkStack stack;
	for (int i=0;i<10;i++)
		stack.push(i);
	stack.pop();
	stack.pop();
	return 0;
}

