#define _USE_MATH_DEFINES 
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

inline double distanceBetween(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

inline double toRadians(double degrees) {
    return degrees * (M_PI / 180.0);
}

inline double clamp(double value, double minVal, double maxVal) {
    if (value < minVal) return minVal;
    if (value > maxVal) return maxVal;
    return value;
}

inline bool isInSafeZone(double x, double y, double cx, double cy, double radius) {
    return distanceBetween(x, y, cx, cy) <= radius;
}

int main() {
    const double homeX = 0.0;
    const double homeY = 0.0;
    const double safeRadius = 50.0;

    struct Waypoint {
        string label;
        double x;
        double y;
    };

    Waypoint waypoints[3] = {
        {"Waypoint A", 15.0, 20.0},  
        {"Waypoint B", 30.0, 40.0},  
        {"Waypoint C", 60.0, 80.0}   
    };

    cout << "Home Base  : (" << homeX << ", " << homeY << ")\n";
    cout << "Safe Radius: " << safeRadius << " units\n\n";

    for (int i = 0; i < 3; i++) {
        double distance = distanceBetween(homeX, homeY, waypoints[i].x, waypoints[i].y);
        bool safe = isInSafeZone(waypoints[i].x, waypoints[i].y, homeX, homeY, safeRadius);

        cout << waypoints[i].label << " (" << waypoints[i].x << ", " << waypoints[i].y << "):\n";
        cout << "  Distance to Home: " << distance << " units\n";
        cout << "  Status          : " << (safe ? "[SAFE]" : "[UNSAFE - OUT OF BOUNDS]") << "\n\n";
    }

    return 0;
}

