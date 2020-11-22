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

        cout << this->durability << endl;
    }
};

const map<ItemType, ItemProperties> Item::types = {
    { ROCK,  { "rock",  true,  10,  1 } },
    { STICK, { "stick", true,  20,  1 } },
    { AXE,   { "axe",   false,  1, 10 } },
};

int main() {
    cout << "These are the following known items:" << endl;

    for (auto itemType : Item::types) {
        cout << " - " << itemType.second.name << ", stackable: "
             << boolalpha << itemType.second.stackable << endl;
    }
}
