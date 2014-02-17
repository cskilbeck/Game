//////////////////////////////////////////////////////////////////////

#include "stdafx.h"


//////////////////////////////////////////////////////////////////////

static App *sApp = null;

//////////////////////////////////////////////////////////////////////

App::App()
{
	assert(sApp == null);
	sApp = this;
}

//////////////////////////////////////////////////////////////////////

App::~App()
{
}

//////////////////////////////////////////////////////////////////////

App &App::Get()
{
	return *sApp;
}

//////////////////////////////////////////////////////////////////////

int App::Run()
{
	if(Graphics::Open())
	{
		OnInit();

		while(Graphics::Update())
		{
			Mouse::Update();
			Keyboard::Update();
			Joypad::Update();
			if(OnUpdate() == false)
			{
				break;
			}
		}

		OnClose();
		Graphics::Close();
	}
	return 0;
}

//////////////////////////////////////////////////////////////////////

