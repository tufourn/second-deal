#ifndef CARDS_CARDS_H
#define CARDS_CARDS_H

#include <vector>
#include <string>

class card_t {
public:
    enum class rank_t : unsigned char {
        ace   = 1,
        two   = 2,
        three = 3,
        four  = 4,
        five  = 5,
        six   = 6,
        seven = 7,
        eight = 8,
        nine  = 9,
        ten   = 10,
        jack  = 11,
        queen = 12,
        king  = 13
    };

    enum class suit_t : unsigned char {
        clubs,
        diamonds,
        hearts,
        spades
    };

    card_t(rank_t RANK, suit_t SUIT);
    auto get_rank() -> rank_t;
    auto get_suit() -> suit_t;

    static auto to_string(suit_t SUIT) noexcept -> std::string;
    static auto to_string(rank_t RANK) noexcept -> std::string;
    static auto to_short_string(suit_t SUIT) noexcept -> std::string;
    static auto to_short_string(rank_t RANK) noexcept -> std::string;

    auto to_string() noexcept -> std::string;
    auto to_short_string() noexcept -> std::string;

    friend std::ostream& operator<<(std::ostream& os, card_t c);
private:
    rank_t rank = rank_t::ace;
    suit_t suit = suit_t::spades;
};

class deck_t {
public:
    static auto full_deck() -> deck_t; // create full deck of 52 cards
    auto shuffle() -> void; // shuffle the deck
    auto peek_top() -> card_t; // peek the top card (back of vector)
    auto deal_top() -> card_t; // deal the top card, return card dealt
    auto deal_sec() -> card_t; // deal the second card, return card dealt
    auto empty() const -> bool;
private:
    std::vector<card_t> cards;

};


#endif //CARDS_CARDS_H
