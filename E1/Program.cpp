#include <string>
#include <memory>
#include "QLCB.h"
#include "CongNhan.h"
#include "KiSu.h"
#include "NhanVien.h"
using namespace std;

int main()
{
    QLCB manager;
    manager.AddEmployee(shared_ptr<CanBo>(new CongNhan("Nguyen Van", "A", 29, MALE, "123456")));
    manager.AddEmployee(shared_ptr<CanBo>(new KiSu("Nguyen Van", "B", 34, MALE, "12314", "IT")));
    manager.AddEmployee(shared_ptr<CanBo>(new KiSu("Nguyen Van", "B", 25, OTHER, "09876", "CS")));
    manager.AddEmployee(shared_ptr<CanBo>(new NhanVien("Nguyen Thi", "Linh", 23, FEMALE, "1231313", "Accountant")));
    manager.AddEmployee(shared_ptr<CanBo>(new CongNhan("Tran Thi", "Linh", 25, OTHER, "4578", 10)));

    manager.ShowInfo();

    vector<shared_ptr<CanBo>> searchRes = manager.GetEmployeeByName("Nguyen Van", "B");
    for (shared_ptr<CanBo> temp : searchRes) {
        temp->ShowInfo();
    }
}
