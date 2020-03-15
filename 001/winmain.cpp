#include <windows.h>
#include <tchar.h>

// 関数プロトタイプ宣言
LRESULT WINAPI MyWinProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hpInst, LPSTR lpCmd, int nCmd)
{
	// windowクラスの登録
	WNDCLASSEX wc;
	wc.cbSize = sizeof(WNDCLASSEX);			// 構造体そのもののサイズ
	wc.style = CS_HREDRAW | CS_VREDRAW;		// クラススタイル
											// //一般的なアプリケーションではCS_HEADRAWとCS_VREDRAW
											// //を指定しておケア良い
	wc.lpfnWndProc = MyWinProc;				// ウィンドウプロシージャのメモリアドレスを指定
	wc.cbClsExtra = 0L;						// この構造体の追加バイト数
	wc.cbWndExtra = 0L;						// この構造体の追加バイト数
	wc.hInstance = hInst;					// プログラムのインスタンスハンドル
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);		// アイコンのハンドル
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);		// cursorのハンドル
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// ウィンドウの背景色
	wc.lpszMenuName = NULL;							// メニュー名
	wc.lpszClassName = _T("__MyTest Windows");		// クラス名またはATOM
	wc.hIconSm = NULL;								//縮小アイコンのハンドル
	if (RegisterClassEx(&wc) == 0) return 0;

	return 0;
};

// ウィンドウプロシージャの定義
LRESULT WINAPI MyWinProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg) {
	case WM_LBUTTONDOWN:
		MessageBox(hWnd, _T("button clicked"), _T("winapp"), MB_OK);
		break;
	default:
		// その他メッセージの処理
		return DefWindowProc(hWnd, msg, wParam, lParam);
	}
	return 0;
}