#include <iostream>
#include <vector>
using namespace std;


class Node {
    public:
        int data;
        Node* next;

        Node(int data, Node* next) {
            this->data = data;
            this->next = next;
        }

        Node(int data) {
            this->data = data;
            next = nullptr;
        }
};


// convert array to linkedlist
Node* convertArr2LL(vector<int> &arr) {
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for(int i=1; i<arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }

    return head;
}

// Length of linked list
int lengthofLL(Node* head) {
    Node* temp = head;
    int cnt = 0;

    while(temp) {
        temp = temp->next;
        cnt++;
    }
    return cnt;
}

// Search element
int checkIfPresent(Node* head, int key) {
    Node* temp = head;

    while(temp) {
        if(temp->data == key) return 1;
        temp = temp->next;
    }
    return 0;
}

// Print linked list
void print(Node* head) {
    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

// Delete linked list - head
Node* removeHead(Node* head) {
    if(head == NULL) return head;
    Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Delete linked list - tail
Node* removeTail(Node* head) {
    if(head == NULL || head->next == NULL) return NULL;
    Node* temp = head;
    while(temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return head;
}

// Delete linked list - Kth pos
Node* removeKthPos(Node* head, int k) {
    if(head== NULL) return NULL;
    if(k == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    int cnt = 0;
    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL) {
        cnt++;
        if(cnt == k) {
            // prev->next = prev->next->next;
            prev->next = temp->next;
            delete temp;
            break;
        }
        // move ahead
        prev = temp;
        temp = temp->next;
    }
    return head;
}

// Delete element K
Node* removeElemK(Node* head, int el) {
    if(head == nullptr) return nullptr;
    if(head->data == el) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;

    }
    Node* temp = head;
    Node* prev = nullptr;
    while(temp != nullptr) {
        if(temp->data == el) {
            prev->next = temp->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;

}

// Inserting a new node at the head
Node* insertHead(Node* head, int el) {

// type 1
    // Node* temp = new Node(el, nullptr);
    // temp->next = head;
    // return temp;

// type 2
    // Node* temp = new Node(el, head);
    // return temp;

// type 3
    return new Node(el, head);
}


// Inserting a new node at the tail
Node* insertTail(Node* head, int el) {
    if(head == nullptr) return new Node(el);
    Node* temp = head;
    while(temp->next != nullptr) {
        temp = temp->next;
    }
    // reaches last
    Node* node = new Node(el, nullptr);
    temp->next = node;
    return head;
}

// Inserting a new node at kth pos
Node* insertAtPos(Node* head, int el, int pos) {
// Type 1
    // if(head == nullptr) {
    //     if(pos == 0) return new Node(el, nullptr);
    //     else return head;
    // }
    // // if head exist and pos = 0
    // if(pos == 0) {
    //     // Node* temp = new Node(el, head);
    //     // return temp;
    //     return new Node(el, head);
    // }
    // int cnt = 0;
    // Node* temp = head;
    // while(temp != nullptr) {
    //     if(cnt == (pos -1)) {
    //         Node* newNode = new Node(el);
    //         newNode->next = temp->next;
    //         temp->next = newNode;
    //         break;
    //     }
    //     cnt++;
    //     temp = temp->next;
    // }
    // return head;

// Type 2
    if(head == nullptr) {
        if(pos == 0) return new Node(el);
        else return head;
    }
    if(pos == 0) {
        return new Node(el, head);
    }

    Node* temp = head;
    Node* prev = nullptr;
    int cnt = 0;
    while(temp != nullptr) {
        if(cnt == pos) {
            Node* newNode = new Node(el, temp);
            prev->next = newNode;
            break;
        }
        prev = temp;
        temp = temp->next;
        cnt++;
    }

    // if temp is null, means pointer exceeds last node
    // append new node at the end
    if(cnt == pos && temp == nullptr) {
        Node* newNode = new Node(el, nullptr);
        prev->next = newNode;
    }
    return head;   
}


// Insert el before the value of x
Node* insertElemBeforeVal (Node* head, int el, int X) {
    if(head == nullptr) return nullptr;
    // if X is the head
    if(head->data == X) {
        return new Node(el, head);
    }
    Node* temp = head;
    while(temp->next != nullptr) {
        if(temp->next->data == X) {
            Node* newNode = new Node(el, temp->next);
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
    return head;
}




int main() {

    // vector<int> arr = {2, 5, 8, 7};

    // it is treated as object
    // Node y = Node(arr[0], nullptr);
    // cout << y.data << endl;
    // cout << y.next;

     // it is treated as node
    // Node* y = new Node(arr[0], nullptr);
    // cout << y->data << endl;
    // cout << y;

// Converting array to LL
    // vector<int> arr = {12, 5, 8, 7};
    // Node* head = convertArr2LL(arr);
    // cout << head->data ; 

// Traversing the LL
    // vector<int> arr = {12, 5, 8, 7};
    // Node* head = convertArr2LL(arr);
    // Node* temp = head;

    // while(temp) {
    //     // cout << temp->data << " ";
    //     temp = temp->next;
    // }

// Length of LL
    // int len = lengthofLL(head);
    // cout << "Len: " << len;

// // Serach an element 
//     vector<int> arr = {12, 5, 8, 7};
//     cout << "Is present: " << checkIfPresent(head, 9);


// Delete linked list(head)
    // vector<int> arr = {12, 5, 8, 7};
    // Node* head = convertArr2LL(arr);
    // head = removeHead(head);
    // print(head);

// Delete linked list(tail)
    // vector<int> arr = {12, 5, 8, 7};
    // Node* head = convertArr2LL(arr);
    // head = removeTail(head);
    // print(head);


// Delete linked list(Kth elem)
    // vector<int> arr = {12, 5, 8, 7};
    // Node* head = convertArr2LL(arr);
    // head = removeKthPos(head, 2);
    // print(head);


// Delete linked list(elem K)
    // vector<int> arr = {12, 5, 8, 7};
    // Node* head = convertArr2LL(arr);
    // head = removeElemK(head, 7);
    // print(head);


// Inserting a new node at head
    // vector<int> arr = {12, 5, 8, 7};
    // Node* head = convertArr2LL(arr);
    // // head = insertHead(head, 87);
    // head = new Node(500, head);
    // print(head);    


// Inserting a new node at tail
    // vector<int> arr = {12, 5, 8, 7};
    // Node* head = convertArr2LL(arr);
    // head = insertTail(head, 1000);
    // print(head); 


// Inserting a new node at pos X
    // vector<int> arr = {12, 5, 8, 7};
    // Node* head = convertArr2LL(arr);
    // head = insertAtPos(head, 50, 4);
    // print(head); 


// Inserting a new node before element X
    vector<int> arr = {12, 5, 8, 7};
    Node* head = convertArr2LL(arr);
    head = insertElemBeforeVal(head, 500, 5);
    print(head);

    




}