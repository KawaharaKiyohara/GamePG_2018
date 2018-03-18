#pragma once
class Player;

class Star : public IGameObject
{
public:
	~Star();
	bool Start();
	void Update();
	//HandsOn 1 prefab::CSkinModelRender*型のメンバ変数を追加。
	
	CVector3 position = CVector3::Zero;
	float angle = 0.0f;	//回転角度。
	Player* player = nullptr;
	
	
};

