#include "stdafx.h"
#include "EnemyGenerator.h"
#include "Enemy.h"

// �R���X�g���N�^�B�C���X�^���X�����������Ƃ��ɌĂ΂�鏈���B
EnemyGenerator::EnemyGenerator()
{
}
// �f�X�g���N�^�B�C���X�^���X���j�������Ƃ��ɌĂ΂�鏈���B
EnemyGenerator::~EnemyGenerator()
{
	//�G���폜�B
	QueryGOs<Enemy>("Enemy", [](Enemy* enemy)->bool
		{
			DeleteGO(enemy);
			return true;
		});
	//BGM���폜�B���܂��ł��B
	prefab::CSoundSource* bgm = FindGO<prefab::CSoundSource>("BGM");
	DeleteGO(bgm);
}
bool EnemyGenerator::Start()
{
	TK_LOG("Start EnemyGenerator");
	return true;
}

void EnemyGenerator::Update()
{
	m_timer++;
	if (m_timer == 60) {
		m_timer = 0; //�^�C�}�[�����Z�b�g�B
	   //60�t���[�����ƂɓG�@���쐬����B
		Enemy* enemy = NewGO<Enemy>(0, "Enemy");
		//X���W�͉�ʍۂɂ���B
		enemy->m_position.x = 9000.0f;
		//Y���W�������_���ɂ���B
		//GetRandDouble��0.0�`1.0�������_���ɕԂ��Ă���֐��B
		float t = g_random->GetRandDouble();
		//CMath::Leap�֐��͓�̒l�̊Ԃ���`�⊮����֐��B
		enemy->m_position.y = CMath::Lerp(t, -5000.0f, 5000.0f);

	}
	
}
