#pragma once 
class Player;
class Star : public IGameObject
{
public:
    ~Star();
    bool Start();
    void Update();
////////////////////////////////////////////////////
//�����o�ϐ�
////////////////////////////////////////////////////

    //prefab::CSkinModelRender*�^�̃����o�ϐ���ǉ��B 
    prefab::CSkinModelRender* skinModelRender = nullptr;

    CVector3 position;    //�X�^�[�̍��W�i�ʒu�j�B
    float angle = 0.0f;    //��]�p�x�B 
    Player* player = nullptr; //�L�����N�^�[�̏��B
    int moveCount = 0;        //�X�^�[���㉺�ɓ��������߂̃J�E���g�B
};
