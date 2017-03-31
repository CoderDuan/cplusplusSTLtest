#include <iostream>
#include <set>
#include <string>

using namespace std;

struct Info {
	string name;
	int id;
	Info(string n, int i) {
		name = n;
		id = i;
	}
	friend ostream & operator << (ostream &os, const Info &i) {
		os << "name:" << i.name << ", id:" << i.id;
		return os;
	}
	friend bool operator < (Info i1, Info i2) {
		if (i1.id < i2.id) return true;
		if (i1.id > i2.id) return false;
		if (i1.id == i2.id) return (i1.name < i2.name);
		//return (i1.name < i2.name);
	}
	friend bool operator > (Info i1, Info i2) {
		return (i1.name > i2.name);
	}
	friend bool operator == (Info i1, Info i2) {
		return (i1.name == i2.name);
		//return (i1.id == i2.id);
	}
};

int main() {
	int input;
	set<Info> s;
	Info i1("duan", 1);
	Info i2("coder", 2);
	s.insert(i1);
	s.insert(i2);
	s.insert(i2);
	s.insert(i2);

	for (auto i : s) {
		cout<<i<<endl;
	}
	Info i3("coder", 1);
	set<Info>::iterator itr = s.find(i3);
	if (itr != s.end())
		cout<<*itr<<endl;
	cout<<(i1 > i2)<<endl;
}