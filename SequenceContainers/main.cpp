// SequenceContainers

#include<iostream>
#include<array>
#include<vector>
#include<deque>
#include<list>
#include<forward_list>
#include<iterator>

//using namespace std;

using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimiter "\n------------------------------\n"

template<typename T> void vector_info(const std::vector<T>& vec);
template<typename T> void deque_info(const std::deque<T>& vec);

//#define STL_ARRAY
#define STL_VECTOR
#define STL_DEQUE
//#define STL_LIST
//#define STL_FORWARD_LIST

void main() {
	setlocale(LC_ALL, "");
	
#ifdef STL_ARRAY
	//array - это контейнер, который хранит данные в виде статического массива;
	//throw;
	const int n = 5;
	std::array<int, n > arr;
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

#ifdef STL_VECTOR

	std::vector<int> vec = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34 };
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << tab;
	}
	cout << endl;

	vector_info(vec);
	vec.push_back(55);
	
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
		cout << *it << tab;
	cout << endl;
	
	for (std::vector<int>::reverse_iterator it = vec.rbegin(); it != vec.rend(); ++it)
		cout << *it << tab;
	cout << endl;

	vector_info(vec);
	
	//vec.shrink_to_fit(); // урезает capacity до фактического размера
	vec.reserve(14);
	//vec.push_back(1024);
	
	//vec.resize(18);
	for (int i : vec)cout << i << tab; cout << endl;
	vector_info(vec);
	
	cout << vec.front() << endl;
	cout << vec.back() << endl;
	
	//////////////////////////////////////
	
	int index;
	int value;
	do {
		cout << "Введите индекс добавляемого элемента: "; cin >> index;
		cout << "Введите значение добавляемого элемента: "; cin >> value;
	} while (index > vec.capacity());
	vec.insert(vec.begin() + index, value);
	for (int i : vec)cout << i << tab; cout << endl;

	do {
		cout << "Введите индекс удаляемого элемента: "; cin >> index;

	} while (index > vec.capacity());
	vec.erase(vec.begin() + index);
	for (int i : vec)cout << i << tab; cout << endl;
	
#endif STL_VECTOR

#ifdef STL_DEQUE
	// deque - контейнер, который хранит данные в виде списка Векторов.
	// Это позволяет обеспечить относительно быстрый доступ к элементам, и
	// относительно быстрое удаление элементов.
	// deque - Double-ended queue (двунаправленная очередь).
	// deque по своим возможностям очень напоминает vector, и дополняет его
	// методами push_front и pop_front.
	// В то время как Вектор гарантированно хранит данные в одном массиве,
	// для изменения размера которого его нужно переопределить,
	// элементы deque могут быть разбросаны в памяти. Именно поэтому Вектор
	// предоставляет прямой доступ к хранилищу в виде указателя на массив, а
	// deque этого не делает.
	// deque внутренне устроен сложнее, чем Вектор, но это позволяет ему изменять
	// размер более эффективно при тех же обстоятельствах, что и Вектор,
	// особенно при больших размерах.

	std::deque<int> deque = { 3, 5, 8, 13, 21 };
	deque.push_back(34);
	deque.push_front(2);
	
	
	/*
	std::vector <int> vec;
	cout << typeid(vec.data()).name() << endl;
	*/
	
	deque_info (deque);
	deque.assign(vec.begin()+3, vec.end()-3);
	for (int i : deque)cout << i << tab; cout << endl;


#endif STL_DEQUE

#ifdef STL_LIST
	// list - это контейнер, который хранит данные в виде двусвязного списка, является шаблонным классом
	std::list<int> list = { 3, 5, 8, 13, 21, 34, 55, 89 };
	list.push_front(2);
	list.push_front(1);
	list.push_front(1);
	list.push_front(0);
	for (std::list<int>::iterator it = list.begin(); it != list.end(); ++it)
		cout << *it << tab;
		cout << endl;
	for (std::list<int>::reverse_iterator it = list.rbegin(); it != list.rend(); ++it)
		cout << *it << tab;
		cout << endl;

		int index;
		int value;
		
		cout << "Введите индекс добавляемого элемента: "; cin >> index;
		cout << "Введите значение добавляемого элемента: "; cin >> value;
		//list.insert(list.begin() + index, value);	// списки не поддерживают арифметику указателей
		std::list<int>::iterator position = list.begin();
		//for (int i = 0; i < index; i++) position++;
		//std::advance(position, index);	// функция advance() смещает итератор вправо
										// на заданное количество элементов
		//list.insert(position, value);

		std::list<int>::reverse_iterator r_position = list.rbegin();
		std::advance(r_position, list.size() - index);
		position = r_position.base();
		list.insert(position, value);
		for (int i : list)cout << i << tab; cout << endl;

		cout << "Введите индекс удаляемого элемента: "; cin >> index;
		position = list.begin();
		std::advance(position, index);
		list.erase(position);
		for (int i : list)cout << i << tab; cout << endl;
		
#endif STL_LIST

#ifdef STL_FORWARD_LIST

		std::forward_list<int> list = { 3, 5, 8, 13, 21 };
		list.push_front(2);
		list.push_front(1);
		list.push_front(1);
		list.push_front(0);
		for(std::forward_list<int>::iterator it = list.begin();it!=list.end();++it)
			cout << *it << tab;
		cout << endl;

		int index;
		int value;
		cout << "Введите индекс добавляемого элемента: "; cin >> index;
		cout << "Введите значение добавляемого элемента: "; cin >> value;
		std::forward_list<int>::iterator position = list.before_begin();
		std::advance(position, index);
		list.insert_after(position, value);
		for (int i : list)cout << i << tab; cout << endl;

		cout << "Введите индекс удаляемого элемента: "; cin >> index;
		position = list.begin();
		std::advance(position, index - 1);
		list.erase_after(position);
		for (int i : list)cout << i << tab; cout << endl;

#endif STL_FORWARD_LIST

}

template<typename T> void vector_info(const std::vector<T>& vec) {

	cout << "Size:\t " << vec.size() << endl; // Фактический размер Вектора, 
	// показывающий сколько элементов хранит Вектор
	cout << "MaxSize: " << vec.max_size() << endl;
	cout << "Capacity: " << vec.capacity() << endl; // Объем зарезервированной памяти.
	// Зарезервированная память нужна для того, чтобы ускорить процесс добавления элементов
	// и избежать необходимости переопределять память при каждом добавлении элемента. 
	// Это экономит ресурсы процессорного времени, но расходует дополнительные ресурсы памяти.
	// Если у Вектора есть свободная зарезервированная память, то добавляемое значение 
	// просто записывается в конец массива, но если зарезервированная память закончилась,
	// то при добавлении элемента Вектор резервирует новую память в половину больше фактического размера.
	// На capacity можно повлиять при помощи методов reserve(), resize(), и shrink_to_fit().

	cout << delimiter << endl;
}

template<typename T> void deque_info(const std::deque<T>& vec) {
	cout << "Size:\t " << vec.size() << endl;
	cout << "MaxSize: " << vec.max_size() << endl;
	//cout << "Capacity: " << vec.capacity() << endl;
	cout << delimiter << endl;
}


