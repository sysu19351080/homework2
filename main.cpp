#include<iostream>
#include<string.h>
using namespace std;
//class类
class identify {
public:
	identify(char *name,long long int number = 370682194901011234);//构造（含类内初始值）
	identify(const identify&i);//复制
	~identify() { cout << "distructor1" << endl; };//析构
	//提供存取函数
	void setnumber(long long int _number = 370682194901011234) { number_ = _number; };
	void setname(char *_name) { if (_name == NULL)return; strcpy_s(name_, _name); };
	long long int getnumber(){ return number_; };
	char getname() { return name_[32]; };
private:
	long long int number_ ;
	char name_[32];	
};
identify::identify( char *name,long long int number) :number_(number)
{ strcpy_s(name_, name); cout << "constructor1" << endl; }//初始化
identify::identify(const identify&i) : number_(i.number_) 
{ strcpy_s(name_, i.name_); cout << "copy constructor1" << endl; };
//student类
class student {
public:
	student(identify id, string school="SYSU") :id_(id), school_(school){ cout << "contructor2" << endl; };//构造（含类内初始值）并初始化
	student(const student&s):id_(s.id_),school_(s.school_){ cout << "copy constructor2" << endl; };//复制并初始化
	~student() { cout << "distructor2" << endl; };//析构
	//提供存取函数
	void setschool(string _school="SYSU") { school_ = _school; };
	void setid(identify _id) { id_ = _id; };
	string getschool() { return school_; };
	identify getid() { return id_; };
	//编写makestudent函数
private:
	identify id_;
	string school_;
};
student makestudent(long long int number, char* name, string school)
{ char a[32] = "Noname"; char* b = a; identify m(b); student c(b); return c; }//定义函数student makestudent(......)
int main() {
	char a[32] = "Noname";
	char *name = a;
	//提供identify类所有函数使用例子
	identify x(name);
	x.setnumber();
	x.setname(name);
	x.getnumber();
	x.getname();
	//提供student类所有函数使用例子
	student y(x);
	y.setschool();
	y.setid(x);
	y.getschool();
	y.getid();
	//调用函数student makestudent（......)
	makestudent(x.getname(), name, y.getschool());
	return 0;
}