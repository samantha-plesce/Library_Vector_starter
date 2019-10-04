#include "../includes_usr/fileIO.h"
#include "../includes_usr/constants.h"
#include <fstream>
#include <sstream>
#include <cstring>
#include <iostream>
#include <fstream>
using namespace std;
/* clears, then loads books from the file filename
 * returns  COULD_NOT_OPEN_FILE if cannot open filename
 * 			NO_BOOKS_IN_LIBRARY if there are 0 entries in books
 * 			SUCCESS if all data is loaded
 * */
int loadBooks(vector<book> &books, const char* filename)
{
	//http://www.cplusplus.com/forum/beginner/93003/
	books.clear();
	ofstream file(filename);
	file.open(filename.c_str()); //what ios
	if (!file.is_open())
	{
		return COULD_NOT_OPEN_FILE;
	}
	if (file.is_open())
	{
		cout << "file opened successfully" << endl;
		if (file.good()){
			//for each element in the vector
			for (i=0; i < books.size(); i++0)
			{
				if books == 0
						return NO_BOOKS_IN_LIBRARY;
				else
					return SUCCESS;
			}
		}
	}
	file.close();
}

/* serializes books to the file filename
 * returns  COULD_NOT_OPEN_FILE if cannot open filename
 * 			NO_BOOKS_IN_LIBRARY if there are 0 entries books (do not create file)
 * 			SUCCESS if all data is saved
 * */
int saveBooks(std::vector<book> &books, const char* filename)
{
	fstream os(filename, ios:binary);
	if(!os.is_open()){
		cout << "error opening filename for write"<<endl; //delete later, https://cboard.cprogramming.com/cplusplus-programming/143556-serializing-vector.html
		return COULD_NOT_OPEN_FILE;
	}
	os.write((char*)&books, sizeof(books));
	os.close();
	//reading from it
	ifstream is(filename, ios::binary);
	if
	return SUCCESS;
}

/* clears, then loads patrons from the file filename
 * returns  COULD_NOT_OPEN_FILE if cannot open filename
 * 			NO_PATRONS_IN_LIBRARY if there are 0 entries in patrons
 * 			SUCCESS if all data is loaded
 * */
int loadPatrons(std::vector<patron> &patrons, const char* filename)
{
	return SUCCESS;
}

/* serializes patrons to the file filename
 * returns  COULD_NOT_OPEN_FILE if cannot open filename
 * 			NO_PATRONS_IN_LIBRARY if there are 0 entries in patrons  (do not create file)
 * 			SUCCESS if all data is saved
 * */
int savePatrons(std::vector<patron> &patrons, const char* filename)
{
	return SUCCESS;
}
