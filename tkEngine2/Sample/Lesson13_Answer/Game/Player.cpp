#include "stdafx.h"
#include "Player.h"
#include "Bullet.h"

//////////////////////////////////////////////////////////
// �R���X�g���N�^�B�C���X�^���X�����������Ƃ��ɌĂ΂�鏈���B
//////////////////////////////////////////////////////////
Player::Player()
{
}
//////////////////////////////////////////////////////////
// �f�X�g���N�^�B�C���X�^���X���j�������Ƃ��ɌĂ΂�鏈���B
//////////////////////////////////////////////////////////
Player::~Player()
{
	//�X�L�����f�������_���[��j��
	DeleteGO(m_skinModelRenderer);
}
//////////////////////////////////////////////////////////
// ���߂�Update�֐����Ă΂�钼�O�ɁA��x�����Ă΂��֐��B
//////////////////////////////////////////////////////////
bool Player::Start()
{
	//�X�L�����f�������_���[���쐬�B
	m_skinModelRenderer = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRenderer->Init(L"modelData/AirPlane.cmo", NULL, 0, CSkinModel::enFbxUpAxisY);

	return true;
}
void Player::MoveAndRotation()
{
	CQuaternion qRot = CQuaternion::Identity;
	if (Pad(0).IsPress(enButtonRight)) {
		m_position.x += 200.0f;
	}
	if (Pad(0).IsPress(enButtonLeft)) {
		m_position.x -= 200.0f;
	}
	if (Pad(0).IsPress(enButtonUp)) {
		m_position.y += 200.0f;
		//Z������̉�]�N�H�[�^�j�I�����쐬�B
		qRot.SetRotationDeg(CVector3::AxisZ, -10.0f);
	}
	if (Pad(0).IsPress(enButtonDown)) {
		m_position.y -= 200.0f;
		//Z������̉�]�N�H�[�^�j�I�����쐬�B
		qRot.SetRotationDeg(CVector3::AxisZ, 10.0f);
	}
	//Y�������-90���񂷉�]�N�H�[�^�j�I�����쐬����B
	CQuaternion qRot2;
	qRot2.SetRotationDeg(CVector3::AxisY, -90.0f);
	m_skinModelRenderer->SetRotation(qRot);

	//qRot��qRot2�̃N�H�[�^�j�I���������B
	qRot.Multiply(qRot2);

	//������m_position.x��10000�����傫���Ȃ�����B
	if (m_position.x > 10000.0f) {
		//10000.0f��������B
		m_position.x = 10000.0f;
	}
	//������m_position.x��150�����������Ȃ�����B
	if (m_position.x < -10000.0f) {
		//-20000.0f��������B
		m_position.x = -10000.0f;
	}

	//������m_position.y��10000�����傫���Ȃ�����B
	if (m_position.y > 5625.0f) {
		//10000.0f��������B
		m_position.y = 5625.0f;
	}
	//������m_position.x��150�����������Ȃ�����B
	if (m_position.y < -5625.0f) {
		//-20000.0f��������B
		m_position.y = -5625.0f;
	}

	//���W���X�L�����f�������_���[�ɔ��f������B
	m_skinModelRenderer->SetPosition(m_position);
	//��]���X�L�����f�������_���[�ɔ��f������B
	m_skinModelRenderer->SetRotation(qRot);
}
//////////////////////////////////////////////////////////
// ���Ԋu�ŌĂ΂��X�V�����B
//////////////////////////////////////////////////////////
void Player::Update()
{
	MoveAndRotation();		//�v���C���[�̈ړ��Ɖ�]������Move�֐��ɂ܂Ƃ߂���B
	//�^�C�}�[���C���N�������g�B
	m_timer++;
	//A�{�^���������ꂽ�A����m_timer��2�ȏ�Ȃ�A
	//�e�ۂ𐶐�����B
	if (Pad(0).IsPress(enButtonA) && m_timer >= 2 ) {
		//���i����e�ۂ��쐬�B
		Bullet* bullet = NewGO<Bullet>(0, "PlayerBullet");
		//�e�ۂ̍��W�Ƀv���C���[�̍��W��������B
		bullet->m_position = m_position;
		//X��������400�̑��x��ݒ肷��B
		bullet->m_moveSpeed.x = 400.0f;
		//�΂ߏ�ɔ��ł����e�ۂ��쐬�B
		bullet = NewGO<Bullet>(0, "PlayerBullet");
		bullet->m_position = m_position;
		bullet->m_moveSpeed.x = 400.0f;
		bullet->m_moveSpeed.y = 200.0f;

		//�΂߉��ɔ��ł����e�ۂ��쐬�B
		bullet = NewGO<Bullet>(0, "PlayerBullet");
		bullet->m_position = m_position;
		bullet->m_moveSpeed.x = 400.0f;
		bullet->m_moveSpeed.y = -200.0f;

		//�^�C�}�[�����Z�b�g�B
		m_timer = 0;
	}

	//EnemyBullet�Ƃ������O�̃Q�[���I�u�W�F�N�g�ɑ΂��ăN�G��(�₢���킹)���s���B
	QueryGOs<Bullet>("EnemyBullet", [&](Bullet* bullet)->bool {
		//�Q�_�Ԃ̋������v�Z����B
		CVector3 diff = bullet->m_position - m_position;
		if (diff.Length() < 500.0f) {	//������500�ȉ��ɂȂ�����B
			//���S�B
			prefab::CSoundSource* ss = NewGO<prefab::CSoundSource>(0);
			ss->Init("sound/explosion.wav");	//explosion.wav�����[�h�B
			ss->SetVolume(0.05f);				//���邳���̂ŉ�������������B
			ss->Play(false);					//�����V���b�g�Đ��B
												//�G�t�F�N�g�̃C���X�^���X�̍쐬�B
			prefab::CEffect* effect = NewGO<prefab::CEffect>(0);
			effect->Play(L"effect/fire.efk");	//fire.efk���Đ��B
			effect->SetPosition(m_position);	//�G�t�F�N�g�̔����ʒu�Ƃ��ēG�@�̍��W��n���B

			DeleteGO(this);
			//�N�G���I���B
			return false;
		}
		return true;
	});
}