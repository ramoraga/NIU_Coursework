#include <iostream>
#include <iomanip>
#include <string>
#include <mysql.h>

using namespace std;

int main()
{
	MYSQL *mysql;
	MYSQL_RES *result;
	MYSQL_ROW row;
	mysql = mysql_init(NULL);
	char choice = 'N';
	
	cout << endl << "CONNECTING TO DATABASE..." << endl << endl;
	if (!mysql_real_connect(mysql, "courses", "anonymous", NULL, "henrybooks", 0, NULL, 0)) {
		cerr << "ERROR: Could not connect to Database!" << endl;
	}

	do {
		cout << "PLEASE CHOOSE AN OPTION (B:BOOK LIST, A:AUTHOR SEARCH, T:TITLE SEARCH, Q:QUIT): ";
		cin >> choice;

		if (choice == 'B' || choice == 'b') {
			mysql_query(mysql, "SELECT Book.Title, Author.AuthorFirst, Author.AuthorLast, Book.Price FROM Book JOIN Wrote ON Book.BookCode = Wrote.BookCode JOIN Author ON Author.AuthorNum = Wrote.AuthorNum");
			result = mysql_store_result(mysql);

			cout << endl << endl << "LIST OF BOOKS" << endl << "-------------" << endl;
			int LC = 0;
			int col = mysql_num_fields(result);
			while ((row = mysql_fetch_row(result))) {
				for (int i = 0; i < col; i++) {
					if (row[i] != NULL) {
						if (LC == 0) {
							cout << row[i] << ", ";
							LC++;	
						} else if (LC == 1) {
							cout << row[i] << " ";
							LC++;
						} else if (LC == 2) {
							cout << row[i] << ", $";
							LC++;
						} else {
							cout << row[i] << endl;
							LC = 0;
						}
					} else {
						cout << "NULL" << endl;
					}
				}
			}
			cout << endl;

			if (result != NULL) {
				mysql_free_result(result);
			}
		}

		if (choice == 'A' || choice == 'a') {
			string input;
			string Author;
			cout << endl << "WHAT IS THE FIRST OR LAST NAME OF THE AUTHOR?: ";
			cin >> input;

			Author = "SELECT Book.Title, Author.AuthorFirst, Author.AuthorLast, Book.Price FROM Book JOIN Wrote ON Book.BookCode = Wrote.BookCode JOIN Author ON Author.AuthorNum = Wrote.AuthorNum WHERE Author.AuthorLast = '" + input + "' OR Author.AuthorFirst = '" + input + "';";
			cout << endl << "SEARCHING FOR AUTHOR..." << endl << "-----------------------" <<  endl << endl;

			mysql_query(mysql, Author.c_str());
			result = mysql_store_result(mysql);
			
			int LC = 0;	
			int succ = 0;
			int col = mysql_num_fields(result);
			while ((row = mysql_fetch_row(result))) {
				for (int i = 0; i < col; i++) {
					if (row[i] != NULL) {
						if (LC == 0) {
							cout << row[i] << ", ";
							LC++;
							succ++;	
						} else if (LC == 1) {
							cout << row[i] << " ";
							LC++;
						} else if (LC == 2) {
							cout << row[i] << ", $";
							LC++;
						} else {
							cout << row[i] << endl;
							LC = 0;
						}
					} else {
						cout << "NULL" << endl;
					}
				}
			}
			cout << endl;

			if (succ == 0) {
				cout << "** ERROR: NAME WAS NOT FOUND **" << endl << endl << endl;
			}

			if (result != NULL) {
				mysql_free_result(result);
			}
		}

		if (choice == 'T' || choice == 't') {
			string input;
			string Title;
			cout << endl << "WHAT IS THE TITLE OF THE BOOK?: ";
			cin.ignore();
			getline(cin, input);

			Title = "SELECT Book.Title, Author.AuthorFirst, Author.AuthorLast, Book.Price FROM Author JOIN Wrote ON Author.AuthorNum = Wrote.AuthorNum JOIN Book ON Book.BookCode = Wrote.BookCode WHERE Book.Title = '" + input + "';";
			cout << endl << "SEARCHING FOR TITLE..." << endl << "----------------------" <<  endl << endl;

			mysql_query(mysql, Title.c_str());
			result = mysql_store_result(mysql);
			
			int LC = 0;	
			int succ = 0;
			int col = mysql_num_fields(result);
			while ((row = mysql_fetch_row(result))) {
				for (int i = 0; i < col; i++) {
					if (row[i] != NULL) {
						if (LC == 0) {
							cout << row[i] << ", ";
							LC++;
							succ++;	
						} else if (LC == 1) {
							cout << row[i] << " ";
							LC++;
						} else if (LC == 2) {
							cout << row[i] << ", $";
							LC++;
						} else {
							cout << row[i] << endl;
							LC = 0;
						}
					} else {
						cout << "NULL" << endl;
					}
				}
			}
			cout << endl;

			if (succ == 0) {
				cout << "** ERROR: TITLE WAS NOT FOUND **" << endl << endl << endl;
			}

			if (result != NULL) {
				mysql_free_result(result);
			}
		}

	}
	while (choice != 'Q' && choice != 'q');

	mysql_close(mysql);
	return 0;
}
