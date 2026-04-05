#ifndef HATAC_PLAYABLE
# define HATAC_PLAYABLE
#include <cstdint>
#include <vector>

#include "DataStructures.hpp"

namespace Hatac
{
	class Playable
	{
	protected:
		uint8_t id;
		std::vector<Move<int32_t>> moves;

		explicit Playable(const uint8_t id) : id(id) {};
	public:
		virtual ~Playable() = default;

		_HATAC_MOVE_TEMPLATE
		auto append(Move<T> && move) -> void
		{
			this->moves.emplace_back(std::forward<Move<T>>(move));
		};

		auto getId() const -> uint8_t { return this->id; };
	};
}

#endif
