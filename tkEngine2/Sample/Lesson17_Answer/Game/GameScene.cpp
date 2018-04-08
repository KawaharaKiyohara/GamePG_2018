#include "stdafx.h"
#include "GameScene.h"
#include "Player.h"
#include "EnemyGenerator.h"
#include "Background.h"
#include "Enemy.h"
#include "GameOver2D.h"
#include "Bullet.h"

GameScene::GameScene()
{
}


GameScene::~GameScene()
{
	//�G�@��������폜�B
	EnemyGenerator* enemyGenerator = FindGO<EnemyGenerator>("EnemyGenerator");
	DeleteGO(enemyGenerator);

	//�w�i���폜�B
	BackGround* bg = FindGO<BackGround>("BackGround");
	DeleteGO(bg);

	//�v���C���[���폜�B
	Player* pl = FindGO<Player>("Player");
	DeleteGO(pl);

	//BGM���폜�B
	prefab::CSoundSource* bgm = FindGO<prefab::CSoundSource>("BGN");
	DeleteGO(bgm);

	//�G���폜�B
	QueryGOs<Enemy>("Enemy", [](Enemy* enemy)->bool
	{
		DeleteGO(enemy);
		return true;
	});

	//GameOver2D���폜�B
	DeleteGO(FindGO<GameOver2D>("GameOver2D"));

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
}
bool GameScene::Start()
{
	//�J�������������B
	MainCamera().SetTarget({ 0.0f, 0.0f, 0.0f });
	MainCamera().SetNear(0.1f);
	MainCamera().SetFar(15000.0f);
	MainCamera().SetPosition({ 0.0f, 0.0f, -10000.0f });
	MainCamera().SetUpdateProjMatrixFunc(CCamera::enUpdateProjMatrixFunc_Ortho);
	MainCamera().SetWidth(20000.0f);
	MainCamera().SetHeight(20000.0f * 9.0f / 16.0f);
	MainCamera().Update();

	//�G�@������̃C���X�^���X���쐬����B
	NewGO<EnemyGenerator>(0, "EnemyGenerator");
	//�w�i�̃C���X�^���X���쐬����B
	NewGO<BackGround>(0, "BackGround");
	//�v���C���[�̃C���X�^���X���쐬�B
	NewGO<Player>(0, "Player");
	//BGM���Đ��B
	prefab::CSoundSource* ss = NewGO<prefab::CSoundSource>(0, "BGM");
	ss->Init("sound/bgm.wav");
	ss->SetVolume(0.03f);
	ss->Play(true);
	return true;
}
void GameScene::Update()
{
}
