#include "DataStructures/Graph.h"

#include <gtest/gtest.h>

using namespace std;
class GraphSingleThreadedTest : public ::testing::Test
{
protected:
    // void SetUp() override {}

    // void TearDown() override {}
    DirectionalGraph<int> testGraph_{};
};

TEST_F(GraphSingleThreadedTest, When_DefaultConstruction_Then_EmptyListOfNodes)
{
    EXPECT_TRUE(testGraph_.getAllNodesInGraph().empty());
}

TEST_F(GraphSingleThreadedTest, When_InsertOneNode_Then_NodeSizeIs1)
{
    int newNode{1};
    EXPECT_TRUE(testGraph_.addNodeToGraph(newNode));
    EXPECT_EQ(1, testGraph_.getAllNodesInGraph().size());
}

TEST_F(GraphSingleThreadedTest, When_InsertOneNode_Then_VerifyElement)
{
    int newNode{1};
    EXPECT_TRUE(testGraph_.addNodeToGraph(newNode));

    std::set<int> expectedNodes{1};
    EXPECT_EQ(expectedNodes, testGraph_.getAllNodesInGraph());
}

TEST_F(GraphSingleThreadedTest, When_InsertMultipleNodes_Then_VerifyElementsAndSize)
{
    int newNode{1};
    EXPECT_TRUE(testGraph_.addNodeToGraph(newNode));
    newNode = 3;
    EXPECT_TRUE(testGraph_.addNodeToGraph(newNode));
    newNode = 5;
    EXPECT_TRUE(testGraph_.addNodeToGraph(newNode));

    std::set<int> expectedNodes{1, 3, 5};
    EXPECT_EQ(expectedNodes, testGraph_.getAllNodesInGraph());
    EXPECT_EQ(3, testGraph_.getAllNodesInGraph().size());
}

TEST_F(GraphSingleThreadedTest, When_InsertNewNodeParentToExistingNode_Then_Successful)
{
    int childNode{1};
    EXPECT_TRUE(testGraph_.addNodeToGraph(childNode));

    int parentNode{6};
    EXPECT_TRUE(testGraph_.addParentToNode(childNode, parentNode));

    std::set<int> expectedNodes{1, 6};
    EXPECT_EQ(expectedNodes, testGraph_.getAllNodesInGraph());
    EXPECT_EQ(2, testGraph_.getAllNodesInGraph().size());
}

TEST_F(GraphSingleThreadedTest, When_InsertNewNodeParentToMissingNode_Then_Failure)
{
    int childNode{1};
    EXPECT_TRUE(testGraph_.addNodeToGraph(childNode));

    int wrongChildNode{2};
    int parentNode{6};
    EXPECT_FALSE(testGraph_.addParentToNode(wrongChildNode, parentNode));

    std::set<int> expectedNodes{1};
    EXPECT_EQ(expectedNodes, testGraph_.getAllNodesInGraph());
    EXPECT_EQ(1, testGraph_.getAllNodesInGraph().size());
}

TEST_F(GraphSingleThreadedTest, WHEN_InsertParentToExistingNode_Then_Successful)
{
    int childNode{1};
    EXPECT_TRUE(testGraph_.addNodeToGraph(childNode));
    int parentNode{6};
    EXPECT_TRUE(testGraph_.addNodeToGraph(parentNode));

    EXPECT_TRUE(testGraph_.addParentToNode(childNode, parentNode));

    std::set<int> expectedNodes{1, 6};
    EXPECT_EQ(expectedNodes, testGraph_.getAllNodesInGraph());
    EXPECT_EQ(2, testGraph_.getAllNodesInGraph().size());
}

TEST_F(GraphSingleThreadedTest, WHEN_InsertParentWhenMultipleNodes_Then_Successful)
{
    int childNode{1};
    EXPECT_TRUE(testGraph_.addNodeToGraph(childNode));
    int randomNode{2};
    EXPECT_TRUE(testGraph_.addNodeToGraph(randomNode));
    int parentNode{6};
    EXPECT_TRUE(testGraph_.addNodeToGraph(parentNode));

    EXPECT_TRUE(testGraph_.addParentToNode(childNode, parentNode));

    std::set<int> expectedNodes{1, 2, 6};
    EXPECT_EQ(expectedNodes, testGraph_.getAllNodesInGraph());
    EXPECT_EQ(3, testGraph_.getAllNodesInGraph().size());
}