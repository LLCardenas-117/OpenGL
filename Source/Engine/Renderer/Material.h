#pragma once
#include "Resources/Resource.h"
#include "GUI/GUI.h"
#include <glm/glm.hpp>

namespace neu {
	class Shader;
	class Program;
	class Texture;

	class Material : public Resource, GUI {
	public:
		enum class Parameters : uint32_t {
			None = 0,
			BaseMap = (1 << 0),
			SpecularMap = (1 << 1),
			EmissiveMap = (1 << 2),
			NormalMap = (1 << 3)
		};

	public:
		Material() = default;
		~Material() = default;

		bool Load(const std::string& filename);
		void Bind();

		void UpdateGui() override;

	public:
		float shininess{ 2 };
		glm::vec2 tiling{ 1, 1 };
		glm::vec2 offset{ 0, 0 };
		glm::vec3 baseColor{ 1, 1, 1 };
		glm::vec3 emissiveColor{ 0, 0, 0 };

		res_t<Texture> baseMap;
		res_t<Texture> emissiveMap;
		res_t<Texture> specularMap;
		res_t<Texture> normalMap;

		res_t<Program> program;
		Parameters parameters;
	};
}