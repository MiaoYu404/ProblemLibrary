#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<pair<int, int>> cows(n); // Stores the smallest card and cow index
        vector<vector<int>> cards(n, vector<int>(m));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> cards[i][j];
            }
            sort(cards[i].begin(), cards[i].end()); // Sort each cow's cards
            cows[i] = {cards[i][0], i}; // Store the smallest card and cow index
        }

        sort(cows.begin(), cows.end()); // Sort cows based on their smallest card

        vector<int> order;
        for (auto& cow : cows) {
            order.push_back(cow.second);
        }

        int topCard = -1;
        bool valid = true;

        for (int round = 0; round < m; ++round) {
            for (int i = 0; i < n; ++i) {
                int cow = order[i];
                auto it = upper_bound(cards[cow].begin(), cards[cow].end(), topCard);
                if (it == cards[cow].end()) {
                    valid = false;
                    break;
                }
                topCard = *it; // Update the top card
                cards[cow].erase(it); // Remove the card from the cow's deck
            }
            if (!valid) break;
        }

        if (valid) {
            for (int i = 0; i < n; ++i) {
                cout << order[i] + 1 << " ";
            }
            cout << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}