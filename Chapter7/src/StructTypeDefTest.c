//
// Created by tkhle on 24.02.2023.
//

#include <stdio.h>

struct SimpleStruct {
    int x;
};

typedef struct {
    int x;
} TypedefAnonymousStruct;

typedef struct TypedefNamedStruct {
    int x;
} TypedefNamedStruct;

// One can only use NO_NAME_ENUM, but not as a parameter
enum {
    NO_NAME_ENUM
};

typedef enum {
    TYPEDEF_ANONYMOUS_ENUM
} TypedefAnonymousEnum;

typedef enum TypedefNamedEnum {
    TYPEDEF_NAMED_ENUM
} TypedefNamedEnum;

void funcSimpleStruct(struct SimpleStruct s) {
    printf("Simple struct: %d\n", s.x);
}

void funcTypedefAnonymousStruct(TypedefAnonymousStruct ta) {
    printf("Typedef anonymous struct: %d\n", ta.x);
}

void funcTypedefNamedStruct(TypedefNamedStruct tn) {
    printf("Typedef anonymous struct: %d\n", tn.x);
}

void funcTypedefAnonymousEnum(TypedefAnonymousEnum ta) {
    printf("Typedef anonymous enum: %d\n", ta);
    // You can not use TypedefAnonymousEnum.TYPEDEF_ANONYMOUS_ENUM
    TypedefAnonymousEnum typedefAnonymousEnum = TYPEDEF_ANONYMOUS_ENUM;
}

void funcTypedefNamedEnum(TypedefNamedEnum tn) {
    printf("Typedef named enum: %d\n", tn);
    // You can not use TypedefNamedEnum.TYPEDEF_NAMED_ENUM
    TypedefNamedEnum typedefNamedEnum = TYPEDEF_NAMED_ENUM;
}

int main() {
    struct SimpleStruct s1;
    TypedefAnonymousStruct ta1;
    TypedefNamedStruct tn1;
    // struct TypedefAnonymousStruct ta2;   // not possible
    struct TypedefNamedStruct tn2;  // totally possible

    funcSimpleStruct(s1);
    funcTypedefAnonymousStruct(ta1);
    funcTypedefNamedStruct(tn1);
    funcTypedefNamedStruct(tn2);
    funcTypedefAnonymousEnum(TYPEDEF_ANONYMOUS_ENUM);
    funcTypedefNamedEnum(TYPEDEF_NAMED_ENUM);
}