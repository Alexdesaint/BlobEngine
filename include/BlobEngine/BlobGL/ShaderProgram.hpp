#ifndef BLOBENGINE_SHADERPROGRAM_HPP
#define BLOBENGINE_SHADERPROGRAM_HPP

#include <string>
#include <glad/glad.h>

namespace BlobEngine::BlobGL {

	class ShaderProgram {
	private:
		GLuint program;

		GLuint vertexShader, fragmentShader;

	public:
		ShaderProgram();

		ShaderProgram(const std::string &pathVertex, const std::string &pathFragment);

		void addVertexShader(const std::string &src);

		void addVertexShaderFile(const std::string &path);

		void addFragmentShader(const std::string &src);

		void addFragmentShaderFile(const std::string &path);

		void linkShaders();

		GLuint getProgram() const;
	};

}

#endif //BLOBENGINE_SHADERPROGRAM_HPP
