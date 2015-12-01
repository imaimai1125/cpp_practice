#include <cstdio>
#include <cstdlib>
using namespace std;

#ifdef NDEBUG //リリース時
#define ASSERT(b) ((void)0)
#else //デバッグ時
//#bで条件式を文字列に変換
#define ASSERT(b) Debug::Assert((b), __FILE__, __LINE__, #b)

//条件を満たすかどうか
namespace Debug{
	void Assert(bool b,const char* file, int line, const char* expr){
		if(b){
			//この条件は常に真じゃないとだめ
		}else{
			//printf系の関数を使い，標準エラー出力に出力
			fprintf(stderr,"%s (%d):条件 \"%s\"が成り立ちませんでした\n",
				file,line,expr);
			abort();
		}
	}
}
#endif

int main(){
	int i = 0;
	ASSERT( i == 0);
	ASSERT( i > 0);
}