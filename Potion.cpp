// Potion Implementation

#include "Potion.h"

std::string Potion::getName() const {
    std::stringstream result {};
    result << getPotionSizeName(getSize()) << " potion of " << getPotionTypeName(getType());
    return result.str();
}