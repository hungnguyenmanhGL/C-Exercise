#include <iostream>
#include "TuyenSinh.h"
using namespace std;

int main()
{
	TuyenSinh admission;
	admission.AddStudent(shared_ptr<Student>(new Student("000", "Nguyen Van A", "09876", 1, 'A')));
	admission.AddStudent(shared_ptr<Student>(new Student("001", "Tran Thi B", "123435", 3, 'C')));
	admission.AddStudent(shared_ptr<Student>(new Student("002", "Nguyen Tran Tien C", "sadf", 0, 'B')));

	admission.ShowInfo();

	shared_ptr<Student> res0 = admission.GetById("005");
	shared_ptr<Student> res1 = admission.GetById("001");
	res1->ShowInfo();
}