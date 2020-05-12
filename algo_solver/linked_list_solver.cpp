#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL) {}
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

ListNode* addTwoNumber(ListNode* l1, ListNode* l2) {
    ListNode ans_head(0), *p = &ans_head;
    int carry = 0;
    while(l1 || l2 || carry)  {
        int tmp = 0;
        if(l1) tmp += l1->val;
        if(l2) tmp += l2->val;
        tmp += carry;
        
        carry = tmp / 10;
        tmp %= 10;
        ListNode* nextnode = l1? l1 : l2;
        if(nextnode==NULL) nextnode = new ListNode(tmp);
        nextnode->val = tmp;
        p->next = nextnode;
        p = p->next;
        l1 = l1? l1->next : NULL;
        l2 = l2? l2->next : NULL;
    }
    return ans_head.next;
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

/** leetcode-328 奇偶链表
 *  @input: 1->2->3->4->5->NULL
 *  @output: 1->3->5->2->4->NULL 
 */
ListNode* oddEvenList(ListNode* head) {
    if(head == nullptr) return NULL;
    ListNode* pslow = head;
    ListNode* pfast = head->next;
    ListNode* evenhead = pfast;
    while(pfast != nullptr) {
        pslow->next = pfast->next;
        if(pslow->next == nullptr) break; 
        pslow = pslow->next;
        pfast->next = pslow->next;
        pfast = pfast->next;
    }
    pslow->next = evenhead;
    return head;
}

/** leetcode-141 环形链表
 *  @input：[3, 2, 0 , -4], pos = 1
 *  @output: 2
 */
ListNode* hasCycle(ListNode* head) {
    if(head == NULL || head->next == NULL) return NULL;
    ListNode* cur1 = head;
    ListNode* cur2 = head;
    while(cur2 != NULL) {
        cur1 = cur1->next;
        cur2 = cur2->next;
        if(cur2 != NULL) cur2 = cur2->next;
        if(cur1 == cur2) return cur1;
    }
    return NULL;
}

/** leetcode-142 环形链表II
 *  @input: [3, 2, 0, -4]
 *  @output: tail connects to node index 1
 */
ListNode* detectCycle(ListNode* head) {
    ListNode* pnode = hasCycle(head);
    if(pnode == NULL) return NULL; 
    ListNode*pnode2 = pnode->next;
    int len = 1;
    while(pnode2 != pnode) {
        pnode2 = pnode2->next;
        len++;
    }
    pnode = head;
    pnode2 = head;
    while(len--) 
        pnode2 = pnode2->next;
    while(pnode != pnode2) {
        pnode = pnode->next;
        pnode2 = pnode2->next;
    }
    return pnode;
}

/** leetcode-19 删除链表的倒数第N个节点
 *  @input: [1, 2, 3, 4, 5] ,n = 2
 *  @output: [1, 2, 3, 5]
 */
ListNode* removeNthFromEnd(ListNode* head, int n) {
    if(head == NULL) return NULL;
    ListNode* pslow = head;
    ListNode* pfast = head;
    while(n--) {
        pfast = pfast->next;
        if(pfast == NULL)
            return head->next;
    }

    while(pfast != NULL) { // [1, 2] n = 1; [1, 2, 3, 4, 5], n = 1
        pfast = pfast->next;
        if(pfast == NULL) break;
        pslow = pslow->next;
    }
    pslow->next = pslow->next->next;
    return head;
}

/** leetcode-203 移除链表元素
 *  @input: 1->2->6->3->4->5->6, val = 6
 *  @output: 1->2->3->4->5
 */
ListNode* removeElements(ListNode* head, int val) {
    if(head == NULL) return NULL;
    ListNode* dummyhead = new ListNode(-1);
    dummyhead->next = head;
    ListNode* p = dummyhead;
    ListNode* s = NULL;
    while(p->next != NULL) {
        if(p->next->val == val) {
            s = p->next;
            p->next = p->next->next;
            delete s;
        } else 
            p = p->next;
    }
    return dummyhead->next;
}


/** leetcode-445 两数相加II
 *  @input: (7->2->4->3)+(5->6->4)
 *  @output: 7->8->0->7
 */
ListNode* addTwoNumber2(ListNode* l1, ListNode* l2) {
    stack<int> s1, s2;
    while (l1) {
        s1.push(l1 -> val);
        l1 = l1 -> next;
    }
    while (l2) {
        s2.push(l2 -> val);
        l2 = l2 -> next;
    }
    int carry = 0;
    ListNode* ans = nullptr;
    while (!s1.empty() or !s2.empty() or carry != 0) {
        int a = s1.empty() ? 0 : s1.top();
        int b = s2.empty() ? 0 : s2.top();
        if (!s1.empty()) s1.pop();
        if (!s2.empty()) s2.pop();
        int cur = a + b + carry;
        carry = cur / 10;
        cur %= 10;
        auto curnode = new ListNode(cur);
        curnode -> next = ans;
        ans = curnode;
    }
    return ans;
}

/** leetcode-234 回文链表
 *  @input: 1->2->2->1 @output: true
 *  @input: 1->2       @output: false
 */
bool isPalindrome(ListNode* head) {
    if(head == NULL || head->next == NULL) return true;
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast->next != NULL && fast->next->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    slow = reverseList_recur(slow->next);
    fast = head;
    while(slow != NULL) {
        if(fast->val != slow->val) return false;
        slow = slow->next;
        fast = fast->next;
    }
    return true;
}

/** leetcode-61 旋转链表
 *  @input：1->2->3->4->5->NULL, k=2;
 *  @output: 4->5->1->2->3->NULL
 */
ListNode* rotateRight(ListNode* head, int k) {
    if(head == NULL || head->next == NULL || k == 0) return head;
    int cnt = 1;
    ListNode* cur = head;
    while(cur->next != NULL) {
        cnt++;
        cur = cur->next;
    }
    k %= cnt;
    if(k == 0) return head;
    cur->next = head;
    for(int i = 0; i < cnt-k; i++)
        cur = cur->next;
    ListNode* ans = cur->next;
    cur->next = NULL;
    return ans;
}

/** leetcode-24 两两交换链表中的节点
 *  @input: 1->2->3->4  @output: 2->1->4->3
 */
ListNode* swapPairs2(ListNode* head) {
    if(head == NULL || head->next == NULL) return head;
    ListNode* cur = head;
    ListNode* dummy = new ListNode(-1);
    dummy->next = head;
    ListNode* prev = dummy;
    while(cur != NULL && cur->next != NULL) {
        ListNode* t1 = cur;
        ListNode* t2 = cur->next;
        cur = t2->next;
        prev->next = t2;
        t2->next = t1;
        t1->next = cur;
        prev = t1;
    }
    return dummy->next;
}
// the helper function for mergeKLists
struct cmp {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

/** leetcode-23 合并K个排序链表
 *  @param：a vector contains K ordered linked lists
 *  @return: a linked list
 */
ListNode* mergeKLists(vector<ListNode*>& lists) {
    if(lists.size() == 0) return NULL;
    ListNode* dummy = new ListNode(-1);
    ListNode* cur = dummy;
    priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
    for(ListNode* list : lists) {
        if(list) pq.push(list);
    }
    while(!pq.empty()) {
        ListNode* node = pq.top();
        pq.pop();
        cur->next = new ListNode(node->val);
        cur = cur->next;
        node = node->next;
        if(node) pq.push(node);
    }
    return dummy->next;
}

// the head function for sortList
ListNode* cut(ListNode* head, int n) {
    ListNode* p = head;
    while(--n && p) 
        p = p->next;
    
    if(!p) return NULL;
    auto next = p->next;
    p->next = NULL;
    return next;
}


/** leetcode-148 排序链表
 *  @param: a linked list
 *  @return: a sorted linked list
 */
ListNode* sortList(ListNode* head) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode* p = head;
    int len = 0;
    while(p) {
        ++len;
        p = p->next;
    }
    for(int i = 1; i < len; i <<= 1) {
        ListNode* cur = dummy.next;
        ListNode* tail = &dummy;

        while(cur) {
            ListNode* left = cur;
            ListNode* right = cut(left, i);
            cur = cut(right, i);

            tail->next = mergedTwoLists_loop(left, right);
            while(tail->next)
                tail = tail->next;
        }
    }
    return dummy.next;
}

int main() {
    
    return 0;
}