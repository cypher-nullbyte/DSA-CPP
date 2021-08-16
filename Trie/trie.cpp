#include<iostream>
#include<iterator>
#include<vector>

using namespace std;


class Trie
{
    public:
        class node
        {
            public:
                bool end;
                node* next[26];
                node()
                {
                    end=false;
                    for(int i=0;i<26;i++)
                        next[i]=NULL;
                }
        };
    node* trie;
    Trie()
    {
        trie=new node();
    }
    void insert(string word)
    {
        int i=0;
        auto *it=trie;
        while(i<word.size())
        {
            if(it->next[word[i]-'a']==NULL) it->next[word[i]-'a']=new node();
            it=it->next[word[i]-'a'];
            i++;
        }
        it->end=true;
    }
    
    bool search(string word)
    {
        int i=0;
        auto *it=trie;
        while(i<word.size())
        {
            if(it->next[word[i]-'a']==NULL) return false;
            it=it->next[word[i]-'a'];
            i++;
        }
        return it->end;
    }
};

int main()
{
    Trie *myTrie=new Trie();
    std::vector<string> words={"chiran","priya","chiya","cypher","nullbyte"};
    for(auto w: words)
    {
        myTrie->insert(w);
    }
    cout<<myTrie->search("cypher");
    return 0;
}
