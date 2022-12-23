#include "MonkeyStateMachine.h"
#include "PairOverlap.h"
#include <sstream>
#include <optional>
namespace Monkeys
{
	MonkeyState::MonkeyState(std::vector<int> items, Operation operation, int divisor): items(items), operation(operation), test_divisor(divisor)
	{

	}
	MonkeyState MonkeyState::parse(std::istream& inputStream)
	{
		std::vector<int> starting_items;
		std::string line="";
		while (line == "" && !inputStream.eof())
		{
			getline(inputStream, line);
		}

		std::optional<int> value = {};

		line = line.substr(sizeof("Monkey ") - 1);
		int monkeyNumber = std::stoi(line);

		getline(inputStream, line);
		line = line.substr(sizeof("  Starting items:")-1);
		auto parts = split(',', line);
		for (auto part : parts)
		{
			starting_items.push_back(std::stoi(part));
		}
		
		auto op = Operation::parse(inputStream);

		getline(inputStream, line);
		auto div = std::stoi(line.substr(line.find_last_of(' ')));


		getline(inputStream, line);
		auto true_monkey = std::stoi(line.substr(line.find_last_of(' ')));
		getline(inputStream, line);
		auto false_monkey= std::stoi(line.substr(line.find_last_of(' ')));


		return MonkeyState(starting_items, op, 0);
	}

	Operation Operation::parse(std::istream& inputStream)
	{
		std::string line;
		getline(inputStream, line);
		line = line.substr(line.find_first_of('=') + 2);
		std::stringstream str_stream(line);

		std::unique_ptr<Operand> left;
		std::unique_ptr<Operand> right;

		if (str_stream.peek() == 'o')
		{
			str_stream.seekg(3);
			left = std::make_unique<OldValue>(OldValue());
		}
		else
		{
			int value = 0;
			str_stream >> value;

			left = std::make_unique<LiteralValue>(LiteralValue(value));
		}

		// get operator
		char op;
		str_stream >> op;
		auto parsed_op = Op::div;
		switch (op)
		{
		case '/':
			parsed_op = Op::div;
			break;
		case '*':
			parsed_op = Op::mul;
			break;
		case '+':
			parsed_op = Op::add;
			break;
		case '-':
			parsed_op = Op::sub;
			break;
		default:
			throw std::invalid_argument("Must have a valid operator specified");
		}

		if (str_stream.peek() == 'o')
		{
			str_stream.seekg(3);
			left = std::make_unique<OldValue>(OldValue());
		}
		else
		{
			int value = 0;
			str_stream >> value;

			right = std::make_unique<LiteralValue>(LiteralValue(value));
		}
		return Operation(std::move(left), std::move(right), parsed_op);
		
	}

	Operation::Operation(std::unique_ptr<Operand> left, std::unique_ptr<Operand> right, Op op): left(std::move(left)), right(std::move(right)), op(op)
	{

	}

	Operation::Operation(const Operation& other) : left(other.left->clone()), right(other.right->clone()), op(other.op)
	{
	}

	std::unique_ptr<Operand> Operand::parse(std::string inputStr)
	{
		char next_char = inputStr[0];
		if (isdigit(next_char))
		{
			int number = std::stoi(inputStr);
			return std::make_unique<LiteralValue>(LiteralValue(number));
		}
		else
		{
			return std::make_unique<OldValue>(OldValue());
		}
	}
	std::unique_ptr<Operand> Operand::clone() const
	{ 
		return std::unique_ptr<Operand>(clone_impl());
	}
	int LiteralValue::getValue()
	{
		return value;
	}

	LiteralValue::LiteralValue(int value): value{value}
	{
		
	}

	int OldValue::getValue()
	{
		return 0;
	}
}