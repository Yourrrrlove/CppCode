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

#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<vector>
#include<memory>
#include<utility>
#include<functional>
#include<list>
#include<type_traits>
#include<cstring>
#include<utility>
#include<tuple>
#include<bitset>
#include<regex>
#include<random>
#include <iomanip>
#include<cmath>
#include<cstdlib>
#include "Sales_data.h"
using namespace std;
using namespace std::regex_constants;
// template <typename T> string debug_rep(const T &t){
//     ostringstream ret;
//     ret << t;
//     cout << "call const T &t" << endl;
//     return ret.str();
// }

// template <typename T> string debug_rep(T *p){
//     ostringstream ret;
//     ret << "pointer: " << p;
//     if(p) ret << " " << debug_rep(*p);
//     else ret << "nullptr";
//     cout << "call T *p" << endl;
//     return ret.str();
// }

// string debug_rep(const string &s){
//     cout << "调用非模板函数" << endl;
//     return '"' + s + '"';
// }

// string debug_rep(char *p){
//     cout << "调用 char *p 的非模板函数" << endl;
//     return debug_rep(string(p));
// }

// string debug_rep(const char *p){
//     cout << "调用 const char *p 的非模板函数" << endl;
//     return debug_rep(string(p));
// }

// template <typename T, typename... Args>
// void foo(const T &t, const Args &... rest){
//     cout << "sizeof...(Args): " << sizeof...(Args) << endl;
//     cout << "sizeof...(rest): " << sizeof...(rest) << endl;
// }

// template <typename T>
// ostream &print(ostream &os, const T &t){
//     cout << "调用非可变参数模板函数" << endl;
//     return os << t;
// }

// template <typename T, typename... Args>
// ostream &print(ostream &os, const T &t, const Args &... rest){
//     cout << "调用可变参数模板函数" << endl;
//     os << t << ", ";
//     return print(os, rest...);
// }

// template <typename T> int compare(const T&, const T&);
// template<size_t N, size_t M> int compare(const char (&)[N], const char (&)[M]);
// template<> int compare(const char* const &p1, const char* const &p2){
//     return strcmp(p1, p2);
// }
// int main(){
//     int i = 0;
//     double d = 3.14;
//     string s = "how now brown cow";
//     print(cout, i, s, 42, d);
//     return 0;
// }

// namespace std{
// template<>
// struct hash<Sales_data>{
//     typedef size_t result_type;
//     typedef Sales_data argument_type;
//     size_t operator()(const Sales_data &s) const;
// };
// size_t hash<Sales_data>::operator()(const Sales_data &s) const{
//     return hash<string>()(s.bookNo)^
//     hash<unsigned>()(s.units_sold)^
//     hash<double>()(s.revenue);
// }
// }


// typedef tuple<vector<Sales_data>::size_type,
//               vector<Sales_data>::const_iterator,
//               vector<Sales_data>::const_iterator> matches;
// vector<matches> findBook(const vector<vector<Sales_data>> &files, const string &book){
//     vector<matches> ret;
//     for(auto it = files.begin(); it != files.end(); ++it){
//         auto found = equal_range(it->cbegin(), it->cend(), book, compareIsbn);
//         if(found.first != found.second){
//             ret.push_back(make_tuple(it - files.cbegin(), found.first, found.second));
//         }
//     }
//     return ret;
// }

// void reportResults(istream &in, ostream &os, const vector<vector<Sales_data>> &files){
//     string s;
//     while(in >> s){
//         auto trans = findBook(files, s);
//         if(trans.empty()){
//             cout << s << " not found in any stores" << endl;
//             continue;
//         }
//         for(const auto &store : trans){
//             os << "store " << get<0>(store) << " sales: " << accumulate(get<1>(store), get<2>(store), Sales_data(s)) << endl;
//         }
//     }
// }

// bool valid(const smatch &m){
//     if(m[1].matched){
//         return m[3].matched && (m[4].matched == 0 || m[4].str() == " ");
//     }
//     else return !m[3].matched && m[4].str() == m[6].str();
// }

class out_of_stock:public std::runtime_error{
public:
    explicit out_of_stock(const std::string &s):std::runtime_error(s){}
};
class isbn_mismatch:public std::logic_error{
public:
    explicit isbn_mismatch(const std::string &s):std::logic_error(s){}
    isbn_mismatch(const std::string &s, const std::string &lhs, const std::string &rhs):std::logic_error(s),left(lhs), right(rhs){}
    const std::string left, right;
};
int main(){
    // string pattern("[^c]ei");
    // string file = "receipt freind theif receive";
    // pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
    // regex r(pattern, regex::icase);
    // for(sregex_iterator it(file.begin(), file.end(), r), end_it; it != end_it; ++it){
    //     cout << it->str() << endl;
    // }

    // string pat("@");
    // pat = "[[:digit:]]*"+pat+"[[:alpha:]]*";
    // regex r2(pat+".com", regex::icase);
    // string email = "913072552@qq.com 123456@gmail.com 4567@outlook.com";
    // for(sregex_iterator it(email.begin(), email.end(), r2), end_it; it != end_it; ++it){
    //     auto pos = it->prefix().length();
    //     pos = pos > 5 ? pos - 5 : 0;
    //     cout << it->prefix().str().substr(pos) << "\n\t\t>>>" << it->str() << " <<<\n" << it->suffix().str().substr(0, 5) << endl;
    // }

    // regex r("([[:alnum:]]+)\\.(cpp|cxx|cc)$", regex::icase);
    // string filename = "main.cpp";
    // smatch results;
    // if(regex_search(filename, results, r)) cout << results.str(0) << "  " << results.str(1) << "  " << results.str(2) << endl;
    
    
    // string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ]?)(\\d{4})";
    // regex r(phone);
    // smatch m;
    // string s;
    // string fmt = "$2.$5.$7";
    // ifstream file("data.txt");
    // if(file.is_open()){
    //     while(getline(file, s)){
    //         for(sregex_iterator it(s.begin(), s.end(), r), end_it; it != end_it; ++it){
    //             if(valid(*it)) cout << "valid: " << it->str() << endl;
    //             else cout << "invalid: " << it->str() << endl;
    //             cout << "——————————————" << endl;
    //             cout << regex_replace(s, r, fmt, format_no_copy) << endl;
    //         }
    //     }
    //     file.close();
    // }
    // else cout << "open file failed" << endl;
    Sales_data item1, item2, sum;
    while(cin >> item1 >> item2){
        try{
            sum = item1 + item2;
        }
        catch(const isbn_mismatch &e){
            cerr << e.what() << ": left isbn(" << e.left << ") right isbn(" << e.right << ")" << endl;
        }
    }
    return 0;
}
