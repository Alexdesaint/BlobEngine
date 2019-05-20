#pragma once

#include <Blob/glTF2/Texture.hpp>
#include <list>

#include <nlohmann/json.hpp>

namespace Blob::glTF2 {
    class Material {
    public:

        /**
         * Reference to a texture.
         */
        struct textureInfo {
            bool set = false; ///< if this data is set with Json constructor

            size_t index; ///< The index of the texture. Required
            size_t texCoord = 0; ///< The set index of texture's TEXCOORD attribute used for texture coordinate mapping.

            std::list<Texture>::iterator indexIt;

            textureInfo() = default;

            explicit textureInfo(const nlohmann::json &j, std::list<Texture> &textures);
        };

        std::string name; ///< The user-defined name of this object.

        /**
         * A set of parameter values that are used to define the metallic-roughness material model from Physically-Based
         * Rendering (PBR) methodology. When not specified, all the default values of pbrMetallicRoughness apply.
         */
        struct PbrMetallicRoughness {
            bool set = false; ///< if this data is set with Json constructor

            std::array<float, 4> baseColorFactor = {1, 1, 1, 1};///< The material's base color factor.
            textureInfo baseColorTexture; ///< The base color texture.
            float metallicFactor = 1; ///< The metalness of the material.
            float roughnessFactor = 1; ///< The roughness of the material.
            textureInfo metallicRoughnessTexture; ///< The metallic-roughness texture.

            PbrMetallicRoughness() = default;

            explicit PbrMetallicRoughness(const nlohmann::json &j, std::list<Texture> &textures);
        } pbrMetallicRoughness;

        /**
         * The normal map texture.
         */
        struct normalTextureInfo : textureInfo {
            float scale = 1; ///< The scalar multiplier applied to each normal vector of the normal texture.

            normalTextureInfo() = default;

            explicit normalTextureInfo(const nlohmann::json &j, std::list<Texture> &textures);
        } normalTexture;

        /**
         * The occlusion map texture.
         */
        struct occlusionTextureInfo : textureInfo {
            float strength = 1; ///< A scalar multiplier controlling the amount of occlusion applied.

            occlusionTextureInfo() = default;

            explicit occlusionTextureInfo(const nlohmann::json &j, std::list<Texture> &textures);
        } occlusionTexture;

        textureInfo emissiveTexture; ///< The emissive map texture.

        std::array<float, 3> emissiveFactor = {0, 0, 0}; ///< The emissive color of the material. default: [0,0,0]
        std::string alphaMode = "OPAQUE"; ///< The alpha rendering mode of the material. default: "OPAQUE"
        float alphaCutoff = 0.5; ///< The alpha cutoff value of the material. default: 0.5
        bool doubleSided = false; ///< Specifies whether the material is double sided. default: false

        Material(const nlohmann::json &j, std::list<Texture> &textures);

        friend std::ostream &operator<<(std::ostream &s, const Material &a);
    };
}