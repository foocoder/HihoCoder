// ---- Program Info Start----
//FileName:     TriTree.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2016-07-15 18:56:08
// ---- Program Info End  ----

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

#define MAX_LEN 26

typedef
struct TrieNode{
    char charactor;
    bool isEnd;
    int  frequency;
    struct TrieNode * nextNode[MAX_LEN];
    TrieNode(){
        charactor = 0;
        frequency = 0;
        isEnd     = true;
        for(int i=0; i<MAX_LEN; ++i){
            nextNode[i] = NULL;
        }
    }
} sTrieNode;

class Trie{
    public:
        Trie():root( new TrieNode ){};
        Trie(Trie &)=delete;
        Trie & operator=(const Trie &)=delete;
        ~Trie(){
            // Memory Leak
            delete root;
        }

        //API
        int insert(const char * word){
            char a;
            sTrieNode * ptr = root;
            ptr->frequency++;
            while( (a=*word++) != '\0' ){
                if( a<'a' && a>'z' )
                    return -1;
                sTrieNode * node;
                if( ptr->nextNode[a-'a']==NULL ){
                    node                 = new sTrieNode;
                    node->charactor      = a;
                    ptr->nextNode[a-'a'] = node;
                }
                else{
                    node = ptr->nextNode[a-'a'];
                }
                node->frequency++;
                node->isEnd = *word == '\0' ? true : false;
                ptr = node;
            }
            return 0;
        }

        int query(const char * word){
            char a;
            sTrieNode * ptr = root;
            while( (a=*word++) != '\0' ){
                if( a<'a' && a>'z' )
                    return -1;
                if( ptr->nextNode[a-'a']!=NULL )
                    ptr = ptr->nextNode[a-'a'];
                else
                    return 0;
            }
            return ptr->frequency;
        }
    private:
        sTrieNode * root;
};

int main(int argc, char *argv[])
{
    string word;
    Trie test;
    int dictNum=0, queryNum=0;
    cin >> dictNum;
    for(int i=0; i<dictNum; ++i){
        cin >> word;
        test.insert( word.c_str() );
    }

    cin >> queryNum;
    for(int i=0; i<queryNum; ++i){
        cin >> word;
        cout<<test.query( word.c_str() )<<endl;
    }
    return 0;
}
