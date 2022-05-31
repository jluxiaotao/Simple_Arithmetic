
// SimpleArithmetic.cpp: 定义应用程序的入口点。
//

#include <iostream>
#include <ctime>
#include <string>
using namespace std;
int right_num = 0;
int wrong_num = 0;
string judge = "\nWrong questions : \n";
double right_time[100] = {0};
double wrong_time[100] = { 0 };
int limit;
struct max_min_avg
{
	double max;
	double min;
	double avg;
};
int rand_int(int lower, int upper, int seed)
{
	int rand_num;
	srand(seed);
	rand_num = lower + rand() % upper;
	return rand_num;
}
void make_plus(int seed, int i)
{
	clock_t start, stop;
	int res;
	int num_first;
	int num_second;
	num_first = rand_int(1, limit - 2, seed);
	num_second = rand_int(1, limit - 1 - num_first, seed+1);
	cout << num_first << " + " << num_second << " = ";
	start = clock();
	cin >> res;
	stop = clock();
	if (res == num_first + num_second)
	{
		right_num += 1;
		right_time[i] = double(stop - start) / 1000;
	}
	else
	{
		wrong_num += 1;
		string num_first_str;
		string num_second_str;
		string res_str;
		num_first_str = to_string(num_first);
		num_second_str = to_string(num_second);
		res_str = to_string(num_first + num_second);
		judge = judge + num_first_str + " + " + num_second_str + " = " + res_str + "\n";
		wrong_time[i] = double(stop - start) / 1000;
	}
}
void make_minus(int seed, int i)
{
	clock_t start, stop;
	int res;
	int num_first;
	int num_second;
	num_first = rand_int(1, limit-1, seed);
	num_second = rand_int(1, num_first, seed+1);
	cout << num_first << " - " << num_second << " = ";
	start = clock();
	cin >> res;
	stop = clock();
	if (res == num_first - num_second)
	{
		right_num += 1;
		right_time[i] = double(stop - start) / 1000;
	}
	else
	{
		wrong_num += 1;
		string num_first_str;
		string num_second_str;
		string res_str;
		num_first_str = to_string(num_first);
		num_second_str = to_string(num_second);
		res_str = to_string(num_first - num_second);
		judge = judge + num_first_str + " - " + num_second_str + " = " + res_str + "\n";
		wrong_time[i] = double(stop - start) / 1000;
	}
}
void make_mutiply(int seed, int i)
{
	clock_t start, stop;
	int res;
	int num_first;
	int num_second;
	num_first = rand_int(1, limit, seed);
	num_second = rand_int(1, limit, seed+1);
	cout << num_first << " * " << num_second << " = ";
	start = clock();
	cin >> res;
	stop = clock();
	if (res == num_first * num_second)
	{
		right_num += 1;
		right_time[i] = double(stop - start) / 1000;
	}
	else
	{
		wrong_num += 1;
		string num_first_str;
		string num_second_str;
		string res_str;
		num_first_str = to_string(num_first);
		num_second_str = to_string(num_second);
		res_str = to_string(num_first * num_second);
		judge = judge + num_first_str + " * " + num_second_str + " = " + res_str + "\n";
		wrong_time[i] = double(stop - start) / 1000;
	}
}
void make_divide(int seed, int i)
{
	clock_t start, stop;
	int res;
	int num_first;
	int num_second;
	num_second = rand_int(1, limit, seed);
	num_first = rand_int(1, limit, seed+1);
	num_first = num_second * num_first;
	cout << num_first << " / " << num_second << " = ";
	start = clock();
	cin >> res;
	stop = clock();
	if (res == num_first / num_second)
	{
		right_num += 1;
		right_time[i] = double(stop - start) / 1000;
	}
	else
	{
		wrong_num += 1;
		string num_first_str;
		string num_second_str;
		string res_str;
		num_first_str = to_string(num_first);
		num_second_str = to_string(num_second);
		res_str = to_string(num_first / num_second);
		judge = judge + num_first_str + " / " + num_second_str + " = " + res_str + "\n";
		wrong_time[i] = double(stop - start) / 1000;
	}
}
max_min_avg statistic_time(double r_array[], double w_array[], int len)
{
	double sum = 0;
	struct max_min_avg mx_mn_ag = { r_array[0], r_array[0], r_array[0] };
	for (int i = 0; i < len; i++)
	{
		if (r_array[i] != 0 && r_array[i] > mx_mn_ag.max)
		{
			mx_mn_ag.max = r_array[i];
		}
		if (r_array[i] != 0 && (mx_mn_ag.min == 0 || r_array[i] < mx_mn_ag.min))
		{
			mx_mn_ag.min = r_array[i];
		}
		sum += r_array[i];
		sum += w_array[i];
	}
	mx_mn_ag.avg = sum / len;
	return mx_mn_ag;
}
int main()
{
	int num;
	string operators = "+-";
	int flag_operator_set = 1;
	int operator_num = 2;
	cout << "Please enter a int number to determine the number of problems:";
	cin >> num;
	while (flag_operator_set)
	{
		cout << "Please choose the difficulty of the test question.\n";
		cout << "Enter '+-*/' or '+-':";
		cin >> operators;
		if (operators == "+-")
		{
			cout << "Please enter a number to determine the limitation "
				"of numbers in addition and subtraction test questions:";
			cin >> limit;
			cout << "There are " << num
				<< " addition and subtraction test questions within "
				<< limit
				<< "(100 points in total)\nQuestions:" << endl;
			operator_num = 2;
			flag_operator_set = 0;
		}
		else if (operators == "+-*/")
		{
			cout << "Please enter a number to determine the limitation "
				"of numbers in test questions:";
			cin >> limit;
			cout << "There are " << num
				<< " test questions within "
				<< limit
				<< "(100 points in total)\nQuestions:" << endl;
			operator_num = 4;
			flag_operator_set = 0;
		}
		else
		{
			cout << "Wrong operator!\n";
		}
	}
	for (int i = 0; i < num; i++)
	{
		int seed = (int)time(0) + i;
		int opt = rand_int(0, operator_num, seed);
		if (opt == 0)
		{
			make_plus(seed, i);
		}
		else if(opt == 1)
		{
			make_minus(seed, i);
		}
		else if (opt == 2)
		{
			make_mutiply(seed, i);
		}
		else if (opt == 3)
		{
			make_divide(seed, i);
		}
	}
	cout << "\nRight num:" << right_num << endl;
	cout << "Wrong num:" << wrong_num << endl;
	cout << "Score:" << 100/num*right_num << endl;
	cout << judge << endl;
	struct max_min_avg mx_mn_ag = statistic_time(right_time, wrong_time, num);
	cout << "Right Question Maximum time:" << mx_mn_ag.max << "s" << endl;
	cout << "Right Question Minimum time:" << mx_mn_ag.min << "s" << endl;
	cout << "Average time:" << mx_mn_ag.avg << "s" << endl;
	return 0;
}
