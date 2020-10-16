#include<iostream>
#include<stack>
#include<queue>
#include<string>
#include<set>
#include<utility>
#include<algorithm>
#include<iterator>
#include<vector>
#include<map>
#include <unordered_map>
using namespace std;

int main()
{
    //----------------------------implementation of pair-------------------------------
    /*
    pair<char, int> cnt[26];
    for(int i=0;i<26;i++){
        cnt[i].second = 0;
        cnt[i].first = i+97;
    }
    string word;
    cin>>word;
    for(int i=0;i<word.length();i++){
        cnt[word[i]-97].second++;
    }
    for(int i=0;i<26;i++)
        cout<<cnt[i].first<<" "<<cnt[i].second<<" ";
    */  
    //----------------------------implementation of map--------------------------------
    /*
    map<int, int> m;
    m.insert(make_pair(9,20));
    m.insert(make_pair(8,20));
    m.insert(make_pair(7,20));
    m.insert(make_pair(11,20));
    map<int, int>::iterator itr;
    for(itr= m.begin();itr!=m.end();itr++){
        cout<<itr->first<<" "<<itr->second<<endl;
    }
    cout<<m[8];
    cout<<endl;
    */
    //----------------------------implementation of unordered map---------------
    /* 
    unordered_map<int, int> um;
    um.insert(make_pair(9,21));
    um.insert(make_pair(8,18));
    um.insert(make_pair(7,22));
    um.insert(make_pair(11,15));
    for(auto x: um){
        cout<<x.first<<" "<<x.second<<endl;
    }
    */
    //-------------------------------implementation of queue--------------------------------
    /*
    queue<int> q;
    q.push(3);
    q.push(5);
    q.push(9);
    
    cout<<q.size();
    for(int i=0;i<3;i++)
    {
        cout<< q.front()<<" ";
        q.pop();
    }
    */
    //----------------------------------2d vector----------------------------
    vector< vector<int> > twodvector(5);
    for(int i=0;i<5;i++){
        for(int j=0;j<3;j++)
            twodvector[i].push_back(0);
    }
    int row = twodvector.size();
    int col = twodvector[0].size();
    cout<<"row "<<row<<" col "<<col<<endl;
    return 0;   
}