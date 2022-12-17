#include <regex>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;


int main()
{
    string filenames = "laba31test.html";
    regex Emailcheck("^[^_.][a-zA-Z0-9_.-]+[^_.]@[a-zA-Z0-9]+\.[a-zA-Z0-9.]+$");
    string lineHtml;
    ifstream fileHtml(filenames);
    if (!fileHtml.is_open()) {
        cout << "File error";
    }
    else {
        while (getline(fileHtml, lineHtml))
        {
            lineHtml.erase(remove(lineHtml.begin(), lineHtml.end(), ' '), lineHtml.end());
            if (regex_search(lineHtml, Emailcheck)) {
                cout << lineHtml << '\n';
            }
        }
    }
}

