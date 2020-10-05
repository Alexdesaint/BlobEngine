#pragma once

#include <Blob/glTF2/Mesh.hpp>
#include <Blob/Shape.hpp>
#include <iostream>
#include <nlohmann/json.hpp>

namespace Blob::glTF2 {

class Node : public Core::Shape {
private:
    int camera = -1; ///< The index of the camera referenced by this node.

    std::vector<int> children; ///< The indices of this node's children.

    int skin = -1; ///< The index of the skin referenced by this node.

    std::array<float, 16> matrix = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1}; ///< A floating-point 4x4 transformation
    ///< matrix stored in column-major order. default: [1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1]

    int mesh = -1; ///< The index of the mesh in this node.

    std::array<float, 4> rotation = {0, 0, 0, 1}; ///< The node's unit quaternion rotation in the order (x, y, z, w),
                                                  ///< where w is the scalar. default: [0,0,0,1]

    std::array<float, 3> scale = {1, 1, 1}; ///< The node's non-uniform scale, given as the scaling factors along the
    ///< x, y, and z axes. default: [1,1,1]

    std::array<float, 3> translation = {0, 0, 0}; ///< The node's translation along the x, y, and z axes.
                                                  ///< default: [0,0,0]

    std::vector<float> weights; ///< The weights of the instantiated Morph Target. Number of elements must match
                                ///< number of Morph Targets of used mesh.

    std::string name; ///< The user-defined name of this object.

public:
    friend std::ostream &operator<<(std::ostream &s, const Node &a);
    Node(const nlohmann::json &j, std::vector<glTF2::Mesh> &meshes);

    void updateChild(std::vector<Node> &nodes);
};

} // namespace Blob::glTF2
