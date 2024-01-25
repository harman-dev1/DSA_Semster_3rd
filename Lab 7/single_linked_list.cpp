#include<iostream>
using namespace std;

//Class for creating node that consists of data and pointer
class Node{
    public:
    string first_name,last_name,email;
    int password;
    Node* next;
    Node(){
        next = NULL;
    }
    Node(string first_name,string last_name,string email,int password){
        this->first_name = first_name;
        this->last_name = last_name;
        this->email = email;
        this->password = password;
        this->next = NULL;
    }
};

//Class consists of head and multiple operations that can be apply on link_list
class linked_list{
    public:
    Node** LL;
    Node* head;
    linked_list(){
        LL = new Node* [10];
        for(int i = 0; i < 10; i++) {
            LL[i] = NULL;
        }
    }
    void insert_node_at_end(string,string,string,int,string,string,string,int);
    void print_node();
};

//Function for inserting Node at tail
void linked_list:: insert_node_at_end(string f_name1,string l_name1,string email1,int password1,string f_name2,string l_name2,string email2,int password2)
{
    Node* n_node1 = new Node(f_name1,l_name1,email1,password1);
    Node* n_node2 = new Node(f_name2,l_name2,email2,password2);
   
    for(int i  = 0; i < 10 ; i++) {
        if(LL[i] == NULL ) {
            LL[i] = n_node1;
            Node* p = LL[i];
            while(p->next != NULL) {
                p  = p->next;
            }
            p->next = n_node2;
            break;
        }        
    }
}

void print(Node* head) {
    Node* temp = head;
    if (head == NULL)
    {
        return;
    }
    while (temp != NULL)
    {
        cout << temp->first_name<< " " << temp->last_name << " " << temp->email << " " << temp->password << " ";
        temp = temp->next;
    }
    cout << "\n";
}


//Function for displaying link_list 
void linked_list:: print_node()
{
    for(int i = 0;i < 10; i++) {
        Node* temp = LL[i];
        print(temp);
    }
}  

//Driver Code
main()
{
    linked_list l1;
    l1.insert_node_at_end("Harmain","Iftikhar","h@gmail.com",1234,"Saboor","Abdul","s@gmail.com",1234);
    l1.insert_node_at_end("Harmain","Iftikhar","h@gmail.com",1234,"Ahamd","Iftikhar","a@gmail.com",1234);
    l1.insert_node_at_end("Ahamd","Iftikhar","a@gmail.com",1234,"Zain","Iftikhar","z@gmail.com",1234);
    l1.print_node();
}