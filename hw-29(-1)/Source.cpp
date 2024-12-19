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




	//Завдання 2: Тварини у зоопарку
	//Реалізуйте систему для опису тварин у зоопарку.
	//Базовий клас Animal:
	//Містить віртуальний метод MakeSound() для відтворення звуку.
	//Містить віртуальний метод PrintInfo() для виведення інформації про тварину.
	
	//Класи-нащадки:
	//Dog: реалізує методи MakeSound() (виводить "Гав!") та PrintInfo() (виводить "Це собака.").
	//Cat: реалізує методи MakeSound() (виводить "Мяу!") та PrintInfo() (виводить "Це кіт.").
	//Bird: реалізує методи MakeSound() (виводить "Цвірінь!") та PrintInfo() (виводить "Це птах.").
	
	//У main створіть список з декількох тварин різних типів (через вказівники на Animal). Зробіть кожну
	//з них такою, щоб вона "озвалася" (MakeSound()) і вивела інформацію про себе (PrintInfo()).


	//Завдання 3: Рахунок у банку
	//Створіть систему для обліку різних типів банківських рахунків.
	//Базовий клас Account:
	//Має поле balance для зберігання залишку на рахунку.
	//Містить віртуальний метод CalculateInterest() для обчислення процентів.
	//Містить метод Deposit(double amount) для поповнення рахунку.
	
	//Класи-нащадки:
	//SavingsAccount: додає фіксований процент (наприклад, 5%) до балансу в методі CalculateInterest().
	//CheckingAccount: не додає процентів, але стягує комісію за обслуговування (наприклад, 2% від
	//балансу).
	//FixedDepositAccount: додає вищий процент (наприклад, 10%), але не дозволяє знімати гроші до
	//певного часу (можна вивести лише помилку при спробі зняти гроші).
	
	//У main створіть масив з декількох рахунків різних типів. Проведіть поповнення (Deposit()),
	//обчисліть проценти (CalculateInterest()), та виведіть стан кожного рахунку.
}