#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Trie {
    int cnt = 0;
    Trie *ptr[27] ;

    Trie() {
        for(int i=0; i<27; i++) {
            ptr[i] = NULL ;
        }
    }
} *root;

void insert(string &s) {
    Trie *tmp = root ;
    for(auto &i : s) {
        int cur = i - 'a' ;
        if(tmp->ptr[cur] == NULL)
            tmp->ptr[cur] = new Trie();

        tmp = tmp->ptr[cur] ;
        tmp->cnt++ ;
    }
}

int Search(string &s) {
    Trie *tmp = root ;
    for(auto &i : s) {
        int cur = i - 'a' ;
        if(tmp->ptr[cur] == NULL)
            return 0;

        tmp = tmp->ptr[cur] ;
    }
    return tmp->cnt;
}
int main() {

}
