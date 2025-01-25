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
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;
        ListNode* curr = head;

        while (curr) {
            if (curr->next && curr->val == curr->next->val) {
                int duplicateVal = curr->val;
                while (curr && curr->val == duplicateVal) {
                    ListNode* temp = curr;
                    curr = curr->next;
                    delete temp;
                }
                prev->next = curr;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }

        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};

void printList(ListNode* head) {
    ListNode* curr = head;
    while (curr) {
        cout << curr->val << " -> ";
        curr = curr->next;
    }
    cout << "nullptr" << std::endl;
}

ListNode* createList(const std::vector<int>& values) {
    if (values.empty()) return nullptr;
    ListNode* head = new ListNode(values[0]);
    ListNode* curr = head;
    for (size_t i = 1; i < values.size(); ++i) {
        curr->next = new ListNode(values[i]);
        curr = curr->next;
    }
    return head;
}