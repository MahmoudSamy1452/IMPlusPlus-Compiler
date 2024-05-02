// name
// type
// value
// line of usage
// arg types (if type = func)
// return type (if type = func)

#include <bits/stdc++.h>
// #include "enums.h"
#include "structs.h"
using namespace std;



struct SymbolTableEntry
{
  Type type;
  void* value;
  vector<pair<Type, string>>* args;
  Type* returnType;
  bool isConst;
};

class SymbolTable
{
private:
    unordered_map<string, SymbolTableEntry> table;
    SymbolTable* parent;

public:
    SymbolTable(SymbolTable* parent = nullptr);

    void insert(string name, Type type, void *value = nullptr, bool isConst = false, vector<pair<Type, string>>* args = nullptr, Type* returnType = nullptr);

    SymbolTableEntry* lookup(string name);

    SymbolTable* getParent();

    void* getValue(string name);
    
    void setValue(string name, Value val);
};
