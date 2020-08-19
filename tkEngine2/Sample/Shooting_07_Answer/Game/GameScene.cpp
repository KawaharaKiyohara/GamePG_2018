#include "stdafx.h"
#include "GameScene.h"
#include "Player.h"
#include "EnemyGenerator.h"
#include "BackGround.h"
#include "Enemy.h"
#include "GameOver2D.h"
#include "Bullet.h"

GameScene::GameScene()
{
}
GameScene::~GameScene()
{
	//�w�i���폜�B
	BackGround* bg = FindGO<BackGround>("BackGround");
	DeleteGO(bg);

	//�v���C���[���폜�B
	Player* pl = FindGO<Player>("Player");
	DeleteGO(pl);
	
	//�G�@��������폜�B
	EnemyGenerator* enemyGenerator = FindGO<EnemyGenerator>("EnemyGenerator");
	DeleteGO(enemyGenerator);


	//BGM���폜�B
	prefab::CSoundSource* bgm = FindGO<prefab::CSoundSource>("BGM");
	DeleteGO(bgm);

	//�v���C���[�̒e�ۂ��폜
	QueryGOs<Bullet>("PlayerBullet", [](Bullet* bullet)->bool
		{
			DeleteGO(bullet);
			return true;
		});

	//�G�@�̒e�ۂ��폜�B
	QueryGOs<Bullet>("EnemyBullet", [](Bullet* bullet)->bool
		{
			DeleteGO(bullet);
			return true;
		});

	//�G���폜�B
	QueryGOs<Enemy>("Enemy", [](Enemy* enemy)->bool
		{
			DeleteGO(enemy);
			return true;
		});

	//GameOver2D���폜�B
	DeleteGO(FindGO<GameOver2D>("GameOver2D"));

}
bool GameScene::Start()
{
	//�J�������������B
	CVector3 target;
	target.x = 0.0f;
	target.y = 0.0f;
	target.z = 0.0f;
	CVector3 pos;
	pos.x = 0.0f;
	pos.y = 0.0f;
	pos.z = -10000.0f;
	g_camera3D->SetTarget(target);
	g_camera3D->SetNear(0.1f);
	g_camera3D->SetFar(15000.0f);
	g_camera3D->SetPosition(pos);
	g_camera3D->SetUpdateProjMatrixFunc(CCamera::enUpdateProjMatrixFunc_Ortho);
	g_camera3D->SetWidth(20000.0f);
	g_camera3D->SetHeight(20000.0f * 9.0f / 16.0f);
	g_camera3D->Update();
	//�G�@������̃C���X�^���X���쐬����B
	NewGO<EnemyGenerator>(0, "EnemyGenerator");
	//�w�i�̃C���X�^���X���쐬����B
	NewGO<BackGround>(0, "BackGround");
	//�v���C���[�̃C���X�^���X���쐬�B
	NewGO<Player>(0, "Player");
	//BGM���Đ�
	prefab::CSoundSource* ss = NewGO<prefab::CSoundSource>(0, "BGM");
	ss->Init("sound/bgm.wav");
	ss->SetVolume(0.03f);
	ss->Play(true);
	return true;
}
void GameScene::Update()
{
}
