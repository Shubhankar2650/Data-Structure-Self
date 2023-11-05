#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main(){

    unordered_map<string,int> m;
    
    //✍️ Insertion
    //1
    pair<string,int> p = make_pair("Shubh",2);
    m.insert(p);

    //2
    pair<string,int> p2("ram",1);
    m.insert(p2);

    //3
    m["shayam"] = 3;

    // ✍️ Searching
    cout<<m["Shubh"]<<endl;
    cout<<m.at("Shubh")<<endl;

    // ✒️ difference betwen m.at(key) and m[key]
    // cout<<m.at("shubh");
    //it shows an error as shubh is not present inside the map
    cout<<m["shubh"];
    // but it takes the input shubh in the hashmap with value 0 if shubh is not present inside the map

    // ✍️ Size
    cout<<"size of map: "<<m.size()<<endl;

    // ✍️ to check presennce
    cout<<m.count("shubh")<<endl; // return 1 if key is present
    cout<<m.count("kumar")<<endl; // else 0 is not present

    // ✍️ earse
    m.erase("shubh");
    cout<<m.size()<<endl;

    // ✍️ iterator
    unordered_map<string,int>:: iterator it = m.begin();
    while(it != m.end()){
        cout<<it->first<<" "<<it->second<<endl;
        it++;
    }

    // ✒️ in case of map output is print as it is inserted
    

}