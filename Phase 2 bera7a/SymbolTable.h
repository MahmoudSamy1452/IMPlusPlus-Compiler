#pragma once
#include <bits/stdc++.h>
#include "structs.h"
using namespace std;

struct SymbolTableEntry
{
  Type type;
  void *value;
  vector<pair<Type, string>> *args;
  Type *returnType;
  bool isConst;
  bool isUsed = false;

  SymbolTableEntry(Type type, void *value = nullptr, bool isConst = false, vector<pair<Type, string>> *args = nullptr, Type *returnType = nullptr)
      : type(type), value(value), isConst(isConst), args(args), returnType(returnType) {}
};

class SymbolTable
{
private:
  unordered_map<string, SymbolTableEntry *> table;
  SymbolTable *parent;
  string *functionName = nullptr;
  bool isReturned = false;

public:
  SymbolTable(SymbolTable *parent = nullptr);

  void insert(string name, Type type, void *value = nullptr, bool isConst = false, vector<pair<Type, string>> *args = nullptr, Type *returnType = nullptr);

  SymbolTableEntry *lookup(string name);

  SymbolTable *getParent();

  void *getValue(string name);

  Type getType(string name);

  void setValue(string name, Value *val);

  string *getFunctionName();
  void setFunctionName(string *name);

  bool getIsReturned();
  void setIsReturned();

  Type *getReturnType(string name);

  void addArgs(string name, string argName, Type argType);

  void checkUnusedVariables();

  SymbolTable *getParentTable();
};
