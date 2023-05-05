#include <iostream>
#include <vector>
#include <cmath>

// Beck Christensen, May 4th, Practice Program, Thu

using namespace std;

/*uses Heron's formula to calculate area of trianle
given the lengths of its side */
int findArea(vector<double> triangle)
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

string btos(bool x)
{
  if(x) return "True";
  return "False";
}

int main()
{

    bool ans;

    // test one: triangle same size as hole
    vector<double> triangle{2.0, 2.0, 2.0};
    vector<double> hole{2.0, 2.0, 2.0};

    ans = doesTriangleFit(triangle, hole);

    cout << "Area of triangle: " << findArea(triangle) << endl;
    cout << "Area of hole: " << findArea(hole) << endl;

    cout << "Answer for test one: " << btos(ans) << endl;
    cout << "Sould be: True" << endl
         << endl;

    // test two: triangle bigger than hole
    vector<double> triangle2{3.0, 3.0, 3.0};

    ans = doesTriangleFit(triangle2, hole);

    cout << "Area of triangle: " << findArea(triangle2) << endl;
    cout << "Area of hole: " << findArea(hole) << endl;

    cout << "Answer for test one: " << btos(ans) << endl;
    cout << "Sould be: False" << endl
         << endl;

    // test three: triangle smaller than hole
    vector<double> triangle3{1.0, 1.0, 1.0};

    ans = doesTriangleFit(triangle3, hole);

    cout << "Area of triangle: " << findArea(triangle3) << endl;
    cout << "Area of hole: " << findArea(hole) << endl;

    cout << "Answer for test one: " << btos(ans) << endl;
    cout << "Sould be: True" << endl;
}