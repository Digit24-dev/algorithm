#include <iostream>
#include <vector>
#include <string>
#include <functional>

class Hashtable {
private:
    std::vector<std::pair<std::string, int>> table;
    int table_length;

public:
    Hashtable(int table_length) {
        this->table_length = table_length;
        this->table.resize(table_length);
    }

    std::pair<bool, int> _search(std::string key, bool test_mode = false) {
        std::hash<std::string> hash_fn;
        int hash1 = hash_fn(key);
        int m = table_length;
        int initial_i = hash1 % m;
        int count = 0;

        if (table[initial_i].first.empty()) {
            if (test_mode) {
                return std::make_pair(false, initial_i, count);
            }
            return std::make_pair(false, initial_i);
        }
        else if (table[initial_i].first == key) {
            return std::make_pair(true, initial_i);
        }

        int hash2 = hash_fn(key + "d");
        int c = (hash2 % (m - 1)) + 1;
        int i = (initial_i + c) % m;

        while (i != initial_i) {
            count++;
            if (table[i].first.empty()) {
                if (test_mode) {
                    return std::make_pair(false, i, count);
                }
                return std::make_pair(false, i);
            }
            else if (table[i].first == key) {
                return std::make_pair(true, i);
            }
            else {
                i = (i + c) % m;
            }
        }
    }

    vector<int> _search(string key, bool test_mode=false) {
        int index = hash(key) % size;
        int num_checked = 0;
        bool found = false;
        for (int i = 0; i < table[index].size(); i++) {
            if (table[index][i][0] == key) {
                found = true;
                break;
            }
            num_checked++;
        }
        if (test_mode) {
            return {found, num_checked};
        }
        return {found, num_checked, index};
    }

    void insert(string key, int value) {
        vector<int> result = _search(key);
        if (result[1] == -1) {
            if (result[0]) {
                int i = result[1];
                table[i][1] = to_string(value);
                return;
            }
            int i = result[1];
            table[i] = {key, to_string(value)};
        }
    }

    int search(string key) {
        vector<int> result = _search(key);
        if (result[1] == -1) {
            if (!result[0]) {
                return false;
            }
            int i = result[1];
            return stoi(table[i][1]);
        }
    }

    void deleteKey(string key) {
        vector<int> result = _search(key);
        if (result[1] == -1) {
            if (result[0]) {
                int i = result[1];
                table[i].erase(table[i].begin() + 1);
            }
        }
    }

    int hash(string key) {
        int hash = 0;
        for (int i = 0; i < key.length(); i++) {
            hash += key[i];
        }
        return hash;
    }
};

int main() {
    Hashtable ht(5);
    ht.insert("key1", 9);
    ht.insert("key2", 2);
    ht.insert("key3", 10);
    ht.insert("key4", 100);
    ht.insert("key5", 10);
    assert(ht.search("key1") == 9);
    assert(ht.search("key2") == 2);
    assert(ht.search("key3") == 10);
    assert(ht.search("key4") == 100);
    assert(ht.search("key5") == 10);
    ht.insert("key3", -1);
    ht.insert("key5", 42);
    assert(ht.search("key3") == -1);
    assert(ht.search("key5") == 42);

    Hashtable ht2(30011);
    for (int i = 0; i < 30011; i++) {
        ht2.insert("key" + std::to_string(i), 1);
    }

    int total = 0;
    int num_trials = 10'000;
    int max_num = 0;
    for (int i = 0; i < num_trials; i++) {
        int num_checked = ht2._search("new_key_" + std::to_string(i), true).first;
        total += num_checked;
        if (num_checked > max_num) {
            max_num = num_checked;
        }
    }
    double average = static_cast<double>(total) / num_trials;
    std::cout << "Average number of elements checked: " << average << std::endl;
    std::cout << "Max number of elements checked: " << max_num << std::endl;

    return 0;
}

