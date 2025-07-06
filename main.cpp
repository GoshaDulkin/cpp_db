#include "db.hpp"
#include <iostream>

using namespace std;

int main() {
    cout << "Welcome to cpp_db. Type 'exit' to quit\n";

    string input;
    Database db;
    while (true){
        cout << "db > ";
        getline(std::cin, input);

        if (input == "exit") {
            cout << "Thanks for using cpp_dbb!\n";
            break;
        }

        if (input.substr(0, 6) == "insert") {
            db.do_insert(input);
        } else if (input.substr(0, 6) == "select") {
            db.do_select(input);
        } else {
            cout << "Invalid command, please try again\n";
        }
    }

    return 0;
}
