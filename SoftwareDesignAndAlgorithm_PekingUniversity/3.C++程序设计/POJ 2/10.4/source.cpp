#include <iostream>
using namespace std;
// 在此处补充你的代码
class CType {
public:
	int value;
	CType():value(0) {};
	void setvalue(int n) {
		value = n;
	}
	//必须使用static变量
	CType &operator++(int) {
		static CType tmp = CType();
		tmp.value = value;
		value *= value;
		return tmp;
	}

	friend ostream & operator<<(ostream &o, CType &cType) {
		o<<cType.value;
		return o;
	}

};
int main(int argc, char* argv[]) {
	CType obj;
	int n;
	cin>>n;
	while ( n ) {
		obj.setvalue(n);
		cout<<obj++<<" "<<obj<<endl;
		cin>>n;
	}
	return 0;
}