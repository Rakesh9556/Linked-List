#include <iostream>
#include <vector>
using namespace std;

// Creation of Doubly Linked List
class Node {
    public:
        int data;
        Node* prev;
        Node* next;

        Node(int data, Node* prev, Node* next) {
            this->data = data;
            this->prev = prev;
            this->next = next;
        }

        Node(int data) {
            this->data = data;
            prev = nullptr;
            next = nullptr;
        }

};

// Converting Array to DLL
Node* convertArr2DLL(vector<int> &arr) {
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i=1; i<arr.size(); i++) {
        Node* temp = new Node(arr[i],prev, nullptr);
        prev->next = temp;
        // prev = temp;
        prev = prev->next;

    }
    return head;
    
}

// Print DLL
void print(Node* head) {
    while(head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
}

// Delete head of the DLL
Node* deleteHead(Node* head) {
    if(head == nullptr || head->next == nullptr) return nullptr;
    Node* temp = head;
    head = head->next;
    head->prev= nullptr;
    temp->next = nullptr;
    delete temp;
    return head;
}

// Delete tail of the DLL
Node* deleteTail(Node* head) {
    if(head == nullptr || head->next == nullptr) return nullptr;

// Type 1:
    // Node* temp = head;
    // while(temp->next != nullptr) {
    //     if(temp->next->next == nullptr) {
    //         Node* tail = temp->next;
    //         tail->prev = nullptr
    //         temp->next = nullptr;
    //         delete tail;
    //         break;
    //     }
    //     temp = temp->next;
    // }
    // return head;

// Type 2:
    Node* tail = head;
    while(tail->next != nullptr) tail = tail->next;
    // we are standing at the last node
    Node* newTail = tail->prev;
    newTail->next = nullptr;
    tail->prev = nullptr;
    delete tail;
    return head;
}


// Delete Kth pos elem of the DLL
Node* deleteKthPosElem(Node* head, int pos) {
    if(head == nullptr) return nullptr;

    Node* temp = head;
    int cnt = 0;
    while(temp != nullptr) {
        // standing at kth index
        if(cnt == pos) break;
        cnt++;
        temp = temp->next;
    }

    // if the pos exceeds the size of the LL
    if(temp == nullptr) return head;

    Node* prevElem = temp->prev;
    Node* nextElem = temp->next;

    // if the list conatin only one el 
    if(prevElem == nullptr && nextElem == nullptr) {
        delete temp;
        return nullptr;
    }
    // we are standing at head - call deleteHead()
    else if(prevElem == nullptr) {
        Node* newHead = temp;
        newHead = newHead->next;
        newHead->prev = nullptr;
        temp->next = nullptr;
        delete temp;
        return newHead; 
    }
    // we are standing at tail - call deleteTail()
    else if(nextElem == nullptr) {
        Node* newTail = temp->prev;
        newTail->next = nullptr;
        temp->prev = nullptr;
        delete temp;
        return head;
    }
    // we are standing in between pos 1 to N
    prevElem->next = nextElem;
    nextElem->prev = prevElem;
    temp->prev = nullptr;
    temp->next = nullptr;
    delete temp;
    return head;      
}


// Delete elem K from the DLL
Node* deleteElemK(Node* head, int el) {
    if(head == nullptr) return nullptr;

    Node* temp = head;
    while(temp != nullptr) {
        if(temp->data == el) break;
        temp = temp->next;
    }
    // if the element nut found after complete traversal
    if(temp == nullptr) return nullptr;

    Node* prevElem = temp->prev;
    Node* nextElem = temp->next;

    // if the elem is at head
    if(prevElem == nullptr) {
        head = head->next;
        if(head != nullptr) head->prev = nullptr;
    }
    // if the elem is at tail
    else if(nextElem == nullptr) {
        prevElem->next = nullptr;
    }
    else {
        prevElem->next = nextElem;
        nextElem->prev = prevElem;
    }
    delete temp;
    return head;
}

// Insert elem before head
Node* insertElemBeforeHead(Node* head, int el) {
    if(head == nullptr) {
        return new Node(el);
    }
    Node* newHead = new Node(el);
    newHead->next = head;
    head->prev = newHead;
    return newHead;
}

// Insert elem before tail
Node* insertElemBeforeTail(Node* head, int el) {
    if(head == nullptr) {
        return new Node(el);
    }
    if(head->next == nullptr) return insertElemBeforeHead(head,el);
    Node* temp = head;
    while(temp->next->next != nullptr) {
        temp = temp->next;
    }
    Node* newNode = new Node(el, temp, temp->next);
    Node* tail = temp->next;
    tail->prev = newNode;
    temp->next =newNode;
    return head;
}

// Insert elem before the Kth pos
Node* insertElemBeforeKthPos(Node* head, int el, int pos) {
    if(head == nullptr) return new Node(el);

    Node* temp = head;
    int cnt = 0;
    while(temp != nullptr) {
        if(cnt == pos) break;
        cnt++;
        temp = temp->next;
    }
    // if the pos exceeds after complete tarversal
    if(temp == nullptr) return head;

    Node* prevElem = temp->prev;

    // if the list has only single element
    if(prevElem == nullptr) return insertElemBeforeHead(head, el);
    else if(temp->next == nullptr) return insertElemBeforeTail(head, el);
    
    Node* newNode = new Node(el, prevElem, temp);
    prevElem->next = newNode;
    temp->prev = newNode;
    return head;
}

// Insert elem before the node K
Node* insertElemBeforeNodeK(Node* head, int el, int key) {
    if(head == nullptr) return new Node(el);

    Node* temp = head;
    while(temp != nullptr) {
        if(temp->data == key) break;
        temp = temp->next;
    }
    // if the pos exceeds after complete tarversal
    if(temp == nullptr) return head;

    Node* prevElem = temp->prev;

    // if the list has only single element
    if(prevElem == nullptr) return insertElemBeforeHead(head, el);
    else if(temp->next == nullptr) return insertElemBeforeTail(head, el);
    
    Node* newNode = new Node(el, prevElem, temp);
    prevElem->next = newNode;
    temp->prev = newNode;
    return head;
}

int main() {
vector<int> arr = {100, 53, 5, 8, 10, 7};


// Convert arr to DLL
Node* head = convertArr2DLL(arr);
// print(head);

// Delete head
// head = deleteHead(head);
// print(head);

// Delete tail
// head = deleteTail(head);
// print(head);

// Delete Kth pos elem
// head = deleteKthPosElem(head, 4); // 100, 53, 5, 8, 10, 7
// print(head);

// Delete elem K
// head = deleteElemK(head, 7); // 100, 53, 5, 8, 10, 7
// print(head);

// Insert elem before head
// head = insertElemBeforeHead(head, 500); // 100, 53, 5, 8, 10, 7
// print(head);

// Insert elem before tail
// head = insertElemBeforeTail(head, 87); // 100, 53, 5, 8, 10, 7
// print(head);

// Insert elem before pos K
// head = insertElemBeforeKthPos(head, 87, 5); // 100, 53, 5, 8, 10, 7
// print(head);

// Insert elem before node K
head = insertElemBeforeNodeK(head, 87, 5); // 100, 53, 5, 8, 10, 7
print(head);






}