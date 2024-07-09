#include <stdio.h>
#include <conio.h>
#include <math.h>

int intersectionPoints (float x1, float y1, float r1, float x2, float y2, float r2) {
    double dist_sq = pow(x2 - x1, 2) + pow(y2 - y1, 2); //dist_sq - квадрат відстані між центрами двох кіл
    double r_sum_sq = pow(r1 + r2, 2);  // r_sum_sq - квадрат суми радіусів
    double r_diff_sq = pow(r1 - r2, 2); // r_diff_sq - квадрат різниці радіусів

    if (dist_sq == 0 && r1 == r2) {
        return -1; // нескінченна кількість точок перетину
    } else if (dist_sq > r_sum_sq || dist_sq < r_diff_sq) {
        return 0; // немає точок перетину
    } else if (dist_sq == r_sum_sq || dist_sq == r_diff_sq) {
        return 1; // одна точка перетину
    } else {
        return 2; // дві точки перетину
    }
}

int main () {
    float x1, y1, r1, x2, y2, r2;
    printf("Enter the coordinates of the centers of the 2 circles and their radii (x1 y1 r1 x2 y2 r2): ");
    scanf ("%f %f %f %f %f %f", &x1, &y1, &r1, &x2, &y2, &r2);
    printf ("Intersection point: %d\n", intersectionPoints (x1, y1, r1, x2, y2, r2));

    printf ("Press any key to exit the program.");
    getch();
    return 0;
}