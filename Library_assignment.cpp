#include <iostream>
#include <cstdlib>
using namespace std;
struct node
{
    int Book_id = -1;
    string title;
    string author;
    string isbn;
    int av_stat;
    int next;
} a[20];

create()
{
    int head;
    int i;
    cout << "enter index of first node";
    cin >> i;
    head = i;
    while (i != -1)
    {
        cout << "Enter Book Id " << endl;
        cin >> a[i].Book_id;
        cout << "Enter title of book" << endl;
        cin >> a[i].title;
        cout << "Enter author of book" << endl;
        cin >> a[i].author;
        cout << "Enter isbn no of book" << endl;
        cin >> a[i].isbn;
        cout << "Enter Availability status  of book" << endl;
        cin >> a[i].av_stat;
        cout << "Enter index of next node";
        cin >> a[i].next;
        i = a[i].next;
    }
    return head;
}
Display(int head)
{
    int i;
    i = head;
    while (i != -1)
    {
        if (a[i].Book_id != -1)
        {
            cout << a[i].Book_id << "|" << a[i].title << "|" << a[i].author << "|" << a[i].isbn << "|" << a[i].av_stat << "|"
                 << "->";
        }
        i = a[i].next;
    }
    cout << "Null" << endl;
}
void insert()
{
    string Nauthor, Ntitle, Nisbn;
    int NBook_id, Navstat, temp;
    cout << "Enter Book id" << endl;
    cin >> NBook_id;
    cout << "enter Title of book" << endl;
    cin >> Ntitle;
    cout << "enter author of book" << endl;
    cin >> Nauthor;
    cout << "enter isbn no of book" << endl;
    cin >> Nisbn;
    cout << "enter Availability status  of book" << endl;
    cin >> Navstat;
    cout << "Enter Book Id of Book after you want to insert";
    cin >> temp;
    for (int i = 0; i < 20; i++)
    {
        if (a[i].Book_id == temp)
        {
            if (a[i + 1].Book_id == -1)
            {
                a[i + 1].Book_id = NBook_id;
                a[i + 1].title = Ntitle;
                a[i + 1].author = Nauthor;
                a[i + 1].isbn = Nisbn;
                a[i + 1].av_stat = Navstat;
                a[i + 1].next = a[i].next;
                a[i].next = i + 1;
                return;
            }
            cout << "Cant insert";
        }
    }
}
void dele(int head)
{
    int temp;
    cout << "Enter Book Id to delete";
    cin >> temp;
    int i = head;
    int prev = 0;
    while (i != -1)
    {
        if (a[i].Book_id == temp)
        {
            a[i].Book_id = -1;
            a[prev].next = a[i].next;
            a[i].next = 0;
            return;
        }
        prev = i;
        i = a[i].next;
    }
    cout << "element not found";
}
void search(int head)
{
    int temp;
    int i = head;
    cout << "enter Book Id of book to search";
    cin >> temp;
    while (i != -1)
    {
        if (a[i].Book_id == temp)
        {
            cout << "element found" << endl;
            cout << a[i].Book_id << "|" << a[i].title << "|" << a[i].author << "|" << a[i].isbn << "|" << a[i].av_stat << "|"
                 << "->";
        }
        i = a[i].next;
    }
    cout << "not found";
}
int main()
{
    int head;
    head = create();
    cout << "data loaded";
    int ch;
    do
    {
        cout << "Menu\n1)insert\n2)display\n3)delete_data\n4)search\n5)exit\nEnter your choice : ";
        cin >> ch;
        switch (ch)
        {

        case 1:
            insert();
            break;
        case 2:
            Display(head);
            break;
        case 3:
            dele(head);
            break;
        case 4:
            search(head);
            break;
        case 5:
            exit(0);
        }
        cout << "do you want to continue(1/0)";
        cin >> ch;
    } while (ch == 1);
    return 0;
}
