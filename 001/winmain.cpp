#include <windows.h>
#include <tchar.h>

// �֐��v���g�^�C�v�錾
LRESULT WINAPI MyWinProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hpInst, LPSTR lpCmd, int nCmd)
{
	// window�N���X�̓o�^
	WNDCLASSEX wc;
	wc.cbSize = sizeof(WNDCLASSEX);			// �\���̂��̂��̂̃T�C�Y
	wc.style = CS_HREDRAW | CS_VREDRAW;		// �N���X�X�^�C��
											// //��ʓI�ȃA�v���P�[�V�����ł�CS_HEADRAW��CS_VREDRAW
											// //���w�肵�Ă��P�A�ǂ�
	wc.lpfnWndProc = MyWinProc;				// �E�B���h�E�v���V�[�W���̃������A�h���X���w��
	wc.cbClsExtra = 0L;						// ���̍\���̂̒ǉ��o�C�g��
	wc.cbWndExtra = 0L;						// ���̍\���̂̒ǉ��o�C�g��
	wc.hInstance = hInst;					// �v���O�����̃C���X�^���X�n���h��
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);		// �A�C�R���̃n���h��
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);		// cursor�̃n���h��
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// �E�B���h�E�̔w�i�F
	wc.lpszMenuName = NULL;							// ���j���[��
	wc.lpszClassName = _T("__MyTest Windows");		// �N���X���܂���ATOM
	wc.hIconSm = NULL;								//�k���A�C�R���̃n���h��
	if (RegisterClassEx(&wc) == 0) return 0;

	return 0;
};

// �E�B���h�E�v���V�[�W���̒�`
LRESULT WINAPI MyWinProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg) {
	case WM_LBUTTONDOWN:
		MessageBox(hWnd, _T("button clicked"), _T("winapp"), MB_OK);
		break;
	default:
		// ���̑����b�Z�[�W�̏���
		return DefWindowProc(hWnd, msg, wParam, lParam);
	}
	return 0;
}