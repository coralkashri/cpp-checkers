#ifndef CHECKERS_SRC_UNITS_QUEEN_HPP
#define CHECKERS_SRC_UNITS_QUEEN_HPP

#include "soldier.hpp"

class queen : public soldier {
public:
	[[nodiscard]] std::string get_shape() const override {
		return "0";
	}

	[[nodiscard]] bool is_bold_shape() const override {
		return true;
	}
};

#endif //CHECKERS_SRC_UNITS_QUEEN_HPP