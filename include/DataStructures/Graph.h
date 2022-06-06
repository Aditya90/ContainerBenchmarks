#include <vector>
#include <set>
#include <utility>
#include <iostream>

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
    bool retVal{false};
    if (allNodes_.contains(childNode))
    {
        // TODO - Clean up returning from within a function
        if (!allNodes_.contains(parentNode))
        {
            if (!this->addNodeToGraph(parentNode))
            {
                return false;
            }
        }

        auto graphIt = std::find_if(graph_.begin(), graph_.end(),
                                    [&childNode](auto graphEntry)
                                    {
                                        return (graphEntry.first == childNode);
                                    });
        if (graphIt != graph_.end())
        {
            graphIt->second.push_back(parentNode);
            retVal = true;
        }
    }
    return retVal;
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