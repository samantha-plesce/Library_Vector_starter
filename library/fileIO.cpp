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
	file.open(filename);
	if (!file.is_open()){
		return COULD_NOT_OPEN_FILE;
	}

	string line = "";
	while (getline(file,line)){
		book booki;
		string title, author, b_id, patron_num, status;
		int num1 =0, num2 = 0;

		stringstream ss(line);

		getline(ss, b_id, ',');
		booki.book_id = stoi(b_id);
		getline(ss, title, ',');
		booki.title = title;
		getline(ss, author, ',');
		booki.author = author;
		getline(ss, status, ',');
		num1 = stoi(status);
		switch (num1){
		case 0:
			booki.state= UNKNOWN;
			break;
		case 1:
			booki.state = IN;
			break;
		case 2:
			booki.state = OUT;
			break;
		}
		getline(ss, patron_num, ',');
		booki.loaned_to_patron_id = stoi(patron_num);

		books.push_back(booki);

	}
	file.close();
	if (books.empty()){
		return NO_BOOKS_IN_LIBRARY;
	}
	return SUCCESS;
}

/* serializes books to the file filename
 * returns  COULD_NOT_OPEN_FILE if cannot open filename
 * 			NO_BOOKS_IN_LIBRARY if there are 0 entries books (do not create file)
 * 			SUCCESS if all data is saved
 * */
int saveBooks(std::vector<book> &books, const char* filename)
{
	int i = 0;
	fstream file;
	file.open(filename, ios_base::out);
	if (!file.is_open()) {
		return COULD_NOT_OPEN_FILE;
	}

	while (i < books.size()){
		file << books[i].book_id << "," << books[i].title << "," << books[i].author << "," << books[i].state <<"," << books[i].loaned_to_patron_id << endl;
		i ++;
	}
	file.close();
	if (books.empty()){
		return NO_BOOKS_IN_LIBRARY;
	}
	return SUCCESS;
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
	file.open(filename);
	if (!file.is_open()){
		return COULD_NOT_OPEN_FILE;
	}

	string line;
	while (getline(file,line)){
		patron patroni;
		string pat_id, name, num_b_out;

		stringstream ss(line);

		getline(ss, pat_id, ',');
		patroni.patron_id = stoi(pat_id);
		getline(ss, name, ',');
		patroni.name = name;
		getline(ss, num_b_out, ',');
		patroni.number_books_checked_out = stoi(num_b_out);

		patrons.push_back(patroni);

	}
	file.close();
	if (patrons.empty()){
		return NO_PATRONS_IN_LIBRARY;
	}
	return SUCCESS;
}


/* serializes patrons to the file filename
 * returns  COULD_NOT_OPEN_FILE if cannot open filename
 * 			NO_PATRONS_IN_LIBRARY if there are 0 entries in patrons  (do not create file)
 * 			SUCCESS if all data is saved
 * */
int savePatrons(std::vector<patron> &patrons, const char* filename)
{
	int i = 0;
	fstream file;
	file.open(filename, ios_base::out);
	if (!file.is_open()) {
		return COULD_NOT_OPEN_FILE;
	}

	while (i < patrons.size()){
		file << patrons[i].patron_id << "," << patrons[i].name << ","<< patrons[i].number_books_checked_out << endl;
		i ++;
	}
	file.close();
	if (patrons.empty()){
		return NO_PATRONS_IN_LIBRARY;
	}
	return SUCCESS;
}


