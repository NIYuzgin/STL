// AssociativeContainers

#include<iostream>
#include<map>
//#include<array>
//#include<vector>
//#include<deque>

using namespace std;

using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimiter "\n------------------------------\n"




#define STL_MAP




void main() {
	setlocale(LC_ALL, "");

#ifdef STL_MAP
	std::map<int, std::string>week = {

		std::pair<int, std::string>(0, "Воскресенье"),
		std::pair<int, std::string>(1, "Понедельник"),
		std::pair<int, std::string>(2, "Вторник"),
		std::pair<int, std::string>(3, "Среда"),
		{4, "Четверг"},
		{5, "Пятница"},
		{6, "Суббота"},
		{4, "Воскресенье"},


	};
		for(std::map<int, std::string>::iterator it = week.begin(); it !=week.end(); ++it){
			cout << it->first << tab << it->second<< endl;
	}
		cout << delimiter << endl;






#endif STL_MAP



}