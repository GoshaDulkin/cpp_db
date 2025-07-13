#ifndef DB_HPP
#define DB_HPP

#include <string>
#include <vector>

using namespace std;

struct Row {
    int id;
    string name;
    int age;
};

class Database {
public:
    void do_insert(const string& input);
    void do_select(const string& input);

private:
    vector<Row> rows;
    int curr_id = 1;

};

#endif

