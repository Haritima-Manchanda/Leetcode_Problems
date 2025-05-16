/*
    Problem Statement: 
        Find the middle node of a singly linked list.

        Example 1: Odd number of nodes
            Input: 1 → 2 → 3 → 4 → 5
            Output: Node with value 3
            Explanation: The middle node in the list of length 5 is node number 3.

            Example 2: Even number of nodes (default: second middle)
            Input: 1 → 2 → 3 → 4 → 5 → 6
            Output: Node with value 4
            Explanation: The two middle nodes are 3 and 4. By default, the function returns the second middle node (4).

            Example 3: Even number of nodes (first middle)
            Input: 1 → 2 → 3 → 4 → 5 → 6
            Output: Node with value 3
            Explanation: Returning the first middle node instead of the second.
*/

#include <iostream>
using namespace std;

struct ListNode{
    int data;
    ListNode *next;

    ListNode(int data): data(data), next(NULL) {}
};

ListNode *second_middle_node(ListNode *head){
    if(!head || !head->next){
        return head;
    }

    ListNode* fast = head;
    ListNode *slow = head;

    while(fast && fast->next){
        slow = slow->next; 
        fast = fast->next->next;
    }

    return slow;
}


ListNode *first_middle_node(ListNode *head){
    if(!head || !head->next){
        return head;
    }

    ListNode* fast = head;
    ListNode *slow = head;

    while(fast && fast->next->next){
        slow = slow->next; 
        fast = fast->next->next;
    }

    return slow;
}

void deleteList(ListNode *head){
    ListNode* current = head;
    while(head){
        head = head->next;
        delete current;
        current = head;
    }
}

int main() {
    // Create linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);

    // Call second_middle_node (default behavior)
    ListNode* secondMid = second_middle_node(head);
    cout << "Second Middle Node: " << (secondMid ? secondMid->data : -1) << endl;

    // Call first_middle_node (alternate behavior)
    ListNode* firstMid = first_middle_node(head);
    cout << "First Middle Node: " << (firstMid ? firstMid->data : -1) << endl;

    // Free allocated memory
    deleteList(head);

    return 0;
}
