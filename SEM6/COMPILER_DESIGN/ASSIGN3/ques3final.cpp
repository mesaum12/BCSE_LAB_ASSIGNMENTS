#include<bits/stdc++.h>
using namespace std;
map<string,vector<string> > gram;
//add function done
void add(string s)
{
    string temp=s.substr(2);
    string current="";
    for(int i=0;i<temp.size();i++)
    {
        if(temp[i]=='|'){
            gram[s[0]+""].push_back(current);
            current="";
            continue;
        }
        current+=temp[i];
    }
}
    
map<string,string> removeDirectLR(map<string,vector<string> > gramA,string A)
{
    // gram is the dictionary here 
    vector<string> temp=gramA[A];
    vector<string> tempWithFirstPosNotA,tempWithFirstPosA;
    for(string i:temp)
    {
        if(i[0] == A[0])
            tempWithFirstPosA.push_back(i.substr(1)+A+"'");
        else{
            tempWithFirstPosNotA.push_back(i.substr(1)+A+"'");
        }
    }

    tempWithFirstPosA.push_back("e");
    gramA[A] = tempWithFirstPosNotA;
    gramA[A+"'"]=tempWithFirstPosA;
    return gramA;
}

bool checkForIndirect(map<string,vector<string> >gramA,string a,string ai)
{
    if(gramA.find(ai)==gramA.end())
     return false;
    if (a==ai)
     return true;
    for(vector<string> s:gramA[ai])
    {
        if(s[0]==ai)return false;
        if(gramA.find(s[0])!=gramA.end())
        {
            return checkForIndirect(gramA,a,s[0]);
        }
    }
    return false;
}

map<char,string> rem()
{
   int c=1;
   map<string,string> conv;
   map<string,string> gramA;
   map<string,string> revconv;

   for(auto itr:gram)
      conv[itr.first]="A"+to_string(c);
      gram["A"+to_string(c)]=vector<string>();
      c+=1
    
   for(auto itr:gram)
   {
       for(auto itr:gram[itr.first])
       {
           vector<string> temp;
           for ()
       }
   }
}

   
   
//add the rules in a map such that A-> bc|d has the key A and values bc and d .

map<string,vector<string> > removeDirectLR(string A)
{
    vector<string> temp=gram[A];
    vector<string> tempWithFirstPosNotA;
    vector<string> tempWithFirstPosA;

    for(string s:temp)
    {
        if(s[0]==A[0])
        tempWithFirstPosA.push_back(s.substr(1)+A+"'");
        else{
            tempWithFirstPosNotA.push_back(s+A+"'");
        }
    }
    tempWithFirstPosA.push_back("e");//e denotes epsilon here
    gram[A]=tempWithFirstPosNotA;
    gram[A+"'"]=tempWithFirstPosA;
    return gram;

}
        
int main()
{
    int n;
    cout<<"Enter the number of productions:";
    cin>>n;
    vector<string> productions;
    string str;
    
    for(int i=0;i<n;i++)
    {
        cin>>str;
        productions.push_back(str);
    }
    map<char,string> result;
    result=rem(gram);
    for(auto itr:result)
    {
        cout<<itr.first<<"->"<<itr.second<<"\n";
    }
    return 0;
    
}
    
    


tes
