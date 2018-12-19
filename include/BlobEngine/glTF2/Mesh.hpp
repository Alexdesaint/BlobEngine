#ifndef BLOBENGINE_MESH_HPP
#define BLOBENGINE_MESH_HPP

#include <BlobEngine/BlobGL/Renderable.hpp>
#include <BlobEngine/glTF2/Accessor.hpp>

namespace BlobEngine::glTF2{

	class Mesh {
	private:

		struct Data {
			GLfloat coor[3];
			GLfloat normal[3];
			GLfloat texCoor[2];
			GLubyte color[4];
		};

		std::vector<Data> dataBuffer;

		Buffer buffer;

		Accessor accessor;

		std::vector<std::vector<BlobGL::Renderable>> primitives;

	public:
		explicit Mesh(Reader::JsonExplorer explorer, BlobGL::VertexBufferObject &vbo);

		friend std::ostream &operator<<(std::ostream &s, Mesh &a);

		std::vector<BlobGL::Renderable*> getShape(int mesh);
	};
}

#endif //BLOBENGINE_MESH_HPP
