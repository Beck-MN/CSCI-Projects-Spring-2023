// Beck Christensen, 5/1/2023, Monday

#include <iostream>
#include <string>

using namespace std;

/*@problem: Create a function that takes a string s (text to be encrypted)
 and an integer k (the rotation factor). It should return an encrypted string. */

string caesarChiper(string s, int degree)
{

    int num;
    int i;
    int length = s.length();
    for (i = 0; i < length; ++i)
    {

        char c = s[i];
        char newC;

        // ingnores spaces
        if (s[i] != ' ')
        {

            // converting char to ASCII vlaue
            num = int(s[i]);

            // if the letter is capital
            if (num > 64 && num < 91)
            {
                if ((num + degree) > 90)
                {
                    num = (num + degree) - 26;
                    newC = char(num);
                    s[i] = newC;
                }
                else
                {
                    num = num + degree;
                    newC = char(num);
                    s[i] = newC;
                }
            }

            // if the letter is lowercase
            if (num > 96 && num < 123)
            {
                if ((num + degree) > 122)
                {
                    num = (num + degree) - 26;
                    newC = char(num);
                    s[i] = newC;
                }
                else
                {
                    num = num + degree;
                    newC = char(num);
                    s[i] = newC;
                }
            }
        }
    }
    return s;
}

int main()
{

    string s;
    int degree;

    cout << "Enter a sentence: ";
    getline(cin, s);
    cout << "Enter a degree: ";
    cin >> degree;

    string newS = caesarChiper(s, degree);

    cout << newS << endl;

    return 0;
}