#include <iostream>
using namespace std;

// Class for creating node that consists of data and pointer
class Node
{
public:
    string first_name,last_name,email;
    int password;
    Node *next;
    Node()
    {
        next = NULL;
    }
    Node(string first_name,string last_name,string email,int password)
    {
        this->first_name = first_name;
        this->last_name = last_name;
        this->email = email;
        this->password = password;
        this->next = NULL;
    }
};

class Hash_Table
{
public:
    Node **HT;
    Hash_Table()
    {
        HT = new Node *[10];
        for (int i = 0; i < 10; i++)
        {
            HT[i] = NULL;
        }
    }
    int hash(int);
    void insert(string,string,string,int);
    int search(int,string);
    int delete_from_hash_table(int,string);
    void print_hash_table();
};

int Hash_Table::hash(int key)
{
    return key % 10;
}

void Hash_Table::insert(string first_name,string last_name,string email,int password)
{
    int hash_table_index = hash(password);
    Node *new_node = new Node(first_name,last_name,email, password);
    if (HT[hash_table_index] == NULL)
    {
        HT[hash_table_index] = new_node;
    }
    else
    {
        Node *p = HT[hash_table_index];
        Node *q = HT[hash_table_index];
        while (p != NULL && p->password < password)
        {
            q = p;
            p = p->next;
        }
        if (password <= q->password)
        {
            new_node->next = q;
            HT[hash_table_index] = new_node;
        }
        else
        {
            new_node->next = q->next;
            q->next = new_node;
        }
    }
}

int Hash_Table::search(int password,string email)
{
    int hash_table_index = hash(password);
    Node *p = HT[hash_table_index];
    while (p && password >= p->password)
    {
        if (p->password == password && p->email == email)
        {
            return 1;
        }
        p = p->next;
    }
    return 0;
}

int Hash_Table::delete_from_hash_table(int password, string email)
{
    int hash_table_index = hash(password);
    Node *temp = HT[hash_table_index];
    // Case: Deleting from head
    if (temp->password == password && temp->email == email)
    {
        Node *d_node = temp;
        HT[hash_table_index] = temp->next;
        delete d_node;
    }
    else
    {
        while (temp->next->password != password && temp->email == email)
        {
            temp = temp->next;
        }
        Node *d_node = temp->next;
        temp->next = temp->next->next;
        delete d_node;
    }
}

void print(Node* head) {
    Node* temp = head;
    if (head == NULL)
    {
        cout << "-1" << endl;
        return;
    }
    while (temp != NULL)
    {
        cout << temp->password << " " << temp->email << temp->first_name << temp->last_name;
        temp = temp->next;
    }
    cout << "\n";
}

void Hash_Table::print_hash_table() {
    for(int i = 0; i < 10; i++) {
        cout << "index: " << i << endl;
        Node* temp = HT[i];
        print(temp);
    }
}

main()
{
    Hash_Table h1;
    string email,first_name,last_name;
    int password;
    int option;
    while(option != 3) {
        cout << "1. signup";
        cin >> option;
        cout << "Email :";
        cin >> email;
        cout << "first name :";
        cin >> first_name;
        cout << "last Name :";
        cin >> last_name;
        cout << "password :";
        cin >> password; 
        h1.insert(first_name,last_name,email,password);
    }
    cin >> email;
    cin >> password;
    cout << h1.search(password,email);
    h1.print_hash_table();
}