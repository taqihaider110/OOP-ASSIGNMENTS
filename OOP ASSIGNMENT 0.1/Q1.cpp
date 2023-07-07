#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Card {
public:
    int number;
    int digit_sum;

    Card(int n) {
        number = n;
        digit_sum = sum_digits(n);
    }

    int sum_digits(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
};

class CardGame {
public:
    vector<Card> cards;

    void get_data() {
        int num_cards;
        cout << "Enter number of cards: ";
        cin >> num_cards;

        for (int i = 0; i < num_cards; i++) {
            int card_number;
            cout << "Enter card number " << i+1 << ": ";
            cin >> card_number;
            cards.push_back(Card(card_number));
        }
    }

    void sort_cards() {
        sort(cards.begin(), cards.end(), [](Card a, Card b) {
            return a.digit_sum < b.digit_sum;
        });
    }

    void display() {
        cout << "Sorted cards:\n";
        for (Card c : cards) {
            cout << c.number << " (sum of digits = " << c.digit_sum << ")\n";
        }
    }
};

int main() {
    CardGame game;
    game.get_data();
    game.sort_cards();
    game.display();
    return 0;
}
