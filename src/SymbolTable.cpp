#include "SymbolTable.h"
#include "enums.h"

extern void throwError(string msg);

extern ofstream quadFile;
extern int forCount;
extern std::stack <string> forStack;

SymbolTable::SymbolTable(SymbolTable *parent) {
    this->parent = parent;
}

void SymbolTable::setFunctionName(string *name) {
    this->functionName = name;
}

string *SymbolTable::getCurrentFunctionName() {
    if (this->parent == nullptr && this->functionName == nullptr)
        return nullptr;
    if (this->functionName == nullptr)
        return this->parent->getFunctionName();
    return this->functionName;
}

string *SymbolTable::getFunctionName() {
    return this->functionName;
}

bool SymbolTable::getIsReturned() {
    return this->isReturned;
}

void SymbolTable::setIsReturned() {
    if (this->parent == nullptr) {
        return;
    }
    if (this->functionName == nullptr) {
        this->parent->setIsReturned();
        return;
    }
    this->isReturned = true;
}

void SymbolTable::insert(string name, Type type, void *value, bool isConst, vector <pair<Type, string>> *args,
                         Type *returnType) {
    
    if (this->table.find(name) != this->table.end()) {
        throwError(name + " already defined in this scope");
    }
    
    if (!(type >= Type::TYPE_BOOL && type <= Type::TYPE_FUNC))
        throwError("Invalid type");
    
    if (type == Type::TYPE_FUNC) {
        if (!(*returnType >= Type::TYPE_BOOL && *returnType <= Type::TYPE_VOID))
            throwError("Invalid return type");
        
        for (auto arg: *args)
            if (!(arg.first >= Type::TYPE_BOOL && arg.first <= Type::TYPE_CHAR_ARRAY))
                throwError("Invalid argument type");
    } else {
        if (args && args->size())
            throwError("Arguments not allowed for non-function types");
    }
    
    this->table[name] = new SymbolTableEntry{type, value, isConst, args, returnType};
}

SymbolTableEntry *SymbolTable::lookup(string name) {
    if (this->table.find(name) != this->table.end()) {
        return this->table[name];
    }
    if (this->parent == nullptr)
        return nullptr;
    return this->parent->lookup(name);
}

void *SymbolTable::getValue(string name) {
    SymbolTableEntry *table = this->lookup(name);
    if (table == nullptr) {
        throwError("Variable not found");
        return nullptr;
    }
    if (table->value == nullptr)
        throwError("Variable was not initialized");
    table->isUsed = true;
    return table->value;
}

Type SymbolTable::getType(string name) {
    SymbolTableEntry *table = this->lookup(name);
    if (table == nullptr) {
        return Type::TYPE_ERROR;
    }
    return table->type;
}

Type *SymbolTable::getReturnType(string name) {
    SymbolTableEntry *table = this->lookup(name);
    if (table == nullptr)
        throwError("Function not found");
    return table->returnType;
}

void SymbolTable::setValue(string name, Value *val) {
    auto entry = lookup(name);
    if (entry == nullptr)
        throwError("Variable not found");
    if (entry->isConst) {
        throwError("Cannot assign to const variable");
    }
    if (entry->type != val->type && entry->type <= Type::TYPE_FLOAT && val->type <= Type::TYPE_FLOAT) {
        if (forCount > 0)
            forStack.push("CAST " + enumTypeToString(entry->type));
        
        else
            quadFile << "CAST " << enumTypeToString(entry->type) << endl;
    } else if (entry->type != val->type && val->type != Type::TYPE_ERROR) {
        throwError("Type mismatch");
    }
    if (val->type == Type::TYPE_ERROR)
        return;
    
    entry->value = val->value;
}

SymbolTable *SymbolTable::getParentTable() {
    return this->parent;
}

void SymbolTable::addArgs(string name, string argName, Type argType) {
    SymbolTableEntry *table = this->lookup(name);
    if (table->type != Type::TYPE_FUNC)
        throwError("Function not found");
    table->args->push_back(make_pair(argType, argName));
}

void SymbolTable::checkUnusedVariables() {
    for (auto it = this->table.begin(); it != this->table.end(); ++it) {
        if (it->second->type != Type::TYPE_FUNC && !it->second->isUsed) {
            string error = "Variable " + it->first + " is declared but not used";
            throwError(error);
        }
    }
}

void SymbolTable::printTable() {
    extern ofstream symbolTable;
    
    symbolTable << std::left << std::setw(20) << "name"
                << std::setw(20) << "Type"
                << std::setw(20) << "isConst"
                << std::setw(20) << "returnType"
                << std::setw(20) << "isUsed" << "\n";
    
    for (auto it = this->table.begin(); it != this->table.end(); ++it) {
        symbolTable << std::setw(20) << it->first
                    << std::setw(20) << enumTypeToString(it->second->type)
                    << std::setw(20) << it->second->isConst;
        
        if (it->second->type == Type::TYPE_FUNC) {
            symbolTable << std::setw(20) << enumTypeToString(*it->second->returnType);
        } else {
            symbolTable << std::setw(20) << "N/A";
        }
        
        symbolTable << std::setw(20) << it->second->isUsed << "\n";
    }
}

string SymbolTable::enumTypeToString(Type type) {
    switch (type) {
        case Type::TYPE_BOOL:
            return "bool";
        case Type::TYPE_FLOAT:
            return "float";
        case Type::TYPE_INT:
            return "int";
        case Type::TYPE_CHAR:
            return "char";
        case Type::TYPE_VOID:
            return "void";
        case Type::TYPE_CHAR_ARRAY:
            return "char[]";
        case Type::TYPE_FUNC:
            return "function";
        default:
            return "N/A";
    }
}