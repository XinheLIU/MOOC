/*
 描述
 下面的程序输出结果是：
 A::Fun
 A::Do
 A::Fun
 C::Do
 请填空：
 */
 
 #include <iostream>
using namespace std;
class A {
private:
	int nVal;
public:
	void Fun()
	{ cout << "A::Fun" << endl; }
	virtual void Do()
	{ cout << "A::Do" << endl; }
};
class B:public A {
public:
	virtual void Do()
	{ cout << "B::Do" << endl; }
};
class C:public B {
public:
	void Do( )
	{ cout << "C::Do" << endl; }
	void Fun()
	{ cout << "C::Fun" << endl; }
};
void Call( A * p// 在此处补充你的代码
        )  {
		p->Fun();  p->Do();
}
int main()  {
	Call( new A() );
	Call( new C() );
	return 0;
}