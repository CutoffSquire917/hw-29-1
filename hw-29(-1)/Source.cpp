#include <iostream>
#include <locale>
using namespace std;

class Shape {
public:
	virtual double CalculateArea() const = 0;
	virtual void Print() const = 0;
};
class Rectangle : public Shape {
private:
	double lenght;
	double width;
public:
	Rectangle(const double l, const double w) : lenght(l), width(w) {}
	virtual double CalculateArea() const override {
		return lenght * width;
	}
	virtual void Print() const override {
		cout << "Lenght : " << lenght << "\nWidth : " << width << "\nArea : " << CalculateArea() << endl;
	}
};
class Circle : public Shape {
private:
	double radius;
public:
	Circle(const double r) : radius(r) {}
	virtual double CalculateArea() const override {
		return 3.14 * (radius * radius);
	}
	virtual void Print() const override {
		cout << "Radius : " << radius << "\nArea : " << CalculateArea() << endl;
	}
};
class Triangle : public Shape {
private:
	double height;
	double base;
public:
	Triangle(const double h, const double b) : height(h), base(b) {}
	virtual double CalculateArea() const override {
		return (height * base) / 2;
	}
	virtual void Print() const override {
		cout << "Height : " << height << "\nBase : " << base << "\nArea : " << CalculateArea() << endl;
	}
};

class Animal {
public:
	virtual void MakeSound() const {}
	virtual void PrintInfo() const {}
};
class Dog : public Animal {
public:
	virtual void MakeSound() const {
		cout << "Ãàâ!" << endl;
	}
	virtual void PrintInfo() const {
		cout << "Öå ñîáàêà." << endl;
	}
};
class Cat : public Animal {
public:
	virtual void MakeSound() const {
		cout << "Ìÿó!" << endl;
	}
	virtual void PrintInfo() const {
		cout << "Öå êiò." << endl;
	}
};
class Bird : public Animal {
public:
	virtual void MakeSound() const {
		cout << "Öâiðiíü!" << endl;
	}
	virtual void PrintInfo() const {
		cout << "Öå ïòàõ." << endl;
	}
};

class Account {
protected:
	double balance;
public:
	Account(const double B) : balance(B) {}
	virtual void CalculateInterest() {}
	virtual void Deposit(double amount) {
		balance += amount;
	}
	double GetBalance() const {
		return balance;
	}
};
class SavingsAccount : public Account {
public:
	SavingsAccount(const double B) : Account(B) {}
	virtual void CalculateInterest() override {
		balance += balance * 0.05;
	}
};
class CheckingAccount : public Account {
public:
	CheckingAccount(const double B) : Account(B) {}
	virtual void CalculateInterest() override {
		balance -= balance * 0.02;
	}
};
class FixedDepositAccount : public Account {
private:
	bool lock;
public:
	FixedDepositAccount(const double B) : Account(B), lock(true) {}
	virtual void CalculateInterest() override {
		balance += balance * 0.10;
		lock = false;
	}
	virtual void Deposit(double amount) override {
		if (!lock) {
			throw runtime_error("Limit");
		}
		balance += amount;
	}
	void SwitchLock() {
		lock = false;
	}
};

int main()
{
	Shape* shapes[] = {
		new Rectangle(5.0, 3.0),
		new Circle(2.5),
		new Triangle(4.0, 2.0)	
	};
	for (Shape* shape : shapes) {
		shape->Print();
		cout << endl;
		delete shape;
	}

	setlocale(LC_ALL, "Ukrainian");
	Animal* animals[] = {
		new Dog(),
		new Cat(),
		new Bird(),
	};
	for (Animal* animal : animals) {
		animal->MakeSound();
		animal->PrintInfo();
		cout << endl;
		delete animal;
	}

	const double balance = 500.0;
	Account* accounts[] = {
		new SavingsAccount(balance),
		new CheckingAccount(balance),
		new FixedDepositAccount(balance)
	};
	for (Account* account : accounts)
	{
		account->Deposit(500.0);
		account->CalculateInterest();
		cout << "Balance : " << account->GetBalance() << endl;
		delete account;
	}
}