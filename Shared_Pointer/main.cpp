#include <iostream>
#include "Shared_ptr.h"



int main() {
	//������� ������
	Temp *main_ptr = new Temp;
	//�������������� ���� �������� ����� ���������
	Shared_ptr Ptr(main_ptr);
	//��������� ������ ������ ���������
	Ptr->TempSet(100);
	Ptr->TempFunction();
	// ������� ����� (������ ������������ �����������)
	Shared_ptr Ptr2 = Ptr;
	/*Ptr2.~Shared_ptr();
	Ptr.~Shared_ptr();*/
	
	system("pause");
	
}


