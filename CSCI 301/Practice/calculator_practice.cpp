#include <iostream>
#include <cmath>

// Beck Christensen, Sun May 7th, practice program

/*Basic calulator, mainly just testing out vs code on my laptop and trying out a new keyboard.
Takes in a line of two number seperated by an opperator and spits out the result*/

using namespace std;

double add(double num, double num2)
{

    return num += num2;
}

double sub(double num, double num2)
{

    return num -= num2;
}

double mult(double num, double num2)
{

    return num *= num2;
}

double div(double num, double num2)
{

    return num /= num2;
}

int main()
{

    double num, num2;
    char opp = ' ';
    char start = 'y';

    while (start = 'y')
    {

        cout << "Please enter an equation: " << endl;
        cin >> num >> opp >> num2;

        if (opp == '+')
        {
            num = add(num, num2);
        }
        else if (opp == '-')
        {
            num = sub(num, num2);
        }
        else if (opp == '*')
        {
            num = mult(num, num2);
        }
        else
        {
            num = div(num, num2);
        }

        cout << "Your number is: " << num << endl;
        cout << "Do you want to continue?: ";
        cin >> start;
    }
    return 0;
}