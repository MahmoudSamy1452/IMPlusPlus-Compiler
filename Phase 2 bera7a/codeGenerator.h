#pragma once
#include "enums.h"
#include "structs.h"
#include <iostream>
#include <queue>
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

void implementOperation(OP op, int forCount, queue<string>* forQueue)
{
    if (forCount > 0){
        switch (op)
        {
            case OP::PLUS:
                forQueue->push("ADD");
                break;
            case OP::MINUS:
                forQueue->push("SUB");
                break;
            case OP::MULTIPLY:
                forQueue->push("MUL");
                break;
            case OP::DIVIDE:
                forQueue->push("DIV");
                break;
            case OP::AND:
                forQueue->push("AND");
                break;
            case OP::OR:
                forQueue->push("OR");
                break;
            case OP::NOT:
                forQueue->push("NOT");
                break;
            case OP::LeT:
                forQueue->push("LT");
                break;
            case OP::GrT:
                forQueue->push("GT");
                break;
            case OP::LeE:
                forQueue->push("LE");
                break;
            case OP::GrE:
                forQueue->push("GE");
                break;
            case OP::EQQ:
                forQueue->push("EQ");
                break;
            case OP::NoE:
                forQueue->push("NE");
                break;
            case OP::NEG:
                forQueue->push("NEG");
                break;
            default:
                break;
        }
    } else {
        switch (op)
        {
            case OP::PLUS:
                cout << "ADD " << endl;
                break;
            case OP::MINUS:
                cout << "SUB " << endl;
                break;
            case OP::MULTIPLY:
                cout << "MUL " << endl;
                break;
            case OP::DIVIDE:
                cout << "DIV " << endl;
                break;
            case OP::AND:
                cout << "AND" << endl;
                break;
            case OP::OR:
                cout << "OR" << endl;
                break;
            case OP::NOT:
                cout << "NOT" << endl;
                break;
            case OP::LeT:
                cout << "LT " << endl;
                break;
            case OP::GrT:
                cout << "GT " << endl;
                break;
            case OP::LeE:
                cout << "LE " << endl;
                break;
            case OP::GrE:
                cout << "GE" << endl;
                break;
            case OP::EQQ:
                cout << "EQ " << endl;
                break;
            case OP::NoE:
                cout << "NE" << endl;
                break;
            case OP::NEG:
                cout << "NEG" << endl;
                break;
            default:
                break;
        }
    }
};