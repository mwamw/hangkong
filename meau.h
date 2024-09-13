#pragma once
#pragma once
#include<iostream>
#include<fstream>
#include"person.h"
#include"hangkong.h"
#include <string>
using namespace std;
class meau
{
public:
	vector<string>set{ "A1","A2","A3","B1","B2","B3","C1","C2","C3","D1","D2","D3","E1","E2","E3","F1","F2","F3","G1","G2","G3","H1","H2","H3","I1","I2","I3","G1","G2","G3","K1","K2","K3","L1","L2","L3" };
	vector<hangkong>a;
	meau();
	string const mima = "352541141";
	void init();//初始化系统
	void creat();//创造新航线
	void show();//显示菜单
	void cheat();//查看所有航线
	void buy();//购买车票
	void back();//退票
	void save1();//保存文件
	bool sudo();//管理员权限
	void change();//修改航班信息
	void wait();//依次查看候补是否满足条件出票
	void save2();
	void local1();//加载航空信息
	void local2();//加载购买乘客信息
	void local3();//加载候补乘客信息
};
