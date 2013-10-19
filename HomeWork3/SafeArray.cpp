

#include "SafeArray.h"

SafeArray::SafeArray(int size)
{
	maxSize=size;
	data= new int[maxSize];
}

void SafeArray::setArray(int data,int pos)
{
	if(pos>=0&&pos<maxSize)
	{
		this->data[pos]=data;
		datapos.push_back(pos);
	}
	else 
	{
		printErr(pos);
		return;
	}
}

void SafeArray::getArray(int pos)
{
	if(pos>=maxSize) 
	{
		printErr(pos);
		return;
	}
	vector<int>::iterator it =datapos.begin();
	while(it!=datapos.end())
	{
		if(pos==*it)
		{		
			cout<<"Data in "<<pos<<" is:"<<data[pos]<<endl;
			return;
		}
		it++;
	}
	cout<<"The position "<<pos<<" have no data"<<endl;
}

void SafeArray::printArray()
{
	vector<int>::iterator it =datapos.begin();
	while(it!=datapos.end())
	{
		cout<<"Position:"<<*it<<" \tData:"<<data[*it]<<endl;
		it++;
	}
}

int main(int argc,char **argv)
{
	SafeArray safe(100);
	int size=60;
	for (int i=0;i<size;i++)
	{
		safe.setArray(i,i+3);
	}
	safe.setArray(20,231);
	safe.getArray(51);
	safe.getArray(73);
	safe.getArray(109);
	return 0;
}
