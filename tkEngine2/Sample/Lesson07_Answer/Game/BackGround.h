#pragma once
#include "tkEngine/physics/tkPhysicsStaticObject.h"

class BackGround : public IGameObject
{
public:
	BackGround();
	~BackGround();
	bool Start();
	prefab::CSkinModelRender* skinModelRender = nullptr;	//�X�L�����f�������_���[�B

	//Backgroud�N���X��CPhysicsStaticObject�̃C���X�^���X��ێ�������B
	CPhysicsStaticObject m_physicsStaticObject;				//�ÓI�����I�u�W�F�N�g�B
};

