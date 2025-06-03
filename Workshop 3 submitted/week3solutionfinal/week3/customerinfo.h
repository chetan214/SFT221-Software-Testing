#pragma once
// +++++++++
// Name: Chetan Arora
// email: carora18@myseneca.ca
// Student id: 100976240
// Section: ZAA

typedef struct {
    char firstName[50];
    char lastName[50];
    char streetAddress[100];
    char city[100];
    char province[10];
    char postalCode[8];
} Customer;

int isValidPostalCode(const char* postalCode);
