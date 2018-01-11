#pragma once

/*!
 * @file serializer_json.h
 * @brief Header file for SerializerJSON class.
 * @author George McDonagh */


// External includes

#include <fstream>
#include <json\json.h>


// Internal includes

#include "utils\i_serializer.h"
#include "mesh_component.h"
#include "transform_component.h"


// Namespaces

namespace engine { namespace utils {

	class SerializerJSON : public ISerializer
	{
	public:
		template <typename T>
		static T* read(const char* filepath)
		{
			utils::Logger::log("ERROR::SERIALIZER::READ - Type \"%s\" is not a serialieable type.", typeis(T).name());
		}

		template <>
		static Game* read<Game>(const char* filepath)
		{
			Game* game = new Game();

			if (openFile(filepath))
			{
				std::ifstream file;
				file.open(filepath);

				Json::Value root;

				file >> root;
			}
		}

		template <>
		static graphics::Scene3D* read<graphics::Scene3D>(const char* filepath)
		{
			graphics::Scene3D* scene = new graphics::Scene3D();

			if (openFile(filepath))
			{
				std::ifstream file;
				file.open(filepath);

				Json::Value root;

				file >> root;

				maths::Vec3 camPosition(
					root["camera"]["position"][0].asFloat(),
					root["camera"]["position"][1].asFloat(),
					root["camera"]["position"][2].asFloat());

				maths::Vec3 camDirection(
					root["camera"]["direction"][0].asFloat(),
					root["camera"]["direction"][1].asFloat(),
					root["camera"]["direction"][2].asFloat());

				float camFOV = root["camera"]["fov"].asFloat();
				float camAspect = root["camera"]["fov"].asFloat();
				float camFar = root["camera"]["fov"].asFloat();
				float camNear = root["camera"]["fov"].asFloat();

				graphics::Camera camera(camPosition, camDirection, camFOV, camAspect, camFar, camNear);

				for (int i = 0; i < root["objects"].size(); i++)
				{
					SceneObject* sceneObject = new SceneObject();

					for (int j = 0; j < root["objects"][i]["components"].size(); j++)
					{
						if (root["objects"][i]["components"][j]["type"] == typeid(TransformComponent).name())
						{
							maths::Vec3 tPosition(
								root["objects"][i]["components"][j]["position"][0].asFloat(),
								root["objects"][i]["components"][j]["position"][1].asFloat(),
								root["objects"][i]["components"][j]["position"][2].asFloat());
							maths::Vec3 tScale(
								root["objects"][i]["components"][j]["scale"][0].asFloat(),
								root["objects"][i]["components"][j]["scale"][1].asFloat(),
								root["objects"][i]["components"][j]["scale"][2].asFloat());
							maths::Vec3 tOrientation(
								root["objects"][i]["components"][j]["orientation"][0].asFloat(),
								root["objects"][i]["components"][j]["orientation"][1].asFloat(),
								root["objects"][i]["components"][j]["orientation"][2].asFloat());

							sceneObject->addComponent<TransformComponent>(new TransformComponent(tPosition, tScale, tOrientation));
						}
						else if (root["objects"][i]["components"][j]["type"] == typeid(MeshComponent).name())
						{
							std::string meshFilepath = root["objects"][i]["components"][j]["filepath"].asCString();
							sceneObject->addComponent<MeshComponent>(new MeshComponent(AssetManager::loadAsset<graphics::Mesh>(meshFilepath.c_str())));
						}
					}

					scene->add(sceneObject);
				}
			}

			return scene;
		}

		template <typename T>
		static void write(const T& object)
		{
			utils::Logger::log("ERROR::SERIALIZER::READ - Type \"%s\" is not a serialieable type.", typeis(T).name());
		}

		template <>
		static void write<Game>(const Game& game)
		{
			Json::Value root;
		}

		template <>
		static void write<graphics::Scene3D>(const graphics::Scene3D& scene)
		{
			Json::Value root;

			const graphics::Camera& camera = scene.getCamera();

			root["camera"]["position"] = Json::Value(Json::arrayValue);
			root["camera"]["position"].append(camera.position().x());
			root["camera"]["position"].append(camera.position().y());
			root["camera"]["position"].append(camera.position().z());

			root["camera"]["direction"] = Json::Value(Json::arrayValue);
			root["camera"]["direction"].append(camera.direction().x());
			root["camera"]["direction"].append(camera.direction().y());
			root["camera"]["direction"].append(camera.direction().z());

			root["camera"]["fov"] = camera.fov();
			root["camera"]["aspect"] = camera.aspect();
			root["camera"]["near"] = camera.nearClip();
			root["camera"]["far"] = camera.farClip();

			const std::vector<SceneObject*> sceneObjects = scene.getObjects();

			// Start an array of objects
			root["objects"] = Json::Value(Json::arrayValue);

			// For each SceneObject the scene current has
			for (int i = 0; i < sceneObjects.size(); i++)
			{
				std::vector<Component*> components = sceneObjects[i]->getComponents();

				// Add an array to the array of objects that we will represent a single scene object (and contain its components)
				root["objects"].append(Json::Value());

				root["objects"][i]["components"] = Json::Value(Json::arrayValue);

				for (int j = 0; j < components.size(); j++)
				{
					root["objects"][i]["components"].append(Json::Value());

					if (dynamic_cast<TransformComponent*>(components[j]))
					{
						TransformComponent* transform = dynamic_cast<TransformComponent*>(components[j]);

						root["objects"][i]["components"][j]["type"] = typeid(TransformComponent).name();

						root["objects"][i]["components"][j]["position"] = Json::Value(Json::arrayValue);
						root["objects"][i]["components"][j]["position"].append(transform->position().x());
						root["objects"][i]["components"][j]["position"].append(transform->position().y());
						root["objects"][i]["components"][j]["position"].append(transform->position().z());

						root["objects"][i]["components"][j]["scale"] = Json::Value(Json::arrayValue);
						root["objects"][i]["components"][j]["scale"].append(transform->scale().x());
						root["objects"][i]["components"][j]["scale"].append(transform->scale().y());
						root["objects"][i]["components"][j]["scale"].append(transform->scale().z());

						root["objects"][i]["components"][j]["orientation"] = Json::Value(Json::arrayValue);
						root["objects"][i]["components"][j]["orientation"].append(transform->orientation().x());
						root["objects"][i]["components"][j]["orientation"].append(transform->orientation().y());
						root["objects"][i]["components"][j]["orientation"].append(transform->orientation().z());
					}
					else if (dynamic_cast<MeshComponent*>(components[j]))
					{
						MeshComponent* meshComponent = dynamic_cast<MeshComponent*>(components[j]);

						root["objects"][i]["components"][j]["type"] = typeid(MeshComponent).name();

						root["objects"][i]["components"][j]["filepath"] = Json::Value(meshComponent->mesh()->getFilepath());
					}
				}
			}

			std::ofstream file_id("res/data/scene.json");

			Json::StyledWriter styledWriter;
			file_id << styledWriter.write(root);

			file_id.close();
		}

	private:
		static bool openFile(const char* filepath);
	};

} }