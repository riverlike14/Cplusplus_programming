#include <iostream>
#include <cstring>
using namespace std;

class Book
{
private:
	char title[50];
	char isbn[50];
	int price;

public:
	Book(char* booktitle, char* bookisbn, int bookprice)
		: price(bookprice)
	{
		strcpy(title, booktitle);
		strcpy(isbn, bookisbn);
	}

	void ShowBookInfo()
	{
		cout << "Title: " << title << endl;
		cout << "ISBN: " << isbn << endl;
		cout << "Price: " << price << endl;
	}
};

class EBook : public Book
{
private:
	char DRMKey[50];

public:
	EBook(char* title, char* isbn, int price, char* bookDRMKey)
		: Book(title, isbn, price)
	{
		strcpy(DRMKey, bookDRMKey);
	}

	void ShowEBookInfo()
	{
		ShowBookInfo();
		cout << "DRMKey: " << DRMKey << endl;
	}
};


int main()
{
	Book book("Good C++", "555-12345-890-0", 20000);
	book.ShowBookInfo();
	cout << endl;

	EBook ebook("Good C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
	ebook.ShowEBookInfo();

	return 0;
}
