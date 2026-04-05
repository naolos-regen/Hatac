#ifndef HATAC_BOARD
# define HATAC_BOARD

#include <vector>
#include "Playable.hpp"

namespace Hatac
{
	class Playable;

	/**
	 * @brief Easily said there is no real grid, instead Board only works with who placed what where and when.
	 * @brief BoardLogic handles the evaluation.
	 **/
	class Board
	{
		std::vector<Playable> moves{};
	public:
		Board();
		~Board();
	};

};

#endif
