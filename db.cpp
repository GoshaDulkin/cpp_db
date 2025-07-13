#include "db.hpp"
#include <iostream>
#include <sstream>
using namespace std;


void print_row(const Row& row) {
    cout << " " << row.id << " " << row.name << " " << row.age << "\n";
}

void Database::do_insert(const string& input) {
    istringstream iss(input);
    string cmd;
    int age;
    string name;
    iss >> cmd >> name >> age;

    if (iss.fail()) {
        cout << "Insert failed. Format should be insert <name> <age> \n";
        return;
    }

    rows.push_back({curr_id, name, age});
    cout << "Inserted: (" <<  name <<  " " << age << ")\n";
}

void Database::do_select(const string& input) {
    istringstream iss(input);
    string cmd, where, col, op, value;
    iss >> cmd >> where >> col >> op >> value;

    if (rows.empty()) {
        cout << "No data in database.\n";
        return;
    }

    if (where != "where"){
        for (const auto& row : rows) {
            print_row(row);
        }
        return;
    }

    if (col == "name") {
        for (const auto& row : rows) {
            if (row.name == value) {
                print_row(row);
            }
        }
    } else if (col == "age"){
        for (const auto& row : rows) {
            int val = stoi(value);
            if ((op == ">" && row.age > val) ||
                (op == "<" && row.age < val) ||
                (op == "==" && row.age == val)) {
                print_row(row);
            }
        }

    } else {
        cout << "Undefined column: " << col << "\n";
    }

    return;
}
