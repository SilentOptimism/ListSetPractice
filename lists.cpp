#include <iostream>
#include <list>
#include <typeinfo>

#define spacing() cout << "\n\n"

using std::list;
using std::cout;
using std::cin;
using std::endl;
using std::string;

// Lists are Sequence Containers: arranged according to the order of elements

// GREAT FOR DOUBLY LINKED LISTS
// Allows for non homogenous data

// STD::LIST SPECIFC
//      Doesnt store the size the index of all the elements

// Multiplayer sessions
//      In a large game with alot of players the session management feature will need to keep track of alot of players
//      To do this it needs to have a list of those players
//      When a player leaves or joins those elements can't be disturbed at all
//      In an array if you need to remove one of the elements/players you will need to remake the entire list
//      This will lead to all players being kicked momentarily. This is obviosly bad
//      To avoid this we need to keep all of our player data on a doubly linked list so it can be quickly modified and a player can be removed or added without effecting the other players
//      Make's insertion and deletion fast without effecting the data around it

// Undo/Redo
//      Works in constant time
//      Allows you to slice an entire list and copy it in constant time by just moving pointers

// Scrolling messages
//      A simple list 
//      Allows you to scroll up or down through the list

int main(int argc, char const *argv[]){
    // Default constructor
    list<int> list1;

    // Initialize the list with a size and OPTIONAL VALUE

    // Auto initializes integers to 0
    list<int> list2(10);// Empty list with 10 elements
    
    list<int> list3(10, 5);// Empty list with 10 elements

    // Prints out list
    for(auto elem: list3)
        cout << elem << " ";
    cout << endl;

    // Prints out list
    for(auto elem: list2)
        cout << elem << " ";
    cout << endl;

    // Initializes a list with a DEEPCOPY
    list<int> listCopy3(list3);

    for(int number: listCopy3)
        cout << number << " ";
    cout << endl;

    // Initializing a list with a initialization list
    list<int> list4 = {1,2,3,4,5,6,7,8};

    // Removes most recent added element on right
    list4.pop_back();
    list4.push_back(100);
    for(int number:list4)
        cout << number << " ";
    cout << endl;

    // Removes oldest elements on left 
    list4.pop_front();
    list4.push_front(100);
    for(int number:list4)
        cout << number << " ";
    cout << "\n\n";

    cout << list4.front() << endl;
    cout << list4.back() << endl;

    list<int> random = {23,56,12,78,23,86,312,7};

    for(int ran: random)
        cout << ran << " ";
    cout << endl;

    list<int> sorted(random);

    sorted.sort();

    for(int sort: sorted)
        cout << sort << " ";
    cout << "\n\n";

    list<string> customers = {"asfd", "sdaf", "asdf"};
    list<string> customers_pending = customers;
    list<int> unsorted = random;

    // Iterating over a container

    list<int> myList = {40,30,50,30,10};

    // Using iterators to iterate through the list
    list<int>::iterator it = myList.begin();
    list<int>::iterator end = myList.end();

    while(it != end){
        cout << *it << " ";
        it++;
    }

    // Printing using a simple for loop
    cout << "\n\n";
    for (list<int>::iterator i = myList.begin(); i != myList.end(); ++i)
        cout << *i << " ";
    spacing();

    // USING SPLICING
    list<int> listP1 = {1,1,1};
    list<int> listP2 = {8,8,8};

    list<int>::iterator iter = listP1.begin();
    advance(iter,2); // Move the iterator one element

    // Inserts a list at the iterator "index"
    listP1.splice(iter , listP2);

    for(auto elem: listP1)
        cout << elem << " ";
    spacing();

    // Just splicing to the begining
    list<int> GroupP1 = {1,1,1};
    list<int> GroupP2 = {8,8,8};

    GroupP1.splice(GroupP1.begin(), GroupP2);

    list<int>::iterator gIt = GroupP1.begin();
    list<int>::iterator gEnd = GroupP1.end();

    while(gIt != gEnd){
        cout << *gIt << " ";
        gIt++;
    }

    // Simply merges the list
    GroupP1.merge(myList);

    gIt = GroupP1.begin();
    gEnd = GroupP1.end();
    while(gIt != gEnd){
        cout << *gIt << " ";
        gIt++;
    }
    spacing();

    // Removes all copies of data
    GroupP1.unique();

    gIt = GroupP1.begin();
    gEnd = GroupP1.end();
    while(gIt != gEnd){
        cout << *gIt << " ";
        gIt++;
    }
    spacing();


    

    return 0;
}
