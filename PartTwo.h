#pragma once
#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;
class Human
{
public:
	Human(string name, string surname);
	Human() {};
	~Human() {};
	string name;
	string surname;
};

class Autor :public Human
{
public:
	Autor(string name, string surname) :Human(name, surname) {};
	Autor() :Human() {};
private:
};


class Student :public Human
{
public:
	Student(string name, string surname, int count);
	Student() {};
	int count_books;
};

class Book
{
public:
	Book() {};
	void setBook(string name, string surname, int year, string title, int count, int count_free);
	Autor autor;
	int year;
	string title;
	int count;
	int count_free;
	void show_book(Book boo);
};


template <class T1, class T2, class T3>
class Shell
{
public:
	Shell() {};
	int count_book;
	int count_student;
	int count_blank; 
	T1* book_list;
	T3* blank_list;
	T2* student_list;
	void setBookCatalog();
	void setStudentList();
	void setBlankList();
	void addNewBlank();
	int findStudent();
	int findBook(Book tmpbook);
	void showNeed();
	void saveAll();
};

class Blank 
{
public:
	Blank() {};
	int status; //0-видано, 1-немає в бібліотеці, 2-відмовлено
	Book book_to_give;
	Student student_to_look;
	Blank setBlank(Book* book_list, int count_book);
	void showSearch(string s, Book* book_list, int colon, int count_book);
	void showSearch(int a, Book* book_list, int count_book);
};

template <>class Shell < Book, Student, Blank >
{
public:
	Shell() {};
	int count_book;
	int count_student;
	int count_blank; 
	Book* book_list;
	Blank* blank_list;
	Student* student_list;
	void setBookCatalog();
	void setStudentList();
	void setBlankList();
	void addNewBlank();
	int findStudent();
	int findBook(Book tmpbook);
	void showNeed();
	void saveAll();
};