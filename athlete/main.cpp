#include <iostream>
#include <string>
#include <limits>
#define For(i, a, b) for(int i = a; i < b; i++)
using namespace std;

class SPORTS_PERSON{
private:
	string mName;
	__int16 mAge;
	string mCompetion;
	float mWeight;
	float mHight;
public:
	SPORTS_PERSON();
	SPORTS_PERSON(string, __int16, string, float, float);
	~SPORTS_PERSON();
	friend istream &operator >> (istream&, SPORTS_PERSON&);
	friend ostream &operator << (ostream&, const SPORTS_PERSON&);
	bool operator > (const SPORTS_PERSON&);
};
// constructor without par
SPORTS_PERSON :: SPORTS_PERSON(){
	mName = mCompetion = "";
	mAge = 0;
	mWeight = mHight = 0.0;
}
// constructor with 5 par
SPORTS_PERSON :: SPORTS_PERSON(string mName, __int16 mAge, string mCompetion, float mHight, float mWeight){
	this -> mName = mName;
	this -> mAge = mAge;
	this -> mCompetion = mCompetion;
	this -> mHight = mHight;
	this -> mWeight = mWeight;
}
// destructor
SPORTS_PERSON :: ~SPORTS_PERSON(){
	mName = mCompetion = "";
	mAge = 0;
	mWeight = mHight = 0.0;
}
//delete cache
void delete_cache(){
	cin.clear();
	cin.ignore(numeric_limits<streamsize> :: max(), '\n');
}
// cin__overloading
istream &operator >> (istream& is, SPORTS_PERSON& pers){
	cout << "\nInput name of sportsperson: ";
	delete_cache();
	getline(is, pers.mName);
	cout << "Name: " << pers.mName << endl;

	cout << "\nInput age of sportsperson: ";
	is >> pers.mAge;
	cout << "Age: " << pers.mAge << endl;

	cout << "\nInput name of competion: ";
	delete_cache();
	getline(is, pers.mCompetion);
	cout << "Competion: " << pers.mCompetion << endl;

	cout << "\nInput weight: ";
	is >> pers.mWeight;
	cout << "Weight: " << pers.mWeight << endl;

	cout << "\nInput hight: ";
	is >> pers.mHight;
	cout << "Hight: " << pers.mHight << endl;

	return is;
}
// cout__overloading
ostream &operator << (ostream& os, const SPORTS_PERSON& pers){
	os << pers.mName << "\t" << pers.mAge << "\t" << pers.mWeight << "\t" << pers.mHight << "\t" << pers.mCompetion << endl;
	return os;
}
//compare
bool SPORTS_PERSON :: operator > (const SPORTS_PERSON& pers){
	(this -> mHight > pers.mHight) ? true : ( (this -> mHight == pers.mHight) ? ( (this -> mWeight > pers.mWeight) ? true : false) : false );
}
void swap_person(SPORTS_PERSON& pers1, SPORTS_PERSON& pers2){
	SPORTS_PERSON tmp;
	tmp = pers1;
	pers1 = pers2;
	pers2 = tmp;
}
void bubble_sort(SPORTS_PERSON *Pers, __int16 athlete_number){
	For(i, 0, athlete_number)
		For(j, i+1, athlete_number)
			if(Pers[i] > Pers[j])
				swap_person(Pers[i], Pers[j]);
}
int main()
{
	__int16 athlete_number;

	cout << "\n\t\tATHLETE MANAGEMENT PROGRAM" << endl;
	cout << "\t\t--------------------------" << endl;
	cout << "\n\tInput number of athlete(>0): ";
	cin >> athlete_number;
	while(!cin || athlete_number < 0){
		cout << "\n\t\tERROR. Please enter the valid number.\n";
		delete_cache();
		cin >> athlete_number;
	}

    SPORTS_PERSON *Pers = new SPORTS_PERSON[athlete_number];
    //enter and display data
    For(i, 0, athlete_number) cin >> Pers[i];
    For(i, 0, athlete_number) cout << Pers[i];
    //sort the sport
    bubble_sort(Pers, athlete_number);
    //display after sorting
    For(i, 0, athlete_number) cout << Pers[i];

    return 0;
}
