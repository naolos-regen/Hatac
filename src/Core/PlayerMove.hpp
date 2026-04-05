#ifndef HATAC_PLAYER_MOVE
# define HATAC_PLAYER_MOVE
#include <cstdint>
#include <memory>

#include "DataStructures.hpp"
#include "Playable.hpp"

namespace Hatac
{
	class PlayerMove final : public Playable
	{
		Move<int32_t> move;

		explicit PlayerMove(const uint8_t id, const Move<int32_t> move)
			: Playable(id)
			, move(move)
		{};

		explicit PlayerMove(const uint8_t id, const int32_t x, const int32_t y)
			: Playable(id)
			, move(x, y)
		{};

	public:
		PlayerMove() = delete;
		~PlayerMove() override = default;

		_HATAC_MOVE_TEMPLATE
		static std::unique_ptr<PlayerMove> create(const Move<T> move)
		{
			static uint8_t nextId = 0;
			std::unique_ptr<PlayerMove> instance = std::make_unique<PlayerMove>(nextId++, move);
			instance->append(move);
			return instance;
		}
	};
}

#endif
