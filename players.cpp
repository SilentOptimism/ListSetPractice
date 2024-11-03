#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <fstream>
using std::ifstream;

#include <list>
using std::list;

#include <string>
using std::string;

#include <vector>
using std::vector;

#define print(container) cout << "["; for(auto elem: container){cout << elem << ", ";}; cout << "]\n" 

void fillNames(vector<string> &names){
    ifstream fin;
    fin.open("names.txt");

    if(!fin){
        cout << "BOEVER :skull:" << endl;
        return;
    }

    while(fin){
        string name;
        getline(fin, name);
        if(fin){
            names.push_back(name);
        }
    }
    fin.close();
}

int main(int argc, char const *argv[]){
    std::vector<string> names;

    fillNames(names);

    srand(time(0));
    list<string> customers;

    int num = rand() % 12 + 5;
    for(int i = 0; i< num; i++)
        customers.push_back(names[rand()% names.size()]);

    print(customers);

    customers.sort(); // You can sort strings
    print(customers);


    return 0;
}

