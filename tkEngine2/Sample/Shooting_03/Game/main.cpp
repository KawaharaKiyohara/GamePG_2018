/*!
 *@brief	main.cpp
 */
#include "stdafx.h"
#include "Player.h"



int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	//�G���W�����g�����܂��Ȃ��B
	CEngine::Boot();

	srand((unsigned)time(NULL));
	//tkEngine2�̏������p�����[�^��ݒ肷��B
	SInitParam initParam;
	initParam.nCmdShow = nCmdShow;
	initParam.hInstance = hInstance;
	initParam.screenWidth =  1280;
	initParam.screenHeight =  720;
	initParam.frameBufferWidth = 1280;
	initParam.frameBufferHeight = 720;
	//�e�̐ݒ�B
	initParam.graphicsConfing.shadowRenderConfig.isEnable = true;
	initParam.graphicsConfing.shadowRenderConfig.shadowMapWidth = 1024;
	initParam.graphicsConfing.shadowRenderConfig.shadowMapHeight = 1024;
	initParam.graphicsConfing.shadowRenderConfig.softShadowLevel = EnSoftShadowQualityLevel::eSSSS_PCF;
	//�A���`
	initParam.graphicsConfing.aaConfig.isEnable = false;
	//Bloom
	initParam.graphicsConfing.bloomConfig.isEnable = true;
	//tonemap
	initParam.graphicsConfing.tonemapConfig.isEnable = true;
	initParam.graphicsConfing.tonemapConfig.luminance = 0.8f;

	g_engine->SetShadowMapFar(1000.0f);
	g_engine->SetShadowMapNear(50.0f);

	

	//�G���W�����������B
	if (g_engine->Init(initParam) == true) {

		//�J�������������B
		CVector3 target;
		target.x = 0.0f;
		target.y = 0.0f;
		target.z = 0.0f;
		CVector3 pos;
		pos.x = 0.0f;
		pos.y = 0.0f;
		pos.z = -10000.0f;

		g_camera3D->SetTarget( target );
		g_camera3D->SetNear( 0.1f );
		g_camera3D->SetFar( 15000.0f );
		g_camera3D->SetPosition( pos );
		g_camera3D->SetUpdateProjMatrixFunc(CCamera::enUpdateProjMatrixFunc_Ortho);
		g_camera3D->SetWidth(20000.0f);
		g_camera3D->SetHeight(20000.0f * 9.0f / 16.0f);
		g_camera3D->Update();


		//�v���C���[�̃C���X�^���X���쐬�B
		NewGO<Player>(0);

		//�G�@������̃C���X�^���X���쐬����B
		

		//�Q�[�����[�v�����s�B
		g_engine->RunGameLoop();
	}
	//�G���W���̏I�������B
	g_engine->Final();
	return 0;
}

