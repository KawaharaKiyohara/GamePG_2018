#pragma once
#include "tkEngine/physics/tkPhysicsStaticObject.h"

class BackGround : public IGameObject
{
public:
	BackGround();
	~BackGround();
	bool Start();
	prefab::CSkinModelRender* skinModelRender = nullptr;	//�X�L�����f�������_���[�B

	//HandsOn1 �ÓI�����I�u�W�F�N�g�����C���������ɓW�J���ێ�������B
	

};

