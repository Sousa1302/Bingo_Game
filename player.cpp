#include "player.h"

Player::Player(string playerName, int cardSize, int max_value, int card_number) : name(playerName), card(cardSize, max_value, card_number) {} 

int Player::markNumber(int num) {
    return card.markNum(num);
}

bool Player::hasBingo() const {
    return card.isComplete();
}

string Player::getName() const {
    return name;
}