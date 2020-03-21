#include <glad/glad.h> // TODO: remove this

#include <Blob/GL/Core.hpp> // TODO: remove this
#include <Blob/Shapes.hpp>
#include <glm/gtc/type_ptr.inl>
#include <imgui.h>
#include <iostream>

using namespace Blob::GL;

namespace Blob::Shapes {

struct Data {
    float coor[3];
    float norm[3];
};

const Data data[] = {
    // x = devant
    // y = droite
    // z = haut

    // CUBE
    // Top face
    {{1.0f, -1.0f, 1.0f}, {0.0f, -0.0f, 1.0f}},
    {{1.0f, 1.0f, 1.0f}, {0.0f, -0.0f, 1.0f}},
    {{-1.0f, 1.0f, 1.0f}, {0.0f, -0.0f, 1.0f}},
    {{-1.0f, -1.0f, 1.0f}, {0.0f, -0.0f, 1.0f}},
    {{-1.0f, -1.0f, 1.0f}, {0.0f, -1.0f, 0.0f}},
    {{-1.0f, -1.0f, -1.0f}, {0.0f, -1.0f, 0.0f}},
    {{1.0f, -1.0f, -1.0f}, {0.0f, -1.0f, 0.0f}},
    {{1.0f, -1.0f, 1.0f}, {0.0f, -1.0f, 0.0f}},
    {{-1.0f, 1.0f, 1.0f}, {-1.0f, -0.0f, 0.0f}},
    {{-1.0f, 1.0f, -1.0f}, {-1.0f, -0.0f, 0.0f}},
    {{-1.0f, -1.0f, -1.0f}, {-1.0f, -0.0f, 0.0f}},
    {{-1.0f, -1.0f, 1.0f}, {-1.0f, -0.0f, 0.0f}},
    {{-1.0f, -1.0f, -1.0f}, {0.0f, 0.0f, -1.0f}},
    {{-1.0f, 1.0f, -1.0f}, {0.0f, 0.0f, -1.0f}},
    {{1.0f, 1.0f, -1.0f}, {0.0f, 0.0f, -1.0f}},
    {{1.0f, -1.0f, -1.0f}, {0.0f, 0.0f, -1.0f}},
    {{1.0f, -1.0f, 1.0f}, {1.0f, -0.0f, 0.0f}},
    {{1.0f, -1.0f, -1.0f}, {1.0f, -0.0f, 0.0f}},
    {{1.0f, 1.0f, -1.0f}, {1.0f, -0.0f, 0.0f}},
    {{1.0f, 1.0f, 1.0f}, {1.0f, -0.0f, 0.0f}},
    {{1.0f, 1.0f, 1.0f}, {0.0f, 1.0f, 0.0f}},
    {{1.0f, 1.0f, -1.0f}, {0.0f, 1.0f, 0.0f}},
    {{-1.0f, 1.0f, -1.0f}, {0.0f, 1.0f, 0.0f}},
    {{-1.0f, 1.0f, 1.0f}, {0.0f, 1.0f, 0.0f}},

    // PLANE
    {{-0.5f, -0.5f, 0.f}, {0.f, 0.f, 1.f}}, // hg
    {{0.5f, -0.5f, 0.f}, {0.f, 0.f, 1.f}},  // bg
    {{0.5f, 0.5f, 0.f}, {0.f, 0.f, 1.f}},   // bd
    {{-0.5f, 0.5f, 0.f}, {0.f, 0.f, 1.f}},  // hd

    // OCTAGONAL PRISM

    // Top face
    {{0.f, 0.f, 0.5f}, {0.f, 0.f, 1.f}}, // centre

    {{-0.2f, -0.5f, 0.5f}, {0.f, 0.f, 1.f}}, // 8 gh
    {{0.2f, -0.5f, 0.5f}, {0.f, 0.f, 1.f}},  // 7 gb
    {{0.5f, -0.2f, 0.5f}, {0.f, 0.f, 1.f}},  // 6 bg
    {{0.5f, 0.2f, 0.5f}, {0.f, 0.f, 1.f}},   // 5 bd
    {{0.2f, 0.5f, 0.5f}, {0.f, 0.f, 1.f}},   // 4 db
    {{-0.2f, 0.5f, 0.5f}, {0.f, 0.f, 1.f}},  // 3 dh
    {{-0.5f, 0.2f, 0.5f}, {0.f, 0.f, 1.f}},  // 2 hd
    {{-0.5f, -0.2f, 0.5f}, {0.f, 0.f, 1.f}}, // 1 hg

    // Bottom face
    {{0.f, 0.f, -0.5f}, {0.f, 0.f, -1.f}}, // centre

    {{-0.5f, -0.2f, -0.5f}, {0.f, 0.f, -1.f}}, // 1 hg
    {{-0.5f, 0.2f, -0.5f}, {0.f, 0.f, -1.f}},  // 2 hd
    {{-0.2f, 0.5f, -0.5f}, {0.f, 0.f, -1.f}},  // 3 dh
    {{0.2f, 0.5f, -0.5f}, {0.f, 0.f, -1.f}},   // 4 db
    {{0.5f, 0.2f, -0.5f}, {0.f, 0.f, -1.f}},   // 5 bd
    {{0.5f, -0.2f, -0.5f}, {0.f, 0.f, -1.f}},  // 6 bg
    {{0.2f, -0.5f, -0.5f}, {0.f, 0.f, -1.f}},  // 7 gb
    {{-0.2f, -0.5f, -0.5f}, {0.f, 0.f, -1.f}}, // 8 gh

    // Front face
    {{0.5f, -0.2f, 0.5f}, {1.f, 0.f, 0.f}},  // 6 bg
    {{0.5f, -0.2f, -0.5f}, {1.f, 0.f, 0.f}}, // 6 bg
    {{0.5f, 0.2f, -0.5f}, {1.f, 0.f, 0.f}},  // 5 bd
    {{0.5f, 0.2f, 0.5f}, {1.f, 0.f, 0.f}},   // 5 bd

    // Right face
    {{-0.2f, 0.5f, -0.5f}, {0.f, 1.f, 0.f}}, // 3 dh
    {{-0.2f, 0.5f, 0.5f}, {0.f, 1.f, 0.f}},  // 3 dh
    {{0.2f, 0.5f, 0.5f}, {0.f, 1.f, 0.f}},   // 4 db
    {{0.2f, 0.5f, -0.5f}, {0.f, 1.f, 0.f}},  // 4 db

    // Back face
    {{-0.5f, -0.2f, -0.5f}, {-1.f, 0.f, 0.f}}, // 6 bg
    {{-0.5f, -0.2f, 0.5f}, {-1.f, 0.f, 0.f}},  // 6 bg
    {{-0.5f, 0.2f, 0.5f}, {-1.f, 0.f, 0.f}},   // 5 bd
    {{-0.5f, 0.2f, -0.5f}, {-1.f, 0.f, 0.f}},  // 5 bd

    // Left face
    {{-0.2f, -0.5f, -0.5f}, {0.f, -1.f, 0.f}}, // 3 dh
    {{0.2f, -0.5f, -0.5f}, {0.f, -1.f, 0.f}},  // 4 db
    {{0.2f, -0.5f, 0.5f}, {0.f, -1.f, 0.f}},   // 4 db
    {{-0.2f, -0.5f, 0.5f}, {0.f, -1.f, 0.f}},  // 3 dh

};

/*GLushort cubeIndices[] = {
    0,  1,  2,  0,  2,  3,  // front
    4,  5,  6,  4,  6,  7,  // back
    8,  9,  10, 8,  10, 11, // top
    12, 13, 14, 12, 14, 15, // bottom
    16, 17, 18, 16, 18, 19, // right
    20, 21, 22, 20, 22, 23  // left
};*/

GLushort cubeIndices[] = {0, 1, 2, 0, 2, 3, 4, 5, 6, 4, 6, 7, 8, 9, 10, 8, 10, 11, 12, 13, 14, 12, 14, 15, 16, 17, 18, 16, 18, 19, 20, 21, 22, 20, 22, 23};

GLushort planeIndices[] = {0, 1, 2, 0, 2, 3};

GLushort octagonalPrismIndices[] = {
    0,  1,  2,  0,  2,  3,  0, 3,  4,  0, 4,  5,  0, 5,  6,  0, 6,  7,  0, 7,  8,  0, 8,  1,  // top
    9,  10, 11, 9,  11, 12, 9, 12, 13, 9, 13, 14, 9, 14, 15, 9, 15, 16, 9, 16, 17, 9, 17, 10, // bottom
    18, 19, 20, 18, 20, 21,                                                                   // front
    22, 23, 24, 22, 24, 25,                                                                   // right
    26, 27, 28, 26, 28, 29,                                                                   // back
    30, 31, 32, 30, 32, 33,                                                                   // back
};

VertexBufferObject *vbo;
VertexArrayObject *vaoCube;
VertexArrayObject *vaoPlane;
VertexArrayObject *vaoOctagonalPrism;
ShaderProgram *singleColorShader;

SingleColorMaterial::SingleColorMaterial() : Material(*singleColorShader) {}

int SingleColorMaterial::model = -1;
int SingleColorMaterial::view = -1;
int SingleColorMaterial::projection = -1;

int SingleColorMaterial::ambientPos = -1;
int SingleColorMaterial::diffusePos = -1;
int SingleColorMaterial::specularPos = -1;
int SingleColorMaterial::shininessPos = -1;
int SingleColorMaterial::viewPos = -1;
Light SingleColorMaterial::light;

/*int SingleColorMaterial::lightDirPos = -1;
int SingleColorMaterial::lightColorPos = -1;
int SingleColorMaterial::colorPos = -1;
float SingleColorMaterial::lightDir[] = {1.0, -1.0, 2.0};
Color SingleColorMaterial::lightColor = Color::White;*/

void SingleColorMaterial::applyMaterial(const ProjectionTransform &pt, const ViewTransform &vt, const ModelTransform &mt) const {
    Blob::GL::Core::setMat4(pt.projectionPtr, projection);
    Blob::GL::Core::setMat4(vt.transform, view);
    Blob::GL::Core::setMat4(mt.model, model);

    Blob::GL::Core::setVec3(&ambient.R, ambientPos);
    Blob::GL::Core::setVec3(&diffuse.R, diffusePos);
    Blob::GL::Core::setVec3(&specular.R, specularPos);
    Blob::GL::Core::setFloat(shininess, shininessPos);

    Blob::GL::Core::setVec3(glm::value_ptr(light.position), light.positionPos);
    Blob::GL::Core::setVec3(&light.ambient.R, light.ambientPos);
    Blob::GL::Core::setVec3(&light.diffuse.R, light.diffusePos);
    Blob::GL::Core::setVec3(&light.specular.R, light.specularPos);

    Blob::GL::Core::setVec3(glm::value_ptr(vt.cameraPosition), viewPos);

    // Blob::GL::Core::setVec3(lightDir, lightDirPos);
    // Blob::GL::Core::setVec3(&lightColor.R, lightColorPos);
    // Blob::GL::Core::setVec4(&color.R, colorPos);
}
void SingleColorMaterial::init() {
    std::cout << "init Shapes" << std::endl;
    singleColorShader = new ShaderProgram(R"=====(
	#version 450

	layout (location = 0) in vec3 POSITION;
	layout (location = 1) in vec3 NORMAL;

	out vec3 FragPos;
	out vec3 FragNormal;

	uniform mat4 model;
	uniform mat4 view;
	uniform mat4 projection;

	void main()
	{
		FragPos = vec3(model * vec4(POSITION, 1.0));
		FragNormal = mat3(transpose(inverse(model))) * NORMAL;

		gl_Position = projection * view * vec4(FragPos, 1.0);
	}
	)=====",
                                          R"=====(
#version 450
out vec4 FragColor;

struct Material {
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;
};

struct Light {
    vec3 position;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

in vec3 FragPos;
in vec3 FragNormal;

uniform vec3 viewPos;
uniform Material material;
uniform Light light;

void main()
{
    // ambient
    vec3 ambient = light.ambient * material.ambient;

    // diffuse
    vec3 norm = normalize(FragNormal);
    vec3 lightDir = normalize(light.position - FragPos + vec3(1.0, 1.0, 1.0));
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = light.diffuse * (diff * material.diffuse);

    // specular
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    vec3 specular = light.specular * (spec * material.specular);

    vec3 result = ambient + diffuse + specular;
    FragColor = vec4(result, 1.0);
}
	)=====");
    model = singleColorShader->getUniformLocation("model");
    view = singleColorShader->getUniformLocation("view");
    projection = singleColorShader->getUniformLocation("projection");

    ambientPos = singleColorShader->getUniformLocation("material.ambient");
    diffusePos = singleColorShader->getUniformLocation("material.diffuse");
    specularPos = singleColorShader->getUniformLocation("material.specular");
    shininessPos = singleColorShader->getUniformLocation("material.shininess");

    light.positionPos = singleColorShader->getUniformLocation("light.position");
    light.ambientPos = singleColorShader->getUniformLocation("light.ambient");
    light.diffusePos = singleColorShader->getUniformLocation("light.diffuse");
    light.specularPos = singleColorShader->getUniformLocation("light.specular");

    viewPos = singleColorShader->getUniformLocation("viewPos");

    /*lightDirPos = singleColorShader->getUniformLocation("lightDir");
    lightColorPos = singleColorShader->getUniformLocation("lightColor");
    colorPos = singleColorShader->getUniformLocation("objectColor");*/
}

void addBasicShaders() {

    std::cout << "add Basic Shaders" << std::endl;

    {
        Blob::GL::ShaderProgram &sp = Blob::GL::ShaderProgram::Shaders["POSITION"];
        sp.addVertexShader(R"=====(
	#version 450

	layout (location = 0) in vec3 POSITION;

	uniform mat4 model;
	uniform mat4 view;
	uniform mat4 projection;

	void main()	{
		gl_Position = projection * view * model * vec4(POSITION, 1.0);
	}
	)=====");
        sp.addFragmentShader(R"=====(
	#version 450

	out vec4 FragColor;

	void main()	{
		FragColor = vec4(0.0, 0.4, 0.4, 1.0);
	}
	)=====");
        sp.linkShaders();
    }
    {
        Blob::GL::ShaderProgram &sp = Blob::GL::ShaderProgram::Shaders["POSITION_NORMAL"];
        sp.addVertexShader(R"=====(
	#version 450

	layout (location = 0) in vec3 POSITION;
	layout (location = 1) in vec3 NORMAL;

	out vec3 FragPos;
	out vec3 FragNormal;

	uniform mat4 model;
	uniform mat4 view;
	uniform mat4 projection;

	void main()
	{
		FragPos = vec3(model * vec4(POSITION, 1.0));
		FragNormal = mat3(transpose(inverse(model))) * NORMAL;

		gl_Position = projection * view * vec4(FragPos, 1.0);
	}
	)=====");
        sp.addFragmentShader(R"=====(
	#version 450

	out vec4 FragColor;

	in vec3 FragNormal;
	in vec3 FragPos;
	in vec2 TexCoord;

	uniform sampler2D ourTexture;
	uniform vec2 texScale;

	void main()
	{
		vec3 lightPos = vec3(4.0, 4.0, 0.0);
		vec3 lightColor = vec3(1.0, 1.0, 1.0);
		vec4 objectColor = vec4(0.0, 0.4, 0.4, 1.0);
		//
		float ambientStrength = 0.2;
		vec3 ambient = ambientStrength * lightColor;

		// diffuse
		vec3 norm = normalize(FragNormal);
		vec3 lightDir = normalize(vec3(1.0, -1.0, 2.0));
		float diff = max(dot(norm, lightDir), 0.0);
		vec3 diffuse = diff * lightColor;

		FragColor = vec4(ambient + diffuse, 1.0) * objectColor;
	}
	)=====");
        sp.linkShaders();
    }
    {
        Blob::GL::ShaderProgram &sp = Blob::GL::ShaderProgram::Shaders["POSITION_NORMAL_TEXCOORD_0"];
        sp.addVertexShader(R"=====(
	#version 450

	layout (location = 0) in vec3 POSITION;
	layout (location = 1) in vec3 NORMAL;
	layout (location = 2) in vec2 TEXCOORD_0;

	out vec3 FragPos;
	out vec3 FragNormal;
	out vec2 TexCoord;

	uniform mat4 model;
	uniform mat4 view;
	uniform mat4 projection;

	void main()
	{
		FragPos = vec3(model * vec4(POSITION, 1.0));
		FragNormal = mat3(transpose(inverse(model))) * NORMAL;

		gl_Position = projection * view * vec4(FragPos, 1.0);

		TexCoord = TEXCOORD_0;
	}
	)=====");
        sp.addFragmentShader(R"=====(
	#version 450

	out vec4 FragColor;

	in vec3 FragNormal;
	in vec3 FragPos;
	in vec2 TexCoord;

	uniform sampler2D ourTexture;
	uniform vec2 texScale;

	void main()
	{
		vec3 lightPos = vec3(4.0, 4.0, 0.0);
		vec3 lightColor = vec3(1.0, 1.0, 1.0);
		vec4 objectColor = texture(ourTexture, TexCoord * texScale);
		//
		float ambientStrength = 0.2;
		vec3 ambient = ambientStrength * lightColor;

		// diffuse
		vec3 norm = normalize(FragNormal);
		vec3 lightDir = normalize(vec3(1.0, -1.0, 2.0));
		float diff = max(dot(norm, lightDir), 0.0);
		vec3 diffuse = diff * lightColor;

		FragColor = vec4(ambient + diffuse, 1.0) * objectColor;
	}
	)=====");
        sp.linkShaders();
    }
}

void init() {
    SingleColorMaterial::init();
    vbo = new VertexBufferObject((GLubyte *) data, sizeof(data));
    vaoCube = new VertexArrayObject();
    vaoCube->setBuffer(*vbo, sizeof(Data));
    vaoCube->setArray(3, singleColorShader->getAttribLocation("POSITION"), GL_FLOAT, (uint32_t) offsetof(Data, coor));
    vaoCube->setArray(3, singleColorShader->getAttribLocation("NORMAL"), GL_FLOAT, (uint32_t) offsetof(Data, norm));

    vaoPlane = new VertexArrayObject();
    vaoPlane->setBuffer(*vbo, sizeof(Data), 4 * 6 * sizeof(Data));
    vaoPlane->setArray(3, singleColorShader->getAttribLocation("POSITION"), GL_FLOAT, (uint32_t) offsetof(Data, coor));
    vaoPlane->setArray(3, singleColorShader->getAttribLocation("NORMAL"), GL_FLOAT, (uint32_t) offsetof(Data, norm));

    vaoOctagonalPrism = new VertexArrayObject();
    vaoOctagonalPrism->setBuffer(*vbo, sizeof(Data), (4 * 6 + 4) * sizeof(Data));
    vaoOctagonalPrism->setArray(3, singleColorShader->getAttribLocation("POSITION"), GL_FLOAT, (uint32_t) offsetof(Data, coor));
    vaoOctagonalPrism->setArray(3, singleColorShader->getAttribLocation("NORMAL"), GL_FLOAT, (uint32_t) offsetof(Data, norm));
}

void destroy() {
    delete vbo;
    delete singleColorShader;
    delete vaoCube;
    delete vaoPlane;
    delete vaoOctagonalPrism;
}

Cube::Cube() : Renderable(*vaoCube, singleColorMaterial) {
    setIndices(cubeIndices, sizeof(cubeIndices) / sizeof(*cubeIndices), GL_UNSIGNED_SHORT);
}

Plane::Plane() : Renderable(*vaoPlane, singleColorMaterial) {
    setIndices(planeIndices, sizeof(planeIndices) / sizeof(*planeIndices), GL_UNSIGNED_SHORT);
}

OctagonalPrism::OctagonalPrism() : Renderable(*vaoOctagonalPrism, singleColorMaterial) {
    setIndices(octagonalPrismIndices, sizeof(octagonalPrismIndices) / sizeof(*octagonalPrismIndices), GL_UNSIGNED_SHORT);
}
} // namespace Blob::Shapes