#include <iostream>
#include <cstring>
using namespace std;

class Book
{
private:
	char* title;
	char* isbn;
	int price;
public:
	Book(char* booktitle, char* bookisbn, int bookprice)
		: price(bookprice)
	{
		title = new char[strlen(booktitle) + 1];
		strcpy(title, booktitle);
		isbn = new char[strlen(bookisbn) + 1];
		strcpy(isbn, bookisbn);
	}

	Book(const Book& ref)
		: price(ref.price)
	{
		title = new char[strlen(ref.title) + 1];
		strcpy(title, ref.title);

		isbn = new char[strlen(ref.isbn) + 1];
		strcpy(isbn, ref.isbn);
	}

	Book& operator=(const Book& ref)
	{
		if (title != NULL)
			delete []title;
		title = new char[strlen(ref.title) + 1];
		strcpy(title, ref.title);

		if (isbn != NULL)
			delete []isbn;
		isbn = new char[strlen(ref.isbn) + 1];
		strcpy(isbn, ref.isbn);

		price = ref.price;
		return *this;
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
	char* DRMKey;
public:
	EBook(char* title, char* isbn, int price, char* bookDRMKey)
		: Book(title, isbn, price)
	{
		DRMKey = new char[strlen(bookDRMKey) + 1];
		strcpy(DRMKey, bookDRMKey);
	}

	EBook(const EBook& ref)
		: Book(ref)
	{
		DRMKey = new char[strlen(ref.DRMKey) + 1];
		strcpy(DRMKey, ref.DRMKey);
	}

	EBook& operator=(const EBook& ref)
	{
		Book::operator=(ref);
		if (DRMKey != NULL)
			delete []DRMKey;
		DRMKey = new char[strlen(ref.DRMKey) + 1];
		strcpy(DRMKey, ref.DRMKey);
		return *this;
	}

	void ShowEBookInfo()
	{
		ShowBookInfo();
		cout << "DRMKey: " << DRMKey << endl;
	}
};


int main()
{
	Book book1("Good C++", "555-12345-890-0", 20000);
	Book book2 = book1;
	book2.ShowBookInfo();
	cout << endl;

	Book book3("Goodbye C++", "000-11111-222-3", 5000);
	book3.ShowBookInfo();
	cout << endl;

	book3 = book2;
	book3.ShowBookInfo();
	cout << endl;

	EBook ebook1("Good C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
	EBook ebook2 = ebook1;
	ebook2.ShowEBookInfo();
	cout << endl;

	EBook ebook3("Goodbye C++ ebook", "000-11111-222-3", 5000, "lf4kl3hn3kjx8");
	ebook3.ShowEBookInfo();
	cout << endl;

	ebook3 = ebook2;
	ebook3.ShowEBookInfo();

	return 0;
}
