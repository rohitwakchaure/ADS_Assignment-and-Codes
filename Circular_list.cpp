#include <iostream>
using namespace std;
struct node
{
    int song_id, rele_yr;
    float duration;
    string track, title, artist, album, generation;
    struct node *next;
};
node *getnode()
{ 
    node *temp;
    temp = new node;
    temp->next = NULL;
    return temp;
}

node *create()
{
    node *temp, *head, *New;

    int song_id, rele_yr;
    float duration;
    string track, title, artist, album, generation;
    int flag;
    int ans;
    temp = NULL;
    flag = 1;
    do
    {
        cout << "enter Song id " << endl;
        cin >> song_id;
        cout << "enter Track of Song  " << endl;
        cin >> track;
        cout << "enter Title of Song " << endl;
        cin >> title;
        cout << "enter release year of Song " << endl;
        cin >> rele_yr;
        cout << "enter  duration of Song " << endl;
        cin >> duration;
        cout << "enter  name of artist  of Song " << endl;
        cin >> artist;
        cout << "enter  name of album of Song " << endl;
        cin >> album;
        cout << "enter  generation  of Song " << endl;
        cin >> generation;

        New = getnode();
        New->song_id = song_id;
        New->track = track;
        New->title = title;
        New->rele_yr = rele_yr;
        New->duration = duration;
        New->artist = artist;
        New->album = album;
        New->generation = generation;
        if (flag == 1)
        {
            head = New;
            New->next = head;
            temp = head;
            flag = 0;
        }
        else
        {
            temp = head;
            while (temp->next != head)

                temp = temp->next;
            temp->next = New;
            New->next = head;
        }
        cout << "Do you want to continue";
        cin >> ans;

    } while (ans == 1);
    return head;
}
Display(node *head)
{
    node *temp;
    temp = head;
    if (temp == NULL)
    {
        cout << "Empty";
    }
    cout << "+-------+-------+-------+-------+-------+-------+-------+-------+" << endl;
    cout << "|"
         << "SONG_ID"
         << "|"
         << "TRACK.."
         << "|"
         << "TITLE.."
         << "|"
         << "RELYEAR"
         << "|"
         << "DURTION"
         << "|"
         << "ARTIST."
         << "|"
         << "ALBUM.."
         << "|"
         << "GEN_RAT"
         << "|" << endl;
    cout << "+-------+-------+-------+-------+-------+-------+-------+-------+" << endl;
    do
    {

        cout << "|" << temp->song_id << "\t|" << temp->track << "\t|" << temp->title << "\t|" << temp->rele_yr << "\t|" << temp->duration << "\t|" << temp->artist << "\t|" << temp->album << "\t|" << temp->generation << "\t|" << endl;

        temp = temp->next;
    } while (temp != head);
    cout << "+-------+-------+-------+-------+-------+-------+-------+------+" << endl;
}
node *insert(node *head)
{
    int key;
    node *New, *temp;
    New = getnode();
    cout << "enter Song id " << endl;
    cin >> New->song_id;
    cout << "enter Track of Song  " << endl;
    cin >> New->track;
    cout << "enter Title of Song " << endl;
    cin >> New->title;
    cout << "enter release year of Song " << endl;
    cin >> New->rele_yr;
    cout << "enter  duration of Song " << endl;
    cin >> New->duration;
    cout << "enter  name of artist  of Song " << endl;
    cin >> New->artist;
    cout << "enter  name of album of Song " << endl;
    cin >> New->album;
    cout << "enter  generation  of Song " << endl;
    cin >> New->generation;

    if (head == NULL)
    {
        head = New;
    }
    else
    {
        cout << "enter song ID after you want to insert";
        cin >> key;
        temp = head;
    } 

    do
    {

        if (temp->song_id == key)
        {
            New->next = temp->next;
            temp->next = New;
        }
        else
        {
            temp = temp->next;
        }
    } while (temp != head);
}
node *inserthead(node *head)
{
  
    node *New, *temp;
    New = getnode();
    cout << "enter Song id " << endl;
    cin >> New->song_id;
    cout << "enter Track of Song  " << endl;
    cin >> New->track;
    cout << "enter Title of Song " << endl;
    cin >> New->title;
    cout << "enter release year of Song " << endl;
    cin >> New->rele_yr;
    cout << "enter  duration of Song " << endl;
    cin >> New->duration;
    cout << "enter  name of artist  of Song " << endl;
    cin >> New->artist;
    cout << "enter  name of album of Song " << endl;
    cin >> New->album;
    cout << "enter  generation  of Song " << endl;
    cin >> New->generation;   
     if(head==NULL)
    {
        head=New;
    }
    else
    {
        temp=head;
        while(temp->next!=head)
        {
        
        temp=temp->next;
        }
            
        temp->next=New;
        
        New->next=head;
        head=New;
    
            
        
        cout<<"the node is inserted";
    }
   return head;

}
node *insertlast(node *head)
{
      node *New, *temp;
    New = getnode();
    cout << "enter Song id " << endl;
    cin >> New->song_id;
    cout << "enter Track of Song  " << endl;
    cin >> New->track;
    cout << "enter Title of Song " << endl;
    cin >> New->title;
    cout << "enter release year of Song " << endl;
    cin >> New->rele_yr;
    cout << "enter  duration of Song " << endl;
    cin >> New->duration;
    cout << "enter  name of artist  of Song " << endl;
    cin >> New->artist;
    cout << "enter  name of album of Song " << endl;
    cin >> New->album;
    cout << "enter  generation  of Song " << endl;
    cin >> New->generation;   
     if(head==NULL)
    {
        head=New;
    }
    else
    {
        temp=head;
        while(temp->next!=head)
        {
        
        temp=temp->next;
        }
            
        temp->next=New;
        
        New->next=head;
    
            
        
        cout<<"the node is inserted";
    }
   return head;

}

void dele(node *head)
{

    node *prev, *temp;
    temp = head;
    int val;

    cout << "enter song Id to delete" << endl;
    cin >> val;
    if (temp == NULL)
    {
        cout << "Empty";
        return;
    }

    do

    {

        prev = temp;
        temp = temp->next;

    } while (temp != head && temp->song_id != val);
    if (temp->song_id == val)
    {
        if (temp == head)
        {
            head = temp->next;
        }

        else
        {
            prev->next = temp->next;
            cout << "deleted succesfully" << endl;
        }
        temp->next = head;
        delete (temp);
    }
    return;
}
Searh(node *head)
{
    node *temp;
    temp = head;
    int val;
    cout << "Enter song Id  to search";
    cin >> val;
    cout << "+-------+-------+-------+-------+-------+-------+-------+-------+" << endl;
    cout << "|"
         << "SONG_ID"
         << "|"
         << "TRACK.."
         << "|"
         << "TITLE.."
         << "|"
         << "RELYEAR"
         << "|"
         << "DURTION"
         << "|"
         << "ARTIST."
         << "|"
         << "ALBUM.."
         << "|"
         << "GEN_RAT"
         << "|" << endl;
    cout << "+-------+-------+-------+-------+-------+-------+-------+-------+" << endl;
    do
    {
        if (temp->song_id == val)
        {
            cout << "|" << temp->song_id << "\t|" << temp->track << "\t|" << temp->title << "\t|" << temp->rele_yr << "\t|" << temp->duration << "\t|" << temp->artist << "\t|" << temp->album << "\t|" << temp->generation << "\t|" << endl;
        }

        temp = temp->next;

    } while (temp != head);
    cout << "+-------+-------+-------+-------+-------+-------+-------+------+" << endl;
}
int main()
{
    int ch, che;
    node *head;
    head = create();
    do
    {

        cout << " 1.Insert After Specific element \n2.Insert As head node \n 3.Insert As Last node\n4.Delete element\n5.Search for specific element\n 6.Display\n7.Exit" << endl;
        cout << "Enter Your Choice";
        cin >> ch;
        switch (ch)
        {

        case 1:
            insert(head);
            break;
             case 2:
            inserthead(head);
            break;
        case 3:
            insertlast(head);
            break;
        case 4:
            dele(head);
            break;
        case 5:
            Searh(head);
            break;
        case 6:
            Display(head);
            break;
        case 7:
            exit(1);
            break;
        default:
            cout << "Invalid";
        }
        cout << "You want to Continue" << endl;
        cin >> che;

    } while (che == 1);
    return 0;
}