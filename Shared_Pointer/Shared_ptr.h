#include <iostream>
using namespace std;

class Temp
{
	int temp;
public:
	//конструктор
	Temp() 
	{ 
		temp = 25; 
	}
	//функция показа на экран
	void TempFunction() 
	{
		cout << "TEMP = " << temp << "\n\n";
	}
	//функция установки значения
	void TempSet(int T) 
	{
		temp = T;
	}
};


class Shared_ptr
{
	// Инкапсулированный указатель
	Temp *ptr;
	//счётчик копий 
	int *  count_copy;

public:
	//конструктор
	Shared_ptr(Temp*p = NULL)
	{
		count_copy = new int(0);
		//записываем 0 при создании копий 
		count_copy = 0;
		ptr = p;
	}
	// конструктор копирования
	Shared_ptr(const Shared_ptr &obj) {
		//создается копия - увеличиваем счётчик
		ptr = obj.ptr;
		count_copy++;
	}
	//перегрузка оператора равно
	Shared_ptr operator=(const Shared_ptr&obj) {
		//создается копия - увеличиваем счётчик
		ptr = obj.ptr;
		ptr = obj.ptr;
		count_copy++;
		//возвращаем сам объект для ситуации a=b=c
		return *this;
	}
	// уничтожение объекта
	~Shared_ptr()
	{
		//если объект есть и копий нет
		if (ptr != NULL && count_copy == 0) {
			cout << "\n~Delete Object\n";
			//уничтожаем объект
			delete[]ptr;
		}
		//в противном случае(уничтожается копия)
		else 
		{
			//уменьшаем счётчик
			count_copy--;
			cout << "\n~Delete Copy\n";
		}

	}
	Temp& operator *()
	{
		return *ptr;
	}

	// перегрузка селектора
	Temp* operator->() 
	{
		return ptr;
	}

};
