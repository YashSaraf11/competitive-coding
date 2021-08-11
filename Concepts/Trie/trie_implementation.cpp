#include<bits/stdc++.h>
using namespace std;

//defining the model datastructure class
class TrieNode{
    public:
        vector<TrieNode*> childrenNodes;
        bool isEnd;

        //constructor to initialise the end as false since the children are empty
        TrieNode(){
            isEnd=false;
            childrenNodes = vector<TrieNode*>(26,nullptr);
        }    
};

//defining the class to add/insert/modify the datastructure
class Trie{
    private: 
        TrieNode* root;
    public:
        //constructor to add words to the trie tree
        Trie(vector<string> words){
            root = new TrieNode();
            for(int i=0;i<words.size();i++)
                addWord(words[i]);
        }

        //returning the root of the Trie tree
        TrieNode* getRoot(){
            return root;
        }

        //function to addWord to the trie tree
        void addWord(string word){
            TrieNode* currNode = root;
            for(int i=0;i<word.length();i++){
                int indexCharacter = word[i]-'a';
                if(currNode->childrenNodes[indexCharacter]==nullptr){
                    currNode->childrenNodes[indexCharacter]= new TrieNode();                    
                }
                currNode = currNode->childrenNodes[indexCharacter];
            }
            currNode->isEnd=true;
        }
};

class Solution{
    public:
        vector<string> findWords(vector<vector<char>>& board,vector<string>& words){
            
            if(words.empty())
                return {};
            
            Trie* trie = new Trie(words);
            TrieNode* root = trie->getRoot();

            //words can be found multiple time in the grid
            set<string> wordsFound;

            for(int i=0;i<board.size();i++){
                for(int j=0;j<board.size();j++){
                    findWordPath(board,wordsFound,root,"",i,j);
                }
            }

            vector<string> result(wordsFound.begin(),wordsFound.end());
            return result;
        }

        void findWordPath(vector<vector<char>>& board,set<string>& wordsFound,TrieNode* root,
                            string currentWord,int i,int j){
            
            if(i<0 || j<0 || i==board.size() || j==board[0].size() || board[i][j]=='.')
                return;
            
            int indexCharacter = board[i][j]-'a';        
            if(root->childrenNodes[indexCharacter]!=nullptr){
                root = root->childrenNodes[indexCharacter];                
                                
                char temp=board[i][j];
                board[i][j]='.';
                
                if(root->isEnd)
                    wordsFound.insert(currentWord+temp);
                
                findWordPath(board,wordsFound,root,currentWord+temp,i+1,j);
                findWordPath(board,wordsFound,root,currentWord+temp,i-1,j);
                findWordPath(board,wordsFound,root,currentWord+temp,i,j+1);
                findWordPath(board,wordsFound,root,currentWord+temp,i,j-1);

                board[i][j]=temp;

            }
        }
};