#include <iostream>
#include <vector>

using namespace std;

class Library;

class Song {
    string name;
    string artist;
    string genre;

    static int instances;
public:
    Song(string artist, string name,  string genre) : name(name), artist(artist), genre(genre) {
        instances++;
    }

    static int instancesCount() {
        return instances;
    }

    bool operator==(Song& other) {
        return other.artist == this->artist && other.name == this->name;
    }

    friend Library;
    friend ostream& operator<<(ostream& out, const Song& s);
};

int Song::instances = 0;

class Collection {
    string name;
    vector<const Song*> songs;
public:
    Collection(string name) : name(name) {}

    void add(const Song& song) {
        songs.push_back(&song);
    }

    const Song* getByIndex(int index) const {
        if (0 /* out of bounds? */) {
            throw "out of bounds";
        }

        return songs[index];
    }

    friend ostream& operator<<(ostream& out, const Collection& c);
};

class Library {
    vector<Song> songs;
public:
    const Song& add(string artist, string name, string genre) {
        songs.push_back(Song(artist, name, genre));

        return songs.back();
    }

    Collection* getByGenre(string name, string genre) {
        Collection* collection = new Collection(name);

        for (Song& s : songs) {
            if (s.genre == genre) {
                collection->add(s);
            }
        }

        return collection;
    }

    Collection* getByIndexRange(string name, int min, int max) {
        if (0 /* out of bounds*/ ) {
            throw "dsadsa";
        }

        Collection* collection = new Collection(name);

        for (vector<Song>::iterator it = songs.begin() + min; it != songs.begin() + max; it++) {
            collection->add(*it);
        }

        return collection;
    }
};

ostream& operator<<(ostream& out, const Song& s) {
    out << "Song: " << s.name << " - " << s.artist << endl;

    return out;
}

ostream& operator<<(ostream& out, const Collection& c) {
    out << "Collection " << c.name << ":" << endl;

    for (const Song* s : c.songs) {
        cout << (*s) << endl;
    }

    return out;
}

int main() {

    try {
        Song s1 = Song("Slipknot", "Duality", "alternative metal");

        Library library;
        Song s2 = library.add("Arctic Monkeys", "Do I wanna know", "alternative rock");
        Song s3 = library.add("Korn", "All in the family", "alternative metal");
        Song s4 = library.add("Slipknot", "Duality", "alternative metal");;

        Collection* c1 = library.getByGenre("Alternative metal", "alternative metal");
        Collection* c2 = library.getByIndexRange("Songs 0:2", 0, 2);
        cout << boolalpha << (s1 == s4) << endl;

        cout << "Songs count: " << Song::instancesCount() << endl;

        cout << (*c1) << endl;

        delete c1;
        delete c2;
    } catch (string msg) {
        cout << "Exception: " << msg << endl;
    }
}