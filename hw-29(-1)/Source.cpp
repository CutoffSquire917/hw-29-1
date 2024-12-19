#include <iostream>
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




	//�������� 2: ������� � ��������
	//��������� ������� ��� ����� ������ � ��������.
	//������� ���� Animal:
	//̳����� ���������� ����� MakeSound() ��� ���������� �����.
	//̳����� ���������� ����� PrintInfo() ��� ��������� ���������� ��� �������.
	
	//�����-�������:
	//Dog: ������ ������ MakeSound() (�������� "���!") �� PrintInfo() (�������� "�� ������.").
	//Cat: ������ ������ MakeSound() (�������� "���!") �� PrintInfo() (�������� "�� ��.").
	//Bird: ������ ������ MakeSound() (�������� "�����!") �� PrintInfo() (�������� "�� ����.").
	
	//� main ������� ������ � �������� ������ ����� ���� (����� ��������� �� Animal). ������ �����
	//� ��� �����, ��� ���� "��������" (MakeSound()) � ������ ���������� ��� ���� (PrintInfo()).


	//�������� 3: ������� � �����
	//������� ������� ��� ����� ����� ���� ���������� �������.
	//������� ���� Account:
	//�� ���� balance ��� ��������� ������� �� �������.
	//̳����� ���������� ����� CalculateInterest() ��� ���������� ��������.
	//̳����� ����� Deposit(double amount) ��� ���������� �������.
	
	//�����-�������:
	//SavingsAccount: ���� ���������� ������� (���������, 5%) �� ������� � ����� CalculateInterest().
	//CheckingAccount: �� ���� ��������, ��� ����� ����� �� �������������� (���������, 2% ��
	//�������).
	//FixedDepositAccount: ���� ����� ������� (���������, 10%), ��� �� �������� ������ ����� ��
	//������� ���� (����� ������� ���� ������� ��� ����� ����� �����).
	
	//� main ������� ����� � �������� ������� ����� ����. �������� ���������� (Deposit()),
	//�������� �������� (CalculateInterest()), �� ������� ���� ������� �������.
}