#include <iostream>
#include <cstdlib>  // for rand() and srand()
#include <ctime>    // for time()
using namespace std;

int main() {
    string name;

    // Ask user for input
    cout << "Enter your name: ";
    getline(cin, name);

    // Handle empty input
    if (name.length() == 0) {
        cout << "Please enter a valid name next time!" << endl;
        return 0;
    }

    // Array of roast templates (at least 10)
    string roasts[] = {
        "{name} writes code so slow that even a turtle switched to Python.",
        "If procrastination were an Olympic sport, {name} would have a gold medal.",
        "{name}'s debugging style is staring at the screen until the bug leaves.",
        "{name} doesn't write bugs, they create unexpected features.",
        "{name}'s code runs so slowly, even dial-up internet feels fast.",
        "If laziness had a face, it would probably look like {name}.",
        "{name} thinks 'Ctrl + C' and 'Ctrl + V' is advanced programming.",
        "{name} spends more time thinking about coding than actually coding.",
        "{name}'s code is so confusing, even {name} doesn't understand it.",
        "{name} once fixed a bug… by turning off the computer."
    };

    // Total number of roasts
    int total = 10;

    // Initialize random seed (ensures different output each run)
    srand(time(0));

    // Generate random index
    int index = rand() % total;

    string selected = roasts[index];

    // Replace {name} with actual input
    string result = "";
    for (int i = 0; i < selected.length(); i++) {
        if (selected.substr(i, 6) == "{name}") {
            result += name;
            i += 5; // skip "{name}"
        } else {
            result += selected[i];
        }
    }

    // Output result
    cout << "\n Your Roast \n";
    cout << result << endl;

    return 0;
}