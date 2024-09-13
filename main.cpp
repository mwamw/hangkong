#include "meau.h"
using namespace std;
int main()
{
	meau c;
	c.local1();
	c.local2();
	c.local3();
	while (1)
	{
		c.show();
		int choice = 0;
		cin >> choice;
		switch (choice)
		{
		case 1:

			if (c.sudo())
			{
				cout << "ÃÜÂëÕýÈ·£¡" << endl;
				c.creat();
			}
			else cout << "ÃÜÂë´íÎó£¡" << endl;
			break;
		case 2:
			c.cheat();
			break;
		case 3:
			c.buy();
			c.save1();
			break;
		case 4:
			c.back();
			c.wait();
			c.save1();
			break;
		case 5:

			if (c.sudo())
			{
				cout << "ÃÜÂëÕýÈ·£¡" << endl;
				c.change();
				c.save1();
			}
			else cout << "ÃÜÂë´íÎó£¡" << endl;
			break;
		case 0:
			exit(0);
			break;
		default:
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}