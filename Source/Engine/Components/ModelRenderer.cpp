#include "EnginePCH.h"
#include "ModelRenderer.h"

namespace neu {
	FACTORY_REGISTER(ModelRenderer)

	void ModelRenderer::Update(float dt) {
		//
	}

	void ModelRenderer::Draw(Renderer& renderer) {
		material->Bind();
		material->program->SetUniform("u_model", owner->transform.GetMatrix());

		glDepthMask(enableDepth);
		glCullFace(cullFace);

		model->Draw(GL_TRIANGLES);
	}

	void ModelRenderer::Read(const serial_data_t& value) {
		Object::Read(value);

		std::string modelName;

		SERIAL_READ_NAME(value, "model", modelName);

		model = Resources().Get<Model>(modelName);


		std::string materialName;

		SERIAL_READ_NAME(value, "material", materialName);

		material = Resources().Get<Material>(materialName);

		SERIAL_READ(value, enableDepth);

		std::string cullFaceName;
		SERIAL_READ_NAME(value, "cullFace", cullFaceName);
		if (equalsIgnoreCase(cullFaceName, "front")) cullFace = GL_FRONT;
	}

	void ModelRenderer::UpdateGui() {
		/*if (ImGui::CollapsingHeader("Material", ImGuiTreeNodeFlags_DefaultOpen)) {
			ImGui::Text("Name: %s", name.c_str());

			ImGui::Text("Shader: %s", program->name.c_str());

			if (baseMap) ImGui::Text("Base Map: %s", baseMap->name.c_str());
			ImGui::ColorEdit3("Base Color", glm::value_ptr(baseColor));

			if (specularMap) ImGui::Text("Specular Map: %s", specularMap->name.c_str());

			if (emissiveMap) ImGui::Text("Emissive Map: %s", emissiveMap->name.c_str());
			ImGui::ColorEdit3("Emissive Color", glm::value_ptr(emissiveColor));

			ImGui::DragFloat("Shinieness", &shininess, 0.1f, 2.0f, 256.0f);

			ImGui::DragFloat2("Tiling", glm::value_ptr(tiling), 0.1f);

			ImGui::DragFloat2("Offset", glm::value_ptr(offset), 0.1f);
		}*/
	}
}
