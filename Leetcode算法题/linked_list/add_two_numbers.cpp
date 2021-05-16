/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    
    string reverseString(string s) {
        string temp = "";

        for (int i = s.length() - 1; i >= 0; i--) {
            temp += s[i];
        }

        return temp;
    }
    
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3 = NULL;
        int carry = 0;
        string num = "";
        ListNode* current_1 = l1;
        ListNode* current_2 = l2;
        
        while (current_1 != NULL || current_2 != NULL || carry > 0) {
            int sum = (current_1 != NULL ? current_1->val : 0) + (current_2 != NULL ? current_2->val : 0) + carry;
            carry = 0;
            num += to_string(sum % 10);
            carry += sum < 10 ? 0 : 1;
            current_1 = current_1 != NULL ? current_1->next : NULL;
            current_2 = current_2 != NULL ? current_2->next : NULL;
        }
        
        for (char& c : reverseString(num)) {
            l3 = new ListNode(c-48, l3);
        }
        
        return l3;
    }
};
