#pragma once
#include "enums.h"
#include "structs.h"
#include <iostream>
using namespace std;

void printValue(Value *val)
{
    if (val->isTemp)
    {
        cout << "$R0";
        return;
    }
    switch (val->type)
    {
    case TYPE_INT:
        std::cout << *(int *)val->value;
        break;
    case TYPE_FLOAT:
        std::cout << *(float *)val->value;
        break;
    case TYPE_BOOL:
        std::cout << *(bool *)val->value;
        break;
    case TYPE_CHAR_ARRAY:
        std::cout << "$R0";
        break;
    }
}

void implementOperation(Value *val1, Value *val2, OP op)
{

    switch (op)
    {
    case OP::PLUS:
        cout << "ADD $R0, ";
        break;
    case OP::MINUS:
        cout << "SUB $R0, ";
        break;
    case OP::MULTIPLY:
        cout << "MUL $R0, ";
        break;
    case OP::DIVIDE:
        cout << "DIV $R0, ";
        break;
    case OP::AND:
        cout << "AND $R0, ";
        break;
    case OP::OR:
        cout << "OR $R0, ";
        break;
    case OP::NOT:
        cout << "NOT $R0, ";
        break;
    case OP::LeT:
        cout << "LT $R0, ";
        break;
    case OP::GrT:
        cout << "GT $R0, ";
        break;
    case OP::LeE:
        cout << "LE $R0, ";
        break;
    case OP::GrE:
        cout << "GE $R0, ";
        break;
    case OP::EQQ:
        cout << "EQ $R0, ";
        break;
    case OP::NoE:
        cout << "NE $R0, ";
        break;
    default:
        break;
    }

    printValue(val1);
    cout << ", ";
    printValue(val2);
    cout << endl;
};
