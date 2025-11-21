
#include <iostream>
#include <string>
#include "StackFactory.hpp"
#include "ArrayStack.hpp"
#include "LinkedListStack.hpp"

using namespace std;

// Helper function to print a divider line
 {
    cout << "\n================ " << title << " ===========\n";
}

int main() {

    //   ===========================================================
    // PART 1: TESTIINg   LINKED list STACK WITH INTEGERS
    //  ======================================================
    divider("LinkedListStack<int>");

    // CreatING a LinkedListStack using the factory (0 → linked list)
    

    cout << "\n--> TEST 1: isEmpty() on new stack\n";
    cout << " Stackk empty ? " << (s->isEmpty() ? "YES " :  "NO ") <<  endl;
 
    cout << "\n--> TEST 2: push() several values\n";
    s->push(10);
    s->push(20);
    s->push(30);  // 30   is on top
    s->print();  

    cout << "\n--> TEST 3: peek()\n";
    cout << "Top vallue  should be 30 → " << s->peek() << endl;

    cout << "\n--> TEST 4: getLength()\n";
    cout << "Length should be 3 → " << s->getLength() << endl;

    cout << "\n--> TEST 5: pop()\n";
    s->pop(); // removes 30
    s->print();
    cout << "New top should be 20 → " << s->peek() << endl;

    cout << "\n--> TEST 6: rotate RIGHT\n";
    // rotate RIGHT: top goes to bottom
    s->rotate(Stack<int>::RIGHT);
    s->print();

    cout << "\n--> TEST 7: rotate LEFT\n";
    // rotate LEFT: bottom goes to top
    s->rotate(Stack<int>::LEFT);
    s->print();

    cout << "\n--> TEST 8: clear()\n";
    s->clear();
    cout << "After clear(), isEmpty? " << (s->isEmpty() ? "YES" : "NO") << endl;


    //   =========================================================
    // PARt 2: TESTING  with STRING DATA TYPE
    // ====================================================
    divider("LinkedListStack<string> STRING TESTS");

    Stack<string>* words = StackFactory<string>::GetStack();

    cout << "\n--> TEST 1: push strings\n";
    words->push("apple");
    words->push("banana");
    words->push("cherry");
    words->print();

    cout << "\n--> TEST 2: peek()\n";
    cout << "Top string should be 'cherry' → " << words->peek() << endl;

    cout << "\n--> TEST 3: rotate RIGHT\n";
    words->rotate(Stack<string>::RIGHT);
    words->print();

    cout << "\n--> TEST 4: pop()\n";
    words->pop();
    words->print();

    cout << "\n--> TEST 5: clear()\n";
    words->clear();
    cout << "Empty now? " << (words->isEmpty() ? "YES" : "NO") << endl;


    // ===========================================================
    // PART 3: COMPARISON TO ARRAYSTACK
    // =================================================
    divider("COMPARISON: LinkedListStack vs ArrayStack (int)");

    // LinkedListStack created with size 0
    Stack<int>* linked = StackFactory<int>::GetStack();

    // ArrayStack created with maxSize 5
    Stack<int>* array = StackFactory<int>::GetStack(5);

    cout << "\n--> Pushing 1, 2, 3 into BOTH stacks\n";
    linked->push(1);
    linked->push(2);
    linked->push(3);

    array->push(1);
    array->push(2);
    array->push(3);

    cout << "LinkedListStack → ";
    linked->print();

    cout << "ArrayStack      → ";
    array->print();

    cout << "\n--> Popping top element from BOTH\n";
    linked->pop();
    array->pop();

    cout << "LinkedListStack → ";
    linked->print();

    cout << "ArrayStack      → ";
    array->print();

    cout << "\n--> Rotating RIGHT on BOTH\n";
    linked->rotate(Stack<int>::RIGHT);
    array->rotate(Stack<int>::RIGHT);

    cout << "LinkedListStack → ";
    linked->print();

    cout << "ArrayStack      → ";
    array->print();


    // ====================================================
    // ENDD OF  TESTS
    // ===========================================================
    divider("ALL TESTS COMPLETE");
    cout << "If everything printed correctly, your LinkedListStack works!\n\n";

    return 0;
}
