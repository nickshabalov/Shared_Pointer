#include <iostream>
using namespace std;

class Temp
{
	int temp;
public:
	//�����������
	Temp() 
	{ 
		temp = 25; 
	}
	//������� ������ �� �����
	void TempFunction() 
	{
		cout << "TEMP = " << temp << "\n\n";
	}
	//������� ��������� ��������
	void TempSet(int T) 
	{
		temp = T;
	}
};


class Shared_ptr
{
	// ����������������� ���������
	Temp *ptr;
	//������� ����� 
	int *  count_copy;

public:
	//�����������
	Shared_ptr(Temp*p = NULL)
	{
		count_copy = new int(0);
		//���������� 0 ��� �������� ����� 
		count_copy = 0;
		ptr = p;
	}
	// ����������� �����������
	Shared_ptr(const Shared_ptr &obj) {
		//��������� ����� - ����������� �������
		ptr = obj.ptr;
		count_copy++;
	}
	//���������� ��������� �����
	Shared_ptr operator=(const Shared_ptr&obj) {
		//��������� ����� - ����������� �������
		ptr = obj.ptr;
		ptr = obj.ptr;
		count_copy++;
		//���������� ��� ������ ��� �������� a=b=c
		return *this;
	}
	// ����������� �������
	~Shared_ptr()
	{
		//���� ������ ���� � ����� ���
		if (ptr != NULL && count_copy == 0) {
			cout << "\n~Delete Object\n";
			//���������� ������
			delete[]ptr;
		}
		//� ��������� ������(������������ �����)
		else 
		{
			//��������� �������
			count_copy--;
			cout << "\n~Delete Copy\n";
		}

	}
	Temp& operator *()
	{
		return *ptr;
	}

	// ���������� ���������
	Temp* operator->() 
	{
		return ptr;
	}

};
