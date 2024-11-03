#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <string>
#include <list>

// Clear terminal command
#ifdef _WIN32
#include <conio.h>
#else
#include <stdio.h>
#define clrscr() printf("\e[1;1H\e[2J")
#endif


using std::list;
using std::string;

class chat
{
private:
    string name;
    list<string> externalUser;
    list<string>::iterator ePtr;

    list<string> internalUser;
    list<string>::iterator iPtr;

    void messageFromExternal(string message)     {externalUser.push_front(message);}
    void messageFronInternal(string message)     {internalUser.push_front(message);}

    void deleteOldExternalUser()    {externalUser.pop_front();}
    void deleteOldInternalUser()    {internalUser.pop_front();}


public:
    chat(string name): name(name) {
        ifstream fin;


        iPtr = internalUser.end();
        ePtr = externalUser.end();

        fin.close();
    };

};

int main(int argc, char const *argv[]){

    return 0;
}

