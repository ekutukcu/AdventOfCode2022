#include "MonkeyStateMachine.h"
#include "PairOverlap.h"
#include <sstream>
#include <optional>
namespace Monkeys
{
	MonkeyState::MonkeyState(std::vector<long long> items, Operation operation, int divisor, int true_monkey, int false_monkey): items(items), operation(operation), test_divisor(divisor), true_monkey(true_monkey), false_monkey(false_monkey)
	{

	}
	MonkeyState MonkeyState::parse(std::istream& inputStream)
	{
		std::vector<long long> starting_items;
		std::string line="";
		while (line == "" && !inputStream.eof())
		{
			getline(inputStream, line);
		}

		std::optional<long> value = {};

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


		return MonkeyState(starting_items, op, div, true_monkey, false_monkey);
	}

	Operation Operation::parse(std::istream& inputStream)
	{
		std::string line;
		getline(inputStream, line);
		line = line.substr(line.find_first_of('=') + 2);
		std::stringstream str_stream(line);

		std::optional<long> left;
		std::optional<long> right;

		if (str_stream.peek() == 'o')
		{
			str_stream.seekg(3);
			left = {};
		}
		else
		{
			int value = 0;
			str_stream >> value;

			left = value;
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
		char b = str_stream.peek();
		str_stream.seekg(1, std::ios::cur);
		char c = str_stream.peek();
		if (str_stream.peek() == 'o')
		{
			str_stream.seekg(3);
			right = {};
		}
		else
		{
			int value = 0;
			str_stream >> value;

			right = value;
		}

		return Operation(left, right, parsed_op);
		
	}

	Operation::Operation(std::optional<long long> left, std::optional<long long> right, Op op): left(left), right(right), op(op)
	{

	}

	MonkeyKeepAway::MonkeyKeepAway(std::istream& input)
	{
		while (!input.eof() && input.peek()!=-1)
		{
			auto ch = input.peek();
			auto monkey = MonkeyState::parse(input);
			states.push_back(monkey);
		}
	}
	long long MonkeyKeepAway::calculate_monkey_business(int round_count, std::optional<long long> divisor)
	{
		std::vector<long> monkey_business;
		long long div = 1;

		for (int j = 0; j < states.size(); j++)
		{
			monkey_business.push_back(0);
			div *= states[j].test_divisor;
		}

		for (int i = 0; i < round_count; i++)
		{
			for (int j = 0; j < states.size(); j++)
			{
				MonkeyState& current_state = states[j];
				for (int k = 0; k < current_state.items.size(); k++)
				{
					long long new_value;
					long long left, right;
					// get left
					if (current_state.operation.left.has_value())
					{
						left = current_state.operation.left.value();
					}
					else
					{
						left = current_state.items[k];
					}

					// get right
					if (current_state.operation.right.has_value())
					{
						right = current_state.operation.right.value();
					}
					else
					{
						right = current_state.items[k];
					}

					switch (current_state.operation.op)
					{
					case Op::add:
						new_value = left + right;
						break;
					case Op::mul:
						new_value = left * right;
						break;
					case Op::div:
						new_value = left / right;
						break;
					case Op::sub:
						new_value = left - right;
						break;

					default:
						throw std::exception();
					}

					//auto div = 9699690;///(current_state.test_divisor);// / current_state.test_divisor;
					if (divisor.has_value())
					{
						new_value /= divisor.value();
					}
					else
					{
						new_value %= div;// divisor;// %= 9699691;
					}
					if (new_value % current_state.test_divisor == 0)
					{
						//new_value %= current_state.test_divisor;
						states[current_state.true_monkey].items.push_back(new_value);
					}
					else
					{
						//new_value %= current_state.test_divisor;

						states[current_state.false_monkey].items.push_back(new_value);
					}
					

					monkey_business[j]++;
				}

				current_state.items.clear();
			}
		}

		long long max1=0, max2=0;
		for (const int& m: monkey_business)
		{
			if (m >= max1)
			{
				max2 = max1;
				max1 = m;
			}
			else if (m >= max2)
			{
				max2 = m;
			}
		}
		return max1*max2;
	}
}