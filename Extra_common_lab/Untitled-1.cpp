#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(){
        next = NULL;
        data = 0;
    }
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class linked_list{
    Node* head;
    public:
    linked_list(){
        this->head = NULL;
    }
    void insert_node_at_end(int);
    void print_node();
    void sorted_list();
};

void linked_list::sorted_list() {
    Node* i, *j, *k, *prev, *temp;
    for(i = head; i->next != NULL; i = i->next) {
        k = i;
        for(j = i; j->next != NULL; j = j->next) {
            if(j->data < k->data) {
                k = j;
            }
            prev = j;
        }
        if(i == head) {
            head = k;
            temp = k->next;
            k->next = i->next;
            prev->next = i;
            i->next = temp;
        }
    }
}

//Function for inserting Node at tail
void linked_list:: insert_node_at_end(int data)
{
    Node* new_node = new Node(data);
    if (head == NULL){
        head = new_node;
        return;
    }
    Node* temp = head;
    while (temp->next!= NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
}

//Function for displaying link_list 
void linked_list:: print_node()
{
    Node* temp;
    temp = head;
    if (head == NULL)
    {
        cout << "List is Empty";
        return;
    }
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}  

//Driver Code
main() {
    linked_list l1;
    l1.insert_node_at_end(50); //1st index
    l1.insert_node_at_end(40); //2nd index
    l1.insert_node_at_end(10); //3rd index
    l1.print_node();
    l1.sorted_list();
    l1.print_node();
}