#include <iostream>
#include <string.h>

using namespace std;

class publication
{
protected :
	string title;
	float price;
public :
	void set_zero()
	{
	title = "000";
	price = 0.0;
	}
	
	void get_data()
	{
	cout<<"Enter name:";
	cin>>title;
	cout<<"Enter the price";
	cin>>price;
	}

	void put_data()
	{
	cout<<"Name:"<<title;
	cout<<"Price:"<<price;
	}
};

class book : public publication
{
int pages;
public:
	void set_zero()
	{
	pages = 0;
	publication::set_zero();
	}

	void get_data()
	{
	publication::get_data();
	cout<<"Enter number of pages:";
	cin>>pages;

	try
	{
	if(price<0)
	{
	throw(0);
	}
	if(pages<0)
	{
	throw(0.0);
	}
	}
	
	catch(double x)
	{
	cout<<"Exception page count cannot be negative:";
	set_zero();
	}
	catch(int x)
	{
	cout<<"Exception price cannot be negative:";
	set_zero();
	}
	}
	
	void put_data()
	{
	publication::put_data();
	cout<<"Number of pages:" << pages;
	}
};

class tape : public publication
{
float play_time;
public:
	void set_zero()
	{
	play_time = 0.0;
	publication::set_zero();
	}

	void get_data()
	{
	publication::get_data();
	cout<<"Enter play time:";
	cin>>play_time;

	try
	{
	if(price<0)
	{
	throw(0);
	}
	if(play_time<0)
	{
	throw(0.0);
	}
	}
	
	catch(double x)
	{
	cout<<"Exception play time cannot be negative:";
	set_zero();
	}
	catch(int x)
	{
	cout<<"Exception price cannot be negative:";
	set_zero();
	}
	}
	
	void put_data()
	{
	publication::put_data();
	cout<<"Play time:" << play_time;
	}
};

int main()
{
tape t; book b;
cout<<"Enter data of tape:";
t.get_data();
t.put_data();
cout<<"Enter data of book:";
b.get_data();
b.put_data();
return 0;
}















