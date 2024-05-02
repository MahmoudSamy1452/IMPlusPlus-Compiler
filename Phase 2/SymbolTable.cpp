#include "SymbolTable.h"
#include <iostream>
using namespace std;
SymbolTable::SymbolTable(SymbolTable *parent = nullptr)
{
    this->parent = parent;
}

void SymbolTable::insert(string name, Type type, void *value, bool isConst, vector<pair<Type, string>>* args, Type* returnType)
{
    
    if (this->table.find(name) != this->table.end())
        throw "Variable already defined in this scope";

    if (!(type >= Type::INT && type <= Type::FUNC))
        throw "Invalid type";

    if (type == Type::FUNC)
    {
        if (!(*returnType >= Type::INT && *returnType <= Type::VOID)) 
            throw "Invalid return type";

        for (auto arg : *args)
            if (!(arg.first >= Type::INT && arg.first <= Type::CHAR_ARRAY)) 
                throw "Invalid argument type";
    }
    else
    {
        if (args && args->size()) 
            throw "Arguments not allowed for non-function types";
    }

    this->table[name] = {type, value, args, returnType, isConst};
}

SymbolTableEntry *SymbolTable::lookup(string name)
{
    if (this->table.find(name) != this->table.end())
    {
        return &this->table[name];
    }
    if (this->parent == nullptr)
        throw "Variable not found";
    return this->parent->lookup(name);
}

void *SymbolTable::getValue(string name)
{
    SymbolTableEntry* table = this->lookup(name);
    return table->value;
}

Type SymbolTable::getType(string name)
{
    SymbolTableEntry* table = this->lookup(name);
    return table->type;
}

void SymbolTable::setValue(string name, Value val)
{
    auto it = this->table.find(name);
    if (it != table.end())
    {
        if (it->second.type != val.type)
        {
            throw "Type mismatch";
        }
        it->second.value = val.value;
    }
    else
    {
        throw "Name not found in symbol table";
    }
}