#ifndef CHECKERS_SRC_UNITS_UNIT_HPP
#define CHECKERS_SRC_UNITS_UNIT_HPP

#include <iostream>
#include "../cpp-text-designer/designer.h"
#include "unit_side.hpp"

class unit {
public:
	unit(unit_side uside) {
		side = uside;
	}

	unit(const unit&) = delete;
	unit& operator=(const unit&) = delete;

	virtual ~unit() = default;

	void print() const {
		std::string colored_shape;
		switch (side) {
			case BLACK:
				colored_shape = designer::make_colored(get_shape(), designer::BLACK, is_bold_shape());
				break;

			case WHITE:
				colored_shape = designer::make_colored(get_shape(), designer::WHITE, is_bold_shape());
				break;
		}
		std::cout << colored_shape;
	}

private:
	unit_side side;

	[[nodiscard]] virtual std::string get_shape() const = 0;

	[[nodiscard]] virtual bool is_bold_shape() const = 0;
};

#endif //CHECKERS_SRC_UNITS_UNIT_HPP