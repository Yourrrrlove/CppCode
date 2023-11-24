#include<iostream>
#include<string>
#include<vector>
using namespace std;

// class Screen{
// public:
//     using pos = string::size_type;
//     friend class Window_mgr;
//     Screen() = default;
//     Screen(pos h, pos w, char c) : height(h), width(w), contents(h * w, c) {}
//     char get() const{
//         return contents[cursor];
//     }
//     inline char get(pos r, pos c) const;
//     Screen &move(pos r, pos c);
//     void some_member() const;
//     Screen &set(char c);
//     Screen &set(pos r, pos c, char ch);
//     Screen &display(ostream &os){
//         do_display(os);
//         return *this;
//     }
//     const Screen &display(ostream &os) const{
//         do_display(os);
//         return *this;
//     }
// private:
//     pos cursor = 0;
//     pos height = 0, width = 0;
//     string contents;
//     mutable size_t access_ctr;
//     void do_display(ostream &os) const{
//         os << contents;
//     }
// };

// inline Screen &Screen::move(pos r, pos c){
//     pos row = r * width;
//     cursor = row + c;
//     return *this;
// }

// char Screen::get(pos r, pos c) const{
//     pos row = r * width;
//     return contents[row + c];
// }

// void Screen::some_member() const{
//     ++access_ctr;
// }

// inline Screen& Screen::set(char c){
//     contents[cursor] = c;
//     return *this;
// }

// inline Screen& Screen::set(pos r, pos c, char ch){
//     contents[r * width + c] = ch;
//     return *this;
// }


// class Window_mgr{
// public:
//     using ScreenIndex = vector<Screen>::size_type;
//     void clear(ScreenIndex);
//     ScreenIndex addScreen(const Screen&);
// private:
//     vector<Screen> screens{Screen(24,80,' ')};
// };


// void Window_mgr::clear(ScreenIndex i){
//     Screen &s = screens[i];
//     s.contents = string(s.height * s.width, ' ');
// }

// Window_mgr::ScreenIndex Window_mgr::addScreen(const Screen &s){
//     screens.push_back(s);
//     return screens.size() - 1;
// }


// class Debug{
// public:
//     constexpr Debug(bool b = true) : hw(b), io(b), other(b){}
//     constexpr Debug(bool h, bool i, bool o) : hw(h), io(i), other(o){}
//     constexpr bool any() const{return hw || io || other;}
//     void set_io(bool b){io = b;}
//     void set_hw(bool b){hw = b;}
//     void set_other(bool b){other = b;}
// private:
//     bool hw;
//     bool io;
//     bool other;
// };

// class Account{
// public:
//     void calculate(){amount += amount * interestRate;}
//     static double rate(){return interestRate;}
//     static void rate(double newRate);
// private:
//     string owner;
//     double amount;
//     static double interestRate;
//     static constexpr int period = 30;
//     double daily_tbl[period];
//     static double initRate();
// };

// void Account::rate(double newRate){
//     interestRate = newRate;
// }

// double Account::initRate(){
//     return 0.0; // Replace with the actual implementation
// }

// class example{
// public:
//     static const double rate;
//     static const int vecSize;
//     static vector<double> vec;
// };
// const double example::rate = 6.5;
// const int example::vecSize = 20;
// vector<double> example::vec(vecSize);


struct PersonInfo{
    string name;
    vector<string> phones;
};