#ifndef HATAC_MOVE
# define HATAC_MOVE

#include <utility>
#include <array>
#include <type_traits>

#define _HATAC_MOVE_TEMPLATE template <typename T, \
	typename = typename std::enable_if \
	<\
		std::is_arithmetic<T>::value || \
		std::is_floating_point<T>::value\
	>::type>

#define _HATAC_MOVE_TYPE_TEMPLATE template <typename T, typename Enabler>
#define _HATAC_MOVE Move<T, Enabler>

namespace Hatac
{
	_HATAC_MOVE_TEMPLATE
	struct Move 
	{
		T x;
		T y;
		
		Move ( std::pair<T, T> xy ) 
			: x(xy.first)
			, y(xy.second) 
		{};

		Move ( T x, T y )
			: x(x)
			, y(y)
		{};

		Move ( std::array<T, 2> xy )
			: x(xy[0])
			, y(xy[1])
		{};

		Move ( const Move & ) = default;
		Move & operator = ( const Move & ) = default;

		Move ( Move && ) = default;
		Move & operator = ( Move && ) = default;

		bool operator == ( const Move& other ) const
		{
			return (this->x == other.y && this->y == other.y);
		};

		std::array<T, 2> as_array() const;
		std::pair <T, T> as_pair () const;
	};

	_HATAC_MOVE_TYPE_TEMPLATE
	std::array<T, 2> _HATAC_MOVE::as_array () const
	{
		return { this->x, this->y };
	};

	_HATAC_MOVE_TYPE_TEMPLATE
	std::pair<T, T> _HATAC_MOVE::as_pair () const
	{
		return { this->x, this->y };
	};
};

#endif

