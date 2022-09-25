//Створити клас «квадрат», такий, що:
//а) його екземпляр містить розмір сторони квадрата.
//b) його конструктор без параметра створює екземпляр зі значенням 0, а конструктор з параметрами створює екземпляр з відповідним значенням сторони.
//c) його методи дозволяють отримувати і присвоювати значення сторони і обчислювати значення площі.
//d) функція print_sqr() виводить на екран значення його сторони і площі.
//e) дружня функція frd в якості параметрів отримує екземпляри двох квадратів і повертає новий квадрат, площа якого дорівнює сумі площ
//цих двох квадратів. Значення сторони нового квадрата має бути перераховане.
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <locale.h>

using namespace std;
class Square
{
private:
	float side, area;
	float print_sqr();
public:
    Square();
	Square(float);
	~Square();

	void setS(float);
	float getS();
	friend Square frd(Square, Square);
};

Square::Square() //конструктор без параметрів 
{
	side = 15;
	
}

Square::Square(float side) //конструктор з параметрами 
{
	this->side = side;

}

float Square::print_sqr()
{

	area = pow(side, 2);

	cout << "Довжина сторони квадрата " << side << "\n" << "Площа " << area << "\n" << endl;

	return area;
}

Square::~Square() //деструктор
{

}

void Square::setS(float side)
{
	side = side;
}

float Square::getS()
{
	return side;
}

Square frd(Square side, Square area) //дружня функція 
{
	float newArea = side.print_sqr() + area.print_sqr();
	float newSide = sqrt(newArea);
	cout << "Новий  квадрат" << endl;
	cout << "Довжина сторони квадрата " << newSide << "\n" << "Площа даної фiгури " << newArea << "\n" << endl;
	Square newSquare(newSide);
	return newSquare;

}


int main()
{
	setlocale(LC_ALL, "Ukrainian");
	Square side1;
	Square side2(10);
	Square side1_side2 = frd(side1, side2);
}