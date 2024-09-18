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

// get array
vector<int> getArray() {
    int n;
    vector<int> arr;

    cin >> n;

    for(int i=0; i<n; i++) {
        int num;
        cin >> num;
        arr.push_back(num); // push the element into the vector
    }
    return arr;
}

// Convert arr to linked list
Node* convertArr2LL(vector<int>  &arr) {
    if(arr.size() == 0) return nullptr;

    Node* head = new Node(arr[0]);
    Node* current = head;

    for(auto i=1; i<arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        current->next = temp;
        current = temp; // foraward the pointer
    }
    return head;
}

// Print LL
void printLL( Node* head) {
    while(head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
}


Node* mergeTwoSortedList(Node* list1, Node* list2) {
    if(list1 == nullptr) return list2;
    if(list2 == nullptr) return list1;

    Node* head = nullptr;
    Node* current = nullptr;

    if(list1->data <= list2->data) {
        head = list1; // head will point to the first element of list1
        list1 = list1->next;
    }
    else {
        head = list2;
        list2 = list2->next;
    }

    current = head;

    while(list1 != nullptr && list2 != nullptr) {
        if(list1->data <= list2->data) {
            current->next = list1;
            list1 = list1->next;
        }
        else {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next; // forward the pointer
    }

    // append reamining elements
    if(list1 != nullptr) {
        current->next = list1;
    }
    else {
        current->next = list2;
    }

    return head;
}
int main() {
    vector<int> arr1 = getArray();
    vector<int> arr2 = getArray();


    Node* list1 = convertArr2LL(arr1);
    Node* list2 = convertArr2LL(arr2);

    Node* head = mergeTwoSortedList(list1, list2);

    printLL(head);
    
    
    return 0;
}