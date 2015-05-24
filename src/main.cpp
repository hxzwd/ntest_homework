#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

class number
{
public:
	string name;
	string cardinality;
	string data;
	virtual void set_name(string n) = 0;
	virtual string get_name(void) = 0;
	virtual string get_cardinality(void) = 0;
	virtual void set_cardinality(string c) = 0;
	virtual void set_data(string d) = 0;
	virtual string get_data(void) = 0;
	virtual bool is_valid(void) = 0;
	virtual bool is_zero(void) = 0;
	virtual bool is_unit(void) = 0;
};

class natural_number : public number
{
public:
	natural_number(string n, string c, string d)
	{
		name = n;
		cardinality = c;
		data = d;
	}
	virtual void set_name(string n)
	{
		name = n;
	}
	virtual string get_name(void)
	{
		return name;
	}
	virtual void set_cardinality(string c)
	{
		cardinality = c;
	}
	virtual string get_cardinality(void)
	{
		return cardinality;
	}
	virtual void set_data(string d)
	{
		data =d;
	}
	virtual string get_data(void)
	{
		return data;
	}
	bool is_unit(void)
	{
		if(data.size() == 1 && data[0] == '1')
			return true;
		else
			return false;
	}
	virtual bool is_valid(void)
	{
		int j, i = data.size();
		for((data[0] == '+') ? j = 1 : j = 0; j < i; j++)
		{
			if(data[j] > '0' && data[j] <= '9')
				continue;
			else
				return false;
		}
		return true;
	}
	bool is_zero(void)
	{
			return false;
	}
};

class integer_number : public natural_number
{
public:

	integer_number(string n, string c, string d):natural_number(n, c, d)
	{
	}
	bool is_zero(void)
	{
		if(data[0] == '0' && data.size() == 1)
			return true;
		else
			return false;
	}
	bool is_less_then_zero()
	{
		if(data[0] == '-')
			return true;
		else
			return false;
	}
	virtual bool is_valid(void)
	{
		int j, i = data.size();
		for((data[0] == '-' || data[0] == '+') ? j = 1 : j = 0; j < i; j++)
		{
			if(data[j] >= '0' && data[j] <= '9')
				continue;
			else
				return false;
		}
		return true;
	}
	bool is_unit(void)
	{
		if(data.size() == 1 && data[0] == '1')
			return true;
		else
			return false;
	}

};

string to_string(int num)
{
	char ch[64];
	sprintf_s(ch, 64, "%d", num);
	return string(ch);
}

void main(void)
{
	int x;
	string s = "hello";
	natural_number nat_num("natural", "alef0", "1");
	integer_number a();
	nat_num.set_name(s);
	cout << s;
	cout << endl << nat_num.is_unit() << endl;
	cout << "__________________________________________________" << endl;
	number *nums[10];
	for(int i = 0; i < 10; i++)
	{
		if(i < 5)
			nums[i] = new natural_number(to_string(i), "alef0", to_string(i + 1));
		if(i >= 5)
			nums[i] = new integer_number(to_string(i), "alef0", to_string(-(i - 5)));
	}
	for(int i = 0; i < 10; i++)
	{
		cout << nums[i]->name << '\t' << nums[i]->cardinality << '\t' << nums[i]->data << '\t' << "is valid: " << nums[i]->is_valid();
		cout << '\t' << "is zero : " << nums[i]->is_zero() << '\t' << "is unit : " << nums[i]->is_unit() << endl;

	}
	for(int i = 0; i < 10; i++)
	{
		delete nums[i];
	}
	cin >> x;
}
	