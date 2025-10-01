// SequenceContainers

#include<iostream>
#include<array>

//using namespace std;

using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
//#define delimiter "\n------------------------------\n"

#define STL_ARRAY

void main() {
	setlocale(LC_ALL, "");
	
#ifdef STL_ARRAY
	//throw std::out_of_range("Переполнение!");
	const int n = 5;
	std::array<int, n> arr;
	for (int i = 0; i < arr.size(); i++) {
		arr[i] = rand() % 100;
	}
	for (int i = 0; i < arr.size(); i++) {
		cout << arr.at(i) << tab;
	}
	cout << endl;
	
	try {
		for (int i = 0; i < arr.size() * 2; i++) {
			cout << arr.at(i) << tab;
			//cout << arr[i] << tab;
			// out of range exception
			// catch
			//throw		
			// CPU - аппаратное исключение
			// OS - системное исключение
			// Program - прикладное исключение
		}
		cout << endl;
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << endl;
	}
	
	/*
	catch (...) {
		std::cout << "Error: Something went wrong" << endl;
	}
	*/

	for (int i : arr) {
		cout << i << tab;
	}
	cout << endl;

#endif STL_ARRAY

}


