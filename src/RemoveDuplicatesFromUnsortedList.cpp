#include <iostream>
#include <vector>
#include <unordered_map>

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



Node* removeDuplicatesFromUnsortedList(Node* head) {

// type 1 - nesting
    // if(head == nullptr || head->next == nullptr) return head;

    // Node* temp = head;
    // while(temp != nullptr && temp->next != nullptr) {
    //     Node* current = temp;
    //     while(current != nullptr && current->next != nullptr) {
    //         if(temp->data == current->next->data) {
    //             Node* duplicate = current->next;
    //             current->next = current->next->next;
    //             delete duplicate;
    //         }
    //         else {
    //             current = current->next;
    //         }
    //     }
    //     temp = temp->next;
    // }
    // return head;


// type 2 - sorting
    // 1. Convert the linked list to vector
    // 2. Sort the vector
    // 3. Convert again into linked list
    // 4. Solve as same as sorted list


// type 3 - hashmap
    if(head == nullptr || head->next == nullptr) return head;

    unordered_map<int, bool> mpp;

    Node* current = head;
    Node* prev = nullptr;

    while(current != nullptr) {
        if(mpp.find(current->data) != mpp.end()) {
            // duplicate exist
            prev->next = current->next;
            delete current;
        }
        else {
            // duplicate not exist
            mpp[current->data] = true;
            prev = current;
        }
        current = prev->next;
    }
    return head;

}
int main() {

// Remove duplicate from unsorted list
    vector<int> arr =getArray();

    Node* head = convertArr2LL(arr);
    head = removeDuplicatesFromUnsortedList(head);
    printLL(head);
 
    return 0;
}