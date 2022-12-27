#include <string>
#include <istream>
#include <vector>
#include <optional>

namespace Monkeys
{
	typedef enum
	{
		div,
		mul,
		add,
		sub
	} Op;



	struct Operation
	{
		std::optional<long> left;
		std::optional<long>  right;
		Op op;

		Operation(std::optional<long long> left, std::optional<long long> right, Op op);


		static Operation parse(std::istream& inputStream);
	};

	struct MonkeyState
	{
		std::vector<long long> items;
		Operation operation;
		int test_divisor;

		int true_monkey;
		int false_monkey;

		MonkeyState(std::vector<long long> items, Operation operation, int divisor, int true_monkey, int false_monkey);

		static MonkeyState parse(std::istream& inputStream);
	};

	class MonkeyKeepAway
	{
		std::vector<MonkeyState> states;
	public:
		MonkeyKeepAway(std::istream& input);
		long long calculate_monkey_business(int round_count, std::optional<long long> divisor);
	};
}