// ---- Program Info Start----
//FileName:     ListOddBeforeEven.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2016-08-23 14:53:26
// ---- Program Info End  ----

#include <iostream>

using namespace std;

struct node {
    struct node * next;
    int value;
    node( int val ):value( val ), next( NULL ){
    }
};

typedef struct node * pNode;
pNode swap( pNode list ){
    if( list == NULL )
        return list;
    pNode oddHead = NULL, evenHead = NULL;
    pNode pOdd = oddHead, pEven = evenHead, ptr = list;
    while( ptr != NULL ){
        if( ptr->value & 0x1 ){
            pOdd == NULL ? pOdd = oddHead = ptr : pOdd -> next = ptr, pOdd = ptr;
        }
        else{
            pEven == NULL ? pEven = evenHead = ptr : pEven -> next = ptr, pEven = ptr;
        }
        ptr = ptr->next;
    }
    oddHead == NULL ? oddHead = evenHead : pOdd->next = evenHead;
    evenHead == NULL ? pOdd->next = NULL : pEven->next = NULL;
    list = oddHead;
    return list;
}

int main(int argc, char *argv[])
{
    int n,m;
    cin>> n;
    pNode head = NULL, ptr;

    if( n>0 ){
        cin >> m;
        head = new node( m );
        ptr = head;
    }

    for( int i=1; i<n; ++i ){
        cin >> m;
        ptr->next = new node( m );
        ptr = ptr->next;
    }
    ptr = head;
    cout<<"Original List:";
    while( ptr!=NULL ){
        cout<<ptr->value<<" ";
        ptr = ptr->next;
    }
    ptr = swap( head );
    cout<<endl;

    cout<<"ReOrdered List:";
    while( ptr!=NULL ){
        cout<<ptr->value<<" ";
        ptr = ptr->next;
    }

    return 0;
}
