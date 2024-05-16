#pragma once
#include "enums.h"
#include "structs.h"
#include <iostream>
#include <stack>
extern void throwError(string msg);
using namespace std;

// void printValue(Value *val)
// {
//     if (val->isTemp)
//     {
//         quadFile << "$R0";
//         return;
//     }
//     switch (val->type)
//     {
//     case TYPE_INT:
//         std::quadFile << *(int *)val->value;
//         break;
//     case TYPE_FLOAT:
//         std::quadFile << *(float *)val->value;
//         break;
//     case TYPE_BOOL:
//         std::quadFile << *(bool *)val->value;
//         break;
//     case TYPE_CHAR_ARRAY:
//         std::quadFile << "$R0";
//         break;
//     }
// }

void implementOperation(OP op, int forCount, stack<string> *forStack, Type type1, Type type2)
{
    extern ofstream quadFile;
    if (type1 == Type::TYPE_CHAR_ARRAY || type2 == Type::TYPE_CHAR_ARRAY || type1 == Type::TYPE_CHAR || type2 == Type::TYPE_CHAR)
    {
        throwError("Invalid operation on string");
    }

    if (forCount > 0)
    {
        switch (op)
        {
        case OP::PLUS:
            forStack->push("ADD");
            break;
        case OP::MINUS:
            forStack->push("SUB");
            break;
        case OP::MULTIPLY:
            forStack->push("MUL");
            break;
        case OP::DIVIDE:
            forStack->push("DIV");
            break;
        case OP::AND:
            forStack->push("AND");
            break;
        case OP::OR:
            forStack->push("OR");
            break;
        case OP::NOT:
            forStack->push("NOT");
            break;
        case OP::LeT:
            forStack->push("LT");
            break;
        case OP::GrT:
            forStack->push("GT");
            break;
        case OP::LeE:
            forStack->push("LE");
            break;
        case OP::GrE:
            forStack->push("GE");
            break;
        case OP::EQQ:
            forStack->push("EQ");
            break;
        case OP::NoE:
            forStack->push("NE");
            break;
        case OP::NEG:
            forStack->push("NEG");
            break;
        default:
            break;
        }
    }
    else
    {
        switch (op)
        {
        case OP::PLUS:
            quadFile << "ADD " << endl;
            break;
        case OP::MINUS:
            quadFile << "SUB " << endl;
            break;
        case OP::MULTIPLY:
            quadFile << "MUL " << endl;
            break;
        case OP::DIVIDE:
            quadFile << "DIV " << endl;
            break;
        case OP::AND:
            quadFile << "AND" << endl;
            break;
        case OP::OR:
            quadFile << "OR" << endl;
            break;
        case OP::NOT:
            quadFile << "NOT" << endl;
            break;
        case OP::LeT:
            quadFile << "LT " << endl;
            break;
        case OP::GrT:
            quadFile << "GT " << endl;
            break;
        case OP::LeE:
            quadFile << "LE " << endl;
            break;
        case OP::GrE:
            quadFile << "GE" << endl;
            break;
        case OP::EQQ:
            quadFile << "EQ " << endl;
            break;
        case OP::NoE:
            quadFile << "NE" << endl;
            break;
        case OP::NEG:
            quadFile << "NEG" << endl;
            break;
        default:
            break;
        }
    }
};