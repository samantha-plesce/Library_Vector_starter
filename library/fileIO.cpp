#include "../includes_usr/fileIO.h"
#include "../includes_usr/constants.h"
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
/* clears, then loads books from the file filename
 * returns  COULD_NOT_OPEN_FILE if cannot open filename
 * 			NO_BOOKS_IN_LIBRARY if there are 0 entries in books
 * 			SUCCESS if all data is loaded
 * */
int loadBooks(vector<book> &books, const char* filename)
{
	books.clear();
	ifstream file;
	file.open(filename, ios::in);
	if (!file.is_open()) {return COULD_NOT_OPEN_FILE;}

	string line = "";
	while (getline(file,line)){
		book booki;
		string title, author, b_id, patron_num;
		int convert = 0;

		stringstream ss(line);

		getline(ss, title, ',');
		booki.title = title;
		getline(ss, author, ',');
		booki.author = author;
		getline(ss, b_id, ',');
		booki.book_id = convert;
		getline(ss, patron_num, ',');
		booki.loaned_to_patron_id = convert;

		books.push_back(booki);

	}
	if (books.empty()) {return NO_BOOKS_IN_LIBRARY;}
	else {return SUCCESS;}
	file.close();
}

/* serializes books to the file filename
 * returns  COULD_NOT_OPEN_FILE if cannot open filename
 * 			NO_BOOKS_IN_LIBRARY if there are 0 entries books (do not create file)
 * 			SUCCESS if all data is saved
 * */
int saveBooks(std::vector<book> &books, const char* filename)
{
	books.clear();
	ifstream file;
	file.open(filename, ios::in);
	if (!file.is_open()) {return COULD_NOT_OPEN_FILE;}

	string line = "";
	while (getline(file,line)){
		book booki;
		string title, author, b_id, patron_num;
		int convert = 0;

		stringstream ss(line);

		getline(ss, title, ',');
		booki.title = title;
		getline(ss, author, ',');
		booki.author = author;
		getline(ss, b_id, ',');
		booki.book_id = convert;
		getline(ss, patron_num, ',');
		booki.loaned_to_patron_id = convert;

		//file << title, author, b_id, patron_num >> endl;

	}
	if (books.empty()) {return NO_BOOKS_IN_LIBRARY;}
	else {return SUCCESS;}
	file.close();
}

/* clears, then loads patrons from the file filename
 * returns  COULD_NOT_OPEN_FILE if cannot open filename
 * 			NO_PATRONS_IN_LIBRARY if there are 0 entries in patrons
 * 			SUCCESS if all data is loaded
 * */
int loadPatrons(std::vector<patron> &patrons, const char* filename)
{
	patrons.clear();
	ifstream file;
	file.open(filename, ios::in);
	if (!file.is_open()) {return COULD_NOT_OPEN_FILE;}

	string line = "";
	while (getline(file,line)){
		patron patroni;
		string pat_id, name, num_b_out;
		int convert = 0;

		stringstream ss(line);

		getline(ss, pat_id, ',');
		patroni.patron_id = convert;
		getline(ss, name, ',');
		patroni.name = name;
		getline(ss, num_b_out, ',');
		patroni.number_books_checked_out = convert;

		patrons.push_back(patroni);

	}
	if (patrons.empty()) {return NO_PATRONS_IN_LIBRARY;}
	else {return SUCCESS;}
	file.close();
}


/* serializes patrons to the file filename
 * returns  COULD_NOT_OPEN_FILE if cannot open filename
 * 			NO_PATRONS_IN_LIBRARY if there are 0 entries in patrons  (do not create file)
 * 			SUCCESS if all data is saved
 * */
int savePatrons(std::vector<patron> &patrons, const char* filename)
{
	patrons.clear();
	ifstream file;
	file.open(filename, ios::in);
	if (!file.is_open()) {return COULD_NOT_OPEN_FILE;}

	string line = "";
	while (getline(file,line)){
		patron patroni;
		string pat_id, name, num_b_out;
		int convert = 0;

		stringstream ss(line);

		getline(ss, pat_id, ',');
		patroni.patron_id = convert;
		getline(ss, name, ',');
		patroni.name = name;
		getline(ss, num_b_out, ',');
		patroni.number_books_checked_out = convert;

		//file << pat_id, name, num_b_out;

	}
	if (patrons.empty()) {return NO_PATRONS_IN_LIBRARY;}
	else {return SUCCESS;}
	file.close();
}

