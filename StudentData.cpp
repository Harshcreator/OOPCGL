#include <iostream>
using namespace std;
class data1
{
	private:
	string name;
	char bg;
	string address;
	string dob;
	string cldiv;
	string lic;
	static int c;
	int roll;
	long int phone;
	public:
	data1();
	static int getcount();
	void getdata();
	void show();
	data1(data1 *obj);
	data1(int roll,long int phone,string name,string address,string dob,string cldiv, string lic);
	~data1();
};
  
int data1::c=0;
data1::data1(data1 *obj)
{
      cout<<"\nCopy constructor implemented"<<endl;
}
data1::~data1()
{
	  cout<<"Destructor called \n";
}
void data1::getdata()
{
 	 cout<<"Enter roll number \n";
 	 cin>>roll;
 	 cout<<"Enter telephone number \n";
 	 cin>>phone;
 	 cout<<"Enter Name \n";
	 cin>>name;
	 cout<<"Enter address \n";
	 cin>>address;
	 cout<<"Enter D.O.B \n";
	 cin>>dob;
	 cout<<"Enter Class and Division\n";
	 cin>>cldiv;
	 cout<<"Enter license number \n";
	 cin>>lic;
 }

void data1::show()
{
	cout<<"Name :"<<name<<endl;
	cout<<"Roll Number :"<<roll<<endl;
	cout<<"Telephone Number :"<<phone<<endl;
	cout<<"Address :"<<address<<endl;
 	cout<<"Date of birth :"<<dob<<endl;
	cout<<"Class and division: "<<cldiv<<endl;
	cout<<"License number :"<<lic<<endl;
 }
 
data1::data1(int roll,long int phone,string name,string address,string dob,string cldiv,string lic)
{
	cout<<"\nParameterized Constructor"<<endl;
	c++;
	this->roll=roll;
	this->phone=phone;
	this->name=name;
	this->address=address;
	this->dob=dob;
	this->cldiv=cldiv;
	this->lic=lic;
 }

data1::data1()
{
	roll=0;
	phone=0;
	name="Name";
	address="Address";
	dob="DOB";
	cldiv="Class and Division";
	lic="License no.";
	cout<<"Default Constructor"<<endl;
	c++;
 }
  
int data1::getcount()
{
	return c;
}

int main()
{
	int num;
	data1 *d1= new data1();
	d1->show();
	delete d1;
	data1 *d2=new data1(42,9844422211,"JOHN","Ravet","22.12.00","SE B","TSIN99Z");
	d2->show();
	data1 *d3=new data1(d2);
	d3->show();
	delete d2;
	cout<<"\nEnter size of database";
	cin>>num;
	data1 dx[num];
	for(int i=0;i<num;i++)
	{
		dx[i].getdata();
	}
	for(int i=0;i<num;i++)
	{
		dx[i].show();
	}
	cout<<"Number of constructor calls and total number of objects:"<<data1::getcount()<<endl;
	return 0;
}
