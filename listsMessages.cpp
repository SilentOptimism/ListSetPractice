#include <iostream>
#include <string>
#include <list>

#ifdef _WIN32
#include <conio.h>
#else
#include <stdio.h>
#define clrscr() printf("\e[1;1H\e[2J")
#endif


using std::list;
using std::cout;
using std::cin;
using std::endl;
using std::string;

class chat
{
private:
    string name;
    list<string> externalUser;
    list<string> internalUser;

    void messageFromExternal(string message)     {externalUser.push_front(message);}
    void messageFronInternal(string message)     {internalUser.push_front(message);}

    void deleteOldExternalUser()    {externalUser.pop_front();}
    void deleteOldInternalUser()    {internalUser.pop_front();}


public:
    chat(string name): name(name) {};

};

int main(int argc, char const *argv[]){

    return 0;
}

