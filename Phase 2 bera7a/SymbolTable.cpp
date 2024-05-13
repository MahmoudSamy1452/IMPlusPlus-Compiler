#include "SymbolTable.h"
#include "enums.h"

SymbolTable::SymbolTable(SymbolTable *parent)
{
    this->parent = parent;
}

void SymbolTable::setFunctionName(string *name)
{
    this->functionName = name;
}

string *SymbolTable::getFunctionName()
{
    return this->functionName;
}

bool SymbolTable::getIsReturned()
{
    return this->isReturned;
}

void SymbolTable::setIsReturned()
{
    this->isReturned = true;
}

void SymbolTable::insert(string name, Type type, void *value, bool isConst, vector<pair<Type, string>> *args,
                         Type *returnType)
{

    // for(auto it = this->table.begin(); it != this->table.end(); ++it) {
    //     cout << it->first << " " << it->second->type << " " << it->second->isConst << endl;
    // }
    // cout << "YA MALLEEEEKEKEKEKEKKEK" << endl;
    if (this->table.find(name) != this->table.end())
    {
        throw invalid_argument("Variable already defined in this scope");
    }

    if (!(type >= Type::TYPE_INT && type <= Type::TYPE_FUNC))
        throw invalid_argument("Invalid type");

    if (type == Type::TYPE_FUNC)
    {
        if (!(*returnType >= Type::TYPE_INT && *returnType <= Type::TYPE_VOID))
            throw invalid_argument("Invalid return type");

        for (auto arg : *args)
            if (!(arg.first >= Type::TYPE_INT && arg.first <= Type::TYPE_CHAR_ARRAY))
                throw invalid_argument("Invalid argument type");
    }
    else
    {
        if (args && args->size())
            throw invalid_argument("Arguments not allowed for non-function types");
    }

    this->table[name] = new SymbolTableEntry{type, value, isConst, args, returnType};
}

SymbolTableEntry *SymbolTable::lookup(string name)
{
    if (this->table.find(name) != this->table.end())
    {
        return this->table[name];
    }
    if (this->parent == nullptr)
        return nullptr;
    return this->parent->lookup(name);
}

void *SymbolTable::getValue(string name)
{
    SymbolTableEntry *table = this->lookup(name);
    if (table == nullptr)
        throw invalid_argument("Variable not found");
    if (table->value == nullptr)
        throw invalid_argument("Variable was not initialized");
    table->isUsed = true;
    return table->value;
}

Type SymbolTable::getType(string name)
{
    SymbolTableEntry *table = this->lookup(name);
    if (table == nullptr)
        throw invalid_argument("Variable not found");
    // table->isUsed = true;
    return table->type;
}

Type *SymbolTable::getReturnType(string name)
{
    SymbolTableEntry *table = this->lookup(name);
    if (table == nullptr)
        throw invalid_argument("Function not found");
    return table->returnType;
}

void SymbolTable::setValue(string name, Value *val)
{
    // print the unordered map
    //    cout << name << endl;
    //    for (auto it = this->table.begin(); it != this->table.end(); ++it) {
    //        cout << it->first << " " << it->second->type << " " << *(int *) (it->second->value) << " "
    //             << it->second->isConst << endl;
    //    }
    auto entry = lookup(name);
    if (entry == nullptr)
        throw invalid_argument("Variable not found");
    if (entry->isConst)
    {
        throw invalid_argument("Cannot assign to const variable");
    }

    if (entry->type != val->type)
    {
        throw invalid_argument("Type mismatch");
    }

    entry->value = val->value;
}

SymbolTable *SymbolTable::getParentTable()
{
    return this->parent;
}

void SymbolTable::addArgs(string name, string argName, Type argType)
{
    SymbolTableEntry *table = this->lookup(name);
    if (table->type != Type::TYPE_FUNC)
        throw invalid_argument("Function not found");
    table->args->push_back(make_pair(argType, argName));
}

void SymbolTable::checkUnusedVariables()
{
    for (auto it = this->table.begin(); it != this->table.end(); ++it)
    {
        if (it->second->type != Type::TYPE_FUNC && !it->second->isUsed)
        {
            throw invalid_argument("Variable " + it->first + " is declared but not used");
        }
    }
}