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
	cout << "�����������º���·�ߵ��յ�վ����ţ����ڣ����������";
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

	cout << "          " << "��ӭʹ�ú���ϵͳ" << endl << "          " << "1.����º��ߣ�����ԱȨ�ޣ�" << endl << "          " << "2.�鿴���к���" << endl
		<< "          " << "3.�����Ʊ" << endl << "          " << "4.��Ʊ" << endl << "          " << "5.�޸ĺ�����Ϣ������ԱȨ�ޣ�" << endl << "          " << "0.�˳�����ϵͳ" << endl;

}

void meau::cheat()
{
	cout << "              " << "������Ϣ���£�" << endl;
	cout << "���		Ŀ�ĵ�		ʣ��Ʊ��		����" << endl;
	for (auto it = this->a.begin(); it != this->a.end(); it++)
	{
		cout << it->NO << "		" << it->final << "		" << it->sum << "		" << it->week << endl;
	}
}


void meau::buy()
{
	cout << "��������Ҫǰ����Ŀ�ĵأ�" << endl;
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
		cout << "�ҵ����Ϻ��࣡" << endl;
		cout << "�Ƿ�ȷ������Y/yȷ��,N/nȡ��" << endl;
		string op;
		cin >> op;
		if (op == "y" || op == "Y")
		{
			int k = -1;
			cout << "ѡ����Ҫ��������У�" << endl;
			cin >> k;
			k--;
			person m;
			cout << "�������������������λ�ȼ�����Ʊ����" << endl;
			cin >> m.name >> m.lever >> m.piao;
			if (m.piao <= its[k]->sum)
			{
				cout << "��Ʊ�ɹ���" << "�����λ����:" << endl;
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

				cout << "��Ʊʧ����λ����" << endl;
				cout << "�Ƿ�ȴ���?";
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
			cout << "��ӭ�´�ʹ�ã�" << endl;
		}
	}
	else cout << "δ�ҵ��˺���" << endl;
}

void meau::back()
{
	cout << "��������������Լ�����ţ�" << endl;
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
		cout << "�ҵ��˺���" << endl;
		for (auto it = its->buy.begin(); it != its->buy.end(); )
		{
			if (it->name == nam)
			{
				cout << "�ҵ���������Ļ�Ʊ" << endl;
				k = 1;
				cout << "�Ƿ�ȷ����ƱY/N:" << endl;
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
					cout << "��Ʊ�ɹ���" << endl;
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
					cout << "��ӭ�´�ʹ�ã�" << endl;
				}


			}
			else { it++; }

		}
		if (k == 0) {
			cout << "δ�ҵ��㹺��Ļ�Ʊ��";
		}
	}
	else if (m == 0) {
		cout << "δ�ҵ��˺��࣡" << endl;
	}

}

void meau::save1()
{

	ofstream ofs;
	ofs.open("hangkong.csv", ios::out);

	for (auto it = this->a.begin(); it != a.end(); it++)
	{
		ofs << "���" << "," << "Ŀ�ĵ�" << "," << "ʣ��Ʊ��" << "," << "����" << endl;
		ofs << it->NO << "," << it->final << "," << it->sum << "," << it->week;
		for (auto im= it->set.begin(); im !=it->set.end(); im++)
		{
			ofs <<"," << *im;
		}
		ofs << endl;
		ofs << "��Ʊ����" << "," << "��λ�ȼ�" << "," << "��Ʊ��" << endl;
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
		ofs << "������" << "," << "��λ�ȼ�" << "," << "��Ʊ��" << endl;
		for (auto its = it->wait.begin(); its != it->wait.end(); its++)
		{
			ofs << its->name << "," << its->lever << "," << its->piao << endl;
		}
		ofs << "----------" << endl;
	}

	ofs.close();
	cout << "�ļ�����ɹ���" << endl;
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
		if (cv == "���,Ŀ�ĵ�,ʣ��Ʊ��,����")
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
		if (cv == "������,��λ�ȼ�,��Ʊ��")
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
		if (cv == "��Ʊ����,��λ�ȼ�,��Ʊ��")
		{
			line = 1;
		}

	}
	ifs.close();
}

bool meau::sudo()
{
	cout << "���������Ա���룡" << endl;

	string k;
	cin >> k;
	return k == this->mima;

}

void meau::change()
{
	cout << "��������Ҫ�޸ĺ����Ŀ�ĵأ�" << endl;
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
		cout << "�ҵ����Ϻ��࣡" << endl;
		cout << "�Ƿ�ȷ���޸�Y/yȷ��,N/nȡ��" << endl;
		string op;
		cin >> op;
		if (op == "y" || op == "Y")
		{
			int k = -1;
			cout << "ѡ����Ҫ�޸ĵ����У�" << endl;
			cin >> k;
			k--;
			cout << "���������޸ĺ����Ŀ�ĵأ���ţ����ڣ�ʣ������" << endl;
			cin >> its[k]->final >> its[k]->NO >> its[k]->week >> its[k]->sum;
		}
		else if (op == "n" || op == "N")
		{
			cout << "��ӭ�´�ʹ�ã�" << endl;
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
		if (cv == "������,��λ�ȼ�,��Ʊ��")
		{
			line = 1;
		}

	}
	ifs.close();
}