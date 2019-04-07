#include <iostream>
#include "Shared_ptr.h"



int main() {
	//создаем объект
	Temp *main_ptr = new Temp;
	//инициализируем этим объектом умный указатель
	Shared_ptr Ptr(main_ptr);
	//проверяем работу умного указателя
	Ptr->TempSet(100);
	Ptr->TempFunction();
	// создаем копию (работа конструктора копирования)
	Shared_ptr Ptr2 = Ptr;
	/*Ptr2.~Shared_ptr();
	Ptr.~Shared_ptr();*/
	
	system("pause");
	
}


