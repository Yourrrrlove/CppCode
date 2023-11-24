#include <iostream>
#include <vector>
#include <algorithm>
#include<string>
#include<sstream>
using namespace std;
class Sales_data{
public:
    Sales_data() = default;
    Sales_data(const string &book) : bookNo(book) {}
    Sales_data(const string &book, const unsigned num, const double sellp, const double salep);
    Sales_data(istream &is);
    double avg_price() const;
public:
    string bookNo;
    unsigned units_sold = 0;
    double sellingprice = 0.0;
    double saleprice = 0.0;
    double discount = 0.0;
};

Sales_data::Sales_data(const string &book, const unsigned num, const double sellp, const double salep){
    bookNo = book;
    units_sold = num;
    sellingprice = sellp;
    saleprice = salep;
    if(sellingprice != 0){
        discount = saleprice / sellingprice;
    }
}

istream& operator>>(istream& is, Sales_data& data) {
    is >> data.bookNo >> data.units_sold >> data.sellingprice >> data.saleprice;
    if (data.sellingprice != 0) {
        data.discount = data.saleprice / data.sellingprice;
    }
    return is;
}

Sales_data::Sales_data(istream &is){
    is >> *this;
}

inline double Sales_data::avg_price() const{
    if(units_sold){
        return saleprice / units_sold;
    }else{
        return 0;
    }
}