#include <iostream>
#include <string>

using namespace std;

// Base class: Book
class Book
{
public:
    string title;
    string author;
    string Sno;

public:
    Book(const string &title, const string &author, const string &Sno)
        : title(title), author(author), Sno(Sno) {}

    virtual void printDetails() const = 0;
};

// Derived class: Textbook
class Textbook : public Book
{
private:
    string subject;

public:
    Textbook(const string &title, const string &author, const string &Sno, const string &subject)
        : Book(title, author, Sno), subject(subject) {}

    void printDetails() const override
    {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Serialnumber: " << Sno << endl;
        cout << "Subject: " << subject << endl;
    }
};

// Derived class: Novel
class Novel : public Book
{
private:
    string genre;

public:
    Novel(const string &title, const string &author, const string &Sno, const string &genre)
        : Book(title, author, Sno), genre(genre) {}

    void printDetails() const override
    {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Serialnumber: " << Sno << endl;
        cout << "Genre: " << genre << endl;
    }
};

// Base class: LibMember
class LibMember
{
protected:
    int memberId;
    string name;
    string address;
    string phone;

public:
    LibMember(int memberId, const string &name, const string &address, const string &phone)
        : memberId(memberId), name(name), address(address), phone(phone) {}

    virtual void printDetails() const = 0;
};

// Derived class: stdMember
class stdMember : public LibMember
{
private:
    int maxBooks;

public:
    stdMember(int memberId, const string &name, const string &address, const string &phone)
        : LibMember(memberId, name, address, phone), maxBooks(5) {}

    void printDetails() const override
    {
        cout << "Member ID: " << memberId << endl;
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Phone: " << phone << endl;
        cout << "Maximum Books Allowed: " << maxBooks << endl;
    }
};

// Derived class: FacultyMember
class FacultyMember : public LibMember
{
private:
    int maxBooks;

public:
    FacultyMember(int memberId, const string &name, const string &address, const string &phone)
        : LibMember(memberId, name, address, phone), maxBooks(10) {}

    void printDetails() const override
    {
        cout << "Member ID: " << memberId << endl;
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Phone: " << phone << endl;
        cout << "Maximum Books Allowed: " << maxBooks << endl;
    }
};

// Transaction class
class Transaction
{
private:
    Book *book;
    LibMember *member;
    string dueDate;

public:
    Transaction() : book(nullptr), member(nullptr), dueDate("") {}

    Transaction(Book *book, LibMember *member, const string &dueDate)
        : book(book), member(member), dueDate(dueDate) {}

    Book *getBook() const
    {
        return book;
    }

    LibMember *getMember() const
    {
        return member;
    }

    string getDueDate() const
    {
        return dueDate;
    }
};

// Library class
class Library
{
private:
    static const int MAX_BOOKS = 100;
    static const int MAX_MEMBERS = 100;
    static const int MAX_TRANSACTIONS = 100;

    Book *books[MAX_BOOKS];
    LibMember *members[MAX_MEMBERS];
    Transaction transactions[MAX_TRANSACTIONS];

    int numBooks;
    int numMembers;
    int numTransactions;

    int findBookIndex(Book *book) const
    {
        for (int i = 0; i < numBooks; ++i)
        {
            if (books[i] == book)
            {
                return i;
            }
        }
        return -1;
    }

    int findMemberIndex(LibMember *member) const
    {
        for (int i = 0; i < numMembers; ++i)
        {
            if (members[i] == member)
            {
                return i;
            }
        }
        return -1;
    }

    int findTransactionIndex(Book *book, LibMember *member) const
    {
        for (int i = 0; i < numTransactions; ++i)
        {
            if (transactions[i].getBook() == book && transactions[i].getMember() == member)
            {
                return i;
            }
        }
        return -1;
    }

public:
    Library()
        : numBooks(0), numMembers(0), numTransactions(0) {}

    void addBook(Book *book)
    {
        if (numBooks < MAX_BOOKS)
        {
            books[numBooks++] = book;
            cout << "Book added successfully." << endl;
        }
        else
        {
            cout << "Cannot add more books. Maximum limit reached." << endl;
        }
    }

    void removeBook(Book *book)
    {
        int index = findBookIndex(book);
        if (index != -1)
        {
            // Shift the books array to remove the book
            for (int i = index; i < numBooks - 1; ++i)
            {
                books[i] = books[i + 1];
            }
            numBooks--;
            cout << "Book removed successfully." << endl;
        }
        else
        {
            cout << "Book not found." << endl;
        }
    }

    void addMember(LibMember *member)
    {
        if (numMembers < MAX_MEMBERS)
        {
            members[numMembers++] = member;
            cout << "Member added successfully." << endl;
        }
        else
        {
            cout << "Cannot add more members. Maximum limit reached." << endl;
        }
    }

    void removeMember(LibMember *member)
    {
        int index = findMemberIndex(member);
        if (index != -1)
        {
            for (int i = index; i < numMembers - 1; ++i)
            {
                members[i] = members[i + 1];
            }
            numMembers--;
            cout << "Member removed successfully." << endl;
        }
        else
        {
            cout << "Member not found." << endl;
        }
    }

    void borrowBook(LibMember *member, Book *book, const string &dueDate)
    {
        int memberIndex = findMemberIndex(member);
        int bookIndex = findBookIndex(book);

        if (memberIndex != -1 && bookIndex != -1)
        {
            if (numTransactions < MAX_TRANSACTIONS)
            {
                Transaction transaction(book, member, dueDate);
                transactions[numTransactions++] = transaction;
                cout << "Book borrowed successfully." << endl;
            }
            else
            {
                cout << "Cannot perform the borrowing operation. Maximum transaction limit reached." << endl;
            }
        }
        else
        {
            cout << "Member or book not found." << endl;
        }
    }

    void returnBook(Book *book, LibMember *member)
    {
        int transactionIndex = findTransactionIndex(book, member);
        if (transactionIndex != -1)
        {
            for (int i = transactionIndex; i < numTransactions - 1; ++i)
            {
                transactions[i] = transactions[i + 1];
            }
            numTransactions--;
            cout << "Book returned successfully." << endl;
        }
        else
        {
            cout << "Transaction not found." << endl;
        }
    }

    void printAllBooks() const
    {
        for (int i = 0; i < numBooks; ++i)
        {
            books[i]->printDetails();
            cout << endl;
        }
    }

    void printAllMembers() const
    {
        for (int i = 0; i < numMembers; ++i)
        {
            members[i]->printDetails();
            cout << endl;
        }
    }
};

int main()
{
    Library Lib;

    Book *book1 = new Textbook("Manto saheb", "Vibha Chauhan And khalid Alvi", "1", "biography");
    Book *book2 = new Novel("Hanging Garden", "Ian Rankin", "2", "Thriller");
    Lib.addBook(book1);
    Lib.addBook(book2);

    LibMember *member1 = new stdMember(12345, "Tayyab Bin Qamar", "block 17", "555-1234");
    LibMember *member2 = new FacultyMember(67890, "abc", "xyz", "555-5678");
    Lib.addMember(member1);
    Lib.addMember(member2);

    cout << "Books in the Lib:" << endl;
    Lib.printAllBooks();

    cout << "\nMembers of the Lib:" << endl;
    Lib.printAllMembers();

    Lib.borrowBook(member1, book1, "2023-07-31");
    Lib.borrowBook(member2, book2, "2023-07-31");
    Lib.returnBook(book1, member1);

    return 0;
}
