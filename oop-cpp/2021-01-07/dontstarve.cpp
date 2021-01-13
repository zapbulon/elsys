#include <iostream>
#include <vector>

using namespace std;

class Object {
public:
    Object(string name = "") : name(name) {}

protected:
    string name;
};

class Building : public Object {

};

class Grave : public Building {
public:
    Grave() {
        this->name = "Grave";
    };
private:
};

class Item : public Object {
public:


};


// Stackable

// Durable

// Spoil

class Stackable : virtual public Item {
public:
    int maxStackSize;

    Stackable(int maxStackSize) : maxStackSize(maxStackSize) {}
};

class Spoilable : virtual public Item {
public:
    int durability; // in seconds

    Spoilable(int durability) : durability(durability) {}
};

class Stick : public Item {

};


class Berry : public Spoilable, public Stackable {
public:
    Berry() : Stackable(40), Spoilable(120) {
        this->name = "Berry";
    }
};




class Weapon : public Item {
    int durability; // in percent
};

class Sword : public Weapon {

};

class Character {
public:
    Character(int health, int sanity, int hunger, int inventorySize)
        : health(health), sanity(sanity), hunger(hunger), inventorySize(inventorySize) {}

    ~Character() {
        for (auto item : inventory) {
            delete item;
        }
    }

    void giveItem(Item* item) {
        // TODO: check inventory size!

        inventory.push_back(item);
    }
protected:

private:
    int health;
    int sanity;
    int hunger;

    int inventorySize;

    vector<Item*> inventory;
};


class WilsonSpecificItem : public Item {

};

class Wilson : public Character {
public:
    Wilson() : Character(160, 160, 160, 15) {
        WilsonSpecificItem* item = new WilsonSpecificItem();

        this->giveItem(item);
    }
};

class Willow : public Character {
public:
    Willow() : Character(120, 180, 120, 10) {

    }
};

class World {
public:
    vector<Character*> players;
    vector<Object> objects;

    void addPlayer(Character& player) {
        players.push_back(&player);
    }

    static World* getInstance() {
        if (World::instance == nullptr) {
            World::instance = new World();
        }

        return World::instance;
    }

    static void delInstance() {
        delete World::instance;
        World::instance = nullptr;
    }
private:
    World() {};
    World(const World&) = delete;            // Prevent construction by copying
    World& operator=(const World&) = delete; // Prevent assignment

    static World* instance;
};

World* World::instance = nullptr;

int main() {
    World* world = World::getInstance();

    Wilson player1;
    Willow player2;

    world->addPlayer(player1);
    world->addPlayer(player2);

    cout << "Characters ingame: " << world->players.size()
         << ", using singleton again: " << World::getInstance()->players.size() << endl;

    World::delInstance();

    return 0;
}