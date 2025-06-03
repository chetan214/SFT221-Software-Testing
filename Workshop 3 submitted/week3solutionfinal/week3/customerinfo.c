// +++++++++
// Name: Chetan Arora
// email: carora18@myseneca.ca
// Student id: 100976240
// Section: ZAA

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include"customerinfo.h"



int isValidPostalCode(const char* postalCode) {

    if (isalpha(postalCode[0]) && isdigit(postalCode[1]) &&
        isalpha(postalCode[2]) && (postalCode[3] == ' ' || postalCode[3] == '\0') &&
        isdigit(postalCode[4]) && isalpha(postalCode[5]) && isdigit(postalCode[6]) && postalCode[7] == '\0') {
        return 1;
    }
    return 0;
}

Customer getCustomerInfo() {
    Customer customer;

    printf("Enter your first name: ");
    fgets(customer.firstName, 50, stdin);
    customer.firstName[strcspn(customer.firstName, "\n")] = 0;
    while (strlen(customer.firstName) == 0) {
        printf("Invalid Entry: Enter your first name: ");
        fgets(customer.firstName, 50, stdin);
        customer.firstName[strcspn(customer.firstName, "\n")] = 0;
    }

    printf("Enter your last name: ");
    fgets(customer.lastName, 50, stdin);
    customer.lastName[strcspn(customer.lastName, "\n")] = 0;
    while (strlen(customer.lastName) == 0) {
        printf("Invalid Entry: Enter your last name: ");
        fgets(customer.lastName, 50, stdin);
        customer.lastName[strcspn(customer.lastName, "\n")] = 0;
    }

    printf("Enter your street address: ");
    fgets(customer.streetAddress, 100, stdin);
    customer.streetAddress[strcspn(customer.streetAddress, "\n")] = 0;
    while (strlen(customer.streetAddress) == 0) {
        printf("Invalid Entry: Enter your street address: ");
        fgets(customer.streetAddress, 100, stdin);
        customer.streetAddress[strcspn(customer.streetAddress, "\n")] = 0;
    }

    printf("Enter your city: ");
    fgets(customer.city, 50, stdin);
    customer.city[strcspn(customer.city, "\n")] = 0;
    while (strlen(customer.city) == 0) {
        printf("Invalid Entry: Enter your city: ");
        fgets(customer.city, 50, stdin);
        customer.city[strcspn(customer.city, "\n")] = 0;
    }

    printf("Enter your province: ");
    fgets(customer.province, 10, stdin);
    customer.province[strcspn(customer.province, "\n")] = 0;
    while (strlen(customer.province) != 2 || !isalpha(customer.province[0]) || !isalpha(customer.province[1])) {
        printf("Invalid Entry: Enter your province: ");
        fgets(customer.province, 10, stdin);
        customer.province[strcspn(customer.province, "\n")] = 0;
    }

    printf("Enter your postal code: ");
    while (1) {
        fgets(customer.postalCode, 8, stdin);
        customer.postalCode[strcspn(customer.postalCode, "\n")] = 0;
        if (isValidPostalCode(customer.postalCode)) {
            break;
        }
        else {
            printf("Invalid Entry: Enter your postal code: ");
        }
    }

    return customer;
}
int main() {
    Customer customer = getCustomerInfo();
    printf("%s %s\n", customer.firstName, customer.lastName);
    printf("%s,\n", customer.streetAddress);
    printf("%s, %s,\n", customer.city, customer.province);
    printf("%s\n", customer.postalCode);

    return 0;
}