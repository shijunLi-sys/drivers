#include <iostream>
#include "ifdef.h"

using namespace std;

typedef struct change {

	int a=0;
	int changed(int tmp) {
		return tmp += 11;
	}
};

typedef struct keep {

	int b=0;
	int kept(int b) {
		return b;
	}
};

typedef struct Device
{
	change cge;
	keep   kep;
};

typedef struct Context
{
	change cg;
	keep kp;
} *pContext;


int main(){
	int a = 10;
	int* p = &a;

	cout << sizeof(a) << " " << sizeof(p) << endl;
	cout << sizeof(int*) << endl;

	int32_t i32 = 100;
	int32_t* pi32 = &i32;

	cout << sizeof(i32)<< " " << sizeof(int32_t) << endl;
	cout << sizeof(pi32) << " " << sizeof(int32_t*) << endl;

#ifdef debug

	int tmp = 1;
	Device* dev = (Device*)malloc(sizeof(Device));
	dev->cge.a = 11;
	dev->kep.b = 10;
	dev->kep.kept(tmp);

	Context ctx;
	memset(&ctx, 0, sizeof(Context));
	pContext pctx = &ctx;
	pctx = (pContext)dev;
	cout << pctx->cg.changed(tmp);
	cout << pctx->kp.b;

#endif // debug



	return 0;
}