#pragma once
class CollisionMgr : public Singleton<CollisionMgr>
{
public:
	bool CollideBox(Object* obj);
};

