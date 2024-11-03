#include <iostream>
using std::endl;
using std::cout;
using std::cin;

#include <set>
using std::set;

// Sets are Associative containers: arranged according to their association to each other

// Whats a set?
//      Stores unique elements in a specific order
//      Order is determined by the elements value
//      Automatically ensures that all elements are unique
//      Unique/Sorted Ensures fast search operations

// Implementation?
//      It is implemented as a balanced binary search tree?
//      Commonly a Red-Black Tree we will eventuall start talking about trees
//      Each element in the set is distinct and sorted according to its value
//      It supports bidirectional iteration
//              Allowing the ability to iterate the set in both ascending and descending order
//
//      UNLIKE std::vector,deque,set you have no direct access to elements by their position
//      As elements are stored in a tree structure. This design choice ensures efficient insertion
//      , deletion, and search operations, but does not support random access as efficiently
//
// Properties?
//      Unique elements: automatically prevent duplicate entries
//      Ordered elements are stored in a sorted order fascilitating fast searches
//      Bidirectional iteration: iterators can move forward and backward through the set
//
// Usecases?
//      When you need to maintain a collection of unique items with fast search, insertion, and deletion
//      Ideal for situations where the order of elements and uniqueness are important


int main(int argc, char const *argv[])
{

    set<int> test;

    return 0;
}
