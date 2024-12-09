#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
int wordLadderLength(string startWord,string targetWord,vector<string>&wordList)
{
    queue<pair<string,int>>q;
    q.push({startWord,1});
    unordered_set<string>st(wordList.begin(),wordList.end());
    st.erase(startWord);
    while(!q.empty())
    {
        string word=q.front().first;
        int steps = q.front().second;
        q.pop();
        if(word==targetWord)return steps;
        for(int i=0;i<word.size();i++)
        {
            char orginal = word[i];
            for(char ch='a';ch<='z';ch++)
            {
                word[i]=ch;
                if(st.find(word)!=st.end())
                {
                    st.erase(word);
                    q.push({word,steps+1});
                }
            }
            word[i]=orginal;
        }
    }
    return 0;
}
int main()
{
    fast;
    int n;
    cin>>n;
    string beginWord,endWord;
    cin>>beginWord>>endWord;
    vector<string>wordList(n+1);
    for(int i=0;i<n;i++)
        cin>>wordList[i];
    int ans = wordLadderLength(beginWord,endWord,wordList);
    cout<<ans<<endl;
    return 0;
}

//6
//hit
//cog
//hot
//dot
//dog
//lot
//log
//cog

