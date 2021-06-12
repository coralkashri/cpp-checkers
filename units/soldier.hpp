#ifndef CHECKERS_SRC_SOLDIER_HPP
#define CHECKERS_SRC_SOLDIER_HPP

#include "unit.hpp"

class soldier : public unit {
public:
	explicit soldier(unit_side uside) : unit(uside) {}

	[[nodiscard]] std::string get_shape() const override {
		return "O";
	}

	[[nodiscard]] bool is_bold_shape() const override {
		return false;
	}
};

#endif //CHECKERS_SRC_SOLDIER_HPP