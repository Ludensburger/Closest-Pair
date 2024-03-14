#include <stdio.h>
#include <math.h>
#include <float.h> // For DBL_MAX

// A structure to represent a Point in 2D plane
struct Point {
    int x, y;
};

// Function to calculate distance between two points
double distance(struct Point p1, struct Point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) +
                (p1.y - p2.y) * (p1.y - p2.y));
}

// Function to find the closest pair of points in the given array of points
void findClosestPair(struct Point points[], int n) {
    double minDist = DBL_MAX;
    int minIndex1 = -1, minIndex2 = -1;

    // Calculate distances between all pairs and find the minimum
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            double dist = distance(points[i], points[j]);
            if (dist < minDist) {
                minDist = dist;
                minIndex1 = i;
                minIndex2 = j;
            }
        }
    }

    // Display the result
    printf("The closest pair is P%d(%d, %d) and P%d(%d, %d) \nwith a distance of %.2f\n",
           minIndex1 + 1, points[minIndex1].x, points[minIndex1].y,
           minIndex2 + 1, points[minIndex2].x, points[minIndex2].y, minDist);
}

int main() {
    // Test data
    struct Point points[] = {{0, 1}, {2, 0}, {2, 2}, {1, 2}};
    int n = sizeof(points) / sizeof(points[0]);

    // Find and print the closest pair of points
    findClosestPair(points, n);

    return 0;
}