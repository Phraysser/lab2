#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct FootballPlayer {
    string surname;
    string position;
    int age;
    int gamesPlayed;
    int goals[5];
};

int main() {
    FootballPlayer players[] = {
        {"Ronaldo", "Forward", 36, 800, {1, 2, 3, 0, 1}},
        {"Messi", "Forward", 34, 750, {2, 2, 1, 3, 0}},
        {"Ramos", "Defender", 35, 700, {0, 0, 0, 0, 0}},
        {"Neymar", "Forward", 29, 600, {3, 1, 2, 2, 1}}
    };

    string filename = "football_players.dat";

    ofstream outfile(filename, ios::binary);

    if (!outfile) {
        cout << "Error opening file." << endl;
        return 1;
    }

    for (int i = 0; i < 4; i++) {
        outfile.write(reinterpret_cast<char*>(&players[i]), sizeof(FootballPlayer));
    }

    outfile.close();

    // Find the best forward
    int maxGoals = 0;
    string bestForward;

    ifstream infile(filename, ios::binary);

    if (!infile) {
        cout << "Error opening file." << endl;
        return 1;
    }

    for (int i = 0; i < 4; i++) {
        FootballPlayer player;
        infile.read(reinterpret_cast<char*>(&player), sizeof(FootballPlayer));

        int totalGoals = 0;
        for (int j = 0; j < 5; j++) {
            totalGoals += player.goals[j];
        }

        if (player.position == "Forward" && totalGoals > maxGoals) {
            maxGoals = totalGoals;
            bestForward = player.surname;
        }
    }

    infile.close();

    cout << "The best forward who scored the most goals in the last 5 games is: " << bestForward << endl;

    return 0;
}