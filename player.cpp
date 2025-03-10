#include "player.h"

Player::Player(string playerName, int cardSize, int max_value, int card_number) : name(playerName), card(cardSize, max_value, card_number) {} 

bool Player::hasBingo() const {
    return card.isComplete();
}

string Player::getName() const {
    return name;
}