/*
    Problem Statement: 
        Input:  1 → 2 → 3 → 4 → 5 → NULL  
        Output: 5 → 4 → 3 → 2 → 1 → NULL
*/

#include <iostream>
using namespace std;

struct ListNode{
    int x;
    ListNode *next = NULL;

    ListNode(int x) : x(x), next(NULL) {};

};

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->x;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << " -> NULL" << endl;
}

void deleteList(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

ListNode* linked_list_reversal(ListNode *head){
    if (not head or not head->next){
        return head;
    }

    ListNode* current = head;
    ListNode *prev = NULL;
    ListNode *temp = head;

    while(current){
        current = current->next;
        temp->next = prev;
        prev = temp;
        temp = current;
    }

    return prev;

}

int main(){

    // Create a sample linked list: 1 → 2 → 3 → 4 → 5 → NULL
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original List: ";
    printList(head);

    // Reverse the list
    ListNode* reversedHead = linked_list_reversal(head);

    cout << "Reversed List: ";
    printList(reversedHead);
    deleteList(reversedHead);
    
    return 0;
}