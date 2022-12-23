#include "pch.h"
#include "gtest/gtest.h"
#include "../AdventOfCode2022/MonkeyStateMachine.h"

TEST(MonkeyState, ParsesMonkeyCorrectly) {
	// arrange
	std::string monkey_str = "Monkey 0:"
		"\n  Starting items: 99, 67, 92, 61, 83, 64, 98"
		"\n  Operation: new = old * 17"
		"\n  Test: divisible by 3"
		"\n    If true: throw to monkey 4"
		"\n    If false: throw to monkey 2";
	std::stringstream strStream(monkey_str);

	// act
	auto monkey = Monkeys::MonkeyState::parse(strStream);

	// assert
	EXPECT_EQ(7, monkey.items.size());
	EXPECT_EQ(Monkeys::Op::mul, monkey.operation.op);
	EXPECT_EQ(0, monkey.operation.left->getValue());
	EXPECT_EQ(17, monkey.operation.right->getValue());
}

TEST(MonkeyState, ParsesAddMonkeyCorrectly) {
	// arrange
	std::string monkey_str = "Monkey 1:"
"\n  Starting items: 78, 74, 88, 89, 50"
"\n  Operation: new = old + old"
"\n  Test: divisible by 5"
"\n    If true: throw to monkey 3"
"\n    If false: throw to monkey 5";
	std::stringstream strStream(monkey_str);

	// act
	auto monkey = Monkeys::MonkeyState::parse(strStream);

	// assert
	EXPECT_EQ(5, monkey.items.size());
	EXPECT_EQ(Monkeys::Op::add, monkey.operation.op);
	EXPECT_EQ(0, monkey.operation.left->getValue());
	EXPECT_EQ(0, monkey.operation.right->getValue());
}


TEST(MonkeyState, ParsesTwoMonkeysCorrectly) {
	// arrange
	std::string monkey_str = "\n"
"\nMonkey 3:"
"\n  Starting items: 59, 72, 94, 91, 79, 88, 94, 51"
"\n  Operation: new = old * old"
"\n  Test: divisible by 13"
"\n    If true: throw to monkey 0"
"\n    If false: throw to monkey 5"
"\n"
"\nMonkey 4:"
"\n  Starting items: 95, 72, 78"
"\n  Operation: new = old + 7"
"\n  Test: divisible by 11"
"\n    If true: throw to monkey 7"
"\n    If false: throw to monkey 6";
	std::stringstream strStream(monkey_str);

	// act
	auto monkey1 = Monkeys::MonkeyState::parse(strStream);
	auto monkey2 = Monkeys::MonkeyState::parse(strStream);

	// assert
	EXPECT_EQ(8, monkey1.items.size());
	EXPECT_EQ(Monkeys::Op::mul, monkey1.operation.op);
	EXPECT_EQ(0, monkey1.operation.left->getValue());
	EXPECT_EQ(0, monkey1.operation.right->getValue());

	EXPECT_EQ(3, monkey2.items.size());
	EXPECT_EQ(Monkeys::Op::add, monkey2.operation.op);
	EXPECT_EQ(0, monkey2.operation.left->getValue());
	EXPECT_EQ(7, monkey2.operation.right->getValue());
}
