//////////////////////////////////////////////////////////////////////

#pragma once

//////////////////////////////////////////////////////////////////////

ALIGN(16, class) App	// Needs to be aligned in case child class needs it
{
public:

	int					Run();

	virtual void		OnInit() = 0;
	virtual bool		OnUpdate() = 0;
	virtual void		OnClose() = 0;

	static App &		Get();

protected:

	App();
	~App();
	
	uint32 pad[3];	// +1 for the vtable = 16
};
