#include <string>
#include <iostream>

class Table;
class Cell {
    Table* table;  // ��� ���̺� �����ִ���
    std::string data;
    int x, y;  // ���̺� ������ ��ġ
public:
    Cell(const std::string& data) : data(data) {};
};

class Table {
    Cell*** data_base;  // �� 3�� ������ ���� �� �����غ�����!
public:
    Table();
    virtual std::string print_table() = 0;
    void reg_cell(Cell* c, int row, int col);  // Cell �� ����Ѵ�
    std::string get_cell_std::string(int row,
        int col);  // �ش� ��ġ�� Cell �����͸� ��´�.
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