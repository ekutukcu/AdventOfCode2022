#include "pch.h"
#include "gtest/gtest.h"
#include "../AdventOfCode2022/Day13/PacketParser.h"

#include <fstream>
TEST(NodeBase, getIndicesSumFile) {
	// arrange
	std::string filePath("C:\\Users\\emin\\source\\repos\\AdventOfCode2022\\AdventOfCode2022Runner\\Data\\input13.txt");

	std::ifstream inputStream(filePath);

	// act
	auto indices_sum = getIndicesSum(inputStream);

	// assert
	EXPECT_EQ(5580, indices_sum);
}
TEST(NodeBase, findDecoderKey) {
	// arrange
	std::string input = "\n[1,1,3,1,1]"
"\n[1,1,5,1,1]"
"\n"
"\n[[1],[2,3,4]]"
"\n[[1],4]"
"\n"
"\n[9]"
"\n[[8,7,6]]"
"\n"
"\n[[4,4],4,4]"
"\n[[4,4],4,4,4]"
"\n"
"\n[7,7,7,7]"
"\n[7,7,7]"
"\n"
"\n[]"
"\n[3]"
"\n"
"\n[[[]]]"
"\n[[]]"
"\n"
"\n[1,[2,[3,[4,[5,6,7]]]],8,9]"
"\n[1,[2,[3,[4,[5,6,0]]]],8,9]";//8;";

	std::stringstream inputStream(input);

	// act
	auto indices_sum = findDecoderKey(inputStream);

	// assert
	EXPECT_EQ(140, indices_sum);
}

TEST(NodeBase, check_syntax_lists_of_same_length) {
	// arrange

	std::string line1 = "[1,1,3,1,1]\n";
	std::string line2 = "[1,1,5,1,1]\n";

	// act
	int pos = 0;

	auto res1 = ListNode::parse(line1, pos);
	pos = 0;
	auto res2 = ListNode::parse(line2, pos);
	auto result = res1->cmp(*res2);

	// assert
	EXPECT_EQ(true, (result < 0));
}

TEST(NodeBase, check_syntax_nested_lists) {
	// arrange

	std::string line1 = "[[1],[2,3,4]]";
	std::string line2= "[[1],4]";
	// act
	int pos = 0;

	auto res1 = ListNode::parse(line1, pos);
	pos = 0;
	auto res2 = ListNode::parse(line2, pos);
	auto result = res1->cmp(*res2);

	// assert
	EXPECT_EQ(true, (result < 0));
}

TEST(NodeBase, check_syntax_list_vs_int) {
	// arrange

	std::string line1 = "[9]";
	std::string line2=	"[[8,7,6]]\n";

	// act
	int pos = 0;

	auto res1 = ListNode::parse(line1, pos);
	pos = 0;
	auto res2 = ListNode::parse(line2, pos);
	auto result = res1->cmp(*res2);

	// assert
	EXPECT_EQ(false, (result < 0));
}


TEST(NodeBase, check_syntax_nested_list_different_length) {
	// arrange

	std::string line1 = "[[4,4],4,4]";
	std::string line2 = "[[4,4],4,4,4]";

	// act
	int pos = 0;

	auto res1 = ListNode::parse(line1, pos);
	pos = 0;
	auto res2 = ListNode::parse(line2, pos);
	auto result = res1->cmp(*res2);

	// assert
	EXPECT_EQ(true, (result < 0));
}


TEST(NodeBase, check_syntax_list_different_length) {
	// arrange

	std::string line1 = "[7,7,7,7]";
	std::string line2 = "[7,7,7]";

	// act
	int pos = 0;

	auto res1 = ListNode::parse(line1, pos);
	pos = 0;
	auto res2 = ListNode::parse(line2, pos);
	auto result = res1->cmp(*res2);

	// assert
	EXPECT_EQ(false, (result < 0));
}


TEST(NodeBase, check_syntax_empty_list) {
	// arrange

	std::string line1 = "[]";
	std::string line2 = "[3]";

	// act
	int pos = 0;

	auto res1 = ListNode::parse(line1, pos);
	pos = 0;
	auto res2 = ListNode::parse(line2, pos);
	auto result = res1->cmp(*res2);

	// assert
	EXPECT_EQ(true, (result < 0));
}


TEST(NodeBase, check_syntax_many_level_nested_empty_list) {
	// arrange

	std::string line1 = "[[[]]]\n";
	std::string line2 = "[[]]\n";

	// act
	int pos = 0;

	auto res1 = ListNode::parse(line1, pos);
	pos = 0;
	auto res2 = ListNode::parse(line2, pos);
	auto result = res1->cmp(*res2);

	// assert
	EXPECT_EQ(false, (result<0));
}


TEST(NodeBase, check_syntax_many_level_nested_list) {
	// arrange

	std::string line1 = "[1,[2,[3,[4,[5,6,7]]]],8,9]\n";
	std::string line2 = "[1,[2,[3,[4,[5,6,0]]]],8,9]\n";


	// act
	int pos = 0;

	auto res1 = ListNode::parse(line1, pos);
	pos = 0;
	auto res2 = ListNode::parse(line2, pos);
	auto result = res1->cmp(*res2);

	// assert
	EXPECT_EQ(false, (result < 0));
}

TEST(NodeBase, check_syntax_many_level_nested_list_reversed) {
	// arrange

	std::string line1 = "[1,[2,[3,[4,[5,6,7]]]],8,9]\n";
	std::string line2 = "[1,[2,[3,[4,[5,6,0]]]],8,9]\n";


	// act
	int pos = 0;

	auto res1 = ListNode::parse(line1, pos);
	pos = 0;
	auto res2 = ListNode::parse(line2, pos);
	auto result = res1->cmp(*res2);

	// assert
	EXPECT_EQ(false, (result<0));
}


TEST(NodeBase, parse) {
	// arrange

	std::string line = "[1,8,9]\n";
	int pos = 0;


	// act
	auto res = ListNode::parse(line, pos);

	// assert
	EXPECT_EQ(3, res->nodes.size());
	EXPECT_EQ(NodeType::Number, res->nodes[0]->getNodeType());
	EXPECT_EQ(NodeType::Number, res->nodes[1]->getNodeType());
	EXPECT_EQ(NodeType::Number, res->nodes[2]->getNodeType());

}

TEST(NodeBase, parse_list_node) {
	// arrange

	std::string line = "[[1],[8],[9]]\n";
	int pos = 0;


	// act
	auto res = ListNode::parse(line, pos);

	// assert
	EXPECT_EQ(3, res->nodes.size());
	EXPECT_EQ(NodeType::List, res->nodes[0]->getNodeType());
	EXPECT_EQ(NodeType::List, res->nodes[1]->getNodeType());
	EXPECT_EQ(NodeType::List, res->nodes[2]->getNodeType());

	auto listNode = dynamic_cast<ListNode*>(res->nodes[0].get());
	EXPECT_EQ(1, listNode->nodes.size());
	EXPECT_EQ(NodeType::Number, listNode->nodes[0]->getNodeType());
	EXPECT_EQ(1, dynamic_cast<NumberNode*>(listNode->nodes[0].get())->number);


	listNode = dynamic_cast<ListNode*>(res->nodes[1].get());
	EXPECT_EQ(1, listNode->nodes.size());
	EXPECT_EQ(NodeType::Number, listNode->nodes[0]->getNodeType());
	EXPECT_EQ(8, dynamic_cast<NumberNode*>(listNode->nodes[0].get())->number);


	listNode = dynamic_cast<ListNode*>(res->nodes[2].get());
	EXPECT_EQ(1, listNode->nodes.size());
	EXPECT_EQ(NodeType::Number, listNode->nodes[0]->getNodeType());
	EXPECT_EQ(9, dynamic_cast<NumberNode*>(listNode->nodes[0].get())->number);

}


TEST(NodeBase, parse_list_node2) {
	// arrange

	std::string line = "[[1,2,3],[8],[9,4]]\n";
	int pos = 0;


	// act
	auto res = ListNode::parse(line, pos);

	// assert
	EXPECT_EQ(3, res->nodes.size());
	EXPECT_EQ(NodeType::List, res->nodes[0]->getNodeType());
	EXPECT_EQ(NodeType::List, res->nodes[1]->getNodeType());
	EXPECT_EQ(NodeType::List, res->nodes[2]->getNodeType());

	auto listNode = dynamic_cast<ListNode*>(res->nodes[0].get());
	EXPECT_EQ(3, listNode->nodes.size());
	EXPECT_EQ(NodeType::Number, listNode->nodes[0]->getNodeType());
	EXPECT_EQ(1, dynamic_cast<NumberNode*>(listNode->nodes[0].get())->number);


	listNode = dynamic_cast<ListNode*>(res->nodes[1].get());
	EXPECT_EQ(1, listNode->nodes.size());
	EXPECT_EQ(NodeType::Number, listNode->nodes[0]->getNodeType());
	EXPECT_EQ(8, dynamic_cast<NumberNode*>(listNode->nodes[0].get())->number);


	listNode = dynamic_cast<ListNode*>(res->nodes[2].get());
	EXPECT_EQ(2, listNode->nodes.size());
	EXPECT_EQ(NodeType::Number, listNode->nodes[0]->getNodeType());
	EXPECT_EQ(9, dynamic_cast<NumberNode*>(listNode->nodes[0].get())->number);

}

TEST(NodeBase, parse_list_node3) {
	// arrange

	std::string line = "[[1,2,3,[]],[8],[9,4]]\n";
	int pos = 0;


	// act
	auto res = ListNode::parse(line, pos);

	// assert
	EXPECT_EQ(3, res->nodes.size());
	EXPECT_EQ(NodeType::List, res->nodes[0]->getNodeType());
	EXPECT_EQ(NodeType::List, res->nodes[1]->getNodeType());
	EXPECT_EQ(NodeType::List, res->nodes[2]->getNodeType());

	auto listNode = dynamic_cast<ListNode*>(res->nodes[0].get());
	EXPECT_EQ(4, listNode->nodes.size());
	EXPECT_EQ(NodeType::List, listNode->nodes[3]->getNodeType());
	EXPECT_EQ(0, dynamic_cast<ListNode*>(listNode->nodes[3].get())->nodes.size());


	listNode = dynamic_cast<ListNode*>(res->nodes[1].get());
	EXPECT_EQ(1, listNode->nodes.size());
	EXPECT_EQ(NodeType::Number, listNode->nodes[0]->getNodeType());
	EXPECT_EQ(8, dynamic_cast<NumberNode*>(listNode->nodes[0].get())->number);


	listNode = dynamic_cast<ListNode*>(res->nodes[2].get());
	EXPECT_EQ(2, listNode->nodes.size());
	EXPECT_EQ(NodeType::Number, listNode->nodes[0]->getNodeType());
	EXPECT_EQ(9, dynamic_cast<NumberNode*>(listNode->nodes[0].get())->number);

}

TEST(NodeBase, getIndicesSum) {
	// arrange

	std::string input = "[1,1,3,1,1]"
		"\n[1,1,5,1,1]"//1
		"\n"
		"\n[[1],[2,3,4]]"
		"\n[[1],4]"//2
		"\n"
		"\n[9]"
		"\n[[8,7,6]]"//3
		"\n"
		"\n[[8,7,6]]"
		"\n[9]"//4
		"\n"
		"\n[[4,4],4,4]"
		"\n[[4,4],4,4,4]"//5
		"\n"
		"\n[7,7,7,7]"
		"\n[7,7,7]"//6
		"\n"
		"\n[]"
		"\n[3]"//7
		"\n"
		"\n[[[]]]"
		"\n[[]]"//8
		"\n"
		"\n[[]]"
		"\n[[[]]]"//9
		"\n"
		"\n[1,[2,[3,[4,[5,6,7]]]],8,9]"
		"\n[1,[2,[3,[4,[5,6,0]]]],8,9]"//10
		"\n"
		"\n[[],2]"
		"\n[[]]";//8;

	std::stringstream inputStream(input);


	// act
	auto res = getIndicesSum(inputStream);

	// assert
	EXPECT_EQ(28, res);

}


TEST(NodeBase, getIndicesSum2) {
	// arrange

	std::string input = "[[],2]"
		"\n[[]]";//8;

	std::stringstream inputStream(input);


	// act
	auto res = getIndicesSum(inputStream);

	// assert
	EXPECT_EQ(0, res);

}