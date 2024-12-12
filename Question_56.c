#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char supplierName[50];
    float price;
} Supplier;

typedef struct {
    char productName[50];
    int numSuppliers;
    Supplier *suppliers;
} Product;

void inputProductData(Product *products, int numProducts) {
    for (int i = 0; i < numProducts; ++i) {
        scanf("%s", products[i].productName);
        scanf("%d", &products[i].numSuppliers);
        products[i].suppliers = (Supplier *)malloc(products[i].numSuppliers * sizeof(Supplier));

        for (int j = 0; j < products[i].numSuppliers; ++j) {
            scanf("%s %f", products[i].suppliers[j].supplierName, &products[i].suppliers[j].price);
        }
    }
}

void calculateAndPrintAverages(Product *products, int numProducts) {
    for (int i = 0; i < numProducts; ++i) {
        printf("Product: %s\n", products[i].productName);

        float totalPrice = 0.0;
        float minPrice = products[i].suppliers[0].price;
        char cheapestSupplier[50];
        strcpy(cheapestSupplier, products[i].suppliers[0].supplierName);

        for (int j = 0; j < products[i].numSuppliers; ++j) {
            totalPrice += products[i].suppliers[j].price;
            if (products[i].suppliers[j].price < minPrice) {
                minPrice = products[i].suppliers[j].price;
                strcpy(cheapestSupplier, products[i].suppliers[j].supplierName);
            }
        }

        float averagePrice = totalPrice / products[i].numSuppliers;
        printf("Average Price: %.2f\n", averagePrice);
        printf("Cheapest Supplier: %s\n", cheapestSupplier);
    }
}

void freeProductData(Product *products, int numProducts) {
    for (int i = 0; i < numProducts; ++i) {
        free(products[i].suppliers);
    }
}

int main() {
    int numProducts;
    scanf("%d", &numProducts);

    Product *products = (Product *)malloc(numProducts * sizeof(Product));

    inputProductData(products, numProducts);
    calculateAndPrintAverages(products, numProducts);
    freeProductData(products, numProducts);

    free(products);
    return 0;
}