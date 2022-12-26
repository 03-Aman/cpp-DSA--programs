#include <bits/stdc++.h>
using namespace std;
int main()
{  unordered_map<string,int> m;
// inserting
// 1->
    pair<string,int> p1=make_pair("mera",1);
    m.insert(p1);
    // 2->
    pair<string,int>p2("naam",2);
    m.insert(p2);
    m["aman"]=1;


    cout<<m.at("naam")<<endl;
    cout<<m["aman"]<<endl;

    // agar m kisi aisim key k liye value print krana chaau jo present hi nahi hai
   // cout<<m.at("unknown");
    // above will give an error i.e key not found 
    // 2nd method
        cout<<m["unknown"]<<endl;   // --> ye pehle ek unknown key k liye entry bnayega fir usse display krayega

        // to check whether the key is present or not
        // simply usko count nikal lo
        // if not present , gives 0 and if it is present gives 1
        cout<<m.count("bro")<<endl;
     return 0;
}