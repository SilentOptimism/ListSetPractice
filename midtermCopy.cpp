#include <fstream>
#include <iostream>
#include <ctime>
#include <string>
#include <thread>

using namespace std;

const int MIN_NR = 10, MAX_NR = 99, MIN_LS = 5, MAX_LS = 20;

class DoublyLinkedList {
private:
    struct Node {
        string customer;
        Node* prev;
        Node* next;
        Node(string name, Node* p = nullptr, Node* n = nullptr) {
            customer = name; 
            prev = p;
            next = n;
        }
    };

    Node* head;
    Node* tail;

public:
    DoublyLinkedList() { head = nullptr; tail = nullptr; }

    void insert_after(string name, int position) {
        if (position < 0) {
            cout << "Position must be >= 0." << endl;
            return;
        }

        Node* newNode = new Node(name);
        if (!head) {
            head = tail = newNode;
            return;
        }

        Node* temp = head;
        for (int i = 0; i < position && temp; ++i)
            temp = temp->next;

        if (!temp) {
            cout << "Position exceeds list size. Node not inserted.\n";
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next)
            temp->next->prev = newNode;
        else
            tail = newNode;
        temp->next = newNode;
    }

    void delete_val(string name) {
        if (!head) return;

        Node* temp = head;
        
        while (temp && temp->customer != name)
            temp = temp->next;

        if (!temp) return; 

        if (temp->prev)
            temp->prev->next = temp->next;
        else
            head = temp->next; 

        if (temp->next)
            temp->next->prev = temp->prev;
        else
            tail = temp->prev; 

        delete temp;
    }

    void delete_pos(int pos) {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }
    
        if (pos == 1) {
            pop_front();
            return;
        }
    
        Node* temp = head;
    
        for (int i = 1; i < pos; i++){
            if (!temp) {
                cout << "Position doesn't exist." << endl;
                return;
            }
            else
                temp = temp->next;
        }
        if (!temp) {
            cout << "Position doesn't exist." << endl;
            return;
        }
    
        if (!temp->next) {
            pop_back();
            return;
        }
    
        Node* tempPrev = temp->prev;
        tempPrev->next = temp->next;
        temp->next->prev = tempPrev;
        delete temp;
    }

    void push_back(string name) {
        Node* newNode = new Node(name);
        if (!tail)
            head = tail = newNode;
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    
    void push_front(string name) {
        Node* newNode = new Node(name);
        if (!head)
            head = tail = newNode;
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    
    string pop_front() {
        string name;

        if (!head) {
            cout << "List is empty." << endl;
            return "";
        }

        Node * temp = head;

        if (head->next) {
            head = head->next;
            head->prev = nullptr;
        }
        else
            head = tail = nullptr;
        
        name = temp->customer;
        delete temp;
        return name;
    }

    string pop_back() {
        string name;
        if (!tail) {
            cout << "List is empty." << endl;
            return "";
        }
        Node * temp = tail;

        if (tail->prev) {
            tail = tail->prev;
            tail->next = nullptr;
        }
        else
            head = tail = nullptr;
        name = temp->customer;
        delete temp;
        return name;
    }

    ~DoublyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    void print() {
        Node* current = head;
        if (!current) {
            cout << "List is empty." << endl;
            return;
        }
        while (current) {
            cout << "\t\t" << current->customer << "\n";
            current = current->next;
        }
        cout << endl;
    }

    void print_reverse() {
        Node* current = tail;
        if (!current) { 
            cout << "List is empty." << endl;
            return;
        }
        while (current) {
            cout << "\t\t" << current->customer << "\n";
            current = current->prev;
        }
        cout << endl;
    }
};

int main() {
    ifstream fin;
    fin.open("names.txt");
    int timeStep = 0;

    if(!fin){
        cout << "File failed to open" << endl;
    }

    DoublyLinkedList patrons;

    // Opens the store and fills the list with 5 patrons
    cout << "Store opens" << endl;
    for (int i = 0; i < 5; i++){
        string customerName;
        getline(fin, customerName);

        patrons.push_front(customerName);
        cout << customerName << " Joins the line" << endl;
    }

    srand(time(nullptr));
    time_t startTime = time(nullptr);

    while(timeStep < 20){
        time_t currentTime = time(nullptr);

        if(difftime(currentTime, startTime) >= 60){
            startTime = currentTime;
            timeStep++;
            cout << "Time step #" << timeStep << endl;

            int random = rand() % 100 + 1;
            if(random <= 10){
                cout << "\t" << patrons.pop_back() << "(at the rear) left the line" << endl;
            }
            else if (random <= 20){
                cout << "\t" << patrons.pop_back() <<"(VIP) joins the front of the line" << endl;
            }
            else if (random <= 40){
                cout  << "\t" << patrons.pop_front() << " is served" << endl;
            }
            else if (random <= 100){
                string newCust;
                getline(fin, newCust);
                patrons.push_front(newCust);
                cout  << "\t" << newCust << " joins the line" << endl;
            }
            cout << "\tResulting Line:" << endl;
            patrons.print();
            
        }

    }

    
    return 0;
}