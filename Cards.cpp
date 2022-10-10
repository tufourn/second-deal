#include <array>
#include <algorithm>
#include <random>
#include <chrono>
#include "Cards.h"

auto deck_t::full_deck() -> deck_t {
    deck_t deck;
    auto all_ranks = std::array<card_t::rank_t, 13> {
        card_t::rank_t::ace,
        card_t::rank_t::two,
        card_t::rank_t::three,
        card_t::rank_t::four,
        card_t::rank_t::five,
        card_t::rank_t::six,
        card_t::rank_t::seven,
        card_t::rank_t::eight,
        card_t::rank_t::nine,
        card_t::rank_t::ten,
        card_t::rank_t::jack,
        card_t::rank_t::queen,
        card_t::rank_t::king,
    };

    auto all_suits = std::array<card_t::suit_t, 4> {
        card_t::suit_t::clubs,
        card_t::suit_t::diamonds,
        card_t::suit_t::hearts,
        card_t::suit_t::spades
    };

    for (auto suit : all_suits) {
        for (auto rank : all_ranks) {
            deck.cards.emplace_back(rank, suit);
        }
    }

    return deck;
}

auto deck_t::shuffle() -> void {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(cards.begin(), cards.end(), std::default_random_engine(seed));
}

auto deck_t::peek_top() -> card_t {
    return cards.back();
}

auto deck_t::deal_top() -> card_t {
    auto c = cards.back();
    cards.pop_back();
    return c;
}

auto deck_t::deal_sec() -> card_t {
    auto c = cards[cards.size() - 2];
    cards.erase(cards.end()-2);
    return c;
}

auto deck_t::empty() const -> bool {
    return cards.empty();
}

card_t::card_t(card_t::rank_t RANK, card_t::suit_t SUIT) {
    rank = RANK;
    suit = SUIT;
}

auto card_t::get_rank() -> card_t::rank_t {
    return rank;
}

auto card_t::get_suit() -> card_t::suit_t {
    return suit;
}

auto card_t::to_string(suit_t SUIT) noexcept -> std::string {
    switch (SUIT) {
        case suit_t::hearts:
            return "hearts";
        case suit_t::diamonds:
            return "diamonds";
        case suit_t::clubs:
            return "clubs";
        case suit_t::spades:
            return "spades";
        default:
            return "unknown suit";
    }
}

auto card_t::to_string(card_t::rank_t RANK) noexcept -> std::string {
    switch (RANK) {
        case rank_t::ace:
            return "ace";
        case rank_t::two:
            return "two";
        case rank_t::three:
            return "three";
        case rank_t::four:
            return "four";
        case rank_t::five:
            return "five";
        case rank_t::six:
            return "six";
        case rank_t::seven:
            return "seven";
        case rank_t::eight:
            return "eight";
        case rank_t::nine:
            return "nine";
        case rank_t::ten:
            return "ten";
        case rank_t::jack:
            return "jack";
        case rank_t::queen:
            return "queen";
        case rank_t::king:
            return "king";
        default:
            return "unknown rank";
    }
}

auto card_t::to_string() noexcept -> std::string {
    return card_t::to_string(rank) + " of " + card_t::to_string(suit);
}

auto card_t::to_short_string(card_t::suit_t SUIT) noexcept -> std::string {
    return std::string(1, toupper(to_string(SUIT)[0]));
}

auto card_t::to_short_string(card_t::rank_t RANK) noexcept -> std::string {
    switch (RANK) {
        case rank_t::ace:
            return "A";
        case rank_t::two:
            return "2";
        case rank_t::three:
            return "3";
        case rank_t::four:
            return "4";
        case rank_t::five:
            return "5";
        case rank_t::six:
            return "6";
        case rank_t::seven:
            return "7";
        case rank_t::eight:
            return "8";
        case rank_t::nine:
            return "9";
        case rank_t::ten:
            return "10";
        case rank_t::jack:
            return "J";
        case rank_t::queen:
            return "Q";
        case rank_t::king:
            return "K";
        default:
            return "unknown rank";
    }
}

auto card_t::to_short_string() noexcept -> std::string {
    return to_short_string(rank) + to_short_string(suit);
}

std::ostream &operator<<(std::ostream &os, card_t c) {
    os << c.to_short_string();
    return os;
}




