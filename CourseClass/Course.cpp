#include"Course.h"
#include <iostream>
#include <conio.h>
using namespace std;


Student::Student()
{
	score = 0;
}

Student::Student(string no,string n,int s)
{
	studentNo = no;
	name = n;
	score = s;
}

CourseManage::CourseManage()
{
	courseName = "C++程序设计";
	maxStudentSize = 200;
	menuOption();
}

void CourseManage::viewNameList()
{
	system("cls");
	cout<<"课程："<<courseName<<endl;
	if(!students.empty())
	{
		cout<<"姓名\t学号\t\t成绩"<<endl;
		for (vector<Student>::iterator it = students.begin();it!=students.end();it++)
		{
			cout<<it->name<<'\t'<<it->studentNo<<'\t'<<it->score<<endl;
		}
	}
	else
	{
		cout<<"暂无学生信息，请先录入"<<endl;
	}
	cout<<"按任意键返回"<<endl;
	getch();
}

void CourseManage::menuOption()
{
	while(1)
	{
		system("cls");
		int option  = 0;
		cout<<"欢迎使用管理系统\n请选择功能：\n1。查看选课名单\n2。选课\n3。退选\n4。输入成绩\n5。退出"<<endl;
		cin>>option;
		if(!cin)
		{
			cout<<"请输入数字"<<endl;
			cin.clear();
			cin.sync();
		}
		switch(option){
			case 1:viewNameList();break;
			case 2:choose();break;
			case 3:unChoose();break;
			case 4:scoreWrite();break;
			case 5:exit(0);break;
                        default:cout<<"错误的选项，请重新输入"<<endl;break;
		}
	}
}

void CourseManage::choose()
{
	system("cls");
	Student stu;
	cout<<"输入学生姓名："<<endl;
	cin>>stu.name;
	cout<<"输入学号："<<endl;
	cin>>stu.studentNo;
	bool status = find(stu.studentNo);
	if(status)
	{
		students.push_back(stu);
		cout<<"学生："<<stu.name<<"成功选择课程!"<<endl;
	}
	else
	{
		cout<<"学生："<<stu.name<<"已选择该课程!"<<endl;
	}
	cout<<"按任意键返回"<<endl;
	getch();
}

void CourseManage::unChoose()
{
	system("cls");
	string exitNo;
	bool status = true;
	cout<<"输入需要退选学生学号:"<<endl;
	cin>>exitNo;
	MyIter iter = findIt(exitNo);
	if(iter!=students.end())
	{
		cout<<"学生："<<iter->name<<"成功退选!"<<endl;
		students.erase(iter);
	}
	else
	{
		cout<<"未找到该学号对应学生！"<<endl;
	}
/*	for (vector<Student>::iterator it = students.begin();it!=students.end();it++)
	{
		if(it->studentNo==exitNo)
		{
			cout<<"学生："<<it->name<<"成功退选!"<<endl;
			students.erase(it);
			status = false;
			break;
		}
	}
	if (status)
	{
		cout<<"未找到该学号对应学生！"<<endl;
	}
*/
	cout<<"按任意键返回"<<endl;
	getch();
}

void CourseManage::scoreWrite()
{
	system("cls");
	string stuNo;
	cout<<"输入需要修改成绩的学生学号："<<endl;
	cin>>stuNo;
	MyIter iter = findIt(stuNo);
	if(iter!=students.end())
	{
		int score;
		cout<<"输入成绩：";
		cin>>score;
		cout<<"学生："<<iter->name<<"，原成绩："<<iter->score<<"，新成绩："<<score<<endl;
		iter->score = score;
	}
	else
	{
		cout<<"未找到该学号对应学生"<<endl;
	}
	cout<<"按任意键返回"<<endl;
	getch();
}

bool CourseManage::find(string no)
{
	for (MyIter it = students.begin();it!=students.end();it++)
		if(it->studentNo==no)
			return false;
	return true;
}

MyIter CourseManage::findIt(string no)
{
	MyIter it = students.begin();
	while(it!=students.end())
	{
		if(it->studentNo==no)
			break;
		++it;
	}
	return it;
}


