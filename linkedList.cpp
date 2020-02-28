#include <iostream>
using namespace std;



class MyLinkedList {
public:
    struct Node {
        int val;
        Node *next;
        Node(int x): val(x), next(NULL) {}
    };
    /** Initialize your data structure here. */
    MyLinkedList() {
        length = 0;
        head = NULL;
        //MyLinkedList *next;

    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        Node *cur = head;
        int pos = 0;
        if (index <= length) {
            for (int i = 0; i < index; i++) {
                cur = cur->next;
            }
            return cur->val;
        }
        return -1;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion,
     *  the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node *newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        length++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node *newNode = new Node(val);
        Node* cur = head;
        while (cur->next != NULL)
            cur = cur->next;
        cur->next = newNode;
        length++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. 
     * If index equals to the length of linked list, the node will be appended to the end of linked list. 
     * If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index == length) addAtTail(val);
       
        if (index >= 0 && index < length) {
            Node *newNode = new Node(val);
            Node *pre = head;
            Node *cur = pre;
            if (index == 0) {
                 newNode->next = pre;
                 head = newNode;
            } else {
                for (int i = 0; i < index; i++) {
                    pre = cur;
                    cur = cur->next;
                }
                pre->next = newNode;
                newNode->next = cur;
                //cur->next = newNode;
            }
            length++;
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index >= 0 && index <= length) {
            Node *pre = head;
            Node *cur = pre;
            // delete the head Node
            if (index == 0) {
                delete head;
                head = cur;
            } else {
                for (int i = 0; i < index; i++) {
                    pre = cur;
                    cur = cur->next;
                //pre = cur->next;
                }
                pre->next = cur->next;
                delete cur;
             }
            length--;
        }
    }
private:
    int length;
    Node *head;
};

int main() {
    MyLinkedList linked_list ; 
    linked_list.addAtHead(1);
    linked_list.addAtTail(3);
    linked_list.addAtIndex(1, 2);
    int a = linked_list.get(1);
    cout << a << endl;
    linked_list.deleteAtIndex(1);
    a = linked_list.get(1);
    cout << a << endl;
    return 0;
}

class MyLinkedList {
public:
    struct Node{
    int val;
    Node* next;
    Node(int x):val(x),next(NULL){}
    };
    int len;
    Node *head,*tail;//head指向头结点，tail指向尾节点
    /** Initialize your data structure here. */
    MyLinkedList() {
        len=0;
        Node* p=new Node(0);
        head=p;
        tail=p;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index<0||index>=len)
            return -1;
        Node* p=head;
        for(int i=0;i<index;i++)
        {
            p=p->next;
        }
        return p->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        if(len==0) {
            head->val=val;
        } else {
            Node *p=new Node(val);
            p->next=head;
            head=p;
        }
        len++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        if(len==0)
        {
            tail->val=val;
        }
        else
        {
            Node *p=new Node(val);
            tail->next=p;
            tail=p;
        }
        len++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index>len)
            return;
        if(index<=0)
        {
            addAtHead(val);
        }
        else if(index==len)
        {
            addAtTail(val);
        }
        else
        {
            Node *p=new Node(val);
            Node *cur=head;
            for(int i=0;i<index-1;i++)
            {
                cur=cur->next;
            }
            p->next=cur->next;
            cur->next=p;
            len++;
        }
        
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index>=0&&index<len)
        {
            if(index==0)
            {
                head=head->next;
            }
            else
            {
                Node *p=head;
                for(int i=0;i<index-1;i++)
                {
                    p=p->next;
                }
                p->next=p->next->next;
                if(index==len-1)
                {
                    tail=p;
                }
            }
            len--;
        }
    }
};
