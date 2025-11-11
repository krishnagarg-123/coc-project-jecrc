#include <stdio.h>

// simple cab fare calculator

void menu();
void showRates();
float calcFare(float dist, int type);

int main() {
    int choice, cabType;
    float dist, fare;

    printf("\n=== CAB FARE CALCULATOR ===\n");

    do {
        menu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                showRates();
                break;

            case 2:
                printf("\nEnter distance (in km): ");
                scanf("%f", &dist);
                printf("Select cab type:\n1. Mini\n2. Sedan\n3. SUV\nEnter: ");
                scanf("%d", &cabType);

                fare = calcFare(dist, cabType);
                if(fare != -1)
                    printf("\nTotal Fare: ₹%.2f\n", fare);
                break;

            case 3:
                printf("\nThanks for using Cab Fare Calculator!\n");
                break;

            default:
                printf("\nInvalid choice! Try again.\n");
        }

    } while(choice != 3);

    return 0;
}

void menu() {
    printf("\n========================\n");
    printf("1. Show Cab Rates\n");
    printf("2. Calculate Fare\n");
    printf("3. Exit\n");
    printf("========================\n");
}

void showRates() {
    printf("\n--- CAB RATES ---\n");
    printf("Mini  - ₹10 per km\n");
    printf("Sedan - ₹15 per km\n");
    printf("SUV   - ₹20 per km\n");
    printf("Base Fare: ₹50\n");
}

float calcFare(float dist, int type) {
    float rate, total;

    if(type == 1)
        rate = 10;
    else if(type == 2)
        rate = 15;
    else if(type == 3)
        rate = 20;
    else {
        printf("\nInvalid cab type!\n");
        return -1;
    }

    total = (rate * dist) + 50;  // base fare added
    return total;
}
