#include <iostream>
#include <map>

using namespace std;

enum ItemType { ROCK, STICK, AXE };

struct ItemProperties {
    string name;
    bool stackable;
    bool stackSize;
    short uses;
};

class Item {
    ItemType type;
    short count;
    short durability;
public:
    const static map<ItemType, ItemProperties> types;

    Item(ItemType type) {
        this->type = type;
        this->count = 0;
        this->durability = this->types.at(type).uses;
    }

    Item& operator+=(int count);
    Item& operator++(int);
    Item operator+(Item& add);

    friend bool operator==(const Item& item, ItemType type);
    friend bool operator==(ItemType type, const Item& item);
    friend bool operator&&(const Item& a, const Item& b);

    friend ostream& operator<<(ostream& out, const Item& item);
};

const map<ItemType, ItemProperties> Item::types = {
    { ROCK,  { "rock",  true,  10,  1 } },
    { STICK, { "stick", true,  20,  1 } },
    { AXE,   { "axe",   false,  1, 10 } },
};

Item& Item::operator++(int) {
    this->count++;
    return *this;
}

Item& Item::operator+=(int count) {
    this->count += count;
    return *this;
}

Item Item::operator+(Item& add) {
    if (!(*this && add)) {
        throw "Items cannot be combined";
    }

    this->count--;
    add.count--;

    Item result = Item(AXE);
    result++;

    return result;
}

bool operator==(const Item& item, ItemType type) {
    return item.type == type;
}

bool operator&&(const Item& a, const Item& b) {
    if ((a == ROCK && b == STICK)
        || (a == STICK && b == ROCK)) {
        return true;
    }

    return false;
}

ostream& operator<<(ostream& out, const Item& item) {
    out << "Item: " << item.types.at(item.type).name
        << ", count "
        << item.count
        << ", uses "
        << item.durability << "/" << item.types.at(item.type).uses;

    return out;
}

int main() {
    Item rock   = Item(ROCK);
    Item stick  = Item(STICK);

    rock += 5;
    stick++;

    Item axe = rock + stick;

    cout << (rock && stick) << endl;
    cout << "Can combine rock and axe? " << endl << boolalpha << (rock && axe) << endl;
}
