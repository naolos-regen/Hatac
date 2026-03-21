#include "../src/Core/DataStructures.hxx"
#include <criterion/criterion.h>

using namespace Hatac;

Test (move_eq_pair_t, assertion, .description = "comparison of move == pair")
{
	const auto & move = Move<int>(1, 1);
	const auto & pair = std::pair<int, int>(1, 1);

	cr_assert_eq(move.as_pair(), pair);
}

Test (move_eq_array_t, assertion, .description = "comparison of move == array")
{
	const auto & move = Move<uint32_t>(42, 42);
	const auto & array = std::array<uint32_t, 2>({42, 42});

	cr_assert_eq(move.as_array(), array);
}

Test (move_eq_move_t, assertion, .description = "comparison of move == move")
{
	const auto & move1 =  Move<float>(42, 42);
	const auto & move2 = Move<float>(42, 42);

	cr_assert_eq(move1, move2);
}

Test (move_create_from_pair_t, assertion, .description = "create move from a pair")
{
	std::pair<float, float> basic = { 42, 3 };

	const auto & move = Move<float>(basic);

	cr_assert_eq(basic.first, move.x);
	cr_assert_eq(basic.second, move.y);
}

Test (move_create_from_array_t, assertion, .description = "create move from an array")
{
	std::array<uint_fast64_t, 2> basic = { static_cast<uint_fast64_t>(-1), 1 };

	const auto & move = Move<uint_fast64_t>(basic);

	cr_assert_eq(basic[0], move.x);
	cr_assert_eq(basic[1], move.y);
}


Test (move_add_or_sub_move, addition_and_subtraction, .description = "just adding and subtracting")
{
	Move<int>  val1 {1, 2};
	Move<long>  val2 { 4, 32};
	
	auto val4 = val2 - val1;
	auto val3 = val2 + val1;
	

	cr_assert_eq(Move<long>(5, 34), val3);
	cr_assert_eq(Move<long>(3, 30), val4);

	val2 += val1;
	cr_assert_eq(val3, val2);

	val1 -= val2;
	cr_assert_eq(Move<int>( -4, -32), val1);
}

