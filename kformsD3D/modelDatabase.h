
struct Model
{
	void load(D3D11GraphicsDevice &g);

	string modelPath;
	D3D11TriMesh mesh;
};

class ModelDatabase
{
public:
	void init();

	Model* getRandomModel(D3D11GraphicsDevice &g)
	{
		Model *m = util::randomElement(models);
		m->load(g);
		return m;
	}

	vector<Model*> models;
};
