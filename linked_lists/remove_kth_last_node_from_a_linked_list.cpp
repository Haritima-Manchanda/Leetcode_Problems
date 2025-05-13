/*
    Problem Statement: 
        Given the head of a singly linked list, remove the k-th node from the end of the list and return its head.
        Your solution should work in one pass.
        You may assume that k is valid, i.e., 1 ≤ k ≤ length of list.


        Example 1:
            Input:
            List: dummy->1 → 2 → 3 → 4 → 5 → NULL
            k = 2

            Output:
            1 → 2 → 3 → 5 → NULL

            Explanation: The 2nd node from the end is 4, which gets removed.

            🧪 Example 2:
            Input:
            List: 1 → 2 → NULL
            k = 2

            Output:
            2 → NULL

            Explanation: The 2nd node from the end is 1, which gets removed (head is updated).
*/

#include <iostream>
using namespace std;

struct ListNode {
    int x;
    ListNode *next;
    ListNode(int x): x(x), next(NULL) {};
};

ListNode* remove_kth_last_node_from_a_linked_list(ListNode* head, int k) {
    // Create a dummy node to handle edge cases like removing the head
    ListNode *dummy = new ListNode(0);
    dummy->next = head;

    ListNode *fast = dummy;
    ListNode *slow = dummy;

    // Move fast pointer k+1 steps ahead
    for (int i = 0; i < k; i++) {
        fast = fast->next;
    }

    // Move both fast and slow until fast reaches the end
    while (fast->next) {
        slow = slow->next;
        fast = fast->next;
    }

    // Remove the k-th node from the end
    ListNode* temp = slow->next;
    slow->next = slow->next->next;
    delete temp;

    head = dummy->next;
    delete dummy;  // Clean up the dummy node
    return head;
}

void printList(ListNode *head) {
    ListNode *current = head;
    while (current) {
        cout << current->x << "->";
        current = current->next;
    }
    cout << "NULL" << endl;
}

// Function to delete the entire linked list and free memory
void deleteList(ListNode *head) {
    ListNode *current = head;
    while (current) {
        ListNode *next = current->next;
        delete current;  // Free the current node
        current = next;  // Move to the next node
    }
}

int main() {
    // Create a sample linked list: 1 → 2 → 3 → 4 → 5 → NULL
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 2; // Remove 2nd node from the end (node with value 4)

    printList(head);
    head = remove_kth_last_node_from_a_linked_list(head, k);
    printList(head);
    deleteList(head);

    head = new ListNode(1);
    head->next = new ListNode(2);

    printList(head);
    head = remove_kth_last_node_from_a_linked_list(head, k);
    printList(head);


    return 0;
}