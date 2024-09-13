#include "meau.h"
using namespace std;
meau::meau() {
	this->init();
}
void meau::init() {
	this->a.clear();

}
void meau::creat() {
	hangkong m;
	cout << "请依次输入新航空路线的终点站，编号，星期，最大容量：";
	cin >> m.final;
	cin >> m.NO >> m.week >> m.sum;
	for (int i = 1; i <= m.sum; i++)
	{
		m.set.push_back(i);
	}
	this->a.push_back(m);
	this->save1();

}

void meau::show()
{

	cout << "          " << "欢迎使用航空系统" << endl << "          " << "1.添加新航线（管理员权限）" << endl << "          " << "2.查看所有航线" << endl
		<< "          " << "3.购买机票" << endl << "          " << "4.退票" << endl << "          " << "5.修改航线信息（管理员权限）" << endl << "          " << "0.退出航空系统" << endl;

}

void meau::cheat()
{
	cout << "              " << "航班信息如下：" << endl;
	cout << "编号		目的地		剩余票数		星期" << endl;
	for (auto it = this->a.begin(); it != this->a.end(); it++)
	{
		cout << it->NO << "		" << it->final << "		" << it->sum << "		" << it->week << endl;
	}
}


void meau::buy()
{
	cout << "请输入你要前往的目的地：" << endl;
	string mudi;
	cin >> mudi;
	int oc = 0;
	vector<hangkong>::iterator its[10];
	for (auto it = this->a.begin(); it != this->a.end(); it++)
	{

		if (it->final == mudi)
		{
			cout << it->NO << "		" << it->final << "		" << it->sum << "		" << it->week << endl;
			its[oc] = it;
			oc++;

		}

	}
	if (oc != 0)
	{
		cout << "找到以上航班！" << endl;
		cout << "是否确定购买Y/y确定,N/n取消" << endl;
		string op;
		cin >> op;
		if (op == "y" || op == "Y")
		{
			int k = -1;
			cout << "选择你要购买的序列：" << endl;
			cin >> k;
			k--;
			person m;
			cout << "依次输入你的姓名，座位等级，购票数量" << endl;
			cin >> m.name >> m.lever >> m.piao;
			if (m.piao <= its[k]->sum)
			{
				cout << "购票成功！" << "你的座位号是:" << endl;
				for (int ck = 0; ck < m.piao; ck++)
				{
					m.setnumber[ck] = its[k]->set[0];
					its[k]->set.pop_front();
					cout << this->set[m.setnumber[ck]] << " ";
				}
				its[k]->sum -= m.piao;
				its[k]->buy.push_back(m);



			}
			else
			{

				cout << "购票失败座位不足" << endl;
				cout << "是否等待候补?";
				string cmm;
				cin >> cmm;
				if (cmm == "Y" || cmm == "y")
				{
					its[k]->wait.push_back(m);
				}
			}
		}
		else if (op == "n" || op == "N")
		{
			cout << "欢迎下次使用！" << endl;
		}
	}
	else cout << "未找到此航班" << endl;
}

void meau::back()
{
	cout << "请输入你的姓名以及航班号：" << endl;
	string nam;
	string no;
	int m = 0;
	int k = 0;
	vector<hangkong>::iterator its;
	cin >> nam >> no;
	for (auto i = this->a.begin(); i != this->a.end(); i++)
	{
		if (i->NO == no)
		{
			its = i;
			m++;
		}
	}
	if (m != 0) {
		cout << "找到此航班" << endl;
		for (auto it = its->buy.begin(); it != its->buy.end(); )
		{
			if (it->name == nam)
			{
				cout << "找到你所购买的机票" << endl;
				k = 1;
				cout << "是否确定退票Y/N:" << endl;
				string op;
				cin >> op;

				if (op == "y" || op == "Y") {
					int go = it->piao;
					for (int i = 0; i < it->piao; i++)
					{
						its->set.push_back(it->setnumber[i]);
					}
					
					its->sum += it->piao;
					it = its->buy.erase(it);
					cout << "退票成功！" << endl;
					//if (!its->wait.empty())
					//{
					//	
					//	for (auto itt = its->wait.begin(); itt != its->wait.end();) {
					//		if (itt->piao <= go)
					//		{
					//			its->buy.push_back(*itt);
					//			its->sum -= itt->piao;
					//			go-= itt->piao;
					//			itt=its->wait.erase(itt);
					//		}
					//		else {
					//			itt++;
					//		}
					//	}
					//}
				}
				else if (op == "n" || op == "N") {
					cout << "欢迎下次使用！" << endl;
				}


			}
			else { it++; }

		}
		if (k == 0) {
			cout << "未找到你购买的机票！";
		}
	}
	else if (m == 0) {
		cout << "未找到此航班！" << endl;
	}

}

void meau::save1()
{

	ofstream ofs;
	ofs.open("hangkong.csv", ios::out);

	for (auto it = this->a.begin(); it != a.end(); it++)
	{
		ofs << "编号" << "," << "目的地" << "," << "剩余票数" << "," << "星期" << endl;
		ofs << it->NO << "," << it->final << "," << it->sum << "," << it->week;
		for (auto im= it->set.begin(); im !=it->set.end(); im++)
		{
			ofs <<"," << *im;
		}
		ofs << endl;
		ofs << "购票姓名" << "," << "座位等级" << "," << "购票数" << endl;
		for (auto its = it->buy.begin(); its != it->buy.end(); its++)
		{
			ofs << its->name << "," << its->lever << "," << its->piao ;
			for (int i = 0; i < its->piao;i++)
			{
				ofs <<"," << its->setnumber[i];
			}
			ofs << endl;
		}
		ofs << endl;
		ofs << "候补姓名" << "," << "座位等级" << "," << "购票数" << endl;
		for (auto its = it->wait.begin(); its != it->wait.end(); its++)
		{
			ofs << its->name << "," << its->lever << "," << its->piao << endl;
		}
		ofs << "----------" << endl;
	}

	ofs.close();
	cout << "文件保存成功！" << endl;
}

void meau::local1()
{
	ifstream ifs;
	ifs.open("hangkong.csv", ios::in);
	string cv;
	int line = 0;
	while (ifs >> cv)
	{

		int pos = -1;
		int start = 0;
		if (line == 1)
		{
			hangkong a;
			pos = cv.find(",", start);
			string temp = cv.substr(start, pos - start);
			a.NO = temp;
			start = pos + 1;
			pos = cv.find(",", start);
			temp = cv.substr(start, pos - start);
			a.final = temp;
			start = pos + 1;
			pos = cv.find(",", start);
			temp = cv.substr(start, pos - start);
			a.sum = stoi(temp);
			start = pos + 1;
			pos = cv.find(",", start);
			temp = cv.substr(start, pos - start);
			a.week = temp;
			
			for (int i = 0; i < a.sum; i++)
			{
				start = pos + 1;
				pos = cv.find(",", start);
				temp = cv.substr(start, pos - start);
				a.set.push_back(stoi(temp));

			}
			this->a.push_back(a);
			line = 0;

		}
		if (cv == "编号,目的地,剩余票数,星期")
		{
			line = 1;
		}


	}
	ifs.close();
}

void meau::local2()
{
	ifstream ifs;
	ifs.open("hangkong.csv", ios::in);
	string cv;
	int line = 0;
	auto it = this->a.begin();
	while (ifs >> cv)
	{
		if (cv == "候补姓名,座位等级,购票数")
		{
			line = 0;
			it++;
		}
		if (line == 1)
		{
			int pos = -1;
			int start = 0;
			person ok;
			pos = cv.find(",", start);
			string temp = cv.substr(start, pos - start);
			ok.name = temp;
			start = pos + 1;
			pos = cv.find(",", start);
			temp = cv.substr(start, pos - start);
			ok.lever = stoi(temp);
			start = pos + 1;
			pos = cv.find(",", start);
			temp = cv.substr(start, pos - start);
			ok.piao = stoi(temp);
			for (int i = 0; i < ok.piao; i++)
			{
				start = pos + 1;
				pos = cv.find(",", start);
				temp = cv.substr(start, pos - start);
				ok.setnumber[i]= stoi(temp);
			}
			it->buy.push_back(ok);

		}
		if (cv == "购票姓名,座位等级,购票数")
		{
			line = 1;
		}

	}
	ifs.close();
}

bool meau::sudo()
{
	cout << "请输入管理员密码！" << endl;

	string k;
	cin >> k;
	return k == this->mima;

}

void meau::change()
{
	cout << "请输入你要修改航班的目的地：" << endl;
	string mudi;
	cin >> mudi;
	int oc = 0;
	vector<hangkong>::iterator its[10];
	for (auto it = this->a.begin(); it != this->a.end(); it++)
	{

		if (it->final == mudi)
		{
			cout << it->NO << "		" << it->final << "		" << it->sum << "		" << it->week << endl;
			its[oc] = it;
			oc++;

		}

	}
	if (oc != 0)
	{
		cout << "找到以上航班！" << endl;
		cout << "是否确定修改Y/y确定,N/n取消" << endl;
		string op;
		cin >> op;
		if (op == "y" || op == "Y")
		{
			int k = -1;
			cout << "选择你要修改的序列：" << endl;
			cin >> k;
			k--;
			cout << "依次输入修改航班的目的地，编号，星期，剩余数量" << endl;
			cin >> its[k]->final >> its[k]->NO >> its[k]->week >> its[k]->sum;
		}
		else if (op == "n" || op == "N")
		{
			cout << "欢迎下次使用！" << endl;
		}
	}
}


void meau::wait()
{
	for (auto it = this->a.begin(); it != this->a.end(); it++)
	{
		if (!it->wait.empty() && it->sum != 0) {
			for (auto its = it->wait.begin(); its != it->wait.end();)
			{
				if (its->piao <= it->sum)
				{
					for (int i = 0; i < its->piao; i++)
					{
						its->setnumber[i] = it->set[0];
						it->set.pop_front();
					}
					it->buy.push_back(*its);
					it->sum -= its->piao;
					its = it->wait.erase(its);

				}
				else {
					its++;
				}
			}
		}
	}

}


void meau::local3()
{
	ifstream ifs;
	ifs.open("hangkong.csv", ios::in);
	string cv;
	int line = 0;
	auto it = this->a.begin();
	while (ifs >> cv)
	{
		if (cv == "----------")
		{
			line = 0;
			it++;
		}
		if (line == 1)
		{
			int pos = -1;
			int start = 0;
			person ok;
			pos = cv.find(",", start);
			string temp = cv.substr(start, pos - start);
			ok.name = temp;
			start = pos + 1;
			pos = cv.find(",", start);
			temp = cv.substr(start, pos - start);
			ok.lever = stoi(temp);
			start = pos + 1;
			pos = cv.find(",", start);
			temp = cv.substr(start, pos - start);
			ok.piao = stoi(temp);
			it->wait.push_back(ok);
		}
		if (cv == "候补姓名,座位等级,购票数")
		{
			line = 1;
		}

	}
	ifs.close();
}