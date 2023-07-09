#include<iostream>
#include<cstring>
using namespace std;
class Book{
    protected:
    string name,author;
    public:
    Book(const string &name, const string &author): name(name), author(author){}
    virtual void display_book() const =0;
};
class Textbook:public Book{
    string Subject;
    public:
    Textbook(const string &name,const string &author,const string &Subject):Book(name,author),Subject(Subject){}
    void display_book() const override{
        cout<<"-------Details for TextBook--------"<<endl;
        cout<<"Text Book name : "<<name<<endl;
        cout<<"Author name : "<<author<<endl;
        cout<<"Subject name : "<<Subject<<endl;
    }
};  
class Novel:public Book{
    string type;
    public:
    Novel(const string &name,const string &author,const string &type):Book(name,author),type(type){}
    void display_book() const override{
        cout<<"-------Details for Novel--------"<<endl;
        cout<<"Novel name : "<<name<<endl;
        cout<<"Novel Author name : "<<author<<endl;
        cout<<"Novel Type name : "<<type<<endl;
    }
};
class LibraryMember{
    protected:
    int Id;
    string name;
    public:
    LibraryMember(int Id,const string &name):Id(Id),name(name){}
    virtual void display_data()=0;
};
class StudentMember:public LibraryMember{
    private:
    int Max_books;
    int borrowed_books_count;
    Book* borrowed_books[5];
    public:
    StudentMember(int Id,const string &name):LibraryMember(Id,name),Max_books(5),borrowed_books_count(0){}
    void display_data(){
        cout<<"-------Details for Student Member--------"<<endl;
        cout<<"Student member Id :"<<Id<<endl;
        cout<<"Student member Name :"<<name<<endl;
        cout<<"Maximum Books Allowed :"<<Max_books<<endl;
        }
    // void borrow_book(Book* book) {
    //     if (borrowed_books_count < Max_books) {
    //         borrowed_books[borrowed_books_count++] = book;
    //         cout << "Book \"" << book->name << "\" borrowed successfully." << endl;
    //     }
    //     else {
    //         cout << "Maximum book limit reached. Cannot borrow more books." <<endl;
    //     }
    // }
    // void return_book(Book* book) {
    //     for (int i = 0; i < borrowed_books_count; i++) {
    //         if (borrowed_books[i] == book) {
    //             borrowed_books[i] = borrowed_books[--borrowed_books_count];
    //             cout << "Book \"" << book->name << "\" returned successfully." <<endl;
    //         }
    //     }
    //     cout << "Book not found in the borrowed books list." << endl;
    // }
};
class FacultyMember:public LibraryMember{
    private:
    int Max_books;
    int borrowed_books_count;
    Book* borrowed_books[5];
    public:
    FacultyMember(int Id,const string &name):LibraryMember(Id,name),Max_books(5){}
    void display_data(){
        cout<<"-------Details for Faculty Member--------"<<endl;
        cout<<"Faculty member Id :"<<Id<<endl;
        cout<<"Faculty member Name :"<<name<<endl;
        cout<<"Maximum Books Allowed :"<<Max_books<<endl;
        }
    // void borrow_book(Book* book) {
    //     if (borrowed_books_count < Max_books) {
    //         borrowed_books[borrowed_books_count++] = book;
    //         cout << "Book \"" << book->name << "\" borrowed successfully." << endl;
    //     }
    //     else {
    //         cout << "Maximum book limit reached. Cannot borrow more books." << endl;
    //     }
    // }

    // void return_book(Book* book) {
    //     for (int i = 0; i < borrowed_books_count; i++) {
    //         if (borrowed_books[i] == book) {
    //             borrowed_books[i] = borrowed_books[--borrowed_books_count];
    //             cout << "Book \"" << book->name << "\" returned successfully." << endl;
    //             return;
    //         }
    //     }
    //     cout << "Book not found in the borrowed books list." << endl;
    // }
};
class Transaction{
    Book* book;
    LibraryMember* member;
    string due_date;
    public:
    Transaction(Book* book,LibraryMember* member,const string &due_date):
    book(book),member(member),due_date(due_date){}
    Book* getBook(){
        return book;
    }
    LibraryMember* getMember(){
        return member;
    }
    string getDueDate(){
        return due_date;
    }
};
class Library{
    static const int MAX_BOOKS = 100;
    static const int MAX_MEMBERS = 100;
    static const int MAX_TRANSACTIONS = 100;
    Book* books[MAX_BOOKS];
    LibraryMember* members[MAX_MEMBERS];
    Transaction* transactions[MAX_TRANSACTIONS];
    int numBooks;
    int numMembers;
    int numTransactions;
    int findBookIndex(Book* book) const{
        for (int i = 0; i < numBooks; ++i){
            if (books[i] == book){
                return i;
            }
        }
        return -1;
    }
    int findMemberIndex(LibraryMember* member) const{
        for (int i = 0; i < numMembers; ++i){
            if (members[i] == member){
                return i;
            }
        }
        return -1;
    }
    int findTransactionIndex(Book* book, LibraryMember* member) const{
        for (int i = 0; i < numTransactions; ++i){
            if (transactions[i]->getBook() == book && transactions[i]->getMember() == member){
                return i;
            }
        }
        return -1;
    }
    public:
    Library(): numBooks(0), numMembers(0), numTransactions(0){}
    void addBook(Book* book){
        if (numBooks < MAX_BOOKS){
            books[numBooks++] = book;
            cout << "Book added successfully." << endl;
        }
        else{
            cout << "Cannot add more books. Maximum limit reached." << endl;
        }
    }
    void removeBook(Book* book){
        int index = findBookIndex(book);
        if (index != -1){
            for (int i = index; i < numBooks - 1; ++i){
                books[i] = books[i + 1];
            }
            numBooks--;
            cout << "Book removed successfully." << endl;
        }
        else{
            cout << "Book not found." << endl;
        }
    }
    void addMember(LibraryMember* member){
        if (numMembers < MAX_MEMBERS){
            members[numMembers++] = member;
            cout << "Member added successfully." << endl;
        }
        else{
            cout << "Cannot add more members. Maximum limit reached." << endl;
        }
    }
    void removeMember(LibraryMember* member){
        int index = findMemberIndex(member);
        if (index != -1){
            for (int i = index; i < numMembers - 1; ++i){
                members[i] = members[i + 1];
            }
            numMembers--;
            cout << "Member removed successfully." << endl;
        }
        else{
            cout << "Member not found." << endl;
        }
    }
    void borrowBook(LibraryMember* member, Book* book, const string &dueDate){
        int memberIndex = findMemberIndex(member);
        int bookIndex = findBookIndex(book);

        if (memberIndex != -1 && bookIndex != -1){
            if (numTransactions < MAX_TRANSACTIONS){
                Transaction* transaction = new Transaction(book, member, dueDate);
                transactions[numTransactions++] = transaction;
                cout << "Book borrowed successfully." << endl;
            }
            else{
                cout << "Cannot perform the borrowing operation. Maximum transaction limit reached." << endl;
            }
        }
        else{
            cout << "Member or book not found." << endl;
        }
    }
    void returnBook(Book* book, LibraryMember* member){
        int transactionIndex = findTransactionIndex(book, member);
        if (transactionIndex != -1)
        {
            for (int i = transactionIndex; i < numTransactions - 1; ++i){
                transactions[i] = transactions[i + 1];
            }
            numTransactions--;
            cout << "Book returned successfully." << endl;
        }
        else{
            cout << "Transaction not found." << endl;
        }
    }
    void printAllBooks() const
    {
        for (int i = 0; i < numBooks; ++i)
        {
            books[i]->display_book();
            cout << endl;
        }
    }
    void printAllMembers() const
    {
        for (int i = 0; i < numMembers; ++i)
        {
            members[i]->display_data();
            cout << endl;
        }
    }
};
int main(){
    Library Lib;

    Book* book1 = new Textbook("In search of Lost time", "Marcel Proust", "Biography");
    Book* book2 = new Novel("Ulysses", "James Joyce", "Thriller");
    Lib.addBook(book1);
    Lib.addBook(book2);

    LibraryMember* member1 = new StudentMember(7574, "Taqi Haider");
    LibraryMember* member2 = new FacultyMember(214421, "Wajih-ur-Rehman");
    Lib.addMember(member1);
    Lib.addMember(member2);

    Lib.printAllBooks();
    Lib.printAllMembers();

    Lib.borrowBook(member1, book1, "09-07-2023");
    Lib.borrowBook(member2, book2, "09-07-2023");
    Lib.returnBook(book1, member1);
    return 0;
}