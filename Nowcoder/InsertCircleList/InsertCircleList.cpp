// ---- Program Info Start----
//FileName:     InsertCircleList.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2016-08-23 10:38:21
// ---- Program Info End  ----

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class InsertValue {
public:
    ListNode* insert(vector<int> A, vector<int> nxt, int val) {
        // write code here
        ListNode * head = constructList( A, nxt );
        if( head == NULL ){
            ListNode * ptr = new ListNode( val );
            ptr->next = ptr;
            return ptr;
        }
        if( head->next == head ){
            ListNode * ptr = new ListNode( val );
            head->next = ptr;
            ptr->next = head;
            return ptr->val > head->val ? head : ptr;
        }
        ListNode * cur, * pre;
        cur = head->next; pre = head;
        int min = head -> val;
        while( cur != head ){
            if( val >= pre->val && val <=cur->val ){
                ListNode * ptr = new ListNode( val );
                ptr -> next = cur;
                pre -> next = ptr;
                break;
            }
            cur = cur->next;
            pre = pre->next;
        }
        if( cur == head ){
            ListNode * ptr = new ListNode( val );
            ptr -> next = cur;
            pre -> next = ptr;
            if( val <= min )
                return ptr;
        }
        return head;
    }
    ListNode * constructList( const vector<int> & A, const vector<int> & nxt ){
        ListNode * ptr, * head, * first;

        int n = A.size();
        if( n == 0 )
            return NULL;
        int min = A[0];
        ptr = new ListNode( min );
        //if( n == 1 ){
        //    ptr -> next = ptr;
        //    return ptr;
        //}
        first = ptr;
        head = ptr;
        int idx = nxt[0];
        for( int i = 1; i<n; ++i ){
            int val = A[ idx ];
            ptr->next = new ListNode( val );
            if( min > val ){
                min = val;
                head = ptr->next;
            }
            ptr = ptr->next;
            idx = nxt[idx];
        }
        ptr -> next = first;
        return head;
    }
};
int main(int argc, char *argv[])
{
    vector<int> A{5,3,7,4};
    vector<int> B{2,3,1,0};
    InsertValue ci;
    ListNode * head = ci.insert( A, B, 10 );
    ListNode * ptr = head;
    while( ptr->next != head ){
        cout<< ptr->val<< " ";
        ptr = ptr->next;
    }
    cout<<ptr->val<<endl;

    return 0;
}
