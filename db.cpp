#include "db.hpp"
#include <iostream>
#include <sstream>
using namespace std;

void Database::do_insert(const string& input) {
    cout << "did insert " << input << "\n";
}

void Database::do_select(const string& input) {
    cout << "did select " << input << "\n";
}
