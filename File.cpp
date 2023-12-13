#include<iostream>
#include<fstream>
using namespace std;
int main() {
    char Give_info[200];
    ofstream Out_file;
    Out_file.open("Info.bat", ios::out);
    cout << "Enter your information: ";
    fgets(Give_info,200, stdin);
    Out_file<<Give_info;
    Out_file.close();

    char Get_info[200];
    ifstream In_file;
    In_file.open("Info.bat", ios::in);
    In_file.getline(Get_info,200);
    cout<<"Your Information is :\n";
    cout<<Get_info;
    In_file.close();
    return 0;
}