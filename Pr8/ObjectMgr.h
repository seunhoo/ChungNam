#pragma once
#define ObjMgr ObjectMgr::GetInst()
class ObjectMgr : public Singleton<ObjectMgr>
{
public:

	std::list<Object*>m_Objects;

	struct stLISTsort
	{
		bool operator()(const Object* pObject1, const Object* pObject2)const
		{
			if (pObject1 < pObject2)
				return TRUE;
			return FALSE;
		}
	};

public:

	void Release();
	void DelteCheck();
	void CollideChekc(Object* obj, std::string tag);
	void Update(float deltatime, float time);
	void Render();
	void AddObject(Object* obj, std::string tag);
	void RemoveObject(Object* obj);
};

