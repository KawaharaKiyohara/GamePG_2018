#pragma once
class Player : public IGameObject
{
public:
	Player();
	~Player();
	prefab::CSkinModelRender* skinModelRenderer; //���f�������_���[
};

