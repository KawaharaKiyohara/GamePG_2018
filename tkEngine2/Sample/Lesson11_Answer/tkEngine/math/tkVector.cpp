/*!
 * @brief	�x�N�g���N���X�B
 */

#include "tkEngine/tkEnginePreCompile.h"
#include "tkEngine/math/tkVector.h"

namespace tkEngine{

	const CVector4 CVector4::White = {1.0f, 1.0f, 1.0f, 1.0f};
	const CVector4 CVector4::Black = { 0.0f, 0.0f, 0.0f, 1.0f };
	const CVector4 CVector4::Yellow = { 1.0f, 1.0f, 0.0f, 1.0f };

	const CVector2 CVector2::Zero   = { 0.0f,  0.0f };
	
	const CQuaternion CQuaternion::Identity = { 0.0f,  0.0f, 0.0f, 1.0f };

	/*!
	*@brief	�s�񂩂�N�H�[�^�j�I�����쐬�B
	*/
	void CQuaternion::SetRotation(const CMatrix& m)
	{
		DirectX::XMStoreFloat4(&vec, DirectX::XMQuaternionRotationMatrix(m));
	}

}