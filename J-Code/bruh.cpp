#include <iostream>
#include <cmath>
using namespace std;

// Function prototypes
double calculateCircleArea(double radius);
double calculateRectangleArea(double length, double width);
double calculateTriangleArea(double base, double height);

int main()
{
    int choice;
    do
    {
        // Display the menu
        cout << "\n=== Area Calculator ===" << endl;
        cout << "1. Circle" << endl;
        cout << "2. Rectangle" << endl;
        cout << "3. Triangle" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            // Circle
            double radius;
            cout << "Enter the radius of the circle: ";
            cin >> radius;
            cout << "The area of the circle is: " << calculateCircleArea(radius) << endl;
            break;
        }
        case 2:
        {
            // Rectangle
            double length, width;
            cout << "Enter the length of the rectangle: ";
            cin >> length;
            cout << "Enter the width of the rectangle: ";
            cin >> width;
            cout << "The area of the rectangle is: " << calculateRectangleArea(length, width) << endl;
            break;
        }
        case 3:
        {
            // Triangle
            double base, height;
            cout << "Enter the base of the triangle: ";
            cin >> base;
            cout << "Enter the height of the triangle: ";
            cin >> height;
            cout << "The area of the triangle is: " << calculateTriangleArea(base, height) << endl;
            break;
        }
        case 4:
            // Exit
            cout << "Exiting the program. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}

// Function to calculate the area of a circle
double calculateCircleArea(double radius)
{
    return M_PI * radius * radius; // M_PI is a constant for Pi
}

// Function to calculate the area of a rectangle
double calculateRectangleArea(double length, double width)
{
    return length * width;
}

// Function to calculate the area of a triangle
double calculateTriangleArea(double base, double height)
{
    return 0.5 * base * height;
}