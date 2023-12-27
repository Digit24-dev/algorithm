#include <string>
#include <iostream>

class Table;
class Cell {
    Table* table;  // 어느 테이블에 속해있는지
    std::string data;
    int x, y;  // 테이블 에서의 위치
public:
    Cell(const std::string& data) : data(data) {};
};

class Table {
    Cell*** data_base;  // 왜 3중 포인터 인지 잘 생각해보세요!
public:
    Table();
    virtual std::string print_table() = 0;
    void reg_cell(Cell* c, int row, int col);  // Cell 을 등록한다
    std::string get_cell_std::string(int row,
        int col);  // 해당 위치의 Cell 데이터를 얻는다.
    ~Table();
};

ostream& operator<<(ostream& o, Table& t) {
    o << t.print_table();
    return o;
}
class TextTable : public Table {


};
class CSVTable : public Table {};
class HTMLTable : public Table {};