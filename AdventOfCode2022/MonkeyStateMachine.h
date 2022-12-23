#include <string>
#include <istream>
#include <vector>

namespace Monkeys
{
	typedef enum
	{
		div,
		mul,
		add,
		sub
	} Op;

	struct Operand
	{
		static std::unique_ptr<Operand> parse(std::string inputStr);
		virtual int getValue() = 0;    
		std::unique_ptr<Operand> clone() const;
	protected:
		virtual Operand* clone_impl() const = 0;
	};

	struct OldValue : public Operand
	{
		virtual int getValue() override;
	protected:
		virtual OldValue* clone_impl() const override { return new OldValue(*this); };
	};

	struct LiteralValue : public Operand
	{
		int value;
		LiteralValue(int value);
		virtual int getValue() override;

	protected:
		virtual LiteralValue* clone_impl() const override { return new LiteralValue(*this); };
	};


	struct Operation
	{
		std::unique_ptr<Operand> left;
		std::unique_ptr<Operand>  right;
		Op op;

		Operation(std::unique_ptr<Operand> left, std::unique_ptr<Operand> right, Op op);

		Operation(const Operation& other);

		static Operation parse(std::istream& inputStream);
	};

	struct MonkeyState
	{
		std::vector<int> items;
		Operation operation;
		int test_divisor;

		MonkeyState(std::vector<int> items, Operation operation, int divisor);

		static MonkeyState parse(std::istream& inputStream);
	};
}