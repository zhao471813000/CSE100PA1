#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <vector>

#include <gtest/gtest.h>
#include "BSTNode.hpp"

using namespace std;
using namespace testing;

TEST(BST_NODE_TESTS, TEST_SUCCESSOR) {
    BSTNode<int> node(3);
    ASSERT_EQ(node.successor(), nullptr);
}

TEST(BST_NODE_TESTS, TEST_SUCCESSOR_CASE1) {
    BSTNode<int> node0(3);
    BSTNode<int> node1(0);
    BSTNode<int> node2(-1);
    BSTNode<int> node3(1);
    BSTNode<int> node4(2);
    BSTNode<int> node5(6);
    BSTNode<int> node6(5);
    BSTNode<int> node7(7);
    BSTNode<int> node8(4);

    node0.left = &node1;
    node1.left = &node2;
    node5.left = &node6;
    node6.left = &node8;

    node0.right = &node5;
    node1.right = &node3;
    node3.right = &node4;
    node5.right = &node7;

    node1.parent = &node0;
    node2.parent = &node1;
    node3.parent = &node1;
    node4.parent = &node3;
    node5.parent = &node0;
    node6.parent = &node5;
    node7.parent = &node5;
    node8.parent = &node6;

    ASSERT_EQ(node0.successor(), &node8);
    ASSERT_EQ(node4.successor(), &node0);
    ASSERT_EQ(node7.successor(), nullptr);
}