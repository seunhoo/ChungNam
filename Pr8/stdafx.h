#pragma once

typedef struct D3DXVECTOR2 Vec2;
typedef struct D3DXMATRIX Matrix;

template<class T>
inline void SafeDelete(T*& x);

using namespace std;

#include<d3d9.h>
#include<d3dx9.h>
#include<Windows.h>
#include<list>
#include<map>
#include<vector>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<ctime>
#include<algorithm>
#include<mmsystem.h>
#include <dshow.h>


#include"Singleton.h"
#include"App.h"
#include"Input.h"
#include"Renderer.h"
#include"Scene.h"
#include"SceneDirector.h"
#include"Texture.h"
#include"Object.h"
#include"ObjectMgr.h"
#include"Sprite.h"
#include"ResourceMgr.h"
#include"Animation.h"
#include"CollisionMgr.h"
#include"TextMgr.h"
#include"Player.h"

template<class T>
inline void SafeDelete(T*& x)
{
	delete x;
	x = static_cast<T*>(0);
}
