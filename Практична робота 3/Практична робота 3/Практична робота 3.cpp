//Створіть текстовий файл на ім’я data.txt, с довільною кількістю рядків, але не меньше 10 зі студентами та їх оцінками з трьох предметів :
//математики, фізики, інформатики.Формат файлу : кожний рядок містить прізвище, ім'я та три числа. Дані в рядку розділені одним пробілом або
//символом «Tab».Оцінки приймають значення від 1 до 5.

//Створити масив екземплярів класу та зчитати дані з файлу data.txt для визначення відповідних полів.Виконати завдання відповідно варіанту.

//Визначте середній бал кожного студента зі всіх предметів. Виведіть три дійсні числа : середній бал усіх студентів за
//зростанням.


#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Student { // початок оголошення класу
private:
	string surname; // прізвище студента
	float math, ph, inf, all; // бали
public:
	void SetSMPI(string surname, float math, float ph, float inf) {
		this->surname = surname;
		this->math = math;
		this->ph = ph;
		this->inf = inf;
	}
	void SetAll(float all) {
		this->all = all;
	}
	string GetName() {
		return surname;
	}
	float GetAll() {
		return all;
	}
	void Print1() {
		cout << surname << "\t" << math << "\t" << ph << "\t" << inf << endl;
	}
	void Print2() {
		cout << surname << "\t" << all << endl;
	}
};
int main() {
	setlocale(LC_ALL, "ukr");
	int kilkist = 0;
	string str;
	ifstream fin("data.txt"); // створення потоку читання файлу
	if (fin) {
		while (!fin.eof()) { // поки не кінець файлу
			getline(fin, str, '\n'); // зчитуємо рядок
			kilkist++; // підраховуємо кількість рядків
		}
		Student* P = new Student[kilkist]; // створюється масив об’єктів (екземплярів класу Student)
			fin.clear(); // скидання прапорця "кінець файлу"
		fin.seekg(0); // позиція каретки на початок файлу
		for (int i = 0; i < kilkist; i++) {
			string name;
			float a, b, c;
			fin >> name; // читання прізвища i-го студента з файлу
			fin >> a; // читання бала математики i-го студента з файлу
			fin >> b; // читання бала фізики i-го студента з файлу
			fin >> c; // читання бала інформатики i-го студента з файлу
			P[i].SetSMPI(name, a, b, c);
			P[i].SetAll((a + b + c) / 3);
		}
		cout << "Студент\t\tМатем.\tФiзика\tIнформатика" << endl;
		for (int i = 0; i < kilkist; i++) P[i].Print1();
		cout << endl;
		cout << "Студент\t\tСереднiй бал" << endl;
		for (int i = 0; i < kilkist - 1; i++) // сортування за зростанням
			for (int j = i + 1; j < kilkist; j++)
				if (P[i].GetAll() > P[j].GetAll()) {
					swap(P[i], P[j]); // міняємо місцями P[i]та P[j]
				}
		for (int i = 0; i < kilkist; i++) P[i].Print2(); // вивід списку за зростання середнього балу
			fin.close(); // закриття потоку
		delete[]P; // звільнення динамічної пам’яті
	}
	else cout << "Не вдалось вiдкрити файл!";
	return 0;
}
