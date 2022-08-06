#include <iostream>
#include <string>
#include <cmath>
#include <Windows.h>
#include <vector>
using namespace std;

long double com = 0;
long double percent_1(bool bet,long double swap);
bool system_compare(long double cp_a, long double pr, long double swap_ss, long double swap_sw);
long double sc_1(long double c_1, long double c_2);
bool system_compare_2(long double cp_b, long double pr2, long double swap_ss2, long double swap_sw2);
int percent_s(bool swap_sigma, bool swap_omega);
void system_switch(int swit);
long double Pro(long double e)
{
	string l;
	long double h;
	h = 1 / (1 + pow(10, -(e / 400)));
	return h;
}

long double short_save()
{
	long double al = 0;
	long double bl = 0;
	cout << "input today win" << endl;
	cin >> al;
	cin.get();
	cout << "input today lose" << endl;
	cin >> bl;
	cin.get();
	long double kl = 0;
	kl = (al) / (al + bl);
	return kl;
}

long double s_w()
{
	long double alp = 0;
	cout << "input 0.** for compare" << endl;
	cin >> alp;
	if (alp <= 1 and alp >= 0)
	{
		return alp;
	}
	else
	{
		cout << "wrong word" << endl;
		abort();
	}
}
bool compare(long double u)
{
	if (u >= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main()
{
	long double ss = 0;
	ss = short_save();
	long double sw = s_w();
	long double Ea = 0;
	long double Eb = 0;
	long double swap1 = ss - sw;
	cout << "队伍A战力:" << endl;
	cin >> Ea;
	cout << endl;
	cin.get();
	cout << "队伍B战力:" << endl;
	cin >> Eb;
	cout << endl;
	cin.get();
	long double ELO_Pro = Pro(Ea - Eb);
	cout << "A队的胜率为" << ELO_Pro << endl;
	long double save = 1 - ELO_Pro;
	cout << "B队的胜率为" << save << endl;
	cin.get();
	if (ELO_Pro > save)
	{
		bool ap = compare(ELO_Pro - sw);
		long double compare_a = percent_1(ap, swap1);
		bool sigma = system_compare(compare_a, ELO_Pro, ss, sw);    //compare_a:隐藏分函数调用后
		bool omega = system_compare_2(compare_a, ELO_Pro, ss, sw);
		int swi = percent_s(sigma, omega);
		system_switch(swi);
	}
	/*if (ap == true)
	{
		cout << "" << endl;     
	}
	else
	{
		cout << "" << endl;     
	}
	*/
	// ss:今日胜率 sw:赛季胜率 ELO_Pro:A队胜率 compare_a:系统隐藏分
	//
	else
	{
		system("pause");
		return 0;
	}
	system("pause");
	return 0;
}

long double percent_1(bool bet,long double swap)
{
	if (bet == true)
	{
		return 1.00;
	}
	else
	{
		if (bet == false)
		{
			if (swap > 0)
			{
				return 0.75;
			}
			else
			{
				return 0.50;
			}
		}
		else
		{
			return 0.00;
		}
	}
}

bool system_compare(long double cp_a, long double pr, long double swap_ss, long double swap_sw)
{
	//计算比较分
	long double compare_s = sc_1(cp_a, pr);
	if (compare_s >= swap_sw)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool system_compare_2(long double cp_b,long double pr2, long double swap_ss2, long double swap_sw2)
{
	long double compare_s2 = sc_1(cp_b, pr2);
	if (compare_s2 >= swap_ss2)
	{
		return true;//比较分大于当日胜率
	}
	else
	{
		return false;//比较分小于当日胜率
	}
}

int percent_s(bool swap_sigma, bool swap_omega)
{
	if (swap_sigma == true and swap_omega == true)
	{
		return 1;
	}
	if (swap_sigma == true and swap_omega == false)
	{
		return 2;
	}
	if (swap_sigma == false and swap_omega == true)
	{
		return 3;
	}
	if (swap_sigma == false and swap_omega == false)
	{
		return 4;
	}
}


void system_switch(int swit)
{
	switch (swit)
	{
	case 1:cout << "100%" << endl;
		break;
	case 2:cout << "75%" << endl;
		break;
	case 3:cout << "50%" << endl;
		break;
	case 4:cout << "25%" << endl;
		break;
	}
}

long double sc_1(long double c_1, long double c_2)
{
	long double swap_sc = (c_1 + c_2) / 3;
	return swap_sc;
}


//搁置，
//胜负分别写一套概率分析
//over