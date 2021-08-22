#include <iostream>
#include <string>

using namespace std;

string str[22];
string commend;
int N;
string MyCopy();	
string MyAdd();	
int MyFind();	
int MyRfind();	
void MyInsert();	
void MyReset();	
struct GETS
{
	GETS(string &s)	
	{
		cin >> s;
		if (s=="copy")
			s = MyCopy();
		else if (s=="add")
			s = MyAdd();
	}
};

struct GETINT
{
	string Commend;
	GETINT(int &n)	
	{
		cin >> Commend;
		if (Commend=="find")
			n = MyFind();
		else if (Commend=="rfind")
			n = MyRfind();
		else
			n = atoi(Commend.c_str());
	}
};

struct GETSTRING
{
	GETSTRING(int &m, string &s)	
	{
		GETS Gets(s);
		int i = 0;
		for (m=0; i<s.length(); i++)
			if ((s.at(i)>='0')&&(s.at(i)<='9'))
				m = m * 10 + s.at(i)-'0';
			else
				break;
		if ((i!=s.length())||(m>99999))
			m = -1;
	}
};

int main()
{
	cin >> N;
	for (int i=0; i<N; i++)
		cin >> str[i+1];
	while (cin >> commend)
	{
		if (commend=="over")
			break;
		switch(commend.at(1))
		{
		case 'n':	MyInsert(); break;
		case 'e':	MyReset(); break;
		case 'r':	if (commend=="print")
					{
						int n;
						cin >> n;
						cout << str[n] << endl;
					}
					else 
					{
						for (int j=1; j<=N; j++)
							cout << str[j] << endl;
					}
					break;
		}
	}
	return 0;
}

string MyCopy()
{
	int n, x, l;
	GETINT getintn(n);
	GETINT getintx(x);
	GETINT getintl(l);
	return (str[n].substr(x,l));
}

string MyAdd()	
{
	string s1,s2;
	int m=-1, n=-1;
	GETSTRING getstringms1(m,s1);
	GETSTRING getstringns2(n,s2);
	if ((m==-1)||(n==-1))
		return (s1+s2);
	else
	{
		m += n;
		char chars[8];
		_itoa(m,chars,10);
		return string(chars);
	}
}


int MyFind()	
{
	string s;
	int n,value;
	cin >> s;
	GETINT getintn(n);
	value = str[n].find(s);
	if (value==string::npos)
		value = str[n].length();
	return value;
}

int MyRfind()	
{
	string s;
	int n,value;
	cin >> s;
	GETINT getintn(n);
	value = str[n].rfind(s);
	if (value==string::npos)
		value = str[n].length();
	return value;
}

void MyInsert()	
{
	string s;
	int n,x;
	GETS Gets(s);
	GETINT getintn(n);
	GETINT getintx(x);
	str[n].insert(x,s);
}

void MyReset()	
{
	string s;
	int n;
	GETS Gets(s);
	GETINT getintn(n);
	str[n].assign(s);
}