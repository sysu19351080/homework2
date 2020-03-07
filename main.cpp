#include<iostream>
#include<string.h>
using namespace std;
//class��
class identify {
public:
	identify(char *name,long long int number = 370682194901011234);//���죨�����ڳ�ʼֵ��
	identify(const identify&i);//����
	~identify() { cout << "distructor1" << endl; };//����
	//�ṩ��ȡ����
	void setnumber(long long int _number = 370682194901011234) { number_ = _number; };
	void setname(char *_name) { if (_name == NULL)return; strcpy_s(name_, _name); };
	long long int getnumber(){ return number_; };
	char getname() { return name_[32]; };
private:
	long long int number_ ;
	char name_[32];	
};
identify::identify( char *name,long long int number) :number_(number)
{ strcpy_s(name_, name); cout << "constructor1" << endl; }//��ʼ��
identify::identify(const identify&i) : number_(i.number_) 
{ strcpy_s(name_, i.name_); cout << "copy constructor1" << endl; };
//student��
class student {
public:
	student(identify id, string school="SYSU") :id_(id), school_(school){ cout << "contructor2" << endl; };//���죨�����ڳ�ʼֵ������ʼ��
	student(const student&s):id_(s.id_),school_(s.school_){ cout << "copy constructor2" << endl; };//���Ʋ���ʼ��
	~student() { cout << "distructor2" << endl; };//����
	//�ṩ��ȡ����
	void setschool(string _school="SYSU") { school_ = _school; };
	void setid(identify _id) { id_ = _id; };
	string getschool() { return school_; };
	identify getid() { return id_; };
	//��дmakestudent����
private:
	identify id_;
	string school_;
};
student makestudent(long long int number, char* name, string school)
{ char a[32] = "Noname"; char* b = a; identify m(b); student c(b); return c; }//���庯��student makestudent(......)
int main() {
	char a[32] = "Noname";
	char *name = a;
	//�ṩidentify�����к���ʹ������
	identify x(name);
	x.setnumber();
	x.setname(name);
	x.getnumber();
	x.getname();
	//�ṩstudent�����к���ʹ������
	student y(x);
	y.setschool();
	y.setid(x);
	y.getschool();
	y.getid();
	//���ú���student makestudent��......)
	makestudent(x.getname(), name, y.getschool());
	return 0;
}