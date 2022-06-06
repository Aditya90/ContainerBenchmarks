#include <vector>
#include <set>
#include <utility>

/**
 * Graph
 *
 * Properties of a graph
 * 1. Each node can be connected to multiple other nodes
 * 2. There can be nodes in a graph which are not connected to other nodes
 * 3. We can choose to construct graphs with and without cycles
 * 4. We assume our graph is  directional
 *
 */

template <typename NodeId, bool hasCycles = false>
class DirectionalGraph
{
public:
    bool addNodeToGraph(NodeId &newNodeId);
    bool addParentToNode(NodeId &childNode, NodeId &parentNode);
    std::set<NodeId> getAllNodesInGraph();

    void printNodesByLevel();

private:
    std::set<NodeId> allNodes_;
    std::vector<std::pair<NodeId, std::vector<NodeId>>> graph_;
};

template <typename NodeId, bool hasCycles>
bool DirectionalGraph<NodeId, hasCycles>::addNodeToGraph(NodeId &newNodeId)
{
    if (!allNodes_.contains(newNodeId))
    {
        allNodes_.insert(newNodeId);
        graph_.emplace_back(newNodeId, std::vector<NodeId>{});
    }

    return true;
}
template <typename NodeId, bool hasCycles>
bool DirectionalGraph<NodeId, hasCycles>::addParentToNode(NodeId &childNode, NodeId &parentNode)
{
    return false;
}
template <typename NodeId, bool hasCycles>
std::set<NodeId> DirectionalGraph<NodeId, hasCycles>::getAllNodesInGraph()
{
    return allNodes_;
}

template <typename NodeId, bool hasCycles>
void DirectionalGraph<NodeId, hasCycles>::printNodesByLevel()
{
}