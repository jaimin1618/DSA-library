#include<bits/stdc++.h>
using namespace std;

struct Item {
    string name;
    Item(string name): name(name) {}
};

vector<Item>* getItem(int count) {
    vector<Item> *items = new vector<Item>();

    for(int i = 1; i <= count; ++i){
        items->push_back(Item(to_string(i)));
    }

    return items;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<Item>* items = getItem(5);
    cout << items[3].name << endl;

    return 0;
}