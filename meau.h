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
	void init();//��ʼ��ϵͳ
	void creat();//�����º���
	void show();//��ʾ�˵�
	void cheat();//�鿴���к���
	void buy();//����Ʊ
	void back();//��Ʊ
	void save1();//�����ļ�
	bool sudo();//����ԱȨ��
	void change();//�޸ĺ�����Ϣ
	void wait();//���β鿴���Ƿ�����������Ʊ
	void save2();
	void local1();//���غ�����Ϣ
	void local2();//���ع���˿���Ϣ
	void local3();//���غ򲹳˿���Ϣ
};
