#pragma once

#include <Blob/Core/Scene.hpp>
#include <Blob/glTF2/Node.hpp>
#include <iostream>
#include <nlohmann/json.hpp>

namespace Blob::glTF2 {

class Scene : public Core::Scene {
public:
    std::vector<int> nodes;
    std::string name;

    Scene(const nlohmann::json &j, const std::deque<Node> &nodesVector);

    friend std::ostream &operator<<(std::ostream &s, const Scene &a);
};
} // namespace Blob::glTF2
