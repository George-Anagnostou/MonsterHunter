// Potion

#ifndef POTION_H
#define POTION_H

#include <sstream>
#include <string>
#include <string_view>
#include "Random.h"

class Potion {
public:
	enum Type {
		health,
		strength,
		poison,
		max_type,
	};

	enum Size {
		small,
		medium,
		large,
		max_size,
	};

private:
	Type m_type {};
	Size m_size {};

public:
	Potion(Type type, Size size)
	: m_type { type }
	, m_size { size }
	{}

	Type getType() const { return m_type; }
	Size getSize() const { return m_size; }

	static std::string_view getPotionTypeName(Type type) {
		static constexpr std::string_view names[] {
			"Health",
			"Strength",
			"Poison",
		};

		return names[type];
	}

	static std::string_view getPotionSizeName(Size size) {
		static constexpr std::string_view names[] {
			"Small",
			"Medium",
			"Large",
		};

		return names[size];
	}

	std::string getName() const {
		std::stringstream result {};
		result << getPotionSizeName(getSize()) << " potion of " << getPotionTypeName(getType());
		return result.str();
	}

	static Potion getRandomPotion() {
		return Potion {
			static_cast<Type>(Random::get(0, max_type - 1)),
			static_cast<Size>(Random::get(0, max_size - 1))
		};
	}
};

#endif