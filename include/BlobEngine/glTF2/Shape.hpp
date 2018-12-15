#ifndef BLOBENGINE_SHAPE_GLTF2_HPP
#define BLOBENGINE_SHAPE_GLTF2_HPP

#include <BlobEngine/glTF2/Mesh.hpp>


namespace BlobEngine::glTF2 {

	class Shape { //un objet à modéliser
	private:
		std::vector<Shape> children;

		int mesh;

		Mesh &meshClass;
	public:
		explicit Shape(int num, Reader::JsonExplorer explorer, Mesh &meshClass);

		friend std::ostream &operator<<(std::ostream &s, const Shape &a);

		BlobGL::Shape getShape();
	};
}

#endif //BLOBENGINE_SHAPE_HPP
