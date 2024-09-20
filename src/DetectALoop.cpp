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



bool DetectALoop(Node* head) {
    Node* temp = head;
    unordered_map<Node*, bool> mpp;

    while(temp != nullptr) {
        if(mpp.find(temp) != mpp.end()) return true;
        mpp[temp] = true;
        temp = temp->next;
    }
    return false;
}
int main() {

// Remove duplicate from unsorted list
    vector<int> arr =getArray();

    Node* head = convertArr2LL(arr);
    bool isLoop = DetectALoop(head);
    // printLL(bool);
    cout << isLoop;
 
    return 0;
}