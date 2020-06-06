#include <iostream>
#include <cmath>
#include <iomanip>
#include "PartTwo.h"
#include "PartOne.h"

using namespace std;

void ShowB1();
void ShowC2();

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Шульц Софiя, IП-96, варiант 26" << endl << endl;
	ShowB1();
	//ShowC2();
}

void ShowB1()
{
	cout << "Перша частина, рiвень Б (та на +1 бал)" << endl << endl;
	int ans = 1;
	while (ans == 1)
	{
		float numer = 1;
		while (!(numer < 1 && numer > -1)) {
			cout << "Введiть х для розрахункiв: " << endl;
			cin >> numer;
		}
		Arcsin my1(numer);
		Function& my3 = my1;
		float n = my3.calculate();
		cout << "Arcsin: " << n << endl;
		Arccos my2(numer);
		Function& my4 = my2;
		float m = my4.calculate();
		cout << "Arccos: " << m << endl;
		cout << "Чи бажаєте продовжити? Так-1, Ні-0 " << endl;
		cin >> ans;
	}
}

void ShowC2()
{
	cout <<endl<< "Друга частина, рівень В" << endl << endl;
	int ans = 1;
	while (ans == 1)
	{
		Shell<Book, Student, Blank> biblio;
		biblio.setBookCatalog();
		biblio.setStudentList();
		biblio.setBlankList();
		biblio.addNewBlank();
		biblio.showNeed();
		biblio.saveAll();
		cout << "Чи бажаєте продовжити? Так-1, Ні-0 " << endl;
		cin >> ans;
	}
}
