#include<iostream>
using namespace std;
class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x = 0, ListNode* next = nullptr) {
        this->val = x;
        this->next = next;
    }
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp = new ListNode();
        ListNode* current = temp;
        int carry = 0;
        while (l1 || l2 || carry) {
            int sum = carry;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            carry = sum / 10;
            current->next = new ListNode(sum % 10);  // Only the last digit
            current = current->next;
        }
        return temp->next;
    }
};