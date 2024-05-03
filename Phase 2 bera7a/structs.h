#pragma once
#include "enums.h"

struct Value
{
  void *value;
  Type type;
  bool isTemp = false;

  Value(void *val, Type type) : value(val), type(type) {}
};