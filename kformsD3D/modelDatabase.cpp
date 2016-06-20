
#include "main.h"

void ModelDatabase::init()
{
	for (auto &folder : Directory::enumerateDirectoriesWithPath(baseModelDir))
	{
		const string modelPath = folder + "/model.obj";
		//if (util::fileExists(modelPath))
		{
			Model *newModel = new Model;
			newModel->modelPath = modelPath;
			models.push_back(newModel);
		}
		/*else
		{
			cout << "Model file not found: " << modelPath << endl;
		}*/
	}
}

void Model::load(D3D11GraphicsDevice &g)
{
	if (mesh.getTriMesh().getVertices().size() > 0)
		return;
	MeshDataf data;
	MeshIOf::loadFromOBJ(modelPath, data);
	TriMeshf triMesh(data);
	for (auto &v : triMesh.getVertices())
	{
		v.color = vec4f(1.0f, 1.0f, 1.0f, 1.0f);
	}
	mesh.load(g, triMesh);
	
}
