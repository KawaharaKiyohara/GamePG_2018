#pragma once
class Player : public IGameObject
{
public:
	bool Start();
	void Update();
	//�������烁���o�ϐ��B
	prefab::CSkinModelRender* skinModelRender = nullptr;	//�X�L�����f�������_���[�B
	//Hands-On 1 ���W�f�[�^��ǉ�����B
	
};

