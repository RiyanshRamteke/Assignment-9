#include <iostream>
#include <string>
#include <vector>
#include <utility>          // std::move is in this header
using namespace std;

// A small class that owns memory (made with new)
class Box {
public:
    int *data;

    Box(int value) {                       // normal constructor
        data = new int(value);
        cout << "Constructor called" << endl;
    }

    Box(const Box &other) {                // COPY constructor
        data = new int(*other.data);       // makes a NEW copy of the value
        cout << "Copy constructor called (new memory created)" << endl;
    }

    Box(Box &&other) {                     // MOVE constructor (&& = rvalue reference)
        data = other.data;                 // just take the pointer
        other.data = nullptr;              // old object gives up the memory
        cout << "Move constructor called (pointer taken, no new memory)" << endl;
    }

    ~Box() {
        delete data;
    }

    void show(string name) {
        if (data != nullptr)
            cout << name << " value = " << *data << endl;
        else
            cout << name << " is empty (data is nullptr)" << endl;
    }
};

int main() {
    string word;
    int num;
    cout << "Enter a word and a number: ";
    cin >> word >> num;

    // ---------- 1. std::move with string ----------
    cout << endl << "--- 1. String ---" << endl;
    string s1 = word;
    string s2 = s1;                        // copy: s1 and s2 both have the word
    cout << "After copy: s1 = [" << s1 << "], s2 = [" << s2 << "]" << endl;

    string s3 = move(s1);                  // move: s3 takes the word from s1
    cout << "After move: s1 = [" << s1 << "], s3 = [" << s3 << "]" << endl;

    // ---------- 2. std::move with vector ----------
    cout << endl << "--- 2. Vector ---" << endl;
    vector<int> v1 = {1, 2, 3, 4, 5};
    vector<int> v2 = move(v1);             // v2 takes all elements of v1
    cout << "v1 size = " << v1.size() << endl;
    cout << "v2 size = " << v2.size() << endl;

    // ---------- 3. Copy constructor vs Move constructor ----------
    cout << endl << "--- 3. Copy and Move Constructor ---" << endl;
    Box b1(num);
    Box b2 = b1;                           // copy constructor is called
    Box b3 = move(b1);                     // move constructor is called

    b1.show("b1");
    b2.show("b2");
    b3.show("b3");

    return 0;
}