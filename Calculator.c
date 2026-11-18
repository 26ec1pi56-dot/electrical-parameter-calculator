#include <stdio.h>
#include <stdlib.h>

double readValue(const char *prompt) {
    double x;
    int r;
    while (1) {
        printf("%s", prompt);
        r = scanf("%lf", &x);
        if (r == EOF) exit(1);
        if (r == 1 && x >= 0) return x;
        printf("Invalid input! Enter a non-negative number.\n");
        while (getchar() != '\n');
    }
}

void showMenu(void) {
    printf("\n--- Electrical Parameter Calculator ---\n");
    printf("1. Voltage  (V = I x R)\n");
    printf("2. Current  (I = V / R)\n");
    printf("3. Resistance (R = V / I)\n");
    printf("4. Power (P = V x I)\n");
    printf("5. Power (P = I^2 x R)\n");
    printf("6. Power (P = V^2 / R)\n");
    printf("7. Exit\n");
    printf("Choice: ");
}

int main(void) {
    int ch;
    double v, i, r;
    do {
        showMenu();
        if (scanf("%d", &ch) != 1) {
            printf("Invalid choice!\n");
            while (getchar() != '\n');
            continue;
        }
        switch (ch) {
        case 1:
            i = readValue("Current (A): ");
            r = readValue("Resistance (ohm): ");
            printf("Voltage = %.4f V\n", i * r);
            break;
        case 2:
            v = readValue("Voltage (V): ");
            r = readValue("Resistance (ohm): ");
            if (r == 0) printf("Error: resistance cannot be zero.\n");
            else printf("Current = %.4f A\n", v / r);
            break;
        case 3:
            v = readValue("Voltage (V): ");
            i = readValue("Current (A): ");
            if (i == 0) printf("Error: current cannot be zero.\n");
            else printf("Resistance = %.4f ohm\n", v / i);
            break;
        case 4:
            v = readValue("Voltage (V): ");
            i = readValue("Current (A): ");
            printf("Power = %.4f W\n", v * i);
            break;
        case 5:
            i = readValue("Current (A): ");
            r = readValue("Resistance (ohm): ");
            printf("Power = %.4f W\n", i * i * r);
            break;
        case 6:
            v = readValue("Voltage (V): ");
            r = readValue("Resistance (ohm): ");
            if (r == 0) printf("Error: resistance cannot be zero.\n");
            else printf("Power = %.4f W\n", v * v / r);
            break;
        case 7:
            printf("Goodbye!\n");
            break;
        default:
            printf("Invalid choice! Select 1-7.\n");
        }
    } while (ch != 7);
    return 0;
}
