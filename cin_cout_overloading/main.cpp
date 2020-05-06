#include <iostream>

using namespace std;
class Phanso{
private:
	__int16 tuso;
	__int16 mauso;
public:
	Phanso(){
		this -> tuso = 0;
		this -> mauso = 0;
	}
	Phanso(__int16 tuso, __int16 mauso){
		this -> tuso = tuso;
		this -> mauso = mauso;
	}
	friend istream& operator >> (istream&, Phanso&);
	friend ostream& operator << (ostream&, const Phanso&);
};

istream& operator >> (istream& is, Phanso& ps){
	is >> ps.tuso >> ps.mauso;
	return is;
}

ostream& operator << (ostream& os, const Phanso& ps){
	os << ps.tuso << "/" << ps.mauso;
}
int main()
{
	Phanso phanso;
	cin >> phanso;
	cout << phanso;
    return 0;
}
