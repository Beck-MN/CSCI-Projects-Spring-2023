#include <iostream>
#include <stdlib.h>
#include <vector>
#include <cmath>

// Beck Christensen, May 4th, Practice Program, Thu

/*@problem: Create a function that takes the dimensions of 
two triangles (as arrays) and checks if the first triangle 
fits into the second one. */

using namespace std;

/*uses Heron's formula to calculate area of trianle
given the lengths of its side */
double findArea(vector<double> triangle)
{
    double a = triangle[0];
    double b = triangle[1];
    double c = triangle[2];

    double s = (a + b + c) / 2;

    double area = sqrt(s * (s - a) * (s - b) * (s - c));

    return area;
}

/*Compares the areas of the two triangles, if the
area of the triangle is less or equal to the area of
the hole, the function returns true*/
bool doesTriangleFit(vector<double> triangle, vector<double> hole)
{

    return findArea(triangle) <= findArea(hole);
}

/*Returns the string value of a boolean input
1 = True, 0 = False*/
string btos(bool x)
{
    if (x)
        return "True";
    return "False";
}

/*function to see if given trianlge is actually a triangle (mathematically speaking).
An input is a triangle if the sum of any two sides is bigger than
remaining side. If input is not a triangle, function throws
excpetion and exits the code*/
void isTriangle(vector<double> triangle)
{

    double a = triangle[0];
    double b = triangle[1];
    double c = triangle[2];

    try
    {
        if (a + b > c && b + c > a && a + c > b && triangle.size() == 3)
        {
            return;
        }
        else
        {
            throw 505;
        }
    }

    catch (...)
    {
        cout << "Error: Impossible Triangle" << endl;
        exit(EXIT_SUCCESS);
    }
}

int main()
{

    bool ans;
    double in;

    vector<double> triangle;
    vector<double> hole;

    cout << "Enter triangle diamentions one at a time:";
    for (int i = 0; i < 3; ++i)
    {
        cin >> in;
        triangle.push_back(in);
    }

    isTriangle(triangle);

    cout << "Enter hole diamentions one at a time:";
    for (int i = 0; i < 3; ++i)
    {
        cin >> in;
        hole.push_back(in);
    }

    isTriangle(hole);

    cout << "Area of triangle: " << findArea(triangle) << endl;
    cout << "Area of hole: " << findArea(hole) << endl;

    if (doesTriangleFit(triangle, hole))
    {
        cout << "Your triangle fits in the hole" << endl;
    }
    else
    {
        cout << "Your triangle does not fit in the hole" << endl;
    }
}