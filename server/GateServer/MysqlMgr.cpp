#include "MysqlMgr.h"


MysqlMgr::~MysqlMgr() {

}

MysqlMgr::MysqlMgr() {
	//��ʼ������
	sql::mysql::MySQL_Driver* driver = NULL;
	sql::Connection* con = NULL;
	driver = sql::mysql::get_mysql_driver_instance();
	if (driver == NULL)
	{
		cout << "driver is null" << endl;
	}
	con = driver->connect("tcp://81.68.86.146:3308", "root", "123456");
	if (con == NULL)
	{
		cout << "conn is null" << endl;
	}
	cout << "connect suceess" << endl;
}