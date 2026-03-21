#ifndef HATAC_MOVE
# define HATAC_MOVE

#include <cstddef>
#include <utility>
#include <array>

namespace Hatac
{
	struct Move 
	{
		std::size_t x;
		std::size_t y;
		
		Move ( std::pair<size_t, size_t> xy ) 
			: x(xy.first)
			, y(xy.second) 
		{};

		Move ( std::size_t x, std::size_t y )
			: x(x)
			, y(y)
		{};

		Move ( std::array<std::size_t, 2> xy )
			: x(xy[0])
			, y(xy[1])
		{};

		Move ( const Move & ) = default;
		Move & operator = ( const Move & ) = default;

		Move ( Move && ) = default;
		Move & operator = ( Move && ) = default;

		bool operator == ( const Move& other ) const;

		std::array<std::size_t, 2>		as_array() const;
		std::pair<std::size_t, std::size_t>	as_pair () const;
		

	};
};

#endif

