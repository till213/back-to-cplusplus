#include <iostream>
using namespace std;
	
#include "LinkedHashMap.h"

int main() {
    LinkedHashMap<std::string, int> phoneBook;

    phoneBook.insert("Jake", 12345);
    phoneBook.insert("Jill", 67890);
    phoneBook.insert("Joe", 42);
    phoneBook.insert("Jane", 1001);

    cout << "Jake's number: " << *(phoneBook.get("Jake")) << endl;
    cout << boolalpha;
    cout << "Has Jill's number: " << phoneBook.contains("Jill") << endl;
    phoneBook.remove("Jill");
    cout << "Still has Jill's number: " << phoneBook.contains("Jill") << endl;
    for (const auto number : phoneBook) {
        cout << "Phone number: " << number << endl;
    }

    phoneBook.insert("Jake", 54321);
    cout << "Jake's new number: " << *(phoneBook.get("Jake")) << endl;
    for (const auto number : phoneBook) {
        cout << "Phone number: " << number << endl;
    }

    return 0;
}