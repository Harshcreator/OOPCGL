#include <iostream>
using namespace std;

class complex 
{
int x,y; 
public :

	complex()
	{
		x=0; y=0;
	}

	friend void operator >>(complex &u, complex &v)
	{
	cout << "Enter r_1";
	cin >> u.x;
	cout << "Enter i_1";
	cin >> u.y;
	cout << "Enter r_2";
	cin >> v.x;
	cout << "Enter i_2";
	cin >> v.y;
	}

	friend void operator <<(complex &u, complex &v)
	{
	cout << "F_C :" << u.x << "+" << "i" << u.y << endl ;
	cout << "S_C :" << v.x << "+" << "i" << v.y << endl ;
	}

	friend void operator +(complex &u, complex &v)
	{
	complex add;
	add.x = u.x + v.x;
	add.y = u.y + v.y;
	if(add.y>0)
		cout << add.x << "+" << add.y << "i" << endl;
	else
		cout << add.x << (-1)*add.y << "i" << endl;
	}
	
	friend void operator -(complex &u, complex &v)
	{
	complex sub;
	sub.x = u.x - v.x;
	sub.y = u.y - v.y;
	if(sub.y>0)
		cout << sub.x << "+" << sub.y << "i" << endl;
	else
		cout << sub.x << (-1)*sub.y << "-i" << endl;
	}
	
	friend void operator *(complex &u, complex &v)
	{
	complex mul;
	mul.x = (u.x * v.x)-(u.y * v.y);
	mul.y = (u.y * v.y)+(v.x*u.y);
	if(mul.y>0)
		cout << mul.x << "+" << mul.y << "i" << endl;
	else
		cout << mul.x << (-1)*mul.y << "-i" << endl;
	}
};

int main()
{
	char ch;
	char des
;
	complex s1,s2;
	operator >>(s1,s2);
	operator <<(s1,s2);
	do
	{
		cout<<"Choose action";
		cout<<"(+)addition"<<endl;
		cout<<"(-)subtraction"<<endl;
		cout<<"(*)Multiplication"<<endl;
		cin>>ch;
		switch(ch)
		{
			case '+':
			s1+s2;
			break;
			case '-':
			s1-s2;
			break;
			case '*':
			s1*s2;
			break;
			default:
 			cout<<"Invalid Operation"<<endl;
		}
		cout<<"Do you Wis To Perform Operation Again ? => (Y/N)";
		cin>>des;
	}while(des=='y'||des=='Y');
}
	















		
