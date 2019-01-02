#include <iostream>

using namespace std;

class Customer;

class Category{
    string c_name;

public:
    Category(){
    }

    Category(string c_name){
        this->c_name = c_name;
    }

    string get_name(){
        return c_name;
    }
};

class Writer{
    string name;

public:
    Writer(){
    }

    Writer(string name){
        this->name = name;
    }

    string get_name(){
        return name;
    }
};

class Book{
    string title;
    string category;
    string writer;
    double price;
    string edition_no;
    int quantity;
public:

    Book(){
    }

    Book(string title, Category c, Writer w, double price, string edition_no, int quantity){
        this->title = title;
        this->category = c.get_name();
        this->writer = w.get_name();
        this->price = price;
        this->edition_no = edition_no;
        this->quantity = quantity;
    }

    void display(){
        cout << "Book Title: " << title << endl;
        cout << "Category Name: " << category << endl;
        cout << "Writer Name: " << writer << endl;
        cout << "Price: " << price << endl;
        cout << "Edition Number: " << edition_no << endl;
        cout << "Remaining  Stock: " << quantity << endl << endl;
    }

    friend void buyBooks(Customer customer, Book book);


};


class Person{
public:
    string name;
    Person(){
    }
    Person(string name){
        this->name = name;
    }
};

class Customer: public Person{
    int books_count;
    string address;
public:
    Customer(){
    }

    Customer(string name,  string address): Person(name){
        this->address = address;
    }
    void display(){
        cout << "Customer Name: " << name << endl;
        cout << "Customer Address: " << address << endl;
        cout << "Number of Books Brought: " << books_count << endl << endl;
    }

    friend void buyBooks(Customer customer, Book book);
};

void buyBooks(Customer customer, Book book){
    double d_price;

    if (customer.books_count >= 5){
        d_price = book.price - (book.price*10)/100;
    }
    else {
        d_price = book.price;
    }

    cout << customer.name << " has brought " << book.title << " at " << d_price << endl << endl;
    book.quantity = book.quantity-1;
    customer.books_count += 1;
    cout << "Book Information Update: " << endl;
    book.display();


}

int main(){

    Category category1("Fiction");
    Category category2("Horror");

    Writer writer1("Shanto");
    Writer writer2("Yasmin");

    Book book1("Hello", category1, writer1, 250.00, "48378349", 200);
    Book book2("Anabella", category2, writer2, 350.00, "48378388", 300);

    cout << "Book Information: " << endl;
    book1.display();
    book2.display();

    cout << "Customer Information: " << endl;
    Customer customer1("Nisha", "Dhaka");
    customer1.display();

    cout << "Book Buy: " << endl;
    buyBooks(customer1, book1);

}
