#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include "PartTwo.h"
#include <cstdlib>


using namespace std;

Human::Human(string name, string surname)
{
	this->name = name;
	this->surname = surname;
}
Student::Student(string name, string surname, int count) :Human(name, surname)
{
	count_books = count;
}

void Book::setBook(string name, string surname, int year, string title, int count, int count_free)
{
	this->count = count;
	this->count_free = count_free;
	this->title = title;
	this->year = year;
	this->autor.name = name;
	this->autor.surname = surname;
}

Blank Blank::setBlank(Book* book_list, int count_book)
{
	cout << "¬и маЇтк всi данi про книгу? (“ак-1, Ќi-0)" << endl;
	int ans = 0, ans2=0;
	string s, s1; int year;
	Blank tmpBlank;
	char h;
	cin >> ans;
	if (ans == 0) {
		cout << "«а чим шукати? 0-назва, 1-автор, 2-рiк виданн€" << endl;
		cin >> ans2;
		if (ans2 == 0) { cout << "¬ведiть назву книги: "; cin.get(h); getline(cin, s);
		showSearch(s, book_list, 0, count_book); ans = 1;
		}
		if (ans2 == 1) {
			cout << "¬ведiть iм'€ автора: "; cin.get(h); getline(cin, s); cout << "¬ведiть прiзвище автора: "; getline(cin, s1);
			s += s1;
		showSearch(s, book_list, 1, count_book); ans = 1;
		}
		if (ans2 == 2) { cout << "¬ведiть рiк написанн€: "; cin >> year;
		showSearch(year, book_list, count_book); ans = 1;
		}
	}
	if (ans == 1) {
		
		string tempNameS, tempSurnameS, tempNameA, tempSurnameA, temptitle;
		int tmpstatus, tmpcountS, tmpyear, tmpcountA, tmpfree;
		cout << "¬ведiть iм'€ та прiзвище автора, рiк виданн€ книги, кiлькiсть книг, забраних книг, назву книги. (все вводити послiдовно через ентер) " << endl;
		cin >> tempNameA;  cin >> tempSurnameA;
		cin >> tmpyear;  cin >> tmpcountA; cin >> tmpfree;
		cin.get();
		getline(cin, temptitle);
		Book tmpbook;
		tmpbook.setBook(tempNameA, tempSurnameA, tmpyear, temptitle, tmpcountA, tmpfree);
		tmpBlank.book_to_give = tmpbook;
	}
	return tmpBlank;
}

void Blank::showSearch(string s, Book* book_list, int colon, int count_book)
{
	for (int i = 0; i < count_book; i++)
	{
		if (colon == 0) {
			if (book_list[i].title == s) { book_list[i].show_book(book_list[i]); }
		}
		if (colon == 1) {
			string a = book_list[i].autor.name;
			a+= book_list[i].autor.surname;
			if (a == s) {
				book_list[i].show_book(book_list[i]);
			}
		}
	}
}

void Blank::showSearch(int a, Book* book_list, int count_book)
{
	for (int i = 0; i < count_book; i++)
	{
		if (book_list[i].year == a) {
			book_list[i].show_book(book_list[i]);
		}
	}
}

void Shell<Book, Student, Blank >::setBookCatalog()
{
	ifstream inFile("BookData.txt");
	char h;
	inFile >> count_book;
	book_list = new Book[count_book*2+1];
	for (int i = 0; i < count_book; i++) {
		string tempName, tempSurname, temptitle;
		int tmpyear, tmpcount, tmpfree;
		inFile >> tempName;  inFile >> tempSurname;
		inFile >> tmpyear; inFile >> tmpcount; inFile >> tmpfree; 
		inFile.get(h);
		getline(inFile, temptitle);
		Book tmpbook;
		tmpbook.setBook(tempName, tempSurname, tmpyear,temptitle, tmpcount, tmpfree);
		book_list[i] = tmpbook;
	}
	inFile.close();
}

void Shell<Book, Student, Blank >::setStudentList()
{
	ifstream inFile("StudentData.txt");
	inFile >> count_student;
	string tempName, tempSurname;
	int tmpcount;
	student_list = new Student[count_student*2+1];
	for (int i = 0; i < count_student; i++) {
		inFile >> tempName; inFile >> tempSurname; inFile >> tmpcount;
		Student tmpstu(tempName, tempSurname, tmpcount);
		student_list[i] = tmpstu;
	}
	inFile.close();
}

void Shell<Book, Student, Blank >::setBlankList()
{
	ifstream inFile("BlankData.txt");
	inFile >> count_blank;
	string tempNameS, tempSurnameS, tempNameA, tempSurnameA, temptitle;
	char h;
	int tmpstatus, tmpcountS, tmpyear, tmpcountA, tmpfree;
	blank_list = new Blank [count_blank*2+1];
	for (int i = 0; i < count_blank; i++) {
		inFile >> tmpstatus;
		inFile >> tempNameS; inFile >> tempSurnameS; inFile >> tmpcountS;
		Student tmpstu(tempNameS, tempSurnameS, tmpcountS);
		inFile >> tempNameA; inFile >> tempSurnameA;
		inFile >> tmpyear; inFile >> tmpcountA; inFile >> tmpfree; inFile.get(h);
		getline(inFile, temptitle);
		Book tmpbook;
		tmpbook.setBook(tempNameA, tempSurnameA, tmpyear, temptitle, tmpcountA, tmpfree);
		blank_list[i].book_to_give = tmpbook;
		blank_list[i].student_to_look = tmpstu;
		blank_list[i].status = tmpstatus;
	}
	inFile.close();
}

void Book::show_book(Book boo)
{
	cout << boo.autor.name << " " << boo.autor.surname << ", " << boo.year << "p., '" << boo.title<<"', всього книг "<<boo.count<<" з них вз€то "<<boo.count_free << endl;
}

int  Shell<Book, Student, Blank >::findStudent()
{
	string tmpName, tmpSurname;
	cout << "¬ведiть вашi iм'€ та прiзвище (через ≈нтери)" << endl;
	cin >> tmpName; cin >> tmpSurname;
	for (int i = 0; i < count_student; i++)
	{
		if (student_list[i].name == tmpName && student_list[i].surname == tmpSurname)
		{
			return i;
		}
	}
	return -1;
}

int  Shell<Book, Student, Blank >::findBook(Book tmpbook)
{
	for (int i = 0; i < count_book; i++)
	{
		if (book_list[i].title == tmpbook.title && book_list[i].year == tmpbook.year &&
			book_list[i].autor.name == tmpbook.autor.name && book_list[i].autor.surname == tmpbook.autor.surname)
		{
			return i;
		}
	}
	return -1;
}

void Shell<Book, Student, Blank >::addNewBlank()
{
	blank_list[count_blank]=blank_list[count_blank].setBlank(book_list, count_book);
	int num = findStudent(), num1=findBook(blank_list[count_blank].book_to_give);
	blank_list[count_blank].student_to_look=student_list[num];
	if (student_list[num].count_books >= 10) {
		blank_list[count_blank].status = 2;
		cout << "\n нигу не видано, перевищено лiмiт!\n" << endl;
	}
	else {
		if (book_list[num1].count > book_list[num1].count_free) { 
			blank_list[count_blank].status = 0; 
			blank_list[count_blank].book_to_give.count_free++;
			book_list[num1].count_free++;
			student_list[num].count_books++; 
			blank_list[count_blank].student_to_look.count_books++;
			cout << "\n нигу видано!\n" << endl;}
		else 
		{	blank_list[count_blank].status = 1;
			cout << "\n нигу не видано, вона вiдсутн€ у бiблiотецi!\n" << endl;}
	}
	count_blank++;
}

void Shell<Book, Student, Blank > :: showNeed()
{
	cout << "¬иданi книги: " << endl;
	for (int i = 0; i < count_blank; i++)
	{
		if (blank_list[i].status == 0)
		{
			blank_list[i].book_to_give.show_book(blank_list[i].book_to_give);
		}
	}
	cout << " ниг не вистачило: " << endl;
	for (int i = 0; i < count_blank; i++)
	{
		if (blank_list[i].status == 1)
		{
			blank_list[i].book_to_give.show_book(blank_list[i].book_to_give);
		}
	}
}

void Shell<Book, Student, Blank > ::saveAll()
{
	ofstream outFile("BookData.txt");
	outFile << count_book << endl;
	for (int i = 0; i < count_book; i++) {
		outFile << book_list[i].autor.name << " " << book_list[i].autor.surname << " " << book_list[i].year 
			<< " " << book_list[i].count << " " << book_list[i].count_free << " " << book_list[i].title << endl;
	}
	outFile.close();
	outFile.open("StudentData.txt");
	outFile << count_student << endl;
	for (int i = 0; i < count_student; i++) {
		outFile << student_list[i].name <<" "<< student_list[i].surname<<" "<< student_list[i].count_books<<  endl;
	}
	outFile.close();
	outFile.open("BlankData.txt");
	outFile << count_blank<< endl;
	for (int i = 0; i < count_blank; i++) {
		outFile << blank_list[i].status << " " << blank_list[i].student_to_look.name << " " << blank_list[i].student_to_look.surname << " " <<
			blank_list[i].student_to_look.count_books << " " << blank_list[i].book_to_give.autor.name << " " <<
			blank_list[i].book_to_give.autor.surname << " " << blank_list[i].book_to_give.year << " " << blank_list[i].book_to_give.count << " " <<
			blank_list[i].book_to_give.count_free <<" "<< blank_list[i].book_to_give.title << endl;
	}
	outFile.close();
}