#include<iostream>
using namespace std;

class Vertex {
    public:
    Vertex* next;
    string first_name,last_name,email;
    int password;
    Vertex() {
        this->next = NULL;
    }
    Vertex(string first_name,string last_name,string email,int password) {
        this->first_name = first_name;
        this->last_name = last_name;
        this->email = email;
        this->password = password;
        this->next = NULL;
    } 
};

class Graph {
    public:
    Vertex** HG;
    Graph() {
        HG = new Vertex* [10];
        for(int i = 0; i < 10; i++) {
            HG[i] = NULL;
        }
        
    }
    void add_edge(string , string,string,int, string,string,string,int);
    void print_graph();
    bool isEmailExists(string);
};

bool Graph::isEmailExists(string email) {
    for (int i = 0; i < 10; i++) {
        Vertex* temp = HG[i];
        while (temp != NULL) {
            if (temp->email == email) {
                return true;
            }
            temp = temp->next;
        }
    }
    return false;
}

void Graph::add_edge(string f_name1,string l_name1,string email1,int password1,string f_name2,string l_name2,string email2,int password2) {
    Vertex* n_node1 = new Vertex(f_name1,l_name1,email1,password1);
    Vertex* n_node2 = new Vertex(f_name2,l_name2,email2,password2);
   
    for(int i  = 0; i < 10 ; i++) {
        if(HG[i] == NULL ) {
            HG[i] = n_node1;
            Vertex* p = HG[i];
            while(p->next != NULL) {
                p  = p->next;
            }
            p->next = n_node2;
            break;
        }
        else if(HG[i]->email == email1) {
            Vertex* p = HG[i];
            while(p->next != NULL) {
                p  = p->next;
            }
            p->next = n_node2;
            break;
        }
        
    }
}

void print(Vertex* head) {
    Vertex* temp = head;
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

void Graph::print_graph() {
    for(int i = 0;i < 10; i++) {
        Vertex* temp = HG[i];
        print(temp);
    }
}

main() {
    Graph g1;
    g1.add_edge("Harmain","Iftikhar","h@gmail.com",1234,"Saboor","Abdul","s@gmail.com",1234);
    g1.add_edge("Harmain","Iftikhar","h@gmail.com",1234,"Ahamd","Iftikhar","a@gmail.com",1234);
    g1.add_edge("Ahamd","Abdul","a@gmail.com",1234,"Harmain","Iftikhar","h@gmail.com",1234);
    g1.add_edge("Ahamd","Abdul","a@gmail.com",1234,"Saboor","Abdul","s@gmail.com",1234);
    g1.print_graph();
}