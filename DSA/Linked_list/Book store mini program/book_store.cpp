//this is a book stor program
//where you can add book with author name, copies and amount
//you have options: search book buy its name, search book by its author name, copies to check if you want more copies but having less copies it 
//will give out mesage if not then proceed to payment and print all the books left (after purchasing copies will be subtracted from original copies)
#include<iostream>
#include<cstdlib>
using namespace std;
class book_node
{
    string NameOfBook;
    string author;
    unsigned int NumOfCopies;
    unsigned int cost;
    book_node* next;
    book_node():NameOfBook(NULL),NumOfCopies(0),cost(0),next(NULL){}
    book_node(string name,string author_name,unsigned int copies,unsigned int price):NameOfBook(name),author(author_name),NumOfCopies(copies),cost(price),next(NULL){}
    book_node(string name,string author_name,unsigned int copies,unsigned int price,book_node* next):NameOfBook(name),author(author_name),NumOfCopies(copies),cost(price),next(next){}
    friend class Book_store;
};
class Book_store
{
    private:
    book_node* head;
    void remove();//used in destructor
    public:
    Book_store(){head=NULL;}
    ~Book_store();//destructor used for freeing the list at the end of the program
    void add_book(string name,string author,unsigned int copies,unsigned int cost); // add book to for selling
    void printlist();//printing all the books with author name, price, copies
    bool search_book(string name);//search book by its name
    bool search_by_the_author(string author_name);//search book by author name
    string return_book_name(string author_name);//returning the book name giving author's name
    bool check_copies_requested(unsigned int size,string name); //check copies are available or not that is requested
    unsigned int return_copies(string name); // return the copies 
    unsigned int amount_to_be_process(string name,unsigned int size);// returning the payment
    bool check_empty();//to check wheter the list is empty or not
};
void Book_store::add_book(string name,string author,unsigned int a,unsigned int copies)
{
    book_node* new_book=new book_node(name,author,a,copies);
    new_book->next=head;
    head=new_book;
}
void Book_store::printlist()
{
    book_node* n=head;
    cout<<"Name of Book_store |  Author  |  Copies  |  cost per each  "<<endl;
    cout<<"_____________|__________|__________|_________________"<<endl;
    while(n!=NULL)
    {
        cout<<n->NameOfBook<<"  |  "<<n->author<<"  |  "<<n->NumOfCopies<<"  |  "<<n->cost<<endl;
        n=n->next;
    }
}
bool Book_store::search_book(string name)
{
    book_node* n=head;
    while(n!=NULL)
    {
        if(n->NameOfBook==name)
        {
            return true;
        }
        n=n->next;
    }
    return false;
}
bool Book_store::search_by_the_author(string author_name)
{
    book_node* n=head;
    while(n!=NULL)
    {
        if(n->author==author_name)
        {
            return true;
        }
        n=n->next;
    }
    return false;
}
string Book_store::return_book_name(string author_name)
{
    book_node* n=head;
    while(n!=NULL)
    {
        if(n->author==author_name)
        {
            return n->NameOfBook;
        }
        n=n->next;
    }
    return "Book_store not available";
}
bool Book_store::check_copies_requested(unsigned int size,string name)
{
    book_node* n=head;
    while(n!=NULL)
    {
        if(n->NameOfBook==name)
        {
            if(n->NumOfCopies<size){return false;}
            else
            {
                n->NumOfCopies=n->NumOfCopies-size;
                return true;
            }
        }
        n=n->next;
    }
    return false;//just a glitch//compiler  ws not accepting
}
unsigned int Book_store::return_copies(string name)
{
    book_node* n=head;
    while(n!=NULL)
    {
        if(n->NameOfBook==name)
        {
            return n->NumOfCopies;
        }
        n=n->next;
    }
    return 0;
}
unsigned int Book_store::amount_to_be_process(string name,unsigned int size)
{
    book_node* n=head;
    while(n!=NULL)
    {
        if(n->NameOfBook==name)
        {
            unsigned int amt=(n->cost)*size;
            n->NumOfCopies=n->NumOfCopies-size;//to deduct the number of copies
            return amt;
        }
        n=n->next;
    }
    return 0;
}
void Book_store::remove()
{
    book_node* n=head;
    head=head->next;
    delete n;
    n=NULL;
}
bool Book_store::check_empty()
{
    if(head==NULL)
    {
        return true;
    }
    return false;
}
Book_store::~Book_store()
{
    while(!check_empty())
    {
        remove();
    }
}
int main()
{
    Book_store b1;
    cout<<"choose from menu:"<<endl;
    cout<<"1.) To add a book, no.of copies, cost of each book."<<endl;
    cout<<"2.) Search for book and copies."<<endl;
    cout<<"3.) Search by author name and proceed payment."<<endl;
    cout<<"4.) Choose to print all books"<<endl;
    cout<<"5.) exit"<<endl;
    cout<<"\n\n\n";
    string nameofBOOk;
    string author;
    unsigned int copies;
    unsigned int cost;
    int ch;
    cout<<"Enter Choice:";cin>>ch;
    cin.ignore();
    system("cls");
    while(ch==1 || ch==2 || ch==3 || ch==4)
    {
        int i=0;
        unsigned int size;
        if(ch==1)
        {
            i++;
            cout<<"Adding Book: "<<i<<endl;
            cout<<"Enter name of Book_store: ";getline(cin,nameofBOOk);
            cout<<"Enter name of author of the book: ";getline(cin,author);
            cout<<"Enter no. of copies: ";cin>>copies;
            cout<<"Enter cost of each book: ";cin>>cost;
            b1.add_book(nameofBOOk,author,copies,cost);
            cout<<"Book_store Added!!"<<endl;
        }
        if(ch==2)
        {
            string name;
            cout<<"Search name of the book:";
            getline(cin,name);
            if(b1.search_book(name)==true)
            {
                cout<<"\nBook existed and now enter copies you want: ";
                cin>>size;
                if(b1.check_copies_requested(size,name)==true)
                {
                    cout<<"copies existed printing payment."<<endl;
                    ch=6;
                }
                else
                {
                    cout<<"Number of copies is less than you require, No. of copies left: "<<b1.return_copies(name)<<endl;
                }
            }
            else
            {
                cout<<"Book_store name not registered and go for menu or search a registered book"<<endl;
            }
        }
        if(ch==3)
        {
            string name_of_author;
            cout<<"Enter the name of the author you want to search:";getline(cin,name_of_author);
            if(b1.search_by_the_author(name_of_author)==false)
            {
                cout<<"There is no book with entered author name."<<endl;
            }
            else
            {
                string book_name=b1.return_book_name(name_of_author);
                cout<<"\nBook name is "<<book_name<<" and now enter copies you want: ";
                cin>>size;
                if(b1.check_copies_requested(size,book_name)==true)
                {
                    cout<<"copies existed printing payment."<<endl;
                    ch=6;
                }
                else
                {
                    cout<<"Number of copies is less than you require, No. of copies left: "<<b1.return_copies(book_name)<<endl;
                }
            }
        }
        if(ch==6)
        {
            cout<<"copies requested are "<<size;
            unsigned int amount=b1.amount_to_be_process(nameofBOOk,size);
            cout<<"Amount to be paid is Rs."<<amount;
        }
        if(ch==4)
        {
            if(b1.check_empty()==true)
            {
                cout<<"No books added"<<endl;
            }
            else
            {
                b1.printlist();
            }
        }
        cout<<"\n\n\n";
        cout<<"choose from menu:"<<endl;
        cout<<"1.) To add a book, no.of copies, cost of each book."<<endl;
        cout<<"2.) Search for book and copies."<<endl;
        cout<<"3.) Search by author name and proceed payment."<<endl;
        cout<<"4.) Choose to print all books"<<endl;
        cout<<"5.) exit"<<endl;
        cout<<"\n\n\n";
        cout<<"Enter choice: ";
        cin>>ch;
        if(ch!=4){system("cls");}
        cin.ignore();
    }
    return 0;
}