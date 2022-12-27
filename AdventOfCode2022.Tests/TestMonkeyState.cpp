#include "pch.h"
#include "gtest/gtest.h"
#include <fstream>
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
	EXPECT_EQ(false, monkey.operation.left.has_value());
	EXPECT_EQ(17, monkey.operation.right);
	EXPECT_EQ(4, monkey.true_monkey);
	EXPECT_EQ(2, monkey.false_monkey);
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
	EXPECT_EQ(false, monkey.operation.left.has_value());
	EXPECT_EQ(false, monkey.operation.right.has_value());
	EXPECT_EQ(5, monkey.test_divisor);
	EXPECT_EQ(3, monkey.true_monkey);
	EXPECT_EQ(5, monkey.false_monkey);
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
	EXPECT_EQ(false, monkey1.operation.left.has_value());
	EXPECT_EQ(false, monkey1.operation.right.has_value());
	EXPECT_EQ(13, monkey1.test_divisor);

	EXPECT_EQ(3, monkey2.items.size());
	EXPECT_EQ(Monkeys::Op::add, monkey2.operation.op);
	EXPECT_EQ(false, monkey2.operation.left.has_value());
	EXPECT_EQ(7, monkey2.operation.right);
	EXPECT_EQ(11, monkey2.test_divisor);
}


TEST(MonkeyKeepAway, calculate_monkey_business) {
	// arrange
	std::string monkey_str = "Monkey 0:"
"\n  Starting items: 79, 98"
"\n  Operation: new = old * 19"
"\n  Test: divisible by 23"
"\n    If true: throw to monkey 2"
"\n    If false: throw to monkey 3"
"\n"
"\nMonkey 1:"
"\n  Starting items: 54, 65, 75, 74"
"\n  Operation: new = old + 6"
"\n  Test: divisible by 19"
"\n    If true: throw to monkey 2"
"\n    If false: throw to monkey 0"
"\n"
"\nMonkey 2:"
"\n  Starting items: 79, 60, 97"
"\n  Operation: new = old * old"
"\n  Test: divisible by 13"
"\n    If true: throw to monkey 1"
"\n    If false: throw to monkey 3"
"\n"
"\nMonkey 3:"
"\n  Starting items: 74"
"\n  Operation: new = old + 3"
"\n  Test: divisible by 17"
"\n    If true: throw to monkey 0"
"\n    If false: throw to monkey 1\n";
	std::stringstream strStream(monkey_str);

	Monkeys::MonkeyKeepAway monkeyKeepAway(strStream);

	// act
	auto monkey_business = monkeyKeepAway.calculate_monkey_business(20, 3);

	// assert
	EXPECT_EQ(10605, monkey_business);
}

TEST(MonkeyKeepAway, calculate_monkey_business_10000_rounds) {
	// arrange
	std::string monkey_str = "Monkey 0:"
		"\n  Starting items: 79, 98"
		"\n  Operation: new = old * 19"
		"\n  Test: divisible by 23"
		"\n    If true: throw to monkey 2"
		"\n    If false: throw to monkey 3"
		"\n"
		"\nMonkey 1:"
		"\n  Starting items: 54, 65, 75, 74"
		"\n  Operation: new = old + 6"
		"\n  Test: divisible by 19"
		"\n    If true: throw to monkey 2"
		"\n    If false: throw to monkey 0"
		"\n"
		"\nMonkey 2:"
		"\n  Starting items: 79, 60, 97"
		"\n  Operation: new = old * old"
		"\n  Test: divisible by 13"
		"\n    If true: throw to monkey 1"
		"\n    If false: throw to monkey 3"
		"\n"
		"\nMonkey 3:"
		"\n  Starting items: 74"
		"\n  Operation: new = old + 3"
		"\n  Test: divisible by 17"
		"\n    If true: throw to monkey 0"
		"\n    If false: throw to monkey 1\n";
	std::stringstream strStream(monkey_str);

	Monkeys::MonkeyKeepAway monkeyKeepAway(strStream);

	// act
	auto monkey_business = monkeyKeepAway.calculate_monkey_business(10000, std::nullopt);

	// assert
	EXPECT_EQ(2713310158, monkey_business);
}

TEST(MonkeyKeepAway, calculate_monkey_business_8monkeys) {
	// arrange
	std::string filePath("C:\\Users\\emin\\source\\repos\\AdventOfCode2022\\input11.txt");

	std::ifstream inputStream(filePath);

	Monkeys::MonkeyKeepAway monkeyKeepAway(inputStream);

	// act
	auto monkey_business = monkeyKeepAway.calculate_monkey_business(20, 3);

	// assert
	EXPECT_EQ(120384, monkey_business);
}
