#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>
#include"Screen.h"
using namespace std;


int main(){
    ifstream in("data.txt");
    if(!in){
        cout << "open error" << endl;
        return -1;
    }
    string line;
    vector<string> vec;
    while(getline(in, line)){
        vec.push_back(line);
    }
    in.close();
    vector<string> :: const_iterator it = vec.begin();
    while(it != vec.end()){
        istringstream line_str(*it);
        string word;
        while(line_str >> word){
            cout << word << " ";
        }
        cout << endl;
        ++it;
    }
    return 0;
}