#pragma once
#include <string>
#include <istream>
#include <vector>
#include <memory>
#include <optional>

enum NodeType
{
	Number,
	List
};

class NodeBase
{
public:
	std::shared_ptr<NodeBase> next;
	virtual NodeType getNodeType()=0;
};

class NumberNode :public NodeBase
{
public:
	NodeType getNodeType();
	NumberNode(int num);
	int number;
};

class ListNode : public NodeBase
{
public:
	std::vector<std::shared_ptr<NodeBase>> nodes;
	
	ListNode(std::vector<std::shared_ptr<NodeBase>> nodes);

	/// <summary>
	/// Return -1 if this is less than other, 1 if it's greater, and 0 otherwise
	/// </summary>
	/// <param name="other"></param>
	/// <returns></returns>
	int cmp(ListNode& other);

	NodeType getNodeType();

	static std::shared_ptr<ListNode> parse(std::string input, int& pos);
};

int getIndicesSum(std::istream& input);



int findDecoderKey(std::istream& input);