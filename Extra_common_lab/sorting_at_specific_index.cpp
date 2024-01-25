#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
    Node* previous;
    Node(){
        this->next = NULL;
        this->previous = NULL;
        this->data = 0;
    }
    Node(int data){
        this->data = data;
        this->next = NULL;
        this->previous = NULL;
    }
};
class doubly_linked_list
{
    Node* head;
    public:
    doubly_linked_list(){
        this->head = NULL;
    }
    void insert_node_at_tail(int);
    void print_doubly_link_list();
    void sorted_list_on_specific_index();
};

void doubly_linked_list::insert_node_at_tail(int data)
{
    Node* new_node = new Node(data);
    if (head == NULL){
        head = new_node;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->previous = temp;

}

void doubly_linked_list::print_doubly_link_list()
{
    Node* temp;
    temp = head;
    while (temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout <<"\n";
}

void doubly_linked_list::sorted_list_on_specific_index() {
    Node *i, *j, *min;

    for (i = head; i != NULL && i->next != NULL; i = i->next) {
        min = i;
        for (j = i->next; j != NULL; j = j->next) {
            if (j->data < min->data) {
                min = j;
            }
        }

        if (min != i) {
            // Case 1: Swapping the first and last node
            if (i == head && min->next == NULL) {
                // Swap the data
                int temp = i->data;
                i->data = min->data;
                min->data = temp;
            }
            // Case 2: Swapping adjacent nodes
            else if (i->next == min) {
                // Adjust previous and next pointers
                Node *prev_i = i->previous;
                Node *next_min = min->next;

                if (prev_i != NULL) {
                    prev_i->next = min;
                } else {
                    head = min;
                }

                if (next_min != NULL) {
                    next_min->previous = i;
                }

                i->next = next_min;
                i->previous = min;
                min->next = i;
                min->previous = prev_i;
            }
            // Case 3: Swapping non-adjacent nodes
            else {
                // Adjust previous and next pointers
                Node *prev_i = i->previous;
                Node *next_i = i->next;
                Node *prev_min = min->previous;
                Node *next_min = min->next;

                if (prev_i != NULL) {
                    prev_i->next = min;
                } else {
                    head = min;
                }

                if (next_i != NULL) {
                    next_i->previous = min;
                }

                if (prev_min != NULL) {
                    prev_min->next = i;
                }

                if (next_min != NULL) {
                    next_min->previous = i;
                }

                i->next = next_min;
                i->previous = prev_min;
                min->next = next_i;
                min->previous = prev_i;
            }
        }
    }
}



main()
{
    doubly_linked_list d1;
    d1.insert_node_at_tail(2);
    d1.insert_node_at_tail(16);
    d1.insert_node_at_tail(10);
    d1.insert_node_at_tail(1);
   
    d1.print_doubly_link_list();
    d1.sorted_list_on_specific_index();
    d1.print_doubly_link_list();
}