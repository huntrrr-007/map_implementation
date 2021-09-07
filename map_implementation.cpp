#include <iostream>
#include <list>
#include <cstring>

using namespace std;

class Hashtable
{
private:
    static const int hashgroups = 10;
    list<pair<int, string>> table[hashgroups];

public:
    bool isempty() const;
    int hashfunction(int key);
    void insertitem(int key, string value);
    void removeitem(int key);
    string searchtable(int key);
    void printtable();
};
bool Hashtable::isempty() const
{
    int sz = 0;
    for (int i = 0; i < hashgroups; i++)
    {
        sz += table[i].size();
    }
    return sz == 0;
}
int Hashtable::hashfunction(int key)
{
    return key % hashgroups; //key=105, then this function will return 5
}
void Hashtable::insertitem(int key, string value)
{
    int hashvalue = hashfunction(key);
    auto &cell = table[hashvalue];
    auto bitr = begin(cell);
    bool keyexist = false;
    for (bitr; bitr != end(cell); bitr++)
    {
        if (bitr->first == key)
        {
            keyexist = true;
            bitr->second = value;
            cout << "[WARNING] key exist.value replaced." << endl;
            break;
        }
    }
    if (!keyexist)
    {
        cell.emplace_back(key, value);
        cout << "[INFO] pair sucessfully added" << endl;
    }
    return;
}
void Hashtable::removeitem(int key)
{
    int hashvalue = hashfunction(key);
    auto &cell = table[hashvalue];
    auto bitr = begin(cell);
    bool keyexist = false;
    for (bitr; bitr != end(cell); bitr++)
    {
        if (bitr->first == key)
        {
            keyexist = true;
            bitr = cell.erase(bitr);
            cout << "[INFO] item removed." << endl;
            break;
        }
    }
    if (!keyexist)
    {
        cout << "[WARNING] key not found.pair not removed" << endl;
    }
    return;
}
void Hashtable::printtable()
{
    for (int i = 0; i < hashgroups; i++)
    {
        if (table[i].size() == 0)
            continue;

        auto bitr = table[i].begin();
        for (; bitr != table[i].end(); bitr++)
        {
            cout << "[INFO] key : " << bitr->first << "value: " << bitr->second << endl;
        }
    }
    return;
}

int main()
{
    Hashtable ht;
    if (ht.isempty())
    {
        cout << "correct answer.gg" << endl;
    }
    else
    {
        cout << "oh,no correct your code" << endl;
    }

    ht.insertitem(905, "jim");
    ht.insertitem(358, "harry");
    ht.insertitem(896, "bhajiya");
    ht.insertitem(888, "deepak");
    ht.insertitem(895, "baranwal");
    ht.insertitem(200, "banti");
    ht.insertitem(892, "kumar");

    ht.printtable();

    ht.removeitem(905);
    ht.removeitem(892);

    ht.printtable();

    if (ht.isempty())
    {
        cout << "correct answer.gg" << endl;
    }
    else
    {
        cout << "oh,no correct your code" << endl;
    }
}
