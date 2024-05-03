//
// Created by moaaz on 03/05/2024.
//

#include "codeGenerator.h"


void codeGenerator::implementOperation(Value *val1, Value *val2, OP op) {
    switch (val1->type) {
        case TYPE_INT:
            int *val1Int = (int *) val1->value;
            break;
        case TYPE_CHAR:
            char *val1Char = (char *) val1->value;
            break;
        case TYPE_CHAR_ARRAY:
            char *val1CharArray = (char *) val1->value;
            break;
    }
    switch (op) {
        case expression:
        
    }
    
}