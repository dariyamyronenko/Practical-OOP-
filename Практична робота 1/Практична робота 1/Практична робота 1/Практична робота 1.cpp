//Створити клас «смайлик», такий, що:
//а) його екземпляр містить розмір радіуса особи R і радіуса r очей.
//b) його конструктор без параметра створює екземпляр зі значенням 0, а
//конструктор з параметрами створює екземпляр з відповідним значенням
//R і r.
//c) його методи дозволяють отримувати і присвоювати значення R і r і
//обчислювати значення площі.
//d) функція print_sqrt () виводить на екран значення її R, r площі (без площі
//очей)

#include <iostream>
#include <cmath>
using namespace std;

class Smile {
private:
    double R;
    double r;
    float M_PI = 3.14;

public:

    //сеттери для обличчя 
    void setFaceR(double RValue) {
        R = RValue;
    }

    void setFaceRSquare(double S) {
        R = sqrt(S / M_PI);
    }

    //сеттери для очей 
    void setEyer(double rValue) {
        r = rValue;
    }

    void setEyerSquare(double S) {
        r = sqrt(S / M_PI);
    }

    //геттери для обличчя
    double getFaceR() {
        return R;
    }

    double getFaceSquare() {
        return M_PI * R * R;
    }

    //геттери для очей
    double getEyer() {
        return r;
    }
    double getEyeSquare() {
        return M_PI * r * r;
    }

    Smile() { //Конструктор без параметрів
        R = r = 0.0;
    }

    Smile(double R, double r) { //Конструктор з параметрами
        setFaceR(R);
        setEyer(r);
    }

    void print_sqrt() { //Вивід на екран площі обличчя
        cout << M_PI * R * R << "\n";
    }
};

int main()
{
    Smile *p = new Smile();
    p->setFaceRSquare(60);
    cout << fixed;
    cout.precision(2);
    cout << p->getFaceR() << "\n"; //Вивід на екран радіусу обличчя
    p->setEyerSquare(30);
    cout << p->getEyer() << "\n"; //Вивід на екран радіусу очей
    p->print_sqrt();

    return 0;
}

