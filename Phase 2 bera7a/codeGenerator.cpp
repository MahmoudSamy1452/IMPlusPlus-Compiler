//
// Created by moaaz on 03/05/2024.
//
#include "codeGenerator.h"

using namespace std;

void implementOperation(Value *val1, Value *val2, OP op)
{
    Type highestType = max(val1->type, val2->type);
    
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
    printValue(val1);
    cout << endl;
}

