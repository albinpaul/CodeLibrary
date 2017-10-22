#include <bits/stdc++.h>
using namespace std;
#define MAXVAL (int)1e9

int minimumLength(string text, vector < string > keys) {

    int answer = MAXVAL;
    text += " $";
    unordered_set<string > us(keys.begin(),keys.end());
    unordered_set<string > us1;
    queue <string > q;
    string word = "";
    int count=0,scount=0;
    for(int i = 0; i < text.size(); i++) {
        if(text[i]==' '){
            //if item exists in first hash table
            if(us.find(word)!=us.end()){
                unordered_set<string >::iterator it=us1.find(word);
                    //if item exists in second hashtable for checking 
                if(it!=us1.end())
                {
                            //popping queue 
                    while(*it!=q.front())
                    {
                        if(us1.find(q.front())!=us1.end()){
                            us1.erase(q.front());                                  
                        }
                        //cout<<"the deleted word in while loop is "<<q.front()<<" with *it as "<<*it<<endl;
                         count--;
                        scount-=q.front().length();
                        q.pop();

                    }
                            //popping conflicting element from queue and hashtable
                    
                    us1.erase(q.front());                                  
                    
                    //cout<<"the deleted word is "<<q.front()<<endl;
                    count--;
                    scount-=q.front().length();
                    q.pop();
                    q.push(word);
                    us1.insert(word);
                    count++;
                    scount+=word.length();
              
                    while(us1.find(q.front())==us1.end()){
                        count--;
                        //cout<<"the deleted word in loop is for queue is"<<q.front()<<endl;
                        scount-=q.front().length();
                        q.pop();    
                    }
                          if (us1.size()==us.size()){

                        answer=min(answer,count+scount-1);
                        //cout<<"one set of values is computed "<<answer<<" "<<count<<" "<<scount-1<<endl;
                    }

                }else
                {
                    count++;
                    scount+=word.length();
                    us1.insert(word);
                    q.push(word);
                    //cout<<"the inserted word is "<<word<<endl;
                    //cout<<"values is computed  "<<count<<" "<<scount<<endl;
                    if (us1.size()==us.size()){

                        answer=min(answer,count+scount-1);
                        //cout<<"one set of values is computed initialiy"<<answer<<" "<<count<<" "<<scount-1<<" "<<us.size()<<" "<<us1.size()<<endl;
                    }
                }
            }
            else
            {
                    //if it does not exist in first table
                
                q.push(word);
                //cout<<"the inserted word is only to queue "<<word<<endl;
                count++;
                scount+=word.length();
                //cout<<"values is computed  "<<count<<" "<<scount<<endl; 
                }
            
            word="";
        }
        else
        {

            word+=text[i];
        }
        

        
    }
    if(answer == MAXVAL)
        answer = -1;

    return answer;
}
int main() {

    string text, buf;
    vector < string > keys;
    getline(cin, text);
    int keyWords;
    cin >> keyWords;
    for(int i = 0; i < keyWords; i++) {
        cin >> buf;
        keys.push_back(buf);
    }
    cout << minimumLength(text, keys) << endl;

    return 0;
}
