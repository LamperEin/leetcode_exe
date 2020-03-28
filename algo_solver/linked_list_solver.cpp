#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL) {}
};

struct Node {
    int val;
    Node* next;
    Node* random ;
    Node(int x):val(x), next(NULL), random(NULL){};
};

ListNode* swapPairs(ListNode* head) {
    if(head->next!= NULL) {
        head->next->next = head;
        head;
    }
    return head;
}

ListNode* reverseList_loop(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* cur = head;
    while(cur != NULL) {
        ListNode* next_node_tmp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next_node_tmp;
    }
    return prev;
}

ListNode* reverseList_recur(ListNode* head) {
    if(head==NULL || head->next == NULL) return head;
    ListNode* p = reverseList_recur(head->next);
    head->next->next = head;
    head->next = NULL;
    return p;
}

ListNode* mergeTwoLists_recur(ListNode* l1, ListNode* l2) {
    if(l1 == NULL)
        return l2;
    else if(l2 == NULL)
        return l1;
    ListNode* merged_head = NULL;
    if(l1->val < l2->val) {
        merged_head = l1;
        merged_head->next = mergeTwoLists_recur(l1->next, l2);
    } else {
        merged_head = l2;
        merged_head->next = mergeTwoLists_recur(l1, l2->next);
    }
    return merged_head;
}

ListNode* mergedTwoLists_loop(ListNode* l1, ListNode* l2) {
    if(l1 == NULL && l2 != NULL) return l2;
    if(l1 != NULL && l2 == NULL) return l1;
    if(l1 == NULL && l2 == NULL) return NULL;

    ListNode* merged_head = new ListNode(1);
    ListNode* cur = merged_head;
    while(l1 != NULL && l2 != NULL) {
        if(l1->val <= l2->val) {
            cur->next = l1;
            l1 = l1->next;
        } else {
            cur->next = l2;
            l2 = l2->next;
        }
        cur = cur->next;
    }
    cur->next = l1 == NULL? l2 : l1;
    return merged_head->next;
}

ListNode* deleteNode(ListNode* head, int val) {
    if(head == NULL) return NULL;
    ListNode* cur = head;
    if(head->val == val) {
        return head->next;
    } 
    cur = cur->next;
    ListNode* prev = head;
    while(cur != NULL && cur->val != val) {
        cur = cur->next;
        prev = prev->next;
    }

    prev->next = cur->next;
    return head;
}

ListNode* getKthFromEnd(ListNode* head, int k) {
    if(head == NULL || k == 0) return NULL;
    int list_len = 0;
    ListNode* cur = head;
    while(cur != NULL) {
        cur = cur->next;
        list_len++;
    }
    int n = list_len - k;
    cur = head;
    while(n--)
        cur = cur->next;
    return cur;

}

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    // double pointers
    if(headA == NULL || headB == NULL) return nullptr;
    ListNode* p1 = headA;
    ListNode* p2 = headB;
    while(p1 != p2) {
        p1 = p1 == NULL ? headB : p1->next;
        p2 = p2 == NULL ? headA : p2->next;
    }
    return p1;
}

void deleteDuplication(ListNode** head) {
    if(*head = NULL) return;
    ListNode* pre = nullptr;
    ListNode* cur = *head;
    while(cur != nullptr) {
        ListNode* pnext = cur->next;
        bool is_dupliacte = false;
        if(pnext != nullptr && pnext->val == pre->val)
            is_dupliacte = true;
        if(!is_dupliacte) {
            pre = cur;
            cur = cur->next;
        } else {
            int val = cur->val;
            ListNode* pto_be_delete = cur;
            while(pto_be_delete != nullptr && pto_be_delete->val == val) {
                pnext = pto_be_delete->next;
                delete pto_be_delete;

                pto_be_delete = nullptr;
                pto_be_delete = pnext;
            }
            if(pre == nullptr)
                *head = pnext;
            else pre->next = pnext;
            cur = pnext;
        }
    }
}


Node* copyRandomList(Node* head) {
    if(head == NULL) return head;
    Node* cur = head;
    while(cur) {
        Node* tmp = new Node(cur->val);
        Node* p = cur->next;
        cur->next = tmp;
        tmp->next = p;
        cur = p;
    }
    cur = head;
    while(cur) {
        Node* t = cur->next;
        if(cur->random)
            t->random = cur->random->next;
        else 
            t->random = NULL;
        cur = t->next;
    }
    cur = head;
    Node* ans = head->next;
    Node* preans = head->next;
    while(ans && ans->next) {
        Node* old = ans->next;
        Node* newp = old->next;
        cur->next = old;
        ans->next = newp;
        cur = old;
        ans = newp;
    }
    if(cur) 
        cur->next = nullptr;
    return preans;
}

ListNode* merge(vector<ListNode*>& lists, int start, int end) {
    if(start == end) return lists[start];
    int mid = (start+end)/2;
    ListNode* l1 = merge(lists, start, mid);
    ListNode* l2 = merge(lists, mid+1, end);
    return mergeTwoLists_recur(l1, l2);
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
    if(lists.empty()) return nullptr;
    return merge(lists, 0, lists.size()-1);
}

int main() {
    //int a[30];
    //memset(a, 0, sizeof(a));
    return 0;
}