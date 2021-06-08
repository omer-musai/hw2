#include <iostream>
using std::cout;
using std::endl;

#include "sortedList.h"

inline bool isEven(int value)
{
    return !(value % 2);
}

inline int increment(int value)
{
    return value + 1;
}

inline int nthn(int value) {return value;}

int main()
{
    //Attempt to destroy an empty list:
    {
        SortedList<int> empty;
    }

    SortedList<int> list, list_copy;
    list_copy.insert(133);
    list.insert(5);
    list.insert(3);
    list.insert(4);
    list.insert(6);
    list.insert(0);
    list.insert(10);
    list_copy = list;
    list.insert(-1);
    list_copy.insert(-2);
    list_copy.insert(77);

    cout << "Original list:\n";
    for (SortedList<int>::const_iterator i = list.begin(); i != list.end(); ++i)
    {
        cout << (*i) << " ";
    }
    cout << "\n" << list.length() << "\n";

    cout << "\nlist_copy:\n";
    for (SortedList<int>::const_iterator i = list_copy.begin(); i != list_copy.end(); ++i)
    {
        cout << (*i) << " ";
    }
    cout << "\n" << list_copy.length() << endl;

    cout << "\neven_list:\n";
    SortedList<int> even_list = list.filter(isEven);
    for (SortedList<int>::const_iterator i = even_list.begin(); i != even_list.end(); ++i)
    {
        cout << (*i) << " ";
    }
    cout << "\n" << even_list.length() << endl;

    cout << "\nOriginal list again (to ensure it wasn't modified by filter):\n";
    for (SortedList<int>::const_iterator i = list.begin(); i != list.end(); ++i)
    {
        cout << (*i) << " ";
    }
    cout << "\n" << list.length() << "\n";

    cout << "\neven_list after removing the second item:\n";
    SortedList<int>::const_iterator iterator = even_list.begin();
    ++iterator;
    even_list.remove(iterator);
    for (SortedList<int>::const_iterator i = even_list.begin(); i != even_list.end(); ++i)
    {
        cout << (*i) << " ";
    }
    cout << "\n" << even_list.length() << endl;

    cout << "\neven_list after removing second element again:\n";
    iterator = even_list.begin();
    ++iterator;
    even_list.remove(iterator);
    for (SortedList<int>::const_iterator i = even_list.begin(); i != even_list.end(); ++i)
    {
        cout << (*i) << " ";
    }
    cout << "\n" << even_list.length() << endl;

    cout << "\neven_list after incrementing all elements by 1:\n";
    SortedList<int> even_list_incremented = even_list.apply(increment);
    for (SortedList<int>::const_iterator i = even_list_incremented.begin();
        i != even_list_incremented.end();
        ++i)
    {
        cout << (*i) << " ";
    }
    cout << "\n" << even_list.length() << endl;

    return 0;
}