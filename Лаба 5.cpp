// Лаба 5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <locale.h>

using namespace std;

class ya {
protected:

	int age;

public:

	virtual void ageM() = 0;

	virtual void print() = 0;

	ya() {
		this->age = 0;
	}

	ya(int age1) :age(age1) {

	}
	void setage(int age1) {
		age = age1;
	}

	virtual ~ya()
	{
		cout << "Деструктор" << endl;
	}
};

class father : public ya {

protected:

	string name;

public:

	father() : ya() {
		this->name = ' ';
	}

	father(string name1, int age1) : ya(age), name(name1) {

	}

	~father()
	{

	}
	void ageM() {
		int age2 = age * 365;
		cout << "Возраст в днях = " << age2;
	}
	void setname(string name1) {
		name = name1;
	}
	void print() {
		cout << endl;
		cout << "Папа:" << endl;
		cout << "Имя : " << this->name << endl;
		cout << "Возраст :" << age << endl;
	}
};

class mother : public ya {

protected:

	string hobby;

public:

	mother() : ya() {
		this->hobby = ' ';
	}

	mother(int age1, string hobby1) : ya(age), hobby(hobby1) {

	}

	void ageM() {
		int age2 = age * 365;
		cout << "Возраст в днях = " << age2;
	}

	void sethobby(string hobby1) {
		hobby = hobby1;
	}

	void print() {
		cout << "Мама:" << endl;
		cout << endl;
		cout << "Хобби : " << hobby << endl;
		cout << "Возраст :" << age << endl;
	}
	~mother()
	{

	}
};

class babyshka : public mother {
protected:

	int rost;

public:

	babyshka() : mother() {
		this->rost = 0;
	}

	babyshka(int age1, int rost1, string hobby1 ) {

	}

	~babyshka()
	{

	}
	void ageM() {
		int age2 = age * 365;
		cout << "Возраст в днях = " << age2;
	}

	void setrost(int rost1) {
		rost = rost1;
	}

	void print() {
		cout << endl;
		cout << "Бабушка:" << endl;
		cout << "Возраст:" << age << endl;
		cout << "Рост :" << rost << endl;
		cout << "Хобби :" << hobby << endl;
	}
};

int check_int(int a)
{
	while (true)
	{
		int a=0;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Повторите попытку: ";
		}
		else
		{
			std::cin.ignore(32767, '\n');
			return a;
		}
	}
}

string check_string(string s)
{
	int i = 0;
	string str;
	while (s[i])
	{
		if ((s[i] >= 97) && (s[i] <= 122))
			str = str + s[i];
		else
		{
			cout << "Повторите попытку : ";
			cin >> s;
			return check_string(s);
		}
		i++;
	}
	return str;
}
void setya(ya& ya1) {
	int age1;
	cout << "Возраст : ";
	cin >> age1;
	check_int(age1);
	ya1.setage(age1);
}

void setfather(father& father1) {
	setya(father1);
	string name1;
	cout << "Имя : ";
	cin >> name1;
	check_string(name1);
	father1.setname(name1);
}

void setmother(mother& mother1) {
	setya(mother1);
	string hobby1;
	cout << "Хобби : ";
	cin >> hobby1;
    check_string(hobby1);
	mother1.sethobby(hobby1);
}

void setbabyshka(babyshka& babyshka1) {
	setmother(babyshka1);
	int rost1;
	cout << "Рост : ";
	cin >> rost1;
	check_int(rost1);
	babyshka1.setrost(rost1);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	string name, hobby; int age = 0; int rost = 0;
	father* ptrfather = new father;
	mother* ptrmother = new mother;
	babyshka* ptrbabyshka = new babyshka;
	ya* ya;
	cout << "========================" << endl;
	for (int i = 0; i < 1; i++)
	{
		setfather(ptrfather[i]);
		ya = &ptrfather[i];
		cout << endl << "******************" << endl;
		ya->print();
		ya->ageM();
	}
	cout << endl << "========================" << endl;
	for (int i = 0; i < 1; i++)
	{
		setmother(ptrmother[i]);
		ya = &ptrmother[i];
		cout << endl << "******************" << endl;
		ya->print();
		ya->ageM();
	}
	cout << endl << "========================" << endl;
	for (int i = 0; i < 1; i++)
	{
		setbabyshka(ptrbabyshka[i]);
		ya = &ptrbabyshka[i];
		cout << endl << "******************" << endl;
		ya->print();
		ya->ageM();
	}
	cout << endl << "========================" << endl;
	cout << endl;

	system("pause");

}