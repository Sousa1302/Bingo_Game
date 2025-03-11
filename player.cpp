#include "player.h"

/**
 * @brief Constructs a Player object with a bingo card of specified size and maximum value.
 * 
 * This constructor initializes a Player object by creating a bingo card for the player.
 * The card is generated with the specified size, maximum value, and a unique card number.
 * 
 * @param cardSize The size of the bingo card (e.g., 5x5 grid).
 * @param max_value The maximum value that can appear on the bingo card.
 * @param card_number A unique identifier for the player's bingo card.
 */
Player::Player(int cardSize, int max_value, int card_number) : card(cardSize, max_value, card_number) {} 



