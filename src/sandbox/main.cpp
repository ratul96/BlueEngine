#include"source/Core.h"
#include "source/Entity.h"
#include<iostream>
#include<memory>
int main()
{
	std::shared_ptr<Core> core=std::make_shared<Core>();
	std::shared_ptr<Entity> entity = std::make_shared<Entity>();
	core->addEntity();

}
