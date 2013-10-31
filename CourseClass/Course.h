#ifndef COURSE_H
#define COURSE_H
#include <string>
#include <vector>
using namespace std;


class Student								//学生信息，包含姓名，学号，成绩
{
public:
	Student();
	Student(string no,string n,int s);
	string studentNo;
	string name;
	int score;
};
typedef vector<Student> MyStus;
typedef MyStus::iterator MyIter;
class CourseManage
{

public:
	CourseManage();
	void viewNameList();							//查看学生名单
	void menuOption();						//主菜单
	void choose();								//选课（输入学生信息）
	void unChoose();							//退选（输入学号）
	void scoreWrite();							//添加成绩（输入学号）
	bool find(string no);									//用于按学号查找学生,返回bool
	MyIter findIt(string no);				//按学号查找学生，返回迭代器
private:
	string courseName;
	int maxStudentSize;
	MyStus students;

};

#endif