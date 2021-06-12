#ifndef CHECKERS_SRC_BOARD_MANAGEMENT_HPP
#define CHECKERS_SRC_BOARD_MANAGEMENT_HPP

#include <memory>
#include "array"
#include "units/unit.hpp"
#include "units/queen.hpp"

template<size_t Width, size_t Height>
class board_management {
public:
	board_management() :
			inaccessible_place_shape(), // TODO make inaccessible_section_shape visible
			empty_place_shape("~") {
		initialize_board();
	}

	void print() {
		auto current_unit = board.cbegin();
		bool is_inaccessible_section = true;
		for (size_t i = 0; i < Width * Height; ++i, is_inaccessible_section = !is_inaccessible_section) {
			if (is_inaccessible_section)
				print_inaccessible_section();
			else {
				print_unit((*current_unit).get());
				current_unit = std::next(current_unit);
				std::cout << " "; // TODO Remove this line
			}
			// TODO std::cout << " ";
			if (is_end_of_row(i)) {
				std::cout << "\n";
				is_inaccessible_section = !is_inaccessible_section;
			}
		}
		std::cout << std::endl;
	}

private:
	std::array<std::unique_ptr<unit>, Width / 2 * Height> board;
	const std::string inaccessible_place_shape;
	const std::string empty_place_shape;

	void initialize_board() {
		size_t row_number = 0;
		size_t current_unit_num = 0;
		for (auto &current_unit : board) {
			if (row_number < 3) {
				current_unit.reset(new soldier(unit_side::BLACK));
			} else if (row_number > 4) {
				current_unit.reset(new soldier(unit_side::WHITE));
			}
			forward_unit_number(current_unit_num);
			if (!current_unit_num)
				row_number++;
		}
		std::cout << std::endl;
	}

	void forward_unit_number(size_t &current_unit_num) {
		current_unit_num = (current_unit_num + 1) % (Width / 2);
	}

	void print_inaccessible_section() {
		std::cout << inaccessible_place_shape;
	}

	void print_unit(const unit *u) {
		if (!u) {
			std::cout << empty_place_shape;
		} else {
			u->print();
		}
	}

	bool is_end_of_row(size_t index) {
		return (index + 1) % Width == 0;
	}
};

#endif //CHECKERS_SRC_BOARD_MANAGEMENT_HPP