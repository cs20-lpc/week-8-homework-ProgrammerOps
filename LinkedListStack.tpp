
template <typename T>
LinkedListStack<T>::LinkedListStack() {
    // Start with an empty stacCk (no nodes)
    //    top = nullptr means the stack has no first node yet.
    top = nullptr;

    //    ------length tracks how many items are in the stack.
    this->length = 0;
}

template <typename T>
LinkedListStack<T>::LinkedListStack(const LinkedListStack<T>& copyObj) {
    // UseS the helper function to "deep copy " the other  stack.
    //   This builds new nodes so the two stacks don't share  memory.
    copy(copyObj); 
}

template <typename T>
LinkedListStack<T>& LinkedListStack<T>::operator=(const LinkedListStack<T>& rightObj) {
    // Prevent self-copy. (Copying yourself would delete your own data.)
    if (this != &rightObj) {
        clear();        // remove current nodes from  THIS stack
        copy(rightObj); // copy nodes  from the source stack
    }
    return *this;       // return the updated object
}

template <typename T>
LinkedListStack<T>::~LinkedListStack() {
    // When stack is destroyed,  delete all nodes toO avoid memory leaks.
    clear();
}

template <typename T>
void LinkedListStack<T>::clear() {
    // Walk through  the linked list and delete each node.
    // Think: we' re removing train cars one by  one.
    Node<T>* curr = top;

    while (curr != nullptr) {
        Node<T>* temp = curr;     // save  the current car
        curr = curr->next;        // move to  the next car
        delete temp;              // delete the old car
    }

    // After deleting everything:
    top = nullptr;                // no cars left
    this->length = 0;             // length  resets to zero
}

template <typename T>
void LinkedListStack<T>::copy(const LinkedListStack<T>& copyObj) {
    // Start fresh with no nodes.
    top = nullptr;
    this->length = 0;

    // If the source stack is empty, nothing to copy.
    if (copyObj.top == nullptr)
        return;

    // Copy the first node separately to set up the list.
    top = new Node<T>(copyObj.top->data);
    this->length = 1;

    // Pointers to walk the old and new lists.
    Node<T>* currNew = top;                // follows the NEW train
    Node<T>* currOld = copyObj.top->next;  // follows the OLD train

    // Copy each remaining node.
    while (currOld != nullptr) {
        // Create new node with same data as old node.
        currNew->next = new Node<T>(currOld->data);

        // Advance both pointers.
        currNew = currNew->next;
        currOld = currOld->next;

        this->length++;    // increase length as we add cars
    }
}

template <typename T>
int LinkedListStack<T>::getLength() const {
    // Just return the number of nodes.
    return this->length;
}

template <typename T>
bool LinkedListStack<T>::isEmpty() const {
    // Stack empty if length is zero.
    return this->length == 0;
}

template <typename T>
T LinkedListStack<T>::peek() const {
    // Can't peek if stack is empty.
    if (isEmpty()) {
        throw runtime_error("Stack is empty, cannot peek.");
    }

    // Return the value in the top node (first train car).
    return top->data;
}

template <typename T>
void LinkedListStack<T>::pop() {
    // Can't pop if empty.
    if (isEmpty()) {
        throw runtime_error("Stack is empty, cannot pop.");
    }

    // Remove the top node.
    Node<T>* temp = top;   // save the old top
    top = top->next;       // move top to the next node
    delete temp;           // delete the removed node

    this->length--;        // stack now has one fewer node
}

template <typename T>
void LinkedListStack<T>::push(const T& elem) {
    // Create a new node containing the new element.
    // Think: a brand-new train car.
    Node<T>* newNode = new Node<T>(elem);

    // New node points to the old top node.
    newNode->next = top;

    // Now the new node becomes the new top.
    top = newNode;

    this->length++;        // stack size increases
}

template <typename T>
void LinkedListStack<T>::rotate(typename Stack<T>::Direction dir) {
    // No rotation needed if 0 or 1 nodes.
    if (this->length <= 1)
        return;

    // ---------------------------------------------------
    // RIGHT ROTATION:
    // Move the top node to the bottom.
    // Example: TOP → [A, B, C] becomes [B, C, A].
    // ---------------------------------------------------
    if (dir == Stack<T>::RIGHT) {
        Node<T>* oldTop = top;    // save the top node
        top = top->next;          // new top becomes the second node

        // Find the last node in the list.
        Node<T>* curr = top;
        while (curr->next != nullptr) {
            curr = curr->next;
        }

        // Attach old top at the end.
        curr->next = oldTop;
        oldTop->next = nullptr;   // old top is now the LAST node
    }

    // ---------------------------------------------------
    // LEFT ROTATION:
    // Move the bottom node to the top.
    // Example: TOP → [A, B, C] becomes [C, A, B].
    // ---------------------------------------------------
    else {
        Node<T>* curr = top;

        // Move until curr is at the second-to-last node.
        while (curr->next->next != nullptr) {
            curr = curr->next;
        }

        // curr->next is the last node.
        Node<T>* last = curr->next;

        // Remove last node from its position.
        curr->next = nullptr;

        // Make last node the new top.
        last->next = top;
        top = last;
    }
}

template <typename T>
void LinkedListStack<T>::print() {
    cout << "LinkedListStack contents: ";

    if (isEmpty()) {
        cout << "Stack is empty, no elements to display.\n";
    }
    else {
        // Walk the list from top to bottom.
        Node<T>* curr = top;

        while (curr != nullptr) {
            cout << curr->data << "\t";  // print each node's data
            curr = curr->next;           // move to next node
        }

        cout << endl;
    }
}
