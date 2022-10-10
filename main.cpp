#include <iostream>
#include <iomanip>
#include "Cards.h"

int main() {
    auto deck = deck_t::full_deck();
    deck.shuffle();

    int hands_num;
    std::cout << "enter number of hands: ";
    std::cin >> hands_num;

    std::vector<std::vector<card_t>> hands(hands_num);

    while (!deck.empty()) {
        for (auto i = 0; i < hands_num; i++) {
            std::cout << "top card is " << deck.peek_top() << "\n\n";
            std::cout << "dealing to player " << i + 1 << "\n\n";

            // get input
            std::string action;
            std::cout << "enter action (1 for top, 2 for second, s to skip): ";
            std::cin >> action;

            // process input
            if (action == "1") {
                hands[i].push_back(deck.deal_top());
            }
            if (action == "2") {
                hands[i].push_back(deck.deal_sec());
            }
            if (action == "s") {
                continue;
            }

            // clear the screen
            std::cout << "\033[2J\033[1;1H";

            // rerender hands
            for (auto j = 0; j < hands_num; j++) {
                std::cout << "player " << j + 1 << ": ";
                for (auto c : hands[j]) {
                    std::cout << std::setw(3) << c;
                }
                std::cout << std::endl;
            }
        }
    }
    return 0;
}
