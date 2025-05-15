/*
    Problem Statement: 
        You are given a special type of linked list node where each node contains three pointers:

        int data: the value of the node.
        Node* next: pointer to the next node on the same level.
        Node* child: pointer to the head of a lower-level linked list (can be null).

        The linked list may have multiple levels of children, forming a multilevel structure.
        Your task is to flatten the list into a single-level linked list. In the flattened list:
        All nodes should appear in a depth-first traversal order.
        The child pointers should be set to null.
        The flattened list should use only next pointers.
    
    Input: A pointer to the head node of a multi-level linked list.
    Output: A pointer to the head node of the flattened single-level linked list.

    Constraints
    1. The depth of child levels is arbitrary (may be more than two levels).
    2. You must flatten in-place (i.e., reusing existing nodes).
    3. List has no cycles

    Example: 
    Input: 
    1 -> 2 -> 3 -> 4 -> 5
              |         |
              7 -> 8 -> 9
                   |
                   12 -> 13

    Output: 
    1 -> 2 -> 3 -> 7 -> 8 -> 12 -> 13 -> 9 -> 4 -> 5
*/

#include <iostream>
#include <unordered_set>
using namespace std;

struct ListNode{
    int data;
    ListNode *next;
    ListNode *prev;
    ListNode *child;

    ListNode(int data): data(data), next(NULL), prev(NULL), child(NULL) {};
};


// Using Recursion
ListNode* flatten(ListNode *head, unordered_set<ListNode*> &visited){
    if(!head){
        return NULL;
    }

    ListNode* current = head;

    while(current){
        visited.insert(current);

        if(current->child){
            if(!visited.count(current->child)){
                ListNode* current_next = current->next; 
                ListNode* flatten_head = flatten(current->child, visited);

                current->next = flatten_head;
                current->child = NULL;
                flatten_head->prev = current;

                // Move to the end of flattened child list
                while(current->next){
                    current = current->next; 
                }

                if(current_next){
                    current->next = current_next;
                    current_next->prev = current;
                }
            }

            else{
                current->child = NULL;
            }
            
        }

        current = current->next;
    }

    return head;   
}

// Helper function to print the flattened list (to test)
void printList(ListNode* head){
    ListNode* curr = head;
    while(curr){
        cout << curr->data;
        if(curr->next) cout << " -> ";
        curr = curr->next;
    }
    cout << endl;
}

void deleteList(ListNode *flatHead){
    cout<< "Deleting List" <<endl;
    ListNode* curr = flatHead;
    while (curr != nullptr) {
        ListNode* next = curr->next;
        cout<<curr->data << "->";
        delete curr;
        curr = next;
    }
}

int main(){
    unordered_set<ListNode*> visited;
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(5);

    ListNode* n7 = new ListNode(7);
    ListNode* n8 = new ListNode(8);
    ListNode* n9 = new ListNode(9);

    ListNode* n12 = new ListNode(12);
    ListNode* n13 = new ListNode(13);

    // Connect next pointers for top-level list
    n1->next = n2; n2->prev = n1;
    n2->next = n3; n3->prev = n2;
    n3->next = n4; n4->prev = n3;
    n4->next = n5; n5->prev = n4;

    // Connect child pointers
    n3->child = n7;

    // Connect next pointers for second level
    n7->next = n8; n8->prev = n7;
    n8->next = n9; n9->prev = n8;

    // Connect child pointer for n8
    n8->child = n12;

    // Connect next pointers for third level
    n12->next = n13; n13->prev = n12;

    // Flatten the list
    ListNode* flatHead = flatten(n1, visited);

    // Print the flattened list
    printList(flatHead);
    deleteList(flatHead);
    return 0;
}
