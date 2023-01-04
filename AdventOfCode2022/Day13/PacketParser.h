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
	NodeType getNodeType()
	{
		return NodeType::Number;
	}
	NumberNode(int num) :number(num)
	{

	}
	int number;
};

class ListNode : public NodeBase
{
public:
	std::vector<std::shared_ptr<NodeBase>> nodes;
	
	ListNode(std::vector<std::shared_ptr<NodeBase>> nodes) : nodes(std::move(nodes))
	{

	}

	/// <summary>
	/// Return -1 if this is less than other, 1 if it's greater, and 0 otherwise
	/// </summary>
	/// <param name="other"></param>
	/// <returns></returns>
	int cmp(ListNode& other)
	{
		int i = 0;
		while (i < nodes.size() && i < other.nodes.size())
		{
			if (nodes[i]->getNodeType() == NodeType::Number && other.nodes[i]->getNodeType() == NodeType::Number)
			{
				auto node1 = dynamic_cast<NumberNode*>(nodes[i].get());
				auto node2 = dynamic_cast<NumberNode*>(other.nodes[i].get());

				if (node1->number < node2->number)
				{
					return -1;
				}
				else if (node1->number > node2->number)
				{
					return 1;
				}
				i++;
				continue;
			}
			else if (nodes[i]->getNodeType() == NodeType::List && other.nodes[i]->getNodeType() == NodeType::List)
			{
				auto node1 = dynamic_cast<ListNode*>(nodes[i].get());
				auto node2 = dynamic_cast<ListNode*>(other.nodes[i].get());

				auto res = node1->cmp(*node2);
				auto res2 = node2->cmp(*node1);
				if (res<0)
				{
					return -1;
				}
				else if (res2<0)
				{
					return 1;
				}
				else
				{
					i++;
					continue;
				}
			}
			else
			{
				std::vector<std::shared_ptr<NodeBase>> newNodeList;
				if (nodes[i]->getNodeType() == NodeType::Number)
				{
					auto num = dynamic_cast<NumberNode*>(nodes[i].get())->number;
					newNodeList.push_back(std::make_shared<NumberNode>(NumberNode(num)));
					nodes[i] = std::make_shared<ListNode>(ListNode(newNodeList));
				}
				else
				{
					auto num = dynamic_cast<NumberNode*>(other.nodes[i].get())->number;
					newNodeList.push_back(std::make_shared<NumberNode>(NumberNode(num)));
					other.nodes[i]=std::make_shared<ListNode>(ListNode(newNodeList));

				}
			}
		}
		if (nodes.size() < other.nodes.size())
		{
			return -1;
		}
		else if(nodes.size() > other.nodes.size())
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	NodeType getNodeType()
	{
		return NodeType::List;
	}

	static std::shared_ptr<ListNode> parse(std::string input, int& pos)
	{
		if (input[pos] != '[')
		{
			throw std::exception("bad input");
		}
		pos++;
		std::vector<std::shared_ptr<NodeBase>> nodes;
		while (pos < input.length())
		{
			
			switch (input[pos])
			{
			case '[':
				nodes.push_back(parse(input, pos));
				break;
			case ']':
				pos++;
				return std::make_shared<ListNode>(ListNode(nodes));
			case ',':
				pos++;
				break;
			case ' ':
				pos++;
				break;
			default:
				int start = pos;
				int value = 0;
				while (isdigit(input[pos]) && pos < input.length())
				{
					value *= 10;
					value += input[pos] - '0';
					pos++;
				}
				nodes.push_back(std::make_shared<NumberNode>(NumberNode(value)));
				break;

			}
		}
	}
};

int getIndicesSum(std::istream& input)
{
	int index = 1;
	int total = 0;
	while (!input.eof())
	{
		std::string line1, line2;
		getline(input, line1);
		getline(input, line2);

		int pos = 0;

		auto res1 = ListNode::parse(line1, pos);
		pos = 0;
		auto res2 = ListNode::parse(line2, pos);
		auto result = res1->cmp(*res2);

		if (result<0)
		{
			total += index;
		}
		index++;

		// throw away blank line
		getline(input, line1);
	}
	return total;
}



int findDecoderKey(std::istream& input)
{
	int index = 1;
	int total = 0;
	std::vector<std::shared_ptr<ListNode>> nodes;
	while (!input.eof())
	{
		std::string line;
		getline(input, line);
		if (line == "")
		{
			continue;
		}
		int pos = 0;

		auto res1 = ListNode::parse(line, pos);
		bool inserted = false;
		int cnt = 0;
		for (auto i = 0; i < nodes.size(); i++)
		{
			auto val = nodes[cnt];
			auto comp = (res1)->cmp(*(val));
			if (comp<0)
			{
				nodes.insert(nodes.begin()+i, res1);
				inserted = true;
				break;
			}
			cnt++;
		}
		if (!inserted)
		{
			nodes.push_back(res1);
		}
	}

	int pos = 0;
	auto divider1 = ListNode::parse("[[2]]", pos);
	pos = 0;
	auto divider2 = ListNode::parse("[[6]]", pos);

	int d1 = 0, d2 = 0, cnt = 1;

	for (auto i = 0; i < nodes.size(); i++)
	{
		auto comp = (divider1)->cmp(*( nodes[i]));
		if (comp<0 && d1 == 0)
		{
			nodes.insert(nodes.begin() + i, divider1);
			d1 = cnt;
		}
		comp = (divider2)->cmp(*(nodes[i]));
		if (comp<0 && d2 == 0)
		{
			nodes.insert(nodes.begin() + i, divider1);
			d2 = cnt;
		}
		cnt++;

	}

	return d1*d2;
}